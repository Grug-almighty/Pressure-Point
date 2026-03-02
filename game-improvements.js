// ===== GAME IMPROVEMENTS PATCH =====
// This file contains improvements for balance, bugs, UI/UX, and performance
// To be integrated into game.js

// ===== PERFORMANCE IMPROVEMENTS =====

// Performance monitoring system
const perfMonitor = {
  enabled: false,
  fps: 60,
  frameCount: 0,
  lastFpsUpdate: 0,
  frameTimes: [],
  avgFrameTime: 16.67,
  
  update(currentTime) {
    this.frameCount++;
    const elapsed = currentTime - this.lastFpsUpdate;
    
    if (elapsed >= 1000) {
      this.fps = Math.round((this.frameCount * 1000) / elapsed);
      this.frameCount = 0;
      this.lastFpsUpdate = currentTime;
    }
    
    // Track frame times for performance analysis
    if (this.frameTimes.length > 60) this.frameTimes.shift();
    this.frameTimes.push(performance.now());
    
    if (this.frameTimes.length >= 2) {
      const recent = this.frameTimes.slice(-10);
      this.avgFrameTime = (recent[recent.length-1] - recent[0]) / (recent.length - 1);
    }
  },
  
  draw(ctx, W, H) {
    if (!this.enabled) return;
    
    // FPS counter
    ctx.save();
    ctx.fillStyle = 'rgba(0, 0, 0, 0.7)';
    ctx.fillRect(W - 120, 10, 110, 70);
    ctx.fillStyle = this.fps >= 55 ? '#6ef2b1' : this.fps >= 30 ? '#ffaa00' : '#ff4444';
    ctx.font = 'bold 16px monospace';
    ctx.fillText(`FPS: ${this.fps}`, W - 110, 30);
    ctx.fillStyle = '#e8f1ff';
    ctx.font = '11px monospace';
    ctx.fillText(`Frame: ${this.avgFrameTime.toFixed(2)}ms`, W - 110, 48);
    ctx.fillText(`Bullets: ${bullets.length}`, W - 110, 64);
    ctx.restore();
  },
  
  toggle() {
    this.enabled = !this.enabled;
    console.log(`Performance monitor: ${this.enabled ? 'ON' : 'OFF'}`);
  }
};

// Object pooling for bullets and particles
const bulletPool = [];
const particlePool = [];

function getBullet() {
  const b = bulletPool.pop();
  if (b) {
    // Reset all properties
    Object.keys(b).forEach(k => delete b[k]);
    return b;
  }
  return {};
}

function returnBullet(b) {
  if (bulletPool.length < MAX_BULLETS * 2) {
    bulletPool.push(b);
  }
}

function getParticle() {
  const p = particlePool.pop();
  if (p) {
    Object.keys(p).forEach(k => delete p[k]);
    return p;
  }
  return {};
}

function returnParticle(p) {
  if (particlePool.length < MAX_PARTICLES * 2) {
    particlePool.push(p);
  }
}

// ===== BALANCE IMPROVEMENTS =====

// Improved shop reroll cost scaling (less punishing)
function calculateRerollCost(currentCost) {
  // Changed from 1.35x + 2 to 1.25x + 1 for better balance
  return Math.min(99, Math.floor(currentCost * 1.25 + 1));
}

// Better rarity distribution with luck scaling
function improvedRollRarity(luck) {
  const base = { common: 50, rare: 35, epic: 10, red: 5 };
  // Improved luck scaling - more noticeable but not overpowered
  const luckFactor = Math.min(luck * 0.8, 10); // Cap luck bonus
  const wCommon = Math.max(20, base.common - luckFactor * 3);
  const wRare = base.rare + luckFactor * 2;
  const wEpic = base.epic + luckFactor * 3;
  const wRed = base.red + luckFactor * 4;
  const total = wCommon + wRare + wEpic + wRed;
  
  let r = Math.random() * total;
  if ((r -= wCommon) <= 0) return 'common';
  if ((r -= wRare) <= 0) return 'rare';
  if ((r -= wEpic) <= 0) return 'epic';
  return 'red';
}

