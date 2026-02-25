# Brotato-lite (Expanded) — v0.56 ALPHA

A polished, local Brotato-inspired top-down arena shooter built with HTML5 Canvas and JavaScript.

## Latest Update (v0.56)
- Weapon HUD now shows all weapons in inventory.
- Added optional Debug HUD (FPS + entity counts).
- Enlarged player character sprite again.
- Enlarged trees (bigger hitbox + more HP).
- Swapped UI to a deep teal/blue neon scheme for menus and settings.
- Integrated new weapon sprite models (`Shotgun`, `Pulse Rifle`, `RPG`, `Titan Cannon`, `Minigun`).
- Auto-target now falls back to trees when no enemies are present.
- Optimized runtime loops by removing repeated alive-player allocations and caching shop weapon previews.

## What’s Included
- **Wave system**: Wave 1 → Wave 20 with scaling enemy counts and difficulty.
- **Boss at Wave 20**: A large Overlord boss spawns on the final wave.
- **Danger levels (1–5)** with unlocks stored in `localStorage`.
- **Co-op**: Two local players with independent weapons, XP, money, and HUD.
- **Shop + Reroll + Lock**: Reroll for increasing cost, lock cards to keep them for the next wave.
- **Items + Rarity + Combining**: 6 item slots, combine two of same item + rarity into next tier.
- **Level-up selector**: Pick one stat upgrade at the end of each wave.
- **Elemental status effects**: Fire burn, Ice slow, Shock chain.
- **Polished UI**: stats panel, split-shop in co-op, end-of-run summary.
- **Background music**: light ambient loop (WebAudio).

## How To Run
1. Open `Index.html` in your browser.
2. Choose **Danger** and **Class**, then click **Start Game**.

Recommended: modern Chromium-based browser for best audio/visual support.

## Controls

Player 1:
- Move: `WASD`
- Switch weapons: `Q` / `E` or `1–5`

Player 2 (co-op):
- Move: Arrow keys

Shop:
- Click card to buy
- Right-click card to **lock**
- Press `Tab` to toggle **Stats**
- Click **Reroll** to refresh shop

## Wave System
- Wave 1 starts at **10 enemies**.
- Each wave adds **+5 enemies**.
- Difficulty scales per wave and per Danger level.
- **Wave 20 = Boss Wave** (Overlord).

## Danger Levels
- 1 → 5 (only 1 unlocked initially)
- Completing Wave 20 unlocks next Danger
- Higher Danger boosts spawn count, HP, damage, XP, money

## Items, Rarity & Combining
- Rarity: **Common → Rare → Epic → Legendary**
- Items scale in power by rarity
- **2 identical items of the same rarity combine** into the next tier
- **Max 6 items** per player

## Elemental Effects
- **Fire**: burn damage over time
- **Ice**: slows enemies
- **Shock**: chains to a nearby enemy
- **Explosive** weapons count as Fire

## End-of-Run Screen
Shows:
- Class and stats
- Weapons owned
- Items owned (with rarity)

## Files
- `Index.html` — entry page and UI
- `game.js` — all gameplay logic
- `style.css` — UI styling

---
If you want more enemies, a better boss pattern, or more weapons, just say the word.
