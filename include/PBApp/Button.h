#pragma once

#include <windows.h>

class Button {
public:
    Button(HWND handle);

    virtual void onClick() = 0;

private:
    HWND handle;
};

template <typename ButtonType>
Button* createButton(HWND parent) {
    HWND buttonHandle = CreateWindow("BUTTON", 
            "CLONE", 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
            0, 
            0, 
            100,
            100, 
            parent, 
            NULL, 
            GetModuleHandle(NULL), 
            NULL);

    Button* button = new ButtonType(buttonHandle);
    SetWindowLongPtr(buttonHandle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(button));
        
    return button;
}