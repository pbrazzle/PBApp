#include <PBApp/Controls/Control.h>

#include <PBApp/PBAssert.h>

#include <commctrl.h>

Control::Control(HWND handle) : handle(handle) { }

void Control::setPosition(unsigned int x, unsigned int y) {
    auto result = SetWindowPos(handle, HWND_BOTTOM, x, y, 0, 0, SWP_NOSIZE);
    PBAPP_ASSERT(result, "Failed to move window");
}

void Control::setSize(unsigned int width, unsigned int height) {
    auto result = SetWindowPos(handle, HWND_BOTTOM, 0, 0, width, height, SWP_NOMOVE);
    PBAPP_ASSERT(result, "Failed to resize window");
}

void Control::setText(const std::string& text) {
    auto result = SetWindowText(handle, text.c_str());
    PBAPP_ASSERT(result, "Failed to set window text");
}

LRESULT Control::sendMessage(UINT msg, WPARAM wParam, LPARAM lParam) {
    return SendMessage(handle, msg, wParam, lParam);
}

LRESULT CALLBACK ControlWndProc(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam, UINT_PTR subclassID, DWORD_PTR extraData) {
    std::cout << "Got message: " << msg << '\n';
    return DefSubclassProc(handle, msg, wParam, lParam);
}

HWND createControlHandle(HWND parent, const std::string& className, DWORD style) {
    HWND handle = CreateWindow(className.c_str(), 
            "", 
            style, 
            0, 
            0, 
            1,
            1, 
            parent, 
            NULL, 
            GetModuleHandle(NULL), 
            NULL);

    PBAPP_ASSERT(handle != NULL, "Could not create Control window");

    return handle;
}

void registerControl(Control* control, HWND handle) {
    SetWindowLongPtr(handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(control));

    auto result = SetWindowSubclass(handle, ControlWndProc, 1, 0);
    PBAPP_ASSERT(result == TRUE, "Could not add Control window procedure");
}