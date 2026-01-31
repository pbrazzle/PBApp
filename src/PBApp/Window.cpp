#include "PBApp/Window.h"

#include "PBApp/PBAssert.h"

#include <stdexcept>
#include <winuser.h>

const char CLASS_NAME[] = "PB Window";

Window::Window(HWND h) : handle(h) {
    screenBuffer = CreateCompatibleDC(GetDC(handle));
    screenBufferBitmap = CreateCompatibleBitmap(screenBuffer, 1, 1);
    SelectObject(screenBuffer, screenBufferBitmap);
}

void Window::show() const {
    ShowWindow(handle, SW_SHOW);
    UpdateWindow(handle);
}

void Window::paint() {
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(handle, &ps);

    onPaint();        
    
    RECT windowSize;
    GetClientRect(handle, &windowSize);
    BitBlt(hdc, 0, 0, windowSize.right, windowSize.bottom, screenBuffer, 0, 0, SRCCOPY);
    EndPaint(handle, &ps);
}

void Window::resize(unsigned int width, unsigned int height) {
    screenBufferBitmap = CreateCompatibleBitmap(screenBuffer, width, height);
    PBAPP_ASSERT(screenBufferBitmap, "Could not create new bitmap");

    auto oldBitmap = SelectObject(screenBuffer, screenBufferBitmap);
    PBAPP_ASSERT(oldBitmap, "Could not select new bitmap");

    auto result = DeleteObject(oldBitmap);
    PBAPP_ASSERT(result, "Could not delete old bitmap");

    RECT newSize = { 0, 0, static_cast<LONG>(width), static_cast<LONG>(height) };
    result = InvalidateRect(handle, &newSize, FALSE);
    PBAPP_ASSERT(result, "Could not schedule repaint");

    onResize(width, height);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    Window* window = reinterpret_cast<Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

    if (!window) return DefWindowProc(hwnd, uMsg, wParam, lParam);

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
        case WM_DESTROY:
            PostQuitMessage(0);
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

    if (handle == NULL)
    {
        throw std::runtime_error("Failed to create window!");
    }

    return handle;
}
