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
    return createControl<Checkbox, CheckboxType>(parent, "BUTTON", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX);
}