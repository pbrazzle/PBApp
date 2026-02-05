#pragma once

#include <PBApp/Controls/Control.h>

#include <windows.h>

class Button : public Control {
public:
    Button(HWND handle);

    virtual void onClick() { }
};

template <typename ButtonType>
Button* createButton(HWND parent) {
    return createControl<Button, ButtonType>(parent, "BUTTON", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON);
}