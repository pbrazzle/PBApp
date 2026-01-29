#pragma once

#include <windows.h>
#include <memory>

class Window {
public:
    Window(HWND h);

    Window& operator=(const Window&) = delete;
    Window(Window&) = delete;

    virtual ~Window() {}

    void show() const;

    virtual void onPaint() {}

protected:
    HWND handle;
};

HWND createWindowHandle();

template <typename WindowType>
std::unique_ptr<Window> createWindow() {
    auto handle = createWindowHandle();

    std::unique_ptr<Window> window = std::make_unique<WindowType>(handle);
    SetWindowLongPtr(handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window.get()));

    return window;
}