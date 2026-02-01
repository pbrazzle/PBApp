#include <PBApp/Button.h>

Button::Button(HWND handle) : handle(handle) { 
    // TODO: This should happen outside of the class
    SetWindowLongPtr(handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
}