#pragma once

#include <PBApp/Controls/Control.h>

#include <windows.h>

class Checkbox : public Control {
public:
    Checkbox(HWND handle);

    virtual void onClick() { }
};

template <typename CheckboxType>
Checkbox* createCheckbox(HWND parent) {
    HWND checkboxHandle = CreateWindow("BUTTON", 
            "CLONE", 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 
            0, 
            0, 
            100,
            100, 
            parent, 
            NULL, 
            GetModuleHandle(NULL), 
            NULL);

    Checkbox* checkbox = new CheckboxType(checkboxHandle);
    SetWindowLongPtr(checkboxHandle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(checkbox));
        
    return checkbox;
}