# Changelog

# Changelog

# Changelog

## v0.31 ALPHA — 2026-02-07
- Compiled `Extra.cs` to WebAssembly with .NET 8; outputs placed in `wasm/dist/_framework`.
- Added `wasm/systems.loader.js` (module) and updated `Index.html` to load it; `game.js` now fetches `window.SystemsWasm` dynamically.
- Keeps JS fallback via stub if WASM fails to load.

## v0.32 ALPHA — 2026-02-07
- `wasm/systems.loader.js` skips WASM when running from `file://` or when `window.DISABLE_WASM` is set, so double-clicking `Index.html` works without localhost.
- Added inline SVG favicon to stop 404s for `/favicon.ico`.

## v0.30 ALPHA — 2026-02-07
- Added WASM bridge scaffolding: `wasm/systems.stub.js` loaded by `Index.html`, plus build instructions in `wasm/README.md` for compiling `Extra.cs` to WebAssembly.
- `game.js` now honors an injected `systems.rollShop` from WASM, while stubbing safely when missing.

## v0.29 ALPHA — 2026-02-07
- Added `Extra.cs` C# blueprint for advanced systems (wave patterns, status engine, shop roller, save schema) to aid future engine ports.
- Kept pause (P) and mute (M) UX; mute indicator stays on HUD.
- Retained impact polish (damage numbers, shake, dash trail/I-frames, low-HP pulse).

## v0.28 ALPHA — 2026-02-07
- Added pause toggle (P) with on-screen overlay; gameplay and spawns halt while paused.
- Added global audio mute toggle (M) with HUD indicator and persisted bgm gain handling.
- Added damage numbers, camera shake, dash trail/I-frames, low-HP pulse, and HUD dash meter.
- Visual polish for panels, shop fog, gradients, and impact feedback.

## v0.27 ALPHA — 2026-02-07
- Introduced dash ability, camera shake, floating damage numbers, and low-HP screen pulse.
- Enhanced shop/wave visuals and HUD gradients.

## v0.26 ALPHA — 2026-02-06
- Initial polished release: danger levels, co-op, shop with reroll/lock, items + combining, level-up selector, elemental effects, boss wave, and ambient BGM.
