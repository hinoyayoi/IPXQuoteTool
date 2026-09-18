# IPXQuoteTool 远程 MCP 服务配置技术文档

## 1. 文档目的

本文档用于说明 IPXQuoteTool 开发版 MCP Server 的远程调用配置方式。

当前方案适用于组内开发协作：MCP Server 运行在开发主机上，组员通过支持 MCP 的 AI 客户端访问该服务，从而查询项目状态、读取统计日志、检查重复统计、执行构建和检查打包产物。

需要注意：远程调用时，所有工具动作都发生在运行 MCP Server 的那台电脑上，不会自动操作组员自己的电脑。

## 2. 当前方案结构

```text
组员 AI 客户端
    |
    | HTTP MCP 请求
    v
开发主机:3001
    |
    | 调用 IPXQuoteTool 开发 MCP 工具
    v
项目源码 / 统计日志 / 打包脚本 / 发布产物
```

当前 MCP 服务提供两个入口：

- `server.js`
  - 本机 stdio MCP 入口。
  - 适合 Codex、Claude Desktop 等本机直接启动 MCP Server 的客户端。
- `http-server.js`
  - 远程 HTTP MCP 入口。
  - 适合组员通过 `http://开发主机IP:3001/mcp` 访问。

## 3. 服务端目录

MCP 服务位于：

```text
<repo-root>\tools\mcp\dev
```

主要文件：

- `package.json`
  - Node 项目配置。
  - 提供 `start` 和 `start:http` 脚本。
- `server.js`
  - MCP 工具定义和 stdio 启动入口。
- `http-server.js`
  - HTTP 远程调用入口。
- `README.md`
  - 简要使用说明。
- `远程MCP服务配置技术文档.md`
  - 本文档。

## 4. 服务端环境要求

开发主机需要安装：

- Node.js 20 LTS 或更高版本
- npm
- 本项目需要的 .NET SDK
- PowerShell

如果 PowerShell 无法直接识别 `npm`，可以使用：

```powershell
npm.cmd
```

或使用完整路径：

```powershell
& "C:\Program Files\nodejs\npm.cmd"
```

## 5. 安装依赖

首次使用时，在 MCP 目录执行：

```powershell
cd <repo-root>\tools\mcp\dev
npm.cmd install
```

如果已经存在 `node_modules` 且服务能正常启动，可以不用重复安装。

## 6. 启动远程 MCP 服务

在开发主机上执行：

```powershell
cd <repo-root>\tools\mcp\dev
$env:IPX_MCP_HOST="0.0.0.0"
$env:IPX_MCP_PORT="3001"
$env:IPX_MCP_TOKEN="换成一段组内口令"
npm.cmd run start:http
```

参数说明：

- `IPX_MCP_HOST`
  - 设置为 `0.0.0.0` 表示允许局域网其他电脑访问。
  - 如果只想本机访问，可以设置为 `127.0.0.1`。
- `IPX_MCP_PORT`
  - MCP 服务端口，当前推荐使用 `3001`。
- `IPX_MCP_TOKEN`
  - 远程调用鉴权口令。
  - 建议设置，不建议空着。

启动成功后，控制台会显示类似：

```text
IPX MCP HTTP server listening at http://0.0.0.0:3001/mcp
Authorization: Bearer token is required.
```

## 7. 防火墙配置

如果组员无法访问开发主机端口，需要在开发主机打开 Windows 防火墙入站规则：

```powershell
New-NetFirewallRule -DisplayName "IPX Dev MCP 3001" -Direction Inbound -Action Allow -Protocol TCP -LocalPort 3001
```

如果以后更换端口，需要同步修改防火墙规则端口。

## 8. 查看开发主机 IP

在开发主机执行：

```powershell
ipconfig
```

找到当前局域网网卡的 IPv4 地址，例如：

```text
192.168.19.249
```

则 MCP 服务地址为：

```text
http://192.168.19.249:3001/mcp
```

健康检查地址为：

```text
http://192.168.19.249:3001/health
```

## 9. 服务端健康检查

启动服务后，可以先在开发主机浏览器访问：

```text
http://192.168.19.249:3001/health
```

正常返回示例：

```json
{
  "ok": true,
  "name": "ipxquote-dev-mcp",
  "mode": "streamable-http",
  "host": "0.0.0.0",
  "port": 3001,
  "tokenEnabled": true,
  "endpoint": "/mcp"
}
```

如果返回 `Invalid Host`，通常表示 HTTP 服务没有按 `IPX_MCP_HOST=0.0.0.0` 启动，或者使用了旧版本 `http-server.js`。

## 10. 组员客户端配置

组员需要使用支持远程 MCP URL 的 AI 客户端。

