namespace IPXQuoteTool.Cad.Creo.Ipc
{
    internal enum CreoPluginIpcStatus
    {
        Succeeded,
        Ready,
        NotReady,
        Timeout,
        PipeDisconnected,
        EmptyResponse,
        InvalidResponse,
        MismatchedResponseId,
        UnsupportedCommand,
        RequestTimeout,
        Failed,
        UnknownError
    }

    internal sealed class CreoPluginIpcOperationResult
    {
        private CreoPluginIpcOperationResult(
            CreoPluginIpcStatus status,
            string requestId,
            string responseJson,
            string errorCode,
            string message)
        {
            Status = status;
            RequestId = requestId;
            ResponseJson = responseJson;
            ErrorCode = errorCode;
            Message = message;
        }

        public CreoPluginIpcStatus Status { get; }
        public string RequestId { get; }
        public string ResponseJson { get; }
        public string ErrorCode { get; }
        public string Message { get; }
        public bool IsSuccess => Status == CreoPluginIpcStatus.Succeeded || Status == CreoPluginIpcStatus.Ready;

        public static CreoPluginIpcOperationResult Success(string requestId, string responseJson)
        {
            return new CreoPluginIpcOperationResult(CreoPluginIpcStatus.Succeeded, requestId, responseJson, null, null);
        }

        public static CreoPluginIpcOperationResult Ready(string requestId, string message)
        {
            return new CreoPluginIpcOperationResult(CreoPluginIpcStatus.Ready, requestId, null, null, message);
        }

        public static CreoPluginIpcOperationResult Fail(CreoPluginIpcStatus status, string requestId, string errorCode, string message)
        {
            return new CreoPluginIpcOperationResult(status, requestId, null, errorCode, message);
        }

        public string ToErrorMessage()
        {
            if (!string.IsNullOrWhiteSpace(ErrorCode) && !string.IsNullOrWhiteSpace(Message))
            {
                return ErrorCode + ": " + Message;
            }

            if (!string.IsNullOrWhiteSpace(Message))
            {
                return Message;
            }

            if (!string.IsNullOrWhiteSpace(ErrorCode))
            {
                return ErrorCode;
            }

            return Status.ToString();
        }
    }
}