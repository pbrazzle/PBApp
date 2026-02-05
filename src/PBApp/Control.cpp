#include <PBApp/Control.h>

#include <PBApp/PBAssert.h>

Control::Control(HWND handle) : handle(handle) { }

void Control::setPosition(unsigned int x, unsigned int y) {
    auto result = SetWindowPos(handle, HWND_BOTTOM, x, y, 0, 0, SWP_NOSIZE);
    PBAPP_ASSERT(result, "Failed to move window");
}

void Control::setSize(unsigned int width, unsigned int height) {
    auto result = SetWindowPos(handle, HWND_BOTTOM, 0, 0, width, height, SWP_NOMOVE);
    PBAPP_ASSERT(result, "Failed to resize window");
}

void Control::setText(const std::string& text) {
    auto result = SetWindowText(handle, text.c_str());
    PBAPP_ASSERT(result, "Failed to set window text");
}