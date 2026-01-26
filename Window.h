#pragma once

#include <windows.h>

class Window {
public:
    Window(HWND h);

    void show() const;

private:
    HWND handle;
};

Window createWindow();