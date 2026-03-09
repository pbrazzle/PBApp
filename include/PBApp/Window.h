#pragma once

#include <PBApp/GUIElement.h>
#include <PBApp/Bitmap.h>

#include <windows.h>

class Window : public GUIElement {
public:
    Window(HWND h);

    Window& operator=(const Window&) = delete;
    Window(Window&) = delete;

    virtual ~Window() {}

    void show();

    void paint();

    void resize(unsigned int width, unsigned int height);

    void mouseDown(unsigned int x, unsigned int y);

    void mouseUp(unsigned int x, unsigned int y);

    void mouseMove(unsigned int x, unsigned int y);

    void mouseLeave();

    void mouseEnter();

    unsigned int getWidth() const noexcept;

    unsigned int getHeight() const noexcept;

protected:
    HWND handle;
    Bitmap buffer;

    unsigned int width, height;
    
    virtual void onPaint();

    virtual void onResize(unsigned int width, unsigned int height) {};

    virtual void onMouseDown(unsigned int x, unsigned int y) {};

    virtual void onMouseUp(unsigned int x, unsigned int y) {};

    virtual void onMouseMove(unsigned int x, unsigned int y) {};

    virtual void onMouseLeave() {};

    virtual void onMouseEnter() {};

private:
    bool mouseOnScreen;
};

template <typename WindowType>
Window* createWindow();

#include "PBApp/Window.tpp"