🗡️ The Chromatic Hero
"The world is gray until you give it color. Choose your Affinity. Master the Dance."
The Chromatic Hero is a 2D top-down Action RPG where combat, survival, and progression are dictated by Color. You don't just fight enemies; you must adapt to their elemental affinities, reflect their beams, and craft gear tailored to the chaotic reality of randomized dungeons.Built with Rust and designed for deep Single-Player engagement (with future Co-op in mind), this game challenges you to master the cycle of elements to restore a colorless world.🎨 Core MechanicsThe Chromatic Cycle
The world operates on a strict, intuitive law:
🔴 Red → 🟢 Green → 🟡 Yellow → 🔵 Blue → 🔴 Red

Weakness: Attacking with the Opposite element deals maximum damage.
Immunity: Attacking with the Same element deals 0 damage or heals the enemy.
Neutral: Unrelated elements deal standard damage.

There are no physics explanations. Red beats Green. That is the rule.
The Two Classes
Choose your path at the start. Your class defines your strengths, weaknesses, and how you interact with the world.
⚔️ The Warrior (Physical Anchor)

Role: Melee Tank & Physical DPS.
Strengths: High HP, Armor, and Block Chance. Can physically block beams.
Weakness: Deals 0 damage to Physical Immune enemies unless switching affinity to gain an elemental buff.
Playstyle: Stand your ground. Switch affinities to bypass immunities. Reflect beams with your shield.

🔮 The Wizard (Elemental Storm)

Role: Ranged DPS & Support.
Strengths: Massive elemental damage, range, and versatility. Can switch affinities instantly.
Weakness: Fragile (Low HP). Dealing 0 damage to Elementally Immune enemies without switching. Mana-dependent.
Playstyle: Kite enemies. Match your spells to enemy weaknesses. Cast Chromatic Shields to reflect beams (costs Mana).


🔨 Loot & Crafting: The Infinite Grind
Inspired by Diablo II and Path of Exile, the endgame is a chaotic dance of Randomized Affinity Dungeons and deep Custom Crafting.
🌪️ Randomized Dungeons
No two runs are the same. Every dungeon generates with random modifiers that dictate enemy behavior and loot drops:

Fire Storm: All enemies are Fire-aligned. They shoot Red beams. (Drop: Red Runes)
Triple Threat: Enemies spawn with mixed affinities (Red+Yellow+Blue), firing complex Purple/Orange/Cyan beams. (Drop: Rare Mixed Shards)
Immunity Zones: Physical damage is useless; only Elemental attacks work.
The Grind: Farm these zones to gather specific Chromatic Shards and Runes needed for your next build.

⚒️ Crafting vs. Drops
There are two paths to power, and both are viable:

The Hunter (Loot): Defeat bosses to find Named Unique Items with fixed, high-tier stats (e.g., "Void's Bane" dropped only by the Void Stalker).

Risk: You might get the item, but with stats you don't need.


The Artificer (Crafting): Farm raw materials in dungeons to craft your own perfect gear.

Base + Gems: Find a "Heavy Blade" base, then socket it with Perfect Yellow Gems specifically to counter Ice enemies in your current run.
Reforging: Spend resources to re-roll unwanted stats until you get the perfect +Crit / +Fire Dmg combination.
Benefit: Tailor your weapon exactly to the dungeon's modifiers. If the map is Green, craft a Red sword.



Why it matters: In most ARPGs, you hope luck gives you the right item. Here, you can force the universe to give you the weapon you need. Whether you rely on the RNG of a boss drop or the precision of the forge, the grind never ends.

🌍 Progression & World

Normal: Learn the Affinity Dance. Survive single-element immunities.
Nightmare: Survive Double Immunities and complex beam patterns.
Hell: Master Mixed Affinity maps, triple beams, and infinite crafting.
Endgame: Procedural maps with escalating difficulty, rare loot, and unique gear affixes.

Accessibility
To ensure the color-based mechanics are playable by everyone:

Visual Clarity: Players and enemies glow with their active affinity color.
Shape Icons: Every affinity has a unique shape (Triangle, Circle, Square, Diamond) overlayed on sprites for colorblind accessibility.
Audio Cues: Distinct sound effects accompany each affinity switch and beam type.


🛠️ Tech Stack

Language: Rust
Graphics: softbuffer (CPU rendering with custom tinting logic for retro pixel-art performance)
Architecture: Component-based design, modular for easy future expansion.


🚀 Getting Started
(Instructions to be added as development progresses)

Clone the repo.
Build with Cargo: cargo build --release
Run: cargo run
Choose your Class (Warrior or Wizard).
Restore the Color.


📜 Design Philosophy

No Free Lunch: Every class has a hard counter. Adaptation is key.
Crafting is King: Luck is fun; control is powerful. You can always craft the perfect tool.
Visual Clarity: Color tells the story. Shapes ensure no one is left behind.
Risk vs. Reward: Do you switch affinity to survive, or stay to deal damage?


Join the fight. Restore the Color. 🌈⚔️🔮
