using System;
using System.Collections.Generic;
using System.Runtime.InteropServices.JavaScript;
using System.Text.Json;
using BrotatoLite.Design;

public partial class Program
{
  private static readonly ShopRoller _roller = new(
    weapons: new List<WeaponSpec>(), // populated from JS
    items: new List<ItemSpec>()      // populated from JS
  );

  [JSExport]
  public static string Echo(string msg) => $"BrotatoSystems: {msg}";

  [JSExport]
  public static void LoadData(string weaponsJson, string itemsJson)
  {
    if(!string.IsNullOrWhiteSpace(weaponsJson))
    {
      var weapons = JsonSerializer.Deserialize<List<WeaponSpec>>(weaponsJson);
      _weaponCache = weapons ?? new();
    }
    if(!string.IsNullOrWhiteSpace(itemsJson))
    {
      var items = JsonSerializer.Deserialize<List<ItemSpec>>(itemsJson);
      _itemCache = items ?? new();
    }
  }

  [JSExport]
  public static string RollShop(int count, int luck)
  {
    var roller = new ShopRoller(_weaponCache, _itemCache);
    var picks = roller.Roll(count, luck);
    return JsonSerializer.Serialize(picks);
  }

  [JSExport]
  public static string SerializeRun(string runJson)
  {
    // Pass-through validation
    var save = JsonSerializer.Deserialize<RunSave>(runJson);
    return JsonSerializer.Serialize(save, new JsonSerializerOptions{ WriteIndented = false });
  }

  [JSExport]
  public static string StatusTick(float dt, string effectsJson)
  {
    var effects = JsonSerializer.Deserialize<List<StatusEffect>>(effectsJson) ?? new();
    var sys = new StatusSystem();
    foreach(var e in effects) sys.Apply(e);
    var result = sys.Tick(dt);
    return JsonSerializer.Serialize(new { result.damage, result.slowMult, result.chain });
  }

  private static List<WeaponSpec> _weaponCache = new();
  private static List<ItemSpec> _itemCache = new();

  public static void Main() { }
}
