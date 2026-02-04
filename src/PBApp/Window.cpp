#include "PBApp/Window.h"

#include "PBApp/PBAssert.h"
#include "PBApp/Button.h"

#include <winuser.h>
#include <set>

const char CLASS_NAME[] = "PB Window";

Window::Window(HWND h) : handle(h) {
    // TODO: Consider making factory functions for creating bitmap, getting size, etc.
    // Would be nice to make this constructor noexcept
    auto hdc = GetDC(handle);
    screenBuffer = CreateCompatibleDC(hdc);
    PBAPP_ASSERT(screenBuffer != NULL, "Failed to create bitmap DC");

    screenBufferBitmap = CreateCompatibleBitmap(hdc, 100, 100);
    PBAPP_ASSERT(screenBufferBitmap != NULL, "Failed to create buffer bitmap");

    auto old = SelectObject(screenBuffer, screenBufferBitmap);
    PBAPP_ASSERT(old != NULL, "Failed to switch to new buffer bitmap");

    RECT size;
    auto result = GetClientRect(handle, &size);
    PBAPP_ASSERT(result, "Failed to get window size");

    width = size.right;
    height = size.bottom;
}

void Window::show() const {
    ShowWindow(handle, SW_SHOW);

    auto result = UpdateWindow(handle);
    PBAPP_ASSERT(result, "Failed to schedule window redraw");
}

void Window::paint() {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(handle, &ps);
    PBAPP_ASSERT(hdc != NULL, "Failed to get window DC");

    onPaint();        
    
    auto result = BitBlt(hdc, 0, 0, width, height, screenBuffer, 0, 0, SRCCOPY);
    PBAPP_ASSERT(result, "Failed to draw buffer to screen");

    result = EndPaint(handle, &ps);
    PBAPP_ASSERT(result, "Failed to end paint");
}

void Window::resize(unsigned int width, unsigned int height) {
    // TODO: Helper functions for bitmap stuff
    auto hdc = GetDC(handle);
    screenBufferBitmap = CreateCompatibleBitmap(hdc, width, height);
    PBAPP_ASSERT(screenBufferBitmap, "Could not create new bitmap");

    auto oldBitmap = SelectObject(screenBuffer, screenBufferBitmap);
    PBAPP_ASSERT(oldBitmap, "Could not select new bitmap");

    auto result = DeleteObject(oldBitmap);
    PBAPP_ASSERT(result, "Could not delete old bitmap");

    this->width = width;
    this->height = height;
    RECT newSize = { 0, 0, static_cast<LONG>(width), static_cast<LONG>(height) };
    result = InvalidateRect(handle, &newSize, FALSE);
    PBAPP_ASSERT(result, "Could not schedule repaint");

    onResize(width, height);
}

void Window::mouseDown(unsigned int x, unsigned int y) {
    onMouseDown(x, y);
}

void Window::mouseUp(unsigned int x, unsigned int y) {
    onMouseUp(x, y);
}

void Window::mouseMove(unsigned int x, unsigned int y) {
    onMouseMove(x, y);
}

unsigned int Window::getWidth() const { return width; }

unsigned int Window::getHeight() const { return height; }

void destroyWindow(Window* window);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    Window* window = reinterpret_cast<Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if (!window) return DefWindowProc(hwnd, uMsg, wParam, lParam);

    // TODO - Route WM_MOUSEMOVE, WM_LBUTTONDOWN, WM_LBUTTONUP
    switch (uMsg) {
        case WM_PAINT:
            window->paint();
            return 0;
        case WM_SIZE:
        {   
            UINT width = LOWORD(lParam);
            UINT height = HIWORD(lParam);
            window->resize(width, height);
        }
        return 0;
        case WM_COMMAND:
        {
            if (HIWORD(wParam) == BN_CLICKED) {
                Button* button = reinterpret_cast<Button*>(GetWindowLongPtr(reinterpret_cast<HWND>(lParam), GWLP_USERDATA));
                button->onClick();
            }
        }
        return 0;
        case WM_MOUSEMOVE:
            window->mouseMove(LOWORD(lParam), HIWORD(lParam));
        return 0;
        case WM_LBUTTONDOWN:
            window->mouseDown(LOWORD(lParam), HIWORD(lParam));
        return 0;
        case WM_LBUTTONUP:
            window->mouseUp(LOWORD(lParam), HIWORD(lParam));
        return 0;
        case WM_DESTROY:
            destroyWindow(window);
            return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void registerWindowClass() {
    static bool registered = false;

    if (registered) return;

    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc); 

    registered = true;
}

HWND createWindowHandle() {
    registerWindowClass();

    HWND handle = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        "Learn to Program Windows",     // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,                   // Parent window    
        NULL,                   // Menu
        GetModuleHandle(NULL),  // Instance handle
        NULL                    // Additional application data
    );

    PBAPP_ASSERT(handle, "Failed to create window");

    return handle;
}

namespace {
    std::set<Window*> activeWindows;
}

void registerWindow(Window* window, HWND handle) {
    activeWindows.insert(window);
    SetWindowLongPtr(handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window));

    // show() must go after handle and Window* are linked to receive first paint() call
    window->show();
}

void destroyWindow(Window* window) {
    delete window;
    activeWindows.erase(window);
    if (activeWindows.empty()) PostQuitMessage(0);
}