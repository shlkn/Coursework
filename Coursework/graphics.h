#pragma once
#ifndef GRAPHICS_H
#include <windows.h>
#include "glut.h"
#include <fstream>
void graphic_init(int argc, char* argv[]);
void ScreenShot(int W, int H);
void display();
void displayText(float x, float y, int r, int g, int b, char string);
void reshape(int w, int h);
#endif //graphics.h