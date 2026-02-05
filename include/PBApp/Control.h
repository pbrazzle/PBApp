#pragma once

#include <windows.h>
#include <string>

class Control {
public:
    Control(HWND handle);

    void setPosition(unsigned int x, unsigned int y);

    void setSize(unsigned int width, unsigned int height);

    void setText(const std::string& text);

private:
    HWND handle;
};