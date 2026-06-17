# The Chromatic Hero

A 2D top-down Action RPG written in Rust.

I'm building this to explore a specific mechanic: **combat that relies entirely on color affinity**. No complex stats, just matching colors to exploit weaknesses. If you attack with the wrong color, you do nothing—or worse, you heal the enemy.

Inspired by the grinding loop of *Diablo II* and the exploration of *Zelda*, but stripped down to a single core system.

## How It Works

### The Affinity Cycle
There are four colors: **Red**, **Green**, **Yellow**, and **Blue**. They follow a strict cycle:

- **Red** beats **Green**
- **Green** beats **Yellow**
- **Yellow** beats **Blue**
- **Blue** beats **Red**

If you attack with your current affinity against a weak point, you deal massive damage. If you attack with the same color, you deal zero damage (or heal the boss). You have to keep switching mid-fight.

### Classes
You pick one at character creation. There is no hybrid build (yet).

- **Warrior**: Melee tank. Can physically block beams. Struggles against enemies immune to physical damage unless you switch affinities to gain elemental buffs.
- **Wizard**: Ranged caster. Deals high elemental damage but has low health. Must spend mana to reflect beams. If you run out of mana, you're vulnerable.

### Progression
- **Campaign**: Restore the world from grayscale. Defeat wardens to unlock new colors.
- **Endgame**: Procedural dungeons with random modifiers (e.g., "Fire Storm," "Physical Immunity"). Farm materials to craft gear tailored to specific dungeon types rather than hoping for a lucky drop.

## Tech Stack

- **Language**: Rust
- **Rendering**: `softbuffer` (CPU-based). I chose this for pixel-perfect control and fast iteration without getting bogged down in GPU boilerplate.
- **Input**: `winit`

## Roadmap

- [ ] Core combat loop (movement, affinity switching, basic enemies)
- [ ] Full implementation of Warrior vs. Wizard
- [ ] First boss fight (Void Stalker)
- [ ] Crafting system & inventory UI
- [ ] Procedural map generation
- [ ] Local Co-op (planned for later)

## Documentation

If you are curious about the design logic or how the systems fit together:

- **[docs/DESIGN.md](docs/DESIGN.md)** — The full Game Design Document
- **[docs/CRAFTING.md](docs/CRAFTING.md)** — Details on the loot and crafting economy
