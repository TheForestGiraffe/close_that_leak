# FdF — 3D Wireframe Renderer

**FdF** is a graphical project from the 42 curriculum.  
It consists of rendering a 3D wireframe representation of a height map (`.fdf` file) using **MiniLibX**.

This implementation focuses on smooth interaction, multiple viewing modes, and real-time transformations.

---

## Table of Contents

- [Preview](#preview)
- [Features](#features)
  - [Mandatory](#mandatory)
  - [Bonus (Implemented)](#bonus-implemented)
- [Controls](#controls)
  - [Keyboard](#keyboard)
  - [Mouse](#mouse)
- [How to Build](#how-to-build)
- [Usage](#usage)
- [.fdf File Format](#fdf-file-format)

---

## Preview

https://github.com/user-attachments/assets/b1c35ecb-aecd-4aa0-a9c1-3d20ad801f21

Music credit:   
Saison, Kid Enigma - The Break Dub - Dub Mix (https://open.spotify.com/track/3ot1sAc8Eqep3Ph5Nu3ycB?si=2fe8d78a6a5240b4)

---

## Features

### Mandatory

- Parse `.fdf` height maps
- Build a grid of 3D points `(x, y, z)`
- Project 3D coordinates into 2D space
- Custom line rasterization (Bresenham-style)
- Display in a window with MiniLibX
- Handle window close and ESC key

### Bonus (Implemented)

- ✅ Mouse-based translation (middle click + drag)
- ✅ Mouse-based rotation (right click + drag)
- ✅ Continuous automatic rotation
- ✅ Keyboard and mouse interaction
- ✅ Multiple camera views
- ✅ Isometric projection
- ✅ Perspective projection
- ✅ Orthographic views (top / side / front)
- ✅ Real-time zoom (mouse wheel)
- ✅ Smooth image rendering

---

## Controls

### Keyboard

| Key              | Action |
|------------------|--------|
| `ESC`            | Exit program |
| `X` (window btn) | Close window |
| `R`              | Toggle automatic rotation |
| `I`              | Isometric view *(resets rotation angles)* |
| `P`              | Perspective view *(resets rotation angles)* |
| `Z`              | Top view *(resets rotation angles)* |
| `X`              | Side view *(resets rotation angles)* |
| `Y`              | Front view *(resets rotation angles)* |
| `← ↑ ↓ →`        | Translate map |
| `W` / `S`        | Rotate around **X axis** (`W`: +, `S`: -) |
| `A` / `D`        | Rotate around **Y axis** (`A`: -, `D`: +) |
| `Q` / `E`        | Rotate around **Z axis** (`Q`: -, `E`: +) |
| `Numpad +` / `Numpad -` | Increase / decrease **height scale** (Z exaggeration) |

> Notes:
> - Zoom is handled via the **mouse wheel** in this implementation.
> - `Z/X/Y/I/P` also reset `rot_angle_x/y/z` to `0` when switching projection/view.

### Mouse

| Action              | Result |
|---------------------|--------|
| Middle Click + Drag | Translate map |
| Right Click + Drag  | Rotate view |
| Scroll Wheel        | Zoom |

---

## How to Build

### Requirements

- C compiler (`cc`)
- `make`
- MiniLibX (42 version)
- Linux

### Compile

```bash
make
```

### Clean

```bash
make clean
make fclean
make re
```

---

## Usage

Run with a map file:

```bash
./fdf maps/<map>.fdf
```

Example:

```bash
./fdf maps/42.fdf
```

---

## .fdf File Format

An `.fdf` file contains a grid of heights:

- Each number represents a Z value
- Position in the grid defines X and Y coordinates
- Optional hexadecimal color values may be present (ignored in this implementation)

Example:

```text
0  0  0  0
0  1  2  0
0  2  4  0
0  0  0  0
```
