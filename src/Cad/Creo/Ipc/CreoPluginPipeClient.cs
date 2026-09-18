using System;
using System.IO;
using System.IO.Pipes;
using System.Text;
using System.Text.Encodings.Web;
using System.Text.Json;
using IPXQuoteTool.Cad.Common;
using IPXQuoteTool.Cad.Creo.Models;

namespace IPXQuoteTool.Cad.Creo.Ipc
{
    internal class CreoPluginPipeClient
    {
        private const string PipeName = "IPXQuoteCreoPlugin";
        private const int ConnectTimeoutMs = 3000;
        private static readonly JsonSerializerOptions RequestJsonOptions = new JsonSerializerOptions
        {
            Encoder = JavaScriptEncoder.UnsafeRelaxedJsonEscaping
        };

        public bool TryPing(out string statusMessage)
        {
            string requestId = CreateRequestId();
            string requestJson = JsonSerializer.Serialize(new
            {
                version = 1,
                requestId,
                command = "Ping"
            }, RequestJsonOptions);

            CreoPluginIpcOperationResult sendResult = SendRequest(requestJson, requestId);
            if (!sendResult.IsSuccess)
            {
                statusMessage = sendResult.ToErrorMessage();
                return false;
            }

            CreoPluginIpcOperationResult parseResult = TryParsePingResponse(sendResult.ResponseJson, requestId);
            statusMessage = parseResult.IsSuccess ? parseResult.Message : parseResult.ToErrorMessage();
            return parseResult.IsSuccess;
        }

        public CreoDocumentMetricsDto TryReadDocument(string filePath, out string errorMessage)
        {
            errorMessage = null;

            if (string.IsNullOrWhiteSpace(filePath))
            {
                errorMessage = "Creo file path is empty.";
                return null;
            }

            string requestId = CreateRequestId();
            string requestJson = JsonSerializer.Serialize(new
            {
                version = 1,
                requestId,
                command = "ReadMetrics",
                filePath,
                timeoutMs = 120000
            }, RequestJsonOptions);

            CreoPluginIpcOperationResult sendResult = SendRequest(requestJson, requestId);
            if (!sendResult.IsSuccess)
            {
                errorMessage = sendResult.ToErrorMessage();
                return null;
            }

            CreoDocumentMetricsDto metrics = ToDto(sendResult.ResponseJson, filePath, requestId, out errorMessage);
            return metrics;
        }

        private static CreoPluginIpcOperationResult SendRequest(string requestJson, string requestId)
        {
            CreoPluginIpcOperationResult framedResult = SendFramedRequest(requestJson, requestId);
            if (framedResult.IsSuccess || !ShouldRetryWithLegacyProtocol(framedResult))
            {
                return framedResult;
            }

            return SendLegacyRequest(requestJson, requestId);
        }

        private static CreoPluginIpcOperationResult SendFramedRequest(string requestJson, string requestId)
        {
            try
            {
                using NamedPipeClientStream pipe = CreateConnectedPipe();
                CreoPluginPipeMessageFraming.WriteMessage(pipe, requestJson);
                string json = CreoPluginPipeMessageFraming.ReadMessage(pipe);
                return ToSuccessfulResponseOrEmptyFailure(json, requestId);
            }
            catch (TimeoutException)
            {
                return CreoPluginIpcOperationResult.Fail(
                    CreoPluginIpcStatus.Timeout,
                    requestId,
                    "ConnectTimeout",
                    "Could not connect to Creo plugin IPC. Make sure Creo is running and IPXQuoteCreoPlugin is loaded.");
            }
            catch (InvalidDataException ex)
            {
                return CreoPluginIpcOperationResult.Fail(
                    CreoPluginIpcStatus.InvalidResponse,
                    requestId,
                    "InvalidMessageFrame",
                    ex.Message);
            }
            catch (EndOfStreamException ex)
            {
                return CreoPluginIpcOperationResult.Fail(
                    CreoPluginIpcStatus.InvalidResponse,
                    requestId,
                    "IncompleteMessageFrame",
                    ex.Message);
            }
            catch (IOException ex)
            {
                return CreoPluginIpcOperationResult.Fail(
                    CreoPluginIpcStatus.PipeDisconnected,
                    requestId,
                    "PipeDisconnected",
                    ex.Message);
            }
            catch (Exception ex)
            {
                return CreoPluginIpcOperationResult.Fail(
                    CreoPluginIpcStatus.UnknownError,
                    requestId,
                    "UnexpectedIpcError",
                    ex.Message);
            }
        }

