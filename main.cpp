#include <vector>
#include <stdio.h>
#include <iostream>
#include "vipgfx.h"

#define RED      0xffff0000
#define ORANGE   0xffffa500
#define YELLOW   0xffffff00
#define GREEN    0xff00ff00
#define CYAN     0xff00ffff
#define BLUE     0xff0000ff
#define PURPLE   0xff800080
#define MAGENTA  0xffff00ff
#define WHITE    0xffffffff
#define BLACK    0xff000000
#define ERASE    0xfffec2c8

using namespace std;

struct Line {
    int startX, startY, endX, endY, radius;
    unsigned int color;
};

vector<Line> lines;

void drawLine(int x1, int y1, int x2, int y2, int radius, unsigned int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        DrawFilledCircleClip(vscreen, x1, y1, radius, color);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void redrawLines() {
    for (const auto& line : lines) {
        drawLine(line.startX, line.startY, line.endX, line.endY, line.radius, line.color);
    }
}

int main() {
    int selectedColor = 0;
    unsigned int colors[11] = {RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PURPLE, MAGENTA, WHITE, BLACK, ERASE};
    keyboardlayout = 0;
    int radius = 10;
    int prevMouseX = -1;
    int prevMouseY = -1;

    InitGFXsystem(1280, 720, true);
    SetGFXwindowPos(360, 200);

    for (unsigned int y = 0; y < vscreen.height; y++)
        for (unsigned int x = 0; x < vscreen.width; x++)
            putPixel(vscreen, x, y, 0xfffec2c8);

    while (!keyboard[KEY_ESCAPE]) {
        if (mouseWheel < 0) radius += 5;
        else if (mouseWheel > 0) radius -= 5;
        if (radius < 5) radius = 5;

        if (mouseL) {
            if (prevMouseX != -1 && prevMouseY != -1) {
                drawLine(prevMouseX, prevMouseY, mouseX, mouseY, radius, colors[selectedColor]);
                lines.push_back({prevMouseX, prevMouseY, mouseX, mouseY, radius, colors[selectedColor]});
            } else {
                DrawFilledCircleClip(vscreen, mouseX, mouseY, radius, colors[selectedColor]);
            }
            prevMouseX = mouseX;
            prevMouseY = mouseY;
        } else {
            prevMouseX = -1;
            prevMouseY = -1;
        }

        if (keyboard[KEY_A]) gfxFullScreen = !gfxFullScreen;
        if (keyboard[KEY_1]) selectedColor = 0;
        if (keyboard[KEY_2]) selectedColor = 1;
        if (keyboard[KEY_3]) selectedColor = 2;
        if (keyboard[KEY_4]) selectedColor = 3;
        if (keyboard[KEY_5]) selectedColor = 4;
        if (keyboard[KEY_6]) selectedColor = 5;
        if (keyboard[KEY_7]) selectedColor = 6;
        if (keyboard[KEY_8]) selectedColor = 7;
        if (keyboard[KEY_9]) selectedColor = 8;
        if (keyboard[KEY_0]) selectedColor = 9;
        if (keyboard[KEY_E]) selectedColor = 10;
        if (keyboard[KEY_LCONTROL] && keyboard[KEY_Z]) {
            if (!lines.empty()) {
                lines.pop_back();
                for (unsigned int y = 0; y < vscreen.height; y++)
                    for (unsigned int x = 0; x < vscreen.width; x++)
                        putPixel(vscreen, x, y, 0xfffec2c8);
                redrawLines();
            }
        }

        UpdateGFXsystem();
    }

    FinishGFXsystem();
    ReturnFPSstring();

    return 0;
}
