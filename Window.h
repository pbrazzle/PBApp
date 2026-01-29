#pragma once

#include <windows.h>
#include <memory>

class Window {
public:
    Window(HWND h);

    void show() const;

    virtual void onPaint() {}

protected:
    HWND handle;
};

HWND createWindowHandle();

template <typename WindowType>
std::unique_ptr<Window> createWindow() {
    return std::make_unique<WindowType>(createWindowHandle());
}