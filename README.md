# Chromatic Hero

A 2D top-down Action RPG written in Rust. No engines. No frameworks. CPU-rendered via `softbuffer`.

## The Core Mechanic

Combat runs on color affinity alone. Four colors, one cycle:

- **Red** beats **Green**
- **Green** beats **Yellow**
- **Yellow** beats **Blue**
- **Blue** beats **Red**

Attack with your matching weakness — massive damage. Attack with the same color — zero damage or heal the enemy. The complexity comes from switching affinities mid-fight, not grinding for numbers.

## Classes

Pick one at character creation. You stick with it. Solo viability is priority #1. Co-op is planned for later.

| Warrior | Wizard |
|---------|--------|
| Melee tank | Ranged caster |
| Blocks beams with shield | Reflects beams via mana spells |
| High HP/Armor | Low health, high elemental damage |
| Needs affinity switch vs physical-immune enemies | Vulnerable when out of mana |

## Progression

- **Campaign**: Restore a grayscale world by defeating Wardens to unlock colors.
- **Endgame**: Procedural dungeons with random modifiers. Farm materials to craft gear tailored to specific dungeon types rather than hoping for lucky drops.

## Tech Stack

- **Language**: Rust
- **Rendering**: `softbuffer` (CPU-based pixel manipulation)
- **Input**: `winit`
- **Architecture**: Custom ECS + FSM

We refactor when the pain hits, not before. All code lives in `/src/engine/` inside a single binary until there's reason to split.

## Status

Early prototype phase. Core combat loop in progress.

## Links

- [Design Document](docs/DESIGN.md)
- [Crafting System](docs/CRAFTING.md)
- [Dev Log](https://metrognomes.dev)
