#include "Window.h"
#include "PBWindow.h"

const char CLASS_NAME[] = "PB Window";

Window::Window(HWND h) : handle(h) { }

void Window::show() const {
    ShowWindow(handle, SW_SHOW);
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

Window createWindow() {
    return Window(createWindowHandle());
}