        private static CreoPluginIpcOperationResult SendLegacyRequest(string requestJson, string requestId)
        {
            try
            {
                using NamedPipeClientStream pipe = CreateConnectedPipe();
                byte[] requestBytes = Encoding.UTF8.GetBytes(requestJson);
                pipe.Write(requestBytes, 0, requestBytes.Length);
                pipe.Flush();

                using StreamReader reader = new StreamReader(pipe, Encoding.UTF8, detectEncodingFromByteOrderMarks: false, bufferSize: 8192, leaveOpen: true);
                string json = reader.ReadToEnd();
                return ToSuccessfulResponseOrEmptyFailure(json, requestId);
            }
            catch (TimeoutException)
            {
                return CreoPluginIpcOperationResult.Fail(
                    CreoPluginIpcStatus.Timeout,
                    requestId,
                    "ConnectTimeout",
                    "Could not connect to Creo plugin IPC. Make sure Creo is running and IPXQuoteCreoPlugin is loaded.");
            }
            catch (IOException ex)
            {
                return CreoPluginIpcOperationResult.Fail(
                    CreoPluginIpcStatus.PipeDisconnected,
                    requestId,
                    "PipeDisconnected",
                    ex.Message);
            }
            catch (Exception ex)
            {
                return CreoPluginIpcOperationResult.Fail(
                    CreoPluginIpcStatus.UnknownError,
                    requestId,
                    "UnexpectedLegacyIpcError",
                    ex.Message);
            }
        }

        private static NamedPipeClientStream CreateConnectedPipe()
        {
            NamedPipeClientStream pipe = new NamedPipeClientStream(
                ".",
                PipeName,
                PipeDirection.InOut,
                PipeOptions.None);
            pipe.Connect(ConnectTimeoutMs);
            return pipe;
        }

        private static CreoPluginIpcOperationResult ToSuccessfulResponseOrEmptyFailure(string json, string requestId)
        {
            if (string.IsNullOrWhiteSpace(json))
            {
                return CreoPluginIpcOperationResult.Fail(
                    CreoPluginIpcStatus.EmptyResponse,
                    requestId,
                    "EmptyResponse",
                    "Creo plugin returned an empty IPC response.");
            }

            return CreoPluginIpcOperationResult.Success(requestId, json);
        }

        private static bool ShouldRetryWithLegacyProtocol(CreoPluginIpcOperationResult result)
        {
            return string.Equals(result.ErrorCode, "InvalidMessageFrame", StringComparison.OrdinalIgnoreCase) ||
                string.Equals(result.ErrorCode, "IncompleteMessageFrame", StringComparison.OrdinalIgnoreCase);
        }

        private static CreoPluginIpcOperationResult TryParsePingResponse(string json, string requestId)
        {
            try
            {
                using JsonDocument document = JsonDocument.Parse(json);
                JsonElement root = document.RootElement;
                string responseRequestId = GetString(root, "requestId");
                if (!string.IsNullOrWhiteSpace(responseRequestId) &&
                    !string.Equals(responseRequestId, requestId, StringComparison.OrdinalIgnoreCase))
                {
                    return CreoPluginIpcOperationResult.Fail(
                        CreoPluginIpcStatus.MismatchedResponseId,
                        requestId,
                        "MismatchedResponseId",
                        "Creo plugin returned a mismatched Ping response id.");
                }

                string status = GetString(root, "status");
                string pluginState = GetString(root, "pluginState");
                string message = GetString(root, "message");
                string statusMessage = string.IsNullOrWhiteSpace(message) ? pluginState : message;

                if (string.Equals(status, "Succeeded", StringComparison.OrdinalIgnoreCase) ||
                    string.Equals(pluginState, "Ready", StringComparison.OrdinalIgnoreCase))
                {
                    return CreoPluginIpcOperationResult.Ready(requestId, string.IsNullOrWhiteSpace(statusMessage) ? "Ready" : statusMessage);
                }

                return CreoPluginIpcOperationResult.Fail(
                    CreoPluginIpcStatus.NotReady,
                    requestId,
                    GetString(root, "errorCode") ?? "NotReady",
                    string.IsNullOrWhiteSpace(statusMessage) ? "Creo plugin did not return Ready." : statusMessage);
            }
            catch (Exception ex)
            {
                return CreoPluginIpcOperationResult.Fail(
                    CreoPluginIpcStatus.InvalidResponse,
                    requestId,
                    "InvalidPingResponse",
                    "Invalid Creo plugin Ping response: " + ex.Message);
            }
        }

