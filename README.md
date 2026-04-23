# Virtual World Simulator

A turn-based virtual ecosystem simulator written in C++, created as a project for the **Object-Oriented Programming** course.

The player controls a human character navigating a grid-based world populated by animals and plants, each with their own behaviors, priorities, and interactions.

---


## Features

- **Turn-based simulation** — every organism acts once per turn according to its initiative and age
- **Singleton world** — the `Swiat` (World) class manages all organisms and game state
- **Polymorphic organisms** — animals and plants share a common `Organizm` base class with virtual methods (`akcja`, `kolizja`, `dziecko`)
- **Human special ability** — Alzur's Shield: pushes away organisms instead of fighting them (5-turn cooldown)
- **ANSI terminal rendering** — the world is drawn in-place in the console using escape codes
- **Event log** — each turn displays a log of all interactions (kills, reproductions, special events)

---

## Organisms

### Animals (`Zwierze`)

| Symbol | Name       | Strength | Initiative | Special behavior                                      |
|--------|------------|----------|------------|-------------------------------------------------------|
| `C`    | Człowiek   | 5        | 4          | Player-controlled; can activate **Alzur's Shield**    |
| `W`    | Wilk       | 9        | 5          | Strong predator                                       |
| `O`    | Owca       | 4        | 4          | Basic herbivore                                       |
| `L`    | Lis        | 3        | 7          | Smart — avoids stronger opponents                     |
| `Z`    | Żółw       | 2        | 1          | Slow (25% chance to move); repels weak attackers      |
| `A`    | Antylopa   | 4        | 4          | Can move 2 cells; 50% chance to escape from combat    |

### Plants (`Roslina`)

| Symbol | Name                 | Strength | Special behavior                                          |
|--------|----------------------|----------|-----------------------------------------------------------|
| `t`    | Trawa                | 0        | Standard plant, spreads randomly                          |
| `m`    | Mlecz                | 0        | Spreads 3× faster than normal plants                      |
| `g`    | Guarana              | 0        | Boosts strength of the animal that eats it by 3           |
| `j`    | Wilcze Jagody        | 99       | Kills any animal that steps on it; dies afterward         |
| `b`    | Barszcz Sosnowskiego | 10       | Poisons all adjacent animals each turn; deadly on contact |

---

## Controls

| Key            | Action                          |
|----------------|---------------------------------|
| `↑ ↓ ← →`      | Set movement direction          |
| `Enter`        | Advance to next turn            |
| `Space`        | Activate / deactivate Alzur's Shield |
| `Esc`          | Quit the game                   |

> **Note:** Press a direction key first to set where the human will move, then press `Enter` to execute the turn.

---

Key design patterns used:
- **Singleton** — `Swiat` (only one world instance)
- **Polymorphism** — `akcja()`, `kolizja()`, `dziecko()` overridden per organism
- **Factory method** — `dziecko()` creates a new instance of the same type for reproduction

---

## Building & Running

### Requirements

- **Windows** (required — uses `<conio.h>` and `_getch()` for keyboard input)
- **C++14** or newer
- **CMake 3.10+**
- A C++ compiler (MSVC, MinGW/GCC on Windows)

### Build with CMake

```bash
# Clone the repository
git clone https://github.com/YOUR_USERNAME/virtual-world.git
cd virtual-world

# Configure and build
cmake -S src -B build
cmake --build build

# Run
./build/VirtualWorld    # or build\VirtualWorld.exe on Windows
```

### Build with g++ (MinGW on Windows)

```bash
cd src
g++ -std=c++14 -o VirtualWorld *.cpp
VirtualWorld.exe
```
