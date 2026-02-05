#include "PBApp/Graphics.h"

#include "PBApp/PBAssert.h"

#include <iostream>

void clearScreen(HDC dc, unsigned int screenWidth, unsigned int screenHeight) {
    RECT windowSize = { 0, 0, static_cast<LONG>(screenWidth), static_cast<LONG>(screenHeight) };
    int bgResult = FillRect(dc, &windowSize, reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1));
    PBAPP_ASSERT(bgResult, "Failed to clear window");
}

void drawText(HDC dc, unsigned int x, unsigned int y, const std::string& text) {
    std::cout << "Drawing text on DC " << dc << '\n'; 
    TextOut(dc, x, y, text.c_str(), text.size());
}