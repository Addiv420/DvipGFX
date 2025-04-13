# 🖌️ DvipGFX

**DvipGFX** is a lightweight drawing program written in C++ using the **VipGFX library** by [key-real on SourceForge](https://sourceforge.net/projects/vipgfx/). It allows you to draw freely with the mouse, switch colors using hotkeys, and undo your last stroke. This project is great for learning about software rendering, basic event handling, and 2D graphics.

---

## ✨ Features

- Draw with the mouse using a circular brush
- Change brush size with the mouse wheel
- Undo your last stroke with `Ctrl + Z`
- Toggle fullscreen mode with a single key
- Pure software rendering – no GPU needed
- Color switching via number keys and `E` for erasing

---

## 🎨 Color Keybinds

| Key | Color     | Hex Code     |
|-----|-----------|--------------|
| 1   | Red       | `0xffff0000` |
| 2   | Orange    | `0xffffa500` |
| 3   | Yellow    | `0xffffff00` |
| 4   | Green     | `0xff00ff00` |
| 5   | Cyan      | `0xff00ffff` |
| 6   | Blue      | `0xff0000ff` |
| 7   | Purple    | `0xff800080` |
| 8   | Magenta   | `0xffff00ff` |
| 9   | White     | `0xffffffff` |
| 0   | Black     | `0xff000000` |
| E   | Eraser    | `0xfffec2c8` (Background color) |

---

## 🕹️ Controls

| Input                  | Action                          |
|------------------------|---------------------------------|
| Left Mouse Button      | Draw                            |
| Mouse Wheel            | Increase/Decrease brush size    |
| Keys 1–0, E            | Change color                    |
| Ctrl + Z               | Undo last stroke                |
| A                      | Toggle fullscreen/windowed      |
| ESC                    | Exit the application            |

---

## 💡 How It Works

Lines are drawn using a simple version of the **Bresenham line algorithm**, rendering a filled circle along the path between points to simulate a brush. Each stroke is stored as a `Line` struct, enabling undo functionality by redrawing all saved strokes after clearing the canvas.

---

## 🛠️ Dependencies

- C++11 or newer
- [`vipgfx`](https://sourceforge.net/projects/vipgfx/) Library

---

## 🧪 Installation

```bash
# Download
git clone https://github.com/Addiv420/DvipGFX.git
cd DvipGFX/src

# Starting Pong
export LD_LIBRARY_PATH=:.
./DvipGFX

# Build Pong
src/compiler.sh
```

---

If you have any questions or would like to contribute to this project, feel free to open an issue on GitHub!