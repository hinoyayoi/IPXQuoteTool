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

## 远程调用版

远程调用版用于组内开发协作：MCP Server 运行在你的电脑上，组员的 AI 客户端通过 URL 调用。所有读取日志、构建、打包、检查发布包等动作都发生在你的电脑上，不会自动操作组员自己的电脑。

完整配置和排障说明见：`远程MCP服务配置技术文档.md`。

### 你的电脑需要配置

1. 启动远程 MCP：

```powershell
cd <repo-root>\tools\mcp\dev
$env:IPX_MCP_HOST="0.0.0.0"
$env:IPX_MCP_PORT="3001"
$env:IPX_MCP_TOKEN="换成一段只有组内知道的口令"
npm.cmd run start:http
```

如果当前 PowerShell 里还不能直接识别 `npm.cmd`，可以用完整路径：

```powershell
& "C:\Program Files\nodejs\npm.cmd" run start:http
```

2. 打开 Windows 防火墙端口：

```powershell
New-NetFirewallRule -DisplayName "IPX Dev MCP 3001" -Direction Inbound -Action Allow -Protocol TCP -LocalPort 3001
```

3. 查看你的本机 IP：

```powershell
ipconfig
```

组员要访问的地址一般是：

```text
http://你的电脑IP:3001/mcp
```

健康检查地址是：

```text
http://你的电脑IP:3001/health
```

### 组员那边需要配置

如果组员使用的 AI 客户端支持远程 MCP URL，配置类似这样：

```json
{
  "mcpServers": {
    "ipx-dev-team": {
      "url": "http://你的电脑IP:3001/mcp",
      "headers": {
        "Authorization": "Bearer 换成同一段口令"
      }
    }
  }
}
```

如果客户端不支持配置请求头，可以把 token 临时放到 URL 上：

```json
{
  "mcpServers": {
    "ipx-dev-team": {
      "url": "http://你的电脑IP:3001/mcp?token=换成同一段口令"
    }
  }
}
```

远程版只建议在公司内网或受控网络里使用。不要把这个端口直接暴露到公网。

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
        "<repo-root>/tools/mcp/dev/server.js"
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
