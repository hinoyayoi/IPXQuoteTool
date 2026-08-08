#!/usr/bin/env node
import { Server } from "@modelcontextprotocol/sdk/server/index.js";
import { CallToolRequestSchema, ListToolsRequestSchema } from "@modelcontextprotocol/sdk/types.js";
import { execFile } from "node:child_process";
import { existsSync } from "node:fs";
import { readdir, readFile, stat } from "node:fs/promises";
import os from "node:os";
import path from "node:path";
import { fileURLToPath } from "node:url";

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const projectRoot = findProjectRoot(path.resolve(__dirname, "../../.."));
const appDataLogDir = path.join(os.homedir(), "AppData", "Roaming", "IPXQuoteTool");

export function createIpxMcpServer() {
  const server = new Server(
  {
    name: "ipxquote-dev-mcp",
    version: "0.1.0"
  },
  {
    capabilities: {
      tools: {}
    }
  }
  );

  server.setRequestHandler(ListToolsRequestSchema, async () => ({
    tools: [
    {
      name: "ipx.project_summary",
      description: "Return key IPXQuoteTool project paths and development MCP status.",
      inputSchema: emptySchema()
    },
    {
      name: "ipx.build",
      description: "Run dotnet build for IPXQuoteTool.csproj and return the build output.",
      inputSchema: {
        type: "object",
        properties: {
          configuration: {
            type: "string",
            enum: ["Debug", "Release"],
            default: "Debug"
          }
        },
        additionalProperties: false
      }
    },
    {
      name: "ipx.publish_portable",
      description: "Run publish-portable.ps1 and then summarize the generated portable package.",
      inputSchema: {
        type: "object",
        properties: {
          selfContained: {
            type: "boolean",
            default: false
          }
        },
        additionalProperties: false
      }
    },
    {
      name: "ipx.inspect_portable_zip",
      description: "Inspect IPXQuoteTool_Portable.zip for required release files and runtime installer.",
      inputSchema: {
        type: "object",
        properties: {
          zipPath: {
            type: "string",
            description: "Optional zip path. Defaults to artifacts/publish/IPXQuoteTool_Portable.zip."
          }
        },
        additionalProperties: false
      }
    },
    {
      name: "ipx.check_object_coefficients",
      description: "Check code and template defaults for unit price and complexity coefficients.",
      inputSchema: emptySchema()
    },
    {
      name: "ipx.read_recent_trace",
      description: "Read the latest IPX analysis trace log from %APPDATA%/IPXQuoteTool.",
      inputSchema: {
        type: "object",
        properties: {
          documentType: {
            type: "string",
            description: "Optional Chinese document type filter, for example 工程图, 装配, 零件."
          },
          lines: {
            type: "integer",
            minimum: 1,
            maximum: 1000,
            default: 200
          }
        },
        additionalProperties: false
      }
    },
    {
      name: "ipx.check_duplicate_metrics",
      description: "Check the latest analysis trace for duplicate metric entries grouped by object type and object name.",
      inputSchema: {
        type: "object",
        properties: {
          documentType: {
            type: "string",
            default: "工程图"
          },
          objectTypeContains: {
            type: "string",
            description: "Optional filter such as 中心, 表格, 普通注释."
          }
        },
        additionalProperties: false
      }
    }
    ]
  }));

  server.setRequestHandler(CallToolRequestSchema, async (request) => {
    const name = request.params.name;
    const args = request.params.arguments ?? {};

    switch (name) {
      case "ipx.project_summary":
        return textResult(await projectSummary());
      case "ipx.build":
        return textResult(await buildProject(args));
      case "ipx.publish_portable":
        return textResult(await publishPortable(args));
      case "ipx.inspect_portable_zip":
        return textResult(await inspectPortableZip(args));
      case "ipx.check_object_coefficients":
        return textResult(await checkObjectCoefficients());
      case "ipx.read_recent_trace":
        return textResult(await readRecentTrace(args));
      case "ipx.check_duplicate_metrics":
        return textResult(await checkDuplicateMetrics(args));
      default:
        throw new Error(`Unknown tool: ${name}`);
    }
  });

  return server;
}

if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) {
  const { StdioServerTransport } = await import("@modelcontextprotocol/sdk/server/stdio.js");
  await createIpxMcpServer().connect(new StdioServerTransport());
}

function emptySchema() {
  return {
    type: "object",
    properties: {},
    additionalProperties: false
  };
}

function textResult(value) {
  return {
    content: [
      {
        type: "text",
        text: JSON.stringify(value, null, 2)
      }
    ]
  };
}

function findProjectRoot(startDir) {
  let current = startDir;
  while (true) {
    if (existsSync(path.join(current, "IPXQuoteTool.csproj"))) {
      return current;
    }

    const parent = path.dirname(current);
    if (parent === current) {
      throw new Error("Could not locate IPXQuoteTool.csproj.");
    }

    current = parent;
  }
}

async function projectSummary() {
  return {
    ok: true,
    projectRoot,
    projectFile: path.join(projectRoot, "IPXQuoteTool.csproj"),
    publishScript: path.join(projectRoot, "publish-portable.ps1"),
    portableZip: path.join(projectRoot, "artifacts", "publish", "IPXQuoteTool_Portable.zip"),
    appDataLogDir,
    tools: [
      "ipx.build",
      "ipx.publish_portable",
      "ipx.inspect_portable_zip",
      "ipx.check_object_coefficients",
      "ipx.read_recent_trace",
      "ipx.check_duplicate_metrics"
    ]
  };
}

async function buildProject(args) {
  const configuration = args.configuration === "Release" ? "Release" : "Debug";
  const result = await execFileText(
    "dotnet",
    ["build", "IPXQuoteTool.csproj", "-c", configuration],
    projectRoot,
    120000
  );

  return {
    ok: result.exitCode === 0,
    command: `dotnet build IPXQuoteTool.csproj -c ${configuration}`,
    exitCode: result.exitCode,
    stdout: result.stdout,
    stderr: result.stderr
  };
}

async function publishPortable(args) {
  const psArgs = ["-NoProfile", "-ExecutionPolicy", "Bypass", "-File", ".\\publish-portable.ps1"];
  if (args.selfContained === true) {
    psArgs.push("-SelfContained");
  }

  const result = await execFileText("powershell", psArgs, projectRoot, 180000);
  const inspection = await inspectPortableZip({});

  return {
    ok: result.exitCode === 0 && inspection.ok,
    command: `powershell ${psArgs.join(" ")}`,
    exitCode: result.exitCode,
    stdout: result.stdout,
    stderr: result.stderr,
    inspection
  };
}

async function inspectPortableZip(args) {
  const zipPath = path.resolve(projectRoot, args.zipPath || path.join("artifacts", "publish", "IPXQuoteTool_Portable.zip"));
  if (!existsSync(zipPath)) {
    return {
      ok: false,
      zipPath,
      missing: ["IPXQuoteTool_Portable.zip"],
      message: "Portable zip was not found."
    };
  }

  const entries = await listZipEntries(zipPath);
  const normalized = new Set(entries.map((entry) => entry.replaceAll("\\", "/")));
  const required = [
    "IPXQuoteTool_Portable/IPXQuoteTool.exe",
    "IPXQuoteTool_Portable/启动费用估算.cmd",
    "IPXQuoteTool_Portable/Start-IPXQuoteTool.ps1",
    "IPXQuoteTool_Portable/对象系数.xlsx",
    "IPXQuoteTool_Portable/免安装使用说明.txt",
    "IPXQuoteTool_Portable/build-info.txt"
  ];
  const runtimeInstaller = "IPXQuoteTool_Portable/runtime/windowsdesktop-runtime-10.0.10-win-x64.exe";
  const missing = required.filter((entry) => !normalized.has(entry));
  const hasRuntimeInstaller = normalized.has(runtimeInstaller);
  const info = await stat(zipPath);

  return {
    ok: missing.length === 0,
    zipPath,
    sizeMb: round(info.size / 1024 / 1024, 2),
    required,
    missing,
    hasRuntimeInstaller,
    runtimeInstaller,
    entryCount: entries.length,
    message: missing.length === 0
      ? "Portable zip contains the required files."
      : "Portable zip is missing required files."
  };
}

async function checkObjectCoefficients() {
  const files = {
    quotePricingSettings: path.join(projectRoot, "src", "Pricing", "QuotePricingSettings.cs"),
    objectCoefficientSettings: path.join(projectRoot, "src", "Pricing", "ObjectCoefficientSettings.cs"),
    quotePriceResult: path.join(projectRoot, "src", "Pricing", "QuotePriceResult.cs"),
    defaultQuotePricingRule: path.join(projectRoot, "src", "Pricing", "DefaultQuotePricingRule.cs"),
    template: path.join(projectRoot, "resources", "Templates", "对象系数.xlsx")
  };

  const codeChecks = {};
  for (const [key, file] of Object.entries(files)) {
    if (key === "template") {
      continue;
    }

    const text = await readFile(file, "utf8");
    codeChecks[key] = {
      file,
      containsUnitPrice3: text.includes("3.0") || text.includes("3.00"),
      containsOldUnitPrice032: text.includes("0.32")
    };
  }

  const templateValues = await readCoefficientTemplateValues(files.template);
  const expected = {
    B15: "3.0",
    C19: "1.0",
    C20: "1.0",
    C21: "1.0",
    C22: "1.0"
  };
  const mismatches = Object.entries(expected)
    .filter(([cell, value]) => normalizeNumberText(templateValues[cell]) !== normalizeNumberText(value))
    .map(([cell, value]) => ({ cell, expected: value, actual: templateValues[cell] ?? null }));

  return {
    ok: mismatches.length === 0 && Object.values(codeChecks).every((check) => check.containsUnitPrice3 && !check.containsOldUnitPrice032),
    expected,
    template: {
      file: files.template,
      values: templateValues,
      mismatches
    },
    codeChecks
  };
}

async function readRecentTrace(args) {
  const lines = clampInteger(args.lines, 200, 1, 1000);
  const latest = await findLatestTraceFile(args.documentType);
  if (!latest) {
    return {
      ok: false,
      logDir: appDataLogDir,
      message: "No analysis trace log was found."
    };
  }

  const text = await readFile(latest.fullPath, "utf8");
  const allLines = text.split(/\r?\n/).filter(Boolean);

  return {
    ok: true,
    file: latest.fullPath,
    lineCount: allLines.length,
    returnedLines: Math.min(lines, allLines.length),
    tail: allLines.slice(-lines)
  };
}

async function checkDuplicateMetrics(args) {
  const latest = await findLatestTraceFile(args.documentType || "工程图");
  if (!latest) {
    return {
      ok: false,
      logDir: appDataLogDir,
      message: "No analysis trace log was found."
    };
  }

  const filter = (args.objectTypeContains || "").trim();
  const text = await readFile(latest.fullPath, "utf8");
  const entries = text.split(/\r?\n/)
    .filter(Boolean)
    .map(parseTraceLine)
    .filter((entry) => entry.objectType && entry.objectName)
    .filter((entry) => !filter || entry.objectType.includes(filter) || entry.objectName.includes(filter));

  const groups = new Map();
  for (const entry of entries) {
    const key = `${entry.objectType}\t${entry.objectName}`;
    const group = groups.get(key) || {
      objectType: entry.objectType,
      objectName: entry.objectName,
      count: 0,
      sources: new Set(),
      examples: []
    };
    group.count += 1;
    if (entry.detail) {
      group.sources.add(entry.detail);
    }
    if (group.examples.length < 5) {
      group.examples.push(entry);
    }
    groups.set(key, group);
  }

  const duplicateGroups = [...groups.values()]
    .filter((group) => group.count > 1)
    .map((group) => ({
      objectType: group.objectType,
      objectName: group.objectName,
      count: group.count,
      sources: [...group.sources],
      examples: group.examples
    }));

  return {
    ok: duplicateGroups.length === 0,
    file: latest.fullPath,
    filter,
    totalEntries: entries.length,
    uniqueEntries: groups.size,
    duplicateGroupCount: duplicateGroups.length,
    duplicateGroups,
    summary: duplicateGroups.length === 0
      ? "No duplicate metric entries were found for the selected filter."
      : `Found ${duplicateGroups.length} duplicate metric group(s).`
  };
}

function parseTraceLine(line) {
  const parts = line.split("\t");
  return {
    time: parts[0] || "",
    documentPath: parts[1] || "",
    objectType: parts[2] || "",
    objectName: parts[3] || "",
    detail: parts[4] || "",
    raw: line
  };
}

async function findLatestTraceFile(documentType) {
  if (!existsSync(appDataLogDir)) {
    return null;
  }

  const names = await readdir(appDataLogDir);
  const typeFilter = (documentType || "").trim();
  let candidates = await getTraceCandidates(names, typeFilter);
  if (candidates.length === 0 && typeFilter) {
    candidates = await getTraceCandidates(names, "");
  }

  candidates.sort((a, b) => b.mtimeMs - a.mtimeMs);
  return candidates[0] || null;
}

async function getTraceCandidates(names, typeFilter) {
  const candidates = [];

  for (const name of names) {
    if (!name.endsWith(".txt") || !isTraceFileName(name)) {
      continue;
    }

    if (typeFilter && !name.includes(typeFilter)) {
      continue;
    }

    const fullPath = path.join(appDataLogDir, name);
    const info = await stat(fullPath);
    candidates.push({ name, fullPath, mtimeMs: info.mtimeMs });
  }

  return candidates;
}

function isTraceFileName(name) {
  return name.includes("统计明细") ||
    name.includes("明细") ||
    name.includes("鏄庣粏");
}

async function listZipEntries(zipPath) {
  const script = `
Add-Type -AssemblyName System.IO.Compression.FileSystem
$zip = [System.IO.Compression.ZipFile]::OpenRead(${psString(zipPath)})
try {
  $zip.Entries | ForEach-Object { $_.FullName }
}
finally {
  $zip.Dispose()
}
`;
  const result = await execFileText("powershell", ["-NoProfile", "-ExecutionPolicy", "Bypass", "-Command", script], projectRoot, 30000);
  if (result.exitCode !== 0) {
    throw new Error(result.stderr || result.stdout || "Failed to list zip entries.");
  }

  return result.stdout.split(/\r?\n/).map((line) => line.trim()).filter(Boolean);
}

async function readCoefficientTemplateValues(filePath) {
  if (!existsSync(filePath)) {
    return {};
  }

  const cells = ["B15", "C19", "C20", "C21", "C22"];
  const script = `
Add-Type -AssemblyName System.IO.Compression.FileSystem
$zip = [System.IO.Compression.ZipFile]::OpenRead(${psString(filePath)})
try {
  $entry = $zip.GetEntry("xl/worksheets/sheet1.xml")
  if ($null -eq $entry) { exit 2 }
  $reader = [System.IO.StreamReader]::new($entry.Open())
  try { $xml = $reader.ReadToEnd() } finally { $reader.Dispose() }
  foreach ($cell in @(${cells.map(psString).join(", ")})) {
    $pattern = '<c\\s+r="' + [regex]::Escape($cell) + '"[^>]*>\\s*<v>(.*?)</v>\\s*</c>'
    $match = [regex]::Match($xml, $pattern)
    if ($match.Success) {
      "$cell=$($match.Groups[1].Value)"
    }
    else {
      "$cell="
    }
  }
}
finally {
  $zip.Dispose()
}
`;

  const result = await execFileText("powershell", ["-NoProfile", "-ExecutionPolicy", "Bypass", "-Command", script], projectRoot, 30000);
  if (result.exitCode !== 0) {
    return {};
  }

  const values = {};
  for (const line of result.stdout.split(/\r?\n/).filter(Boolean)) {
    const index = line.indexOf("=");
    if (index > 0) {
      values[line.slice(0, index)] = line.slice(index + 1);
    }
  }

  return values;
}

function execFileText(command, args, cwd, timeout) {
  return new Promise((resolve) => {
    execFile(
      command,
      args,
      {
        cwd,
        timeout,
        windowsHide: true,
        maxBuffer: 10 * 1024 * 1024,
        encoding: "utf8"
      },
      (error, stdout, stderr) => {
        resolve({
          exitCode: error ? (typeof error.code === "number" ? error.code : 1) : 0,
          stdout: stdout || "",
          stderr: stderr || (error && !error.code ? error.message : "")
        });
      }
    );
  });
}

function psString(value) {
  return `'${String(value).replaceAll("'", "''")}'`;
}

function clampInteger(value, fallback, min, max) {
  const parsed = Number.parseInt(value, 10);
  if (!Number.isFinite(parsed)) {
    return fallback;
  }

  return Math.min(max, Math.max(min, parsed));
}

function normalizeNumberText(value) {
  const parsed = Number.parseFloat(value);
  return Number.isFinite(parsed) ? parsed.toFixed(4) : String(value ?? "").trim();
}

function round(value, digits) {
  const factor = 10 ** digits;
  return Math.round(value * factor) / factor;
}
