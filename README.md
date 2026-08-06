# IPXQuoteTool

IPX 费用估算，用于读取 SolidWorks 零件、装配体、工程图指标，并根据对象系数和文件类型系数生成费用估算报表。

## 项目结构

```text
src\UI\                 WPF 界面与窗口代码
src\Services\           SolidWorks/Document Manager 服务封装
src\Analysis\           零件、装配体、工程图指标提取逻辑
src\Pricing\            对象系数、单价、折扣和报价规则
src\Reporting\          费用估算 xlsx 生成
src\Settings\           用户路径配置读写
src\Models\             报价过程使用的数据模型
resources\Templates\    随软件发布的输入模板，例如对象系数.xlsx
lib\SolidWorks\         SolidWorks 互操作 DLL
packaging\              免安装包发布脚本
packaging\runtime\      可选：随包携带的 .NET Desktop Runtime 安装程序
artifacts\bin\          编译输出目录
artifacts\obj\          编译中间产物目录
artifacts\publish\      免安装发布包输出目录
```

## 免安装打包

在项目根目录打开 PowerShell：

```powershell
cd C:\Users\GESIC\Desktop\xuhongtao\IPXQuote-mytest\IPXQuotetest
```

生成默认小包版：

```powershell
powershell -ExecutionPolicy Bypass -File .\publish-portable.ps1
```

如果要让客户在没有网络或没有 `winget` 的环境下也能安装 .NET Runtime，请先把安装包放到：

```text
packaging\runtime\windowsdesktop-runtime-10.0.10-win-x64.exe
```

发布脚本会把它复制到：

```text
IPXQuoteTool_Portable\runtime\windowsdesktop-runtime-10.0.10-win-x64.exe
```

当前脚本也兼容历史目录名 `packaging\runntime\...`，但推荐后续统一使用 `packaging\runtime`。

不要直接使用 `dotnet publish` 当作发包命令；`dotnet publish` 只会生成程序文件，不会补齐 `启动费用估算.cmd`、启动器脚本、使用说明和压缩包。

生成结果：

```text
artifacts\publish\IPXQuoteTool_Portable\
artifacts\publish\IPXQuoteTool_Portable.zip
```

发给客户时，发送这个压缩包：

```text
artifacts\publish\IPXQuoteTool_Portable.zip
```

## 客户使用方式

客户解压整个压缩包后，双击：

```text
启动费用估算.cmd
```

启动器会检测客户电脑是否安装 `.NET 10 Desktop Runtime x64`。

如果未安装，启动器会按顺序处理：

1. 如果发布包内存在 `runtime\windowsdesktop-runtime-10.0.10-win-x64.exe`，提示客户确认后，以管理员权限启动本地安装程序。
2. 如果发布包内没有 runtime 安装程序，才尝试通过 `winget` 自动安装：

```powershell
winget install --id Microsoft.DotNet.DesktopRuntime.10 --source winget --accept-package-agreements --accept-source-agreements
```

3. 如果自动安装失败，会打开微软官方下载页面。

安装完成后，重新双击 `启动费用估算.cmd`。

## 自包含大包

如果希望客户不需要安装 .NET，可以生成自包含版：

```powershell
powershell -ExecutionPolicy Bypass -File .\publish-portable.ps1 -SelfContained
```

自包含版包体会明显变大，但客户电脑不需要额外安装 .NET Runtime。

## 发布包注意事项

- 不要把 `bin` 目录发给客户。
- 不要只单独发送 `IPXQuoteTool.exe`。
- 应发送整个 `IPXQuoteTool_Portable.zip`。
- `对象系数.xlsx` 必须和 `IPXQuoteTool.exe` 保持在同一目录。
- Release 包固定使用程序内置单价和复杂度系数；Debug 包才会从 `对象系数.xlsx` 读取单价和复杂度配置。
- 如果使用小包版并希望客户免联网安装 .NET，请确认压缩包内包含 `runtime\windowsdesktop-runtime-10.0.10-win-x64.exe`。
- 客户电脑仍需具备对应的 SolidWorks/Document Manager 环境，否则无法读取 SolidWorks 文件。
