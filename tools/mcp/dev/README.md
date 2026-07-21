# IPXQuoteTool 开发版 MCP

这是 IPXQuoteTool 的开发辅助 MCP Server。

它用于本地开发、维护和发布检查，不面向客户交付。第一版主要提供构建、打包、发布包检查、对象系数检查、统计明细读取和重复统计诊断能力。

## 环境要求

- Node.js 20 LTS 或更高版本
- npm
- 本项目使用的 .NET SDK
- PowerShell

进入本目录安装依赖：

```powershell
cd tools\mcp\dev
npm install
```

手动启动：

```powershell
npm start
```

通常 MCP 客户端会自动启动这个服务，手动启动主要用于冒测试。

## 工具列表

- `ipx.project_summary`
  - 返回项目根目录、关键路径和当前可用工具。
- `ipx.build`
  - 执行 `dotnet build IPXQuoteTool.csproj`。
- `ipx.publish_portable`
  - 执行 `publish-portable.ps1`，并检查生成的 portable 压缩包。
- `ipx.inspect_portable_zip`
  - 检查 `artifacts\publish\IPXQuoteTool_Portable.zip` 是否包含发布必需文件。
- `ipx.check_object_coefficients`
  - 检查代码和 `resources\Templates\对象系数.xlsx` 中的默认单价、复杂度系数是否一致。
- `ipx.read_recent_trace`
  - 读取 `%APPDATA%\IPXQuoteTool` 下最近的统计明细日志。
- `ipx.check_duplicate_metrics`
  - 按对象类型和对象名称分组最近统计明细，用于检查中心线、表格、注释等是否重复统计。

## MCP 客户端配置示例

在支持 MCP 的 AI 客户端里增加类似配置：

```json
{
  "mcpServers": {
    "ipx-dev": {
      "command": "node",
      "args": [
        "C:/Users/GESIC/Desktop/xuhongtao/IPXQuote-mytest/IPXQuotetest/tools/mcp/dev/server.js"
      ]
    }
  }
}
```

配置好之后，可以在 AI 客户端里这样提问：

```text
用 IPX MCP 检查 portable 包能不能发客户。
```

```text
用 IPX MCP 检查最近工程图统计明细里中心线有没有重复。
```

## 安全边界

这是开发版 MCP Server，可以执行构建、打包脚本，读取发布产物和统计日志。

它不会开放：

- 任意 shell 命令执行
- 破坏性文件操作
- 注册表修改
- 终止 SolidWorks 进程
- 任意源码修改

不要把这个开发版 MCP Server 直接发给客户。
