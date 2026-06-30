# Game Design Document (GDD)

## Core Concept
The Chromatic Hero is a 2D top-down Action RPG where the primary mechanic is **Color Affinity**. The world starts gray. As you progress, you restore color, but with it comes the threat of elemental immunities and beam attacks.

**The Golden Rule:** There are no stats-based damage numbers in the combat loop. Damage is binary based on affinity matching.
- **Correct Affinity:** Full Damage.
- **Wrong Affinity (Same):** Zero Damage or Heal the Enemy.
- **Wrong Affinity (Neutral):** Standard/Reduced Damage.

## The Chromatic Cycle
The universe follows a strict cycle:
> **Red** → **Green** → **Yellow** → **Blue** → **Red**

- **Red** beats **Green**
- **Green** beats **Yellow**
- **Yellow** beats **Blue**
- **Blue** beats **Red**

There is no "why" in physics; this is simply the Law of the world. If you attack a Green enemy with Red, they take massive damage. If you attack them with Green, they heal.

## Classes
Players choose one path at character creation. There is no hybrid build in the base game.

### The Warrior
- **Role:** Melee Tank / Physical DPS.
- **Mechanic:** Can physically block beams with a shield. High HP/Armor.
- **Weakness:** Useless against enemies immune to physical damage unless they switch affinity to gain an elemental buff.
- **Survival:** Relies on blocking and kiting.

### The Wizard
- **Role:** Ranged DPS / Support.
- **Mechanic:** Casts spells based on current affinity. High burst damage.
- **Weakness:** Fragile (Low HP). Cannot reflect beams without spending Mana (Chromatic Shield Spell).
- **Survival:** Relies on mana management and positioning.

## Combat Flow
1. **Observe:** Identify the enemy's color/affinity.
2. **Switch:** Change player affinity to the counter-color.
3. **Attack:** Deal maximum damage.
4. **Defend:** If a beam is incoming, ensure your current affinity is the opposite color to reflect it.

## Accessibility
To ensure the game is playable by everyone regardless of color vision:
- **Shape Icons:** Every affinity has a unique shape overlay (Triangle=Red, Circle=Blue, Square=Green, Diamond=Yellow).
- **Audio Cues:** Distinct sounds play when switching affinities or when an enemy changes color.

## Technical Notes
- **Rendering:** CPU-based (`softbuffer`) for pixel-art precision and fast iteration.
- **Scale:** Internal resolution is low (e.g., 320x240), scaled up to window size.