配置示例：

```json
{
  "mcpServers": {
    "ipx-dev-team": {
      "url": "http://192.168.19.249:3001/mcp",
      "headers": {
        "Authorization": "Bearer 换成同一段组内口令"
      }
    }
  }
}
```

如果客户端不支持配置 `headers`，可以临时把 token 放在 URL 参数中：

```json
{
  "mcpServers": {
    "ipx-dev-team": {
      "url": "http://192.168.19.249:3001/mcp?token=换成同一段组内口令"
    }
  }
}
```

优先推荐使用 `Authorization: Bearer` 请求头。URL 参数方式更容易泄露 token，只建议内部临时调试使用。

## 11. 可调用能力

当前 MCP 工具包括：

- `ipx.project_summary`
  - 查看项目路径、日志路径、可用工具列表。
- `ipx.build`
  - 执行 `dotnet build IPXQuoteTool.csproj`。
- `ipx.publish_portable`
  - 执行 portable 打包脚本并检查打包结果。
- `ipx.inspect_portable_zip`
  - 检查 portable 压缩包内是否包含必要文件和 .NET Runtime 安装包。
- `ipx.check_object_coefficients`
  - 检查默认单价、复杂度系数在代码和模板中的配置。
- `ipx.read_recent_trace`
  - 读取最近一次统计明细日志。
- `ipx.check_duplicate_metrics`
  - 按对象类型和对象名称检查统计明细中的重复项。

组员可以向 AI 客户端提问：

```text
用 IPX MCP 看一下最近工程图中心线统计有没有重复。
```

```text
用 IPX MCP 检查 portable 包是否包含运行时安装包。
```

```text
用 IPX MCP 看一下当前项目默认单价和复杂度系数配置。
```

## 12. 停止 MCP 服务

如果服务是在 PowerShell 窗口中启动的，可以在该窗口按：

```text
Ctrl + C
```

也可以直接关闭该 PowerShell 窗口。

如果窗口找不到，可以查端口占用：

```powershell
netstat -ano | findstr :3001
```

找到最后一列 PID 后执行：

```powershell
taskkill /PID 进程ID /F
```

## 13. 安全边界

这是开发版 MCP，不建议直接对客户开放。

当前服务不提供：

- 任意 shell 命令执行
- 任意源码修改
- 破坏性文件删除
- 注册表修改
- 终止 SolidWorks 进程

但它可以：

- 读取项目路径信息
- 读取统计日志
- 执行构建
- 执行打包脚本
- 检查发布产物

因此建议：

- 只在公司内网或 VPN 内使用。
- 必须配置 `IPX_MCP_TOKEN`。
- 不要将端口直接暴露到公网。
- token 定期更换。
- 不使用时关闭服务。

## 14. 常见问题

### 14.1 返回 Invalid Host

表现：

```json
{
  "jsonrpc": "2.0",
  "error": {
    "code": -32000,
    "message": "Invalid Host: 192.168.19.249"
  },
  "id": null
}
```

处理：

确认启动前设置了：

```powershell
$env:IPX_MCP_HOST="0.0.0.0"
```

并确认当前代码中 `http-server.js` 使用：

```js
createMcpExpressApp({ host })
```

### 14.2 组员无法连接

检查顺序：

1. 开发主机服务是否正在运行。
2. 开发主机本机能否访问 `/health`。
3. 组员电脑能否 ping 通开发主机 IP。
4. Windows 防火墙是否放行端口 `3001`。
5. 组员配置的 URL 是否是 `http://开发主机IP:3001/mcp`。
6. token 是否一致。

### 14.3 返回 401 Unauthorized

说明 token 不正确或没有传 token。

检查客户端配置：

```json
"headers": {
  "Authorization": "Bearer 换成同一段组内口令"
}
```

### 14.4 npm 无法执行

如果提示 `npm` 无法识别，使用：

```powershell
npm.cmd install
npm.cmd run start:http
```

如果 PowerShell 提示禁止运行脚本，不要用 `npm`，改用：

```powershell
npm.cmd
```

### 14.5 服务启动后一直占用窗口

这是正常现象。

MCP HTTP 服务是一个常驻进程，PowerShell 窗口保持打开表示服务正在运行。关闭窗口或按 `Ctrl + C` 后，组员就无法继续调用该 MCP 服务。

## 15. 后续可扩展方向

后续可以继续扩展：

- 增加只读模式和可执行模式开关。
- 增加操作审计日志，记录谁调用了什么工具。
- 增加工具级权限，例如只允许组员读取日志，不允许执行打包。
- 打包成 exe，减少 Node.js 环境配置。
- 做一个内部 Web 管理页，用于启动状态、token 配置和调用记录查看。