// Improved difficulty scaling
function getEnemyHealthMultiplier(wave, danger) {
  // More gradual scaling for better balance
  const waveScale = 1 + (wave - 1) * 0.08; // Was likely higher
  const dangerScale = 1 + (danger - 1) * 0.15;
  return waveScale * dangerScale;
}

function getEnemyDamageMultiplier(wave, danger) {
  // Damage scales slower than health for better balance
  const waveScale = 1 + (wave - 1) * 0.05;
  const dangerScale = 1 + (danger - 1) * 0.12;
  return waveScale * dangerScale;
}

// ===== UI/UX IMPROVEMENTS =====

// Keyboard shortcuts help overlay
const helpOverlay = {
  visible: false,
  
  toggle() {
    this.visible = !this.visible;
  },
  
  draw(ctx, W, H, palette) {
    if (!this.visible) return;
    
    // Semi-transparent background
    ctx.fillStyle = 'rgba(0, 0, 0, 0.85)';
    ctx.fillRect(0, 0, W, H);
    
    const panelW = Math.min(600, W * 0.9);
    const panelH = Math.min(500, H * 0.9);
    const px = (W - panelW) / 2;
    const py = (H - panelH) / 2;
    
    // Panel background
    ctx.fillStyle = palette.uiLight;
    ctx.strokeStyle = palette.outline;
    ctx.lineWidth = 3;
    roundRect(px, py, panelW, panelH, 14);
    ctx.fill();
    ctx.stroke();
    
    // Title
    ctx.fillStyle = palette.uiAccent;
    ctx.font = 'bold 24px "Trebuchet MS", system-ui, sans-serif';
    ctx.textAlign = 'center';
    ctx.fillText('KEYBOARD SHORTCUTS', W / 2, py + 40);
    
    // Shortcuts list
    ctx.textAlign = 'left';
    ctx.font = '14px "Trebuchet MS", system-ui, sans-serif';
    ctx.fillStyle = palette.text;
    
    const shortcuts = [
      { key: 'WASD', desc: 'Move Player 1' },
      { key: 'Arrow Keys', desc: 'Move Player 2 (Co-op)' },
      { key: 'Q / E', desc: 'Switch Weapons' },
      { key: '1-5', desc: 'Select Weapon Slot' },
      { key: 'Space', desc: 'Dash' },
      { key: 'Tab', desc: 'Toggle Stats (in shop)' },
      { key: 'Enter', desc: 'Start Wave / Confirm' },
      { key: 'P', desc: 'Pause / Resume' },
      { key: 'M', desc: 'Mute / Unmute Audio' },
      { key: 'F', desc: 'Toggle FPS Counter' },
      { key: 'H', desc: 'Toggle This Help' },
      { key: 'R', desc: 'Reroll Shop' },
    ];
    
    let y = py + 80;
    shortcuts.forEach(s => {
      ctx.fillStyle = palette.uiAccent;
      ctx.fillText(s.key, px + 40, y);
      ctx.fillStyle = palette.text;
      ctx.fillText(s.desc, px + 180, y);
      y += 28;
    });
    
    // Close instruction
    ctx.textAlign = 'center';
    ctx.fillStyle = palette.textLight;
    ctx.font = '12px "Trebuchet MS", system-ui, sans-serif';
    ctx.fillText('Press H or ESC to close', W / 2, py + panelH - 20);
    ctx.textAlign = 'left';
  }
};

// Enhanced damage numbers with better visibility
function createEnhancedFloatingText(x, y, text, color = '#fff', size = 14, duration = 1.2) {
  if (floatingTexts.length >= MAX_FLOATING_TEXTS) {
    floatingTexts.shift();
  }
  
  floatingTexts.push({
    x, y,
    text,
    color,
    size,
    life: duration,
    maxLife: duration,
    vx: (Math.random() - 0.5) * 30,
    vy: -60 - Math.random() * 20,
    // Add outline for better visibility
    outline: true,
    outlineColor: 'rgba(0, 0, 0, 0.8)'
  });
}

// Improved visual feedback for critical hits
function createCriticalHitEffect(x, y) {
  // Create burst of particles
  for (let i = 0; i < 8; i++) {
    const angle = (Math.PI * 2 * i) / 8;
    const speed = 80 + Math.random() * 40;
    createParticle(
      x, y,
      Math.cos(angle) * speed,
      Math.sin(angle) * speed,
      '#ffff00',
      0.6,
      8
    );
  }
  
  // Enhanced floating text
  createEnhancedFloatingText(x, y, 'CRIT!', '#ffff00', 20, 1.5);
}

// Better affordability indicators in shop
function drawAffordabilityIndicator(ctx, x, y, w, h, canAfford, palette) {
  if (canAfford) {
    // Glowing green effect
    ctx.save();
    ctx.shadowColor = 'rgba(110, 242, 177, 0.8)';
    ctx.shadowBlur = 12;
    ctx.strokeStyle = palette.uiGreen;
    ctx.lineWidth = 2;
    roundRect(x, y, w, h, 10);
    ctx.stroke();
    ctx.restore();
    
    // Pulsing effect
    const pulse = 0.7 + Math.sin(performance.now() / 300) * 0.3;
    ctx.globalAlpha = pulse;
    ctx.fillStyle = 'rgba(110, 242, 177, 0.1)';
    roundRect(x, y, w, h, 10);
    ctx.fill();
    ctx.globalAlpha = 1;
  } else {
    // Red tint for unaffordable
    ctx.fillStyle = 'rgba(255, 70, 70, 0.1)';
    roundRect(x, y, w, h, 10);
    ctx.fill();
  }
}

// ===== BUG FIXES =====

// Fixed dash cooldown synchronization
function updateDashCooldown(player, dt) {
  if (player.dashCooldown > 0) {
    player.dashCooldown = Math.max(0, player.dashCooldown - dt);
  }
}

// Improved collision detection with bounds checking
function safeCollisionCheck(x1, y1, r1, x2, y2, r2) {
  // Add bounds checking to prevent NaN issues
  if (!isFinite(x1) || !isFinite(y1) || !isFinite(x2) || !isFinite(y2)) {
    return false;
  }
  
  const dx = x2 - x1;
  const dy = y2 - y1;
  const dist = Math.sqrt(dx * dx + dy * dy);
  return dist < (r1 + r2);
}

// Better error handling for asset loading
function safeLoadImage(src, fallback = null) {
  const img = new Image();
  img.onerror = () => {
    console.warn(`Failed to load image: ${src}`);
    if (fallback) img.src = fallback;
  };
  img.src = src;
  return img;
}

// Fixed memory leak in particle system
function cleanupParticles(particles) {
  // Remove dead particles and return to pool
  for (let i = particles.length - 1; i >= 0; i--) {
    if (particles[i].life <= 0) {
      returnParticle(particles[i]);
      particles.splice(i, 1);
    }
  }
}

// ===== INTEGRATION HELPERS =====

// Call this in the main update loop
function updatePerformanceMonitor(currentTime) {
  perfMonitor.update(currentTime);
}

// Call this in the main draw loop
function drawPerformanceMonitor(ctx, W, H) {
  perfMonitor.draw(ctx, W, H);
}

// Call this in the main draw loop
function drawHelpOverlay(ctx, W, H, palette) {
  helpOverlay.draw(ctx, W, H, palette);
}

// Export for integration
if (typeof module !== 'undefined' && module.exports) {
  module.exports = {
    perfMonitor,
    helpOverlay,
    getBullet,
    returnBullet,
    getParticle,
    returnParticle,
    calculateRerollCost,
    improvedRollRarity,
    getEnemyHealthMultiplier,
    getEnemyDamageMultiplier,
    createEnhancedFloatingText,
    createCriticalHitEffect,
    drawAffordabilityIndicator,
    updateDashCooldown,
    safeCollisionCheck,
    safeLoadImage,
    cleanupParticles,
    updatePerformanceMonitor,
    drawPerformanceMonitor,
    drawHelpOverlay
  };
}

