#include <PBApp/Button.h>

Button::Button(HWND handle) : handle(handle) { 
    SetWindowLongPtr(handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));
}