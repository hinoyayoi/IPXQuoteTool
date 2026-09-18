using System;
using System.IO;
using System.Text;

namespace IPXQuoteTool.Cad.Creo.Ipc
{
    internal static class CreoPluginPipeMessageFraming
    {
        private const int HeaderLengthBytes = 4;
        private const int MaxMessageBytes = 4 * 1024 * 1024;

        public static void WriteMessage(Stream stream, string json)
        {
            if (stream == null)
            {
                throw new ArgumentNullException(nameof(stream));
            }

            byte[] payload = Encoding.UTF8.GetBytes(json ?? string.Empty);
            if (payload.Length <= 0 || payload.Length > MaxMessageBytes)
            {
                throw new InvalidDataException($"Creo IPC message length is invalid: {payload.Length} bytes.");
            }

            byte[] header = BitConverter.GetBytes(payload.Length);
            if (!BitConverter.IsLittleEndian)
            {
                Array.Reverse(header);
            }

            stream.Write(header, 0, HeaderLengthBytes);
            stream.Write(payload, 0, payload.Length);
            stream.Flush();
        }

        public static string ReadMessage(Stream stream)
        {
            if (stream == null)
            {
                throw new ArgumentNullException(nameof(stream));
            }

            byte[] header = ReadExact(stream, HeaderLengthBytes);
            if (!BitConverter.IsLittleEndian)
            {
                Array.Reverse(header);
            }

            int payloadLength = BitConverter.ToInt32(header, 0);
            if (payloadLength <= 0 || payloadLength > MaxMessageBytes)
            {
                throw new InvalidDataException($"Creo IPC message length is invalid: {payloadLength} bytes.");
            }

            byte[] payload = ReadExact(stream, payloadLength);
            return Encoding.UTF8.GetString(payload);
        }

        private static byte[] ReadExact(Stream stream, int byteCount)
        {
            byte[] buffer = new byte[byteCount];
            int offset = 0;
            while (offset < byteCount)
            {
                int read = stream.Read(buffer, offset, byteCount - offset);
                if (read <= 0)
                {
                    throw new EndOfStreamException("Creo IPC pipe closed before the complete message was received.");
                }

                offset += read;
            }

            return buffer;
        }
    }
}
