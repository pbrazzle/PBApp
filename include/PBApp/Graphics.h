#pragma once

#include <string>
#include <windows.h>

void clearScreen(HDC dc, unsigned int screenWidth, unsigned int screenHeight);

void drawText(HDC dc, unsigned int x, unsigned int y, const std::string& text);