        private static CreoDocumentMetricsDto ToDto(string json, string requestedFilePath, string requestId, out string errorMessage)
        {
            errorMessage = null;

            try
            {
                using JsonDocument document = JsonDocument.Parse(json);
                JsonElement root = document.RootElement;
                JsonElement metricsRoot = root;

                if (root.TryGetProperty("requestId", out JsonElement responseRequestIdElement) &&
                    responseRequestIdElement.ValueKind == JsonValueKind.String)
                {
                    string responseRequestId = responseRequestIdElement.GetString();
                    if (!string.IsNullOrWhiteSpace(responseRequestId) &&
                        !string.Equals(responseRequestId, requestId, StringComparison.OrdinalIgnoreCase))
                    {
                        errorMessage = CreoPluginIpcOperationResult.Fail(
                            CreoPluginIpcStatus.MismatchedResponseId,
                            requestId,
                            "MismatchedResponseId",
                            "Creo plugin returned a mismatched response id.").ToErrorMessage();
                        return null;
                    }
                }

                string status = GetString(root, "status");
                string responseMessage = GetString(root, "message");
                string errorCode = GetString(root, "errorCode");

                if (root.TryGetProperty("metrics", out JsonElement nestedMetrics) && nestedMetrics.ValueKind == JsonValueKind.Object)
                {
                    metricsRoot = nestedMetrics;
                }
                else if (!string.IsNullOrWhiteSpace(status) &&
                         !string.Equals(status, "Succeeded", StringComparison.OrdinalIgnoreCase) &&
                         !root.TryGetProperty("FileName", out _))
                {
                    errorMessage = BuildProtocolError(errorCode, responseMessage, status);
                    return null;
                }

                CreoDocumentMetricsDto dto = MetricsToDto(metricsRoot, requestedFilePath);
                if (!string.IsNullOrWhiteSpace(status) &&
                    !string.Equals(status, "Succeeded", StringComparison.OrdinalIgnoreCase) &&
                    string.IsNullOrWhiteSpace(dto.ErrorMessage))
                {
                    dto.Succeeded = false;
                    dto.ErrorMessage = BuildProtocolError(errorCode, responseMessage, status);
                }

                return dto;
            }
            catch (Exception ex)
            {
                errorMessage = CreoPluginIpcOperationResult.Fail(
                    CreoPluginIpcStatus.InvalidResponse,
                    requestId,
                    "InvalidMetricsResponse",
                    "Invalid Creo plugin IPC JSON response: " + ex.Message).ToErrorMessage();
                return null;
            }
        }

        private static CreoDocumentMetricsDto MetricsToDto(JsonElement root, string requestedFilePath)
        {
            string responseFilePath = GetString(root, "FilePath");
            string responseFileName = GetString(root, "FileName");
            string requestedFileName = Path.GetFileName(requestedFilePath);
            int configurationCount = GetInt(root, "ConfigurationCount");

            return new CreoDocumentMetricsDto
            {
                FilePath = string.IsNullOrWhiteSpace(requestedFilePath) ? responseFilePath : requestedFilePath,
                FileName = string.IsNullOrWhiteSpace(requestedFileName) ? responseFileName : requestedFileName,
                DocumentType = ToCadDocumentType(GetString(root, "DocumentKind"), requestedFilePath),
                FeatureCount = GetInt(root, "FeatureCount"),
                ConfigurationCount = configurationCount,
                ExpressionCount = GetInt(root, "ExpressionCount"),
                ComponentCount = GetInt(root, "ComponentCount"),
                MateCount = GetInt(root, "MateCount"),
                AssemblyFeatureCount = GetInt(root, "AssemblyFeatureCount"),
                ViewCount = GetInt(root, "ViewCount"),
                NoteCount = GetInt(root, "NoteCount"),
                DimensionCount = GetInt(root, "DimensionCount"),
                TableCount = GetInt(root, "TableCount"),
                Succeeded = GetBool(root, "Succeeded"),
                ErrorMessage = GetString(root, "ErrorMessage")
            };
        }

        private static string CreateRequestId()
        {
            return Guid.NewGuid().ToString("N");
        }

        private static string BuildProtocolError(string errorCode, string message, string fallbackStatus)
        {
            if (!string.IsNullOrWhiteSpace(errorCode) && !string.IsNullOrWhiteSpace(message))
            {
                return errorCode + ": " + message;
            }

            if (!string.IsNullOrWhiteSpace(message))
            {
                return message;
            }

            return string.IsNullOrWhiteSpace(errorCode) ? fallbackStatus : errorCode;
        }

        private static CadDocumentType ToCadDocumentType(string kind, string fallbackFilePath)
        {
            CadDocumentType documentType = kind switch
            {
                "Part" => CadDocumentType.Part,
                "Assembly" => CadDocumentType.Assembly,
                "Drawing" => CadDocumentType.Drawing,
                _ => CadDocumentType.Unknown
            };

            return documentType == CadDocumentType.Unknown
                ? CadFileTypeDetector.GetDocumentTypeFromPath(fallbackFilePath)
                : documentType;
        }

        private static string GetString(JsonElement root, string propertyName)
        {
            return root.TryGetProperty(propertyName, out JsonElement value) && value.ValueKind == JsonValueKind.String
                ? value.GetString()
                : null;
        }

        private static int GetInt(JsonElement root, string propertyName)
        {
            return root.TryGetProperty(propertyName, out JsonElement value) && value.TryGetInt32(out int result)
                ? result
                : 0;
        }

        private static bool GetBool(JsonElement root, string propertyName)
        {
            return root.TryGetProperty(propertyName, out JsonElement value) && value.ValueKind == JsonValueKind.True;
        }
    }
}

