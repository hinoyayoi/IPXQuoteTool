#!/usr/bin/env node
import { randomUUID } from "node:crypto";
import os from "node:os";
import { createMcpExpressApp } from "@modelcontextprotocol/sdk/server/express.js";
import { StreamableHTTPServerTransport } from "@modelcontextprotocol/sdk/server/streamableHttp.js";
import { isInitializeRequest } from "@modelcontextprotocol/sdk/types.js";
import { createIpxMcpServer } from "./server.js";

const host = process.env.IPX_MCP_HOST || "127.0.0.1";
const port = Number.parseInt(process.env.IPX_MCP_PORT || "3001", 10);
const token = (process.env.IPX_MCP_TOKEN || "").trim();
const transports = new Map();

const app = createMcpExpressApp({ host });

app.get("/health", (_req, res) => {
  res.json({
    ok: true,
    name: "ipxquote-dev-mcp",
    mode: "streamable-http",
    host,
    port,
    tokenEnabled: token.length > 0,
    machine: os.hostname(),
    endpoint: "/mcp"
  });
});

app.all("/mcp", authorizeRequest, async (req, res) => {
  try {
    const sessionId = req.headers["mcp-session-id"];
    let transport = sessionId ? transports.get(sessionId) : undefined;

    if (!transport && req.method === "POST" && isInitializeRequest(req.body)) {
      transport = new StreamableHTTPServerTransport({
        sessionIdGenerator: () => randomUUID(),
        onsessioninitialized: (newSessionId) => {
          transports.set(newSessionId, transport);
        }
      });

      transport.onclose = () => {
        const closedSessionId = transport.sessionId;
        if (closedSessionId) {
          transports.delete(closedSessionId);
        }
      };

      await createIpxMcpServer().connect(transport);
    }

    if (!transport) {
      res.status(400).json({
        jsonrpc: "2.0",
        error: {
          code: -32000,
          message: "Bad Request: initialize first or provide a valid mcp-session-id."
        },
        id: null
      });
      return;
    }

    await transport.handleRequest(req, res, req.body);
  } catch (error) {
    console.error("Error handling IPX MCP HTTP request:", error);
    if (!res.headersSent) {
      res.status(500).json({
        jsonrpc: "2.0",
        error: {
          code: -32603,
          message: "Internal server error."
        },
        id: null
      });
    }
  }
});

const httpServer = app.listen(port, host, (error) => {
  if (error) {
    console.error("Failed to start IPX MCP HTTP server:", error);
    process.exit(1);
  }

  console.log(`IPX MCP HTTP server listening at http://${host}:${port}/mcp`);
  console.log(token ? "Authorization: Bearer token is required." : "Authorization: token is disabled.");
});

process.on("SIGINT", shutdown);
process.on("SIGTERM", shutdown);

function authorizeRequest(req, res, next) {
  if (!token) {
    next();
    return;
  }

  const auth = req.headers.authorization || "";
  const queryToken = typeof req.query.token === "string" ? req.query.token : "";
  if (auth === `Bearer ${token}` || queryToken === token) {
    next();
    return;
  }

  res.status(401).json({
    jsonrpc: "2.0",
    error: {
      code: -32001,
      message: "Unauthorized."
    },
    id: null
  });
}

async function shutdown() {
  for (const transport of transports.values()) {
    try {
      await transport.close();
    } catch {
      // Ignore shutdown cleanup errors.
    }
  }

  httpServer.close(() => process.exit(0));
}
