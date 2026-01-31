#pragma once

#include <windows.h>

class Window {
public:
    Window(HWND h);

    Window& operator=(const Window&) = delete;
    Window(Window&) = delete;

    virtual ~Window() {}

    void show() const;

    void paint();

    void resize(unsigned int width, unsigned int height);

    unsigned int getWidth() const;

    unsigned int getHeight() const;

protected:
    HWND handle;
    HDC screenBuffer;
    HBITMAP screenBufferBitmap;

    unsigned int width, height;
    
    virtual void onPaint() {};

    virtual void onResize(unsigned int width, unsigned int height) {};
};

HWND createWindowHandle();

void registerWindow(Window*, HWND);

template <typename WindowType>
Window* createWindow() {
    auto handle = createWindowHandle();
    Window* window = new WindowType(handle);
    registerWindow(window, handle);

    return window;
}