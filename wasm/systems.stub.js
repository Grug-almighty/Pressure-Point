// Stub WASM bridge for Brotato-lite.
// If a compiled WASM module is present, replace this object by setting window.SystemsWasm at load.
(function(){
  const stub = {
    ready: Promise.resolve(),
    isStub: true,
    rollShop(count, luck, fallback){
      // Use JS fallback generator if provided
      return typeof fallback === 'function' ? fallback() : null;
    },
    serializeRun(state){ return null; },
    deserializeRun(json){ return null; },
    statusTick(dt, statusState){ return null; }
  };
  window.SystemsWasm = window.SystemsWasm || stub;
})();
