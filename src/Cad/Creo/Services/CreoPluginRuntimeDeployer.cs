using System;
using System.IO;

namespace IPXQuoteTool.Cad.Creo.Services
{
    internal class CreoPluginRuntimeDeployer
    {
        public bool TryDeploy(CreoPluginEnvironment environment, out string message, out string error)
        {
            message = null;
            error = null;

            if (environment == null)
            {
                error = "Creo 插件环境为空，无法准备插件运行目录。";
                return false;
            }

            if (!IsAsciiPath(environment.PluginDllPath) || !IsAsciiPath(environment.TextDirectory))
            {
                error = "Creo 插件运行目录仍包含非英文字符，无法安全写入 protk.dat：" + environment.DeployedPluginDirectory;
                return false;
            }

            try
            {
                Directory.CreateDirectory(environment.DeployedPluginDirectory);
                Directory.CreateDirectory(environment.TextDirectory);
                bool changed = false;

                changed |= CopyFileIfChanged(environment.PackagedPluginDllPath, environment.PluginDllPath);
                CopyDirectoryFiles(environment.PackagedTextDirectory, environment.TextDirectory, ref changed);

                message = changed
                    ? "已准备 Creo 插件运行目录：" + environment.DeployedPluginDirectory
                    : "Creo 插件运行目录已是最新：" + environment.DeployedPluginDirectory;
                return true;
            }
            catch (IOException ex)
            {
                error = "准备 Creo 插件运行目录失败，可能是当前版本 Creo 正在占用旧插件 DLL。详情：" + ex.Message;
                return false;
            }
            catch (UnauthorizedAccessException ex)
            {
                error = "准备 Creo 插件运行目录失败，请检查目录权限：" + ex.Message;
                return false;
            }
            catch (Exception ex)
            {
                error = "准备 Creo 插件运行目录失败：" + ex.Message;
                return false;
            }
        }

        private static bool CopyFileIfChanged(string sourcePath, string targetPath)
        {
            if (string.IsNullOrWhiteSpace(sourcePath) || !File.Exists(sourcePath))
            {
                throw new FileNotFoundException("未找到源文件。", sourcePath);
            }

            string targetDirectory = Path.GetDirectoryName(targetPath);
            if (!string.IsNullOrWhiteSpace(targetDirectory))
            {
                Directory.CreateDirectory(targetDirectory);
            }

            FileInfo sourceInfo = new FileInfo(sourcePath);
            FileInfo targetInfo = new FileInfo(targetPath);
            if (targetInfo.Exists && sourceInfo.Length == targetInfo.Length && FilesHaveSameContent(sourcePath, targetPath))
            {
                return false;
            }

            File.Copy(sourcePath, targetPath, overwrite: true);
            File.SetLastWriteTimeUtc(targetPath, sourceInfo.LastWriteTimeUtc);
            return true;
        }

        private static bool FilesHaveSameContent(string sourcePath, string targetPath)
        {
            const int BufferSize = 81920;
            using FileStream sourceStream = File.OpenRead(sourcePath);
            using FileStream targetStream = File.OpenRead(targetPath);
            byte[] sourceBuffer = new byte[BufferSize];
            byte[] targetBuffer = new byte[BufferSize];

            while (true)
            {
                int sourceRead = sourceStream.Read(sourceBuffer, 0, sourceBuffer.Length);
                int targetRead = targetStream.Read(targetBuffer, 0, targetBuffer.Length);
                if (sourceRead != targetRead)
                {
                    return false;
                }

                if (sourceRead == 0)
                {
                    return true;
                }

                for (int index = 0; index < sourceRead; index++)
                {
                    if (sourceBuffer[index] != targetBuffer[index])
                    {
                        return false;
                    }
                }
            }
        }

        private static void CopyDirectoryFiles(string sourceDirectory, string targetDirectory, ref bool changed)
        {
            if (!Directory.Exists(sourceDirectory))
            {
                throw new DirectoryNotFoundException("未找到源目录：" + sourceDirectory);
            }

            foreach (string sourceFile in Directory.GetFiles(sourceDirectory, "*", SearchOption.AllDirectories))
            {
                string relativePath = sourceFile.Substring(sourceDirectory.Length).TrimStart(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar);
                string targetFile = Path.Combine(targetDirectory, relativePath);
                if (CopyFileIfChanged(sourceFile, targetFile))
                {
                    changed = true;
                }
            }
        }

        private static bool IsAsciiPath(string path)
        {
            if (string.IsNullOrWhiteSpace(path))
            {
                return false;
            }

            foreach (char ch in path)
            {
                if (ch > 127)
                {
                    return false;
                }
            }

            return true;
        }
    }
}
