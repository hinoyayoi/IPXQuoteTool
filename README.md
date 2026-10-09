# IPXQuoteTool

IPX 费用估算，用于读取 SolidWorks/Creo 零件、装配体、工程图指标，并根据对象系数和文件类型系数生成费用估算报表。

## 项目结构

```text
src\UI\                  WPF 界面与窗口代码
src\Cad\SolidWorks\      SolidWorks/Document Manager 服务封装
src\Cad\Creo\            Creo 启动、插件部署、IPC 通讯、指标映射
src\Pricing\             对象系数、单价、折扣和报价规则
src\Reporting\           费用估算 xlsx 生成
src\Settings\            用户路径配置读写
src\Models\              报价过程使用的数据模型
resources\Templates\     随软件发布的输入模板，例如对象系数.xlsx
bridges\CreoPlugin\      Creo Toolkit 进程内插件工程
lib\SolidWorks\          SolidWorks 互操作 DLL
lib\Creo\                Creo Toolkit 头文件和链接库
packaging\               免安装包发布脚本
packaging\runtime\       可选：随包携带的 .NET Desktop Runtime 安装程序
artifacts\bin\           编译输出目录
artifacts\obj\           编译中间产物目录
artifacts\publish\       免安装发布包输出目录
```

## 免安装打包

在项目根目录打开 PowerShell：

```powershell
cd <repo-root>
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

## Creo 支持说明

Creo 读取通过 `bridges\CreoPlugin` 下的 Creo Toolkit 插件完成。发布包中的 `creo-plugin` 目录只是插件源文件目录，程序启动 Creo 前会先把插件复制到一个运行目录，再把该运行目录写入 Creo 的 `protk.dat`。

### Creo 插件运行目录

插件运行目录是 Creo 实际加载 DLL 的位置。目录名中带有根据 Creo 安装根目录生成的 `environmentId`，用于隔离不同 Creo 安装环境：

```text
Creo_3FF3FE516C42AA14
```

运行目录固定使用 ProgramData：

```text
C:\ProgramData\IPXQuoteTool\CreoPluginRuntime\<environmentId>\
```

这样做的目的不是把插件安装进 Creo 目录，而是让 Creo 从一个稳定、英文路径的公共运行目录加载插件，并避免 Creo 锁定发布包内 DLL 后影响后续更新。`environmentId` 仍由 Creo 安装根目录生成，用于隔离不同 Creo 安装环境；不再根据包路径或用户目录是否包含中文切换到不同目录。

### protk.dat 注册

程序会在当前 Creo 的 `Parametric\bin\protk.dat` 中写入插件注册块：

```text
name IPXQuoteCreoPlugin
startup dll
exec_file <插件运行目录>\IPXQuoteCreoPlugin.dll
text_dir <插件运行目录>\text
revision 4
end
```

插件会统一复制到 ProgramData 下的运行目录；该目录写入权限取决于客户电脑策略。写入 Creo 安装目录下的 `protk.dat` 可能需要管理员权限，管理员权限主要用于注册插件路径，不是把 DLL 复制到 Creo 安装目录。

### IPC 通讯

插件被 Creo 加载后，会启动命名管道：

```text
IPXQuoteCreoPlugin_<environmentId>
```

报价工具通过该管道向 Creo 插件发送文件路径并读取指标。模型文件路径允许包含中文；IPC 使用 UTF-8 JSON，插件侧再转成宽字符路径处理。

### Creo 数据提取口径

当前 Creo 插件以 Creo4 Toolkit 为基线编译，使用 Creo4 可用的通用 API 做数据提取，不是 Creo10 专版适配。后续如果要正式区分 Creo4/Creo10，应拆成不同 Toolkit 版本的插件 DLL，并按 Creo 版本选择对应 DLL。

当前装配统计口径：

- 组件数：按父装配模型树中的二级组件口径统计。只要特征类型是组件，即使组件模型无法解析，也仍计入组件数。
- 装配特征：按装配同级的非组件特征统计，例如草绘、阵列、孔、拉伸、旋转等；基准、坐标系、引用类特征和容器类特征不计入。
- 装配约束：只对可解析为零件/装配模型的组件读取约束。若组件模型无法解析到零件/装配类型，组件数保留，装配约束计 0。

常用诊断文件：

```text
%TEMP%\IPXQuoteCreoPlugin\plugin.log
%TEMP%\IPXQuoteCreoPlugin\last-result.json
```

`last-result.json` 会记录最近一次 Creo 插件提取结果，包括组件、装配特征、约束来源和过滤原因，适合对照 Excel 报表排查。

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
- 客户电脑如果需要读取 Creo 文件，必须安装对应 Creo，并允许程序写入或更新该 Creo `Parametric\bin\protk.dat` 中的插件注册块。
- 发布包中必须包含 `creo-plugin\IPXQuoteCreoPlugin.dll` 和 `creo-plugin\text`，否则无法自动部署 Creo 插件运行目录。
- Creo 已加载插件时会锁定 DLL。替换插件或验证新包前，需要关闭相关 Creo 进程，让下次启动加载新的运行目录副本。
