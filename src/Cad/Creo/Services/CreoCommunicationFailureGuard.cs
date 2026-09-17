namespace IPXQuoteTool.Cad.Creo.Services
{
    internal class CreoCommunicationFailureGuard
    {
        private readonly int _maxConsecutiveFailures;
        private int _consecutiveFailures;

        public CreoCommunicationFailureGuard(int maxConsecutiveFailures)
        {
            _maxConsecutiveFailures = maxConsecutiveFailures < 1 ? 1 : maxConsecutiveFailures;
        }

        public bool ShouldStopAfterResult(bool processingFailed, string errorMessage, out string stopReason)
        {
            stopReason = null;

            if (!processingFailed)
            {
                _consecutiveFailures = 0;
                return false;
            }

            if (!CreoCommunicationErrorClassifier.IsCommunicationFailure(errorMessage))
            {
                _consecutiveFailures = 0;
                return false;
            }

            _consecutiveFailures++;
            if (_consecutiveFailures < _maxConsecutiveFailures)
            {
                return false;
            }

            stopReason = $"Creo 插件连续 {_consecutiveFailures} 次通信失败，已停止后续处理。请确认 Creo 未崩溃、IPXQuoteCreoPlugin 已加载且插件日志无异常。最后一次错误：{errorMessage}";
            return true;
        }
    }
}