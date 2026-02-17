# WASM Bridge for C# Systems

This project ships a stub loader (`wasm/systems.stub.js`) so the game keeps running without the WASM binary. A prebuilt WASM bundle now lives in `wasm/dist/_framework` (built with .NET 8). To rebuild or update the C# systems from `Extra.cs`, follow the steps below.

## Build (requires .NET 8 SDK)
```bash
# 1) Install .NET 8 SDK (skip if already installed)
# Linux: https://learn.microsoft.com/dotnet/core/install/linux

cd wasm
dotnet new console -n BrotatoSystems
cd BrotatoSystems

# 2) Replace generated Program.cs with the interop implementation (copy ../templates/Program.cs)
# 3) Add Extra.cs from project root:
cp ../../Extra.cs .

# 4) Update the csproj to target WASM AOT (sample below)
cat > BrotatoSystems.csproj <<'EOF'
<Project Sdk="Microsoft.NET.Sdk">
  <PropertyGroup>
    <TargetFramework>net8.0</TargetFramework>
    <RuntimeIdentifier>browser-wasm</RuntimeIdentifier>
    <PublishAot>true</PublishAot>
    <InvariantGlobalization>true</InvariantGlobalization>
    <WasmNativeRelocatable>false</WasmNativeRelocatable>
  </PropertyGroup>
  <ItemGroup>
    <PackageReference Include="Microsoft.NET.Sdk.WebAssembly" Version="8.0.0" />
  </ItemGroup>
</Project>
EOF

# 5) Publish
dotnet publish -c Release
```

The build output lives under `bin/Release/net8.0/publish/wwwroot/_framework/`. Copy that folder into `wasm/dist/_framework/` (already done). The module loader `wasm/systems.loader.js` reads `blazor.boot.json` from that location.

## Wire into the page
- `Index.html` already loads `wasm/systems.stub.js`. Replace it with `systems.loader.js` after you drop the compiled assets:
```html
<script src="wasm/systems.loader.js"></script>
```
- Ensure the loader sets `window.SystemsWasm` with functions:
  - `ready: Promise`
  - `rollShop(count, luck)` → array of shop entries
  - `serializeRun(runState)` / `deserializeRun(json)`
  - `statusTick(dt, statusState)`

## Notes
- If the WASM fails to load, the stub keeps the game running with JS fallbacks.
- Keep payload small: prefer AOT release build to reduce runtime overhead.
