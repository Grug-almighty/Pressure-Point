# Changelog

## v0.38 ALPHA — 2026-02-07
- Added Electron desktop scaffolding with auto-updates via GitHub releases.

## v0.37 ALPHA — 2026-02-07
- Minigun now overheats, has 200 ammo, and costs 1000 (red-tier only).

## v0.36 ALPHA — 2026-02-07
- Added on-screen Pause button (top-right) alongside the P key.

## v0.35 ALPHA — 2026-02-07
- Added wave-complete watchdog to avoid freezes when a wave finishes.

## v0.34 ALPHA — 2026-02-07
- Ensured trees spawn each wave with a safety check.
- Disabled player movement during Shop and Level-Up screens.

## v0.33 ALPHA — 2026-02-07
- Added destructible Trees that spawn each wave and drop healing Fruit.
- Added fruit pickups that heal on contact.

## v0.32 ALPHA — 2026-02-07
- Fixed shop lock/reroll glitches and reduced shop card text overlap.
- Added Harpoon weapon with pierce and a Piercing Bullet item.
- Added main menu settings for screen shake toggle and low-graphics mode.

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
