using System;

namespace IPXQuoteTool.Cad.Creo.Services
{
    internal static class CreoCommunicationErrorClassifier
    {
        public static bool IsCommunicationFailure(string errorMessage)
        {
            if (string.IsNullOrWhiteSpace(errorMessage))
            {
                return false;
            }

            return Contains(errorMessage, "ConnectTimeout") ||
                   Contains(errorMessage, "PipeDisconnected") ||
                   Contains(errorMessage, "EmptyResponse") ||
                   Contains(errorMessage, "InvalidMetricsResponse") ||
                   Contains(errorMessage, "InvalidPingResponse") ||
                   Contains(errorMessage, "MismatchedResponseId") ||
                   Contains(errorMessage, "RequestTimeout") ||
                   Contains(errorMessage, "Could not connect to Creo plugin IPC") ||
                   Contains(errorMessage, "Creo plugin returned an empty IPC response") ||
                   Contains(errorMessage, "Invalid Creo plugin IPC JSON response") ||
                   Contains(errorMessage, "Timed out waiting for Creo plugin");
        }

        private static bool Contains(string value, string expected)
        {
            return value.IndexOf(expected, StringComparison.OrdinalIgnoreCase) >= 0;
        }
    }
}