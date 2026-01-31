#include <windows.h>

class Window;

HWND createWindowHandle();

void registerWindow(Window*, HWND);

template <typename WindowType>
Window* createWindow() {
    auto handle = createWindowHandle();
    Window* window = new WindowType(handle);
    registerWindow(window, handle);

    return window;
}