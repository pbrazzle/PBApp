#include <PBApp/Button.h>

#include "PBApp/PBAssert.h"

void setWindowPosition(HWND handle, unsigned int x, unsigned int y) {
    auto result = SetWindowPos(handle, HWND_BOTTOM, x, y, 0, 0, SWP_NOSIZE);
    PBAPP_ASSERT(result, "Failed to move window");
}

void setWindowSize(HWND handle, unsigned int width, unsigned int height) {
    auto result = SetWindowPos(handle, HWND_BOTTOM, 0, 0, width, height, SWP_NOMOVE);
    PBAPP_ASSERT(result, "Failed to resize window");
}

Button::Button(HWND handle) : handle(handle) { }

void Button::setPosition(unsigned int x, unsigned int y) {
    setWindowPosition(handle, x, y);
}

void Button::setSize(unsigned int width, unsigned int height) {
    setWindowSize(handle, width, height);
}

void Button::setText(const std::string& text) {
    auto result = SetWindowText(handle, text.c_str());
    PBAPP_ASSERT(result, "Failed to set window text");
}