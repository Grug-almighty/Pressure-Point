// Brotato-lite Advanced Systems Sketch (C#)
// This file outlines complex systems to port the JS prototype into Unity/Godot.
// It is self-contained and focuses on data design + algorithmic steps, not engine glue.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.Json;

namespace BrotatoLite.Design
{
  public enum DamageType { Physical, Fire, Ice, Shock, Explosive }
  public enum Rarity { Common, Rare, Epic, Legendary }

  public record EnemyArchetype(
    string Id,
    string Name,
    float Radius,
    float BaseHp,
    float Speed,
    float Damage,
    DamageType[] Resistances = null);

  public record StatusEffect(string Id, DamageType Type, float Duration, float TickDamage, float SlowMult = 1f, float ChainRange = 0f);

  public record WeaponSpec(
    string Id,
    string Name,
    DamageType Type,
    float Damage,
    float FireDelay,
    float Spread,
    int Magazine,
    float Reload,
    bool Explosive = false,
    bool Melee = false,
    string AltMode = null, // e.g., "charged", "burst"
    Rarity Rarity = Rarity.Common,
    int BasePrice = 100
  );

  public record ItemSpec(string Id, string Name, Rarity Rarity, string Description, Dictionary<string, float> StatMods);

  public record WaveSegment(
    int Wave,
    string EnemyId,
    int Count,
    float SpawnInterval,
    float Delay = 0f,
    bool GateNextOnClear = false);

  public class WavePattern
  {
    public List<WaveSegment> Segments { get; } = new();

    public IEnumerable<WaveSegment> ForWave(int wave) =>
      Segments.Where(s => s.Wave == wave).OrderBy(s => s.Delay);
  }

  public class StatusSystem
  {
    public class ActiveStatus
    {
      public StatusEffect Effect;
      public float TimeLeft;
      public float Accumulated;
    }

    private readonly Dictionary<string, ActiveStatus> _active = new();

    public void Apply(StatusEffect effect)
    {
      if(_active.TryGetValue(effect.Id, out var current))
      {
        current.TimeLeft = Math.Max(current.TimeLeft, effect.Duration);
        current.Effect = effect;
      }
      else
      {
        _active[effect.Id] = new ActiveStatus { Effect = effect, TimeLeft = effect.Duration };
      }
    }

    // Tick returns (damage, slowMult, shouldChain)
    public (float damage, float slowMult, bool chain) Tick(float dt)
    {
      float dmg = 0f;
      float slow = 1f;
      bool chain = false;

      foreach(var key in _active.Keys.ToList())
      {
        var st = _active[key];
        st.TimeLeft -= dt;
        st.Accumulated += dt;
        if(st.Accumulated >= 1f) // 1s ticks
        {
          st.Accumulated = 0f;
          dmg += st.Effect.TickDamage;
        }
        slow = Math.Min(slow, st.Effect.SlowMult);
        chain |= st.Effect.ChainRange > 0;
        if(st.TimeLeft <= 0) _active.Remove(key);
      }
      return (dmg, slow, chain);
    }
  }

  public record ShopEntry(string Type, object Data, Rarity Rarity, int Price);

  public class ShopRoller
  {
    private readonly Random _rng = new();
    private readonly IReadOnlyList<WeaponSpec> _weapons;
    private readonly IReadOnlyList<ItemSpec> _items;

    public ShopRoller(IReadOnlyList<WeaponSpec> weapons, IReadOnlyList<ItemSpec> items)
    {
      _weapons = weapons; _items = items;
    }

    public List<ShopEntry> Roll(int count, int luck)
    {
      var picks = new List<ShopEntry>();
      while(picks.Count < count)
      {
        var rarity = RollRarity(luck);
        var poolWeapons = _weapons.Where(w => (w.Rarity) == rarity).ToList();
        var poolItems   = _items.Where(i => i.Rarity == rarity).ToList();
        var choicePool = new List<(string type, object data)>();
        choicePool.AddRange(poolWeapons.Select(w => ("weapon", (object)w)));
        choicePool.AddRange(poolItems.Select(i => ("item", (object)i)));
        if(choicePool.Count == 0) continue;
        var pick = choicePool[_rng.Next(choicePool.Count)];
        float mult = rarity switch
        {
          Rarity.Common => 1f,
          Rarity.Rare => 1.25f,
          Rarity.Epic => 1.5f,
          Rarity.Legendary => 2f,
          _ => 1f
        };
        int price;
        if(pick.type == "weapon"){
          var w = (WeaponSpec)pick.data;
          price = (int)Math.Max(10, Math.Round(w.BasePrice * mult));
        } else {
          var it = (ItemSpec)pick.data;
          var baseVal = (it.StatMods != null && it.StatMods.Count > 0) ? it.StatMods.Values.Sum() : 40;
          price = (int)Math.Max(5, Math.Round(baseVal * mult));
        }
        picks.Add(new ShopEntry(pick.type, pick.data, rarity, price));
      }
      return picks;
    }

    private Rarity RollRarity(int luck)
    {
      // Simple weight model; adjust to match JS version.
      float c = 50 + luck * 4;
      float r = 35 + luck * 8;
      float e = 12 + luck * 6;
      float l = 3  + luck * 2;
      float total = c + r + e + l;
      float roll = (float)_rng.NextDouble() * total;
      if((roll -= c) <= 0) return Rarity.Common;
      if((roll -= r) <= 0) return Rarity.Rare;
      if((roll -= e) <= 0) return Rarity.Epic;
      return Rarity.Legendary;
    }

  }

  public record PlayerSnapshot(
    string ClassId,
    int Level,
    float Hp,
    float MaxHp,
    int Coins,
    List<string> Weapons,
    List<(string id, Rarity rarity)> Items);

  public record RunSave(int Wave, int Danger, PlayerSnapshot[] Players);

  public static class SaveSystem
  {
    public static string Serialize(RunSave save) =>
      JsonSerializer.Serialize(save, new JsonSerializerOptions{ WriteIndented = true });

    public static RunSave Deserialize(string json) =>
      JsonSerializer.Deserialize<RunSave>(json);
  }
}
