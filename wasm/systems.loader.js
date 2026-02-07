// Auto-generated WASM loader for BrotatoSystems
// Loads dotnet WASM, then exposes JS-friendly APIs on window.SystemsWasm

;(async () => {
  const stub = window.SystemsWasm || {};
  // If opened via file:// or explicit opt-out, stay on stub to avoid CORS issues.
  if (location.protocol === 'file:' || window.DISABLE_WASM === true) {
    window.SystemsWasm = { ...stub, isStub: true, ready: Promise.resolve() };
    return;
  }

  const base = new URL('./dist/_framework/', import.meta.url);
  const bootUrl = new URL('blazor.boot.json', base);
  try {
    const { default: createDotnetRuntime } = await import(base + 'dotnet.js');
    const runtime = await createDotnetRuntime({
      configSrc: bootUrl.href,
      disableDotnet6Compatibility: true,
    });
    const exports = await runtime.getAssemblyExports('BrotatoSystems.dll');
    const mod = exports.Program;

    window.SystemsWasm = {
      ready: Promise.resolve(),
      rollShop: (count, luck, fallback) => {
        try{
          const res = mod.RollShop(count, luck);
          return JSON.parse(res);
        } catch(err){ console.warn('rollShop fallback', err); return typeof fallback==='function'?fallback():null; }
      },
      loadData: (weaponsJson, itemsJson) => { try{ mod.LoadData(weaponsJson, itemsJson); }catch(e){ console.warn('loadData failed', e); } },
      serializeRun: (json) => { try{ return mod.SerializeRun(json); }catch(e){ return null; } },
      statusTick: (dt, effectsJson) => { try{ return JSON.parse(mod.StatusTick(dt, effectsJson)); }catch(e){ return null; } },
    };
  } catch(err){
    console.warn('WASM loader failed, using stub', err);
    window.SystemsWasm = { ...stub, isStub:true, ready: Promise.resolve() };
  }
})();
