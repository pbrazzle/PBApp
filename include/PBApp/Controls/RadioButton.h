#pragma once

#include <PBApp/Controls/Control.h>

#include <windows.h>

class RadioButton : public Control {
public:
    RadioButton(HWND handle) : Control(handle) { }

    virtual void onClick() { }
};

template <typename RadioButtonType>
RadioButton* createRadioButton(HWND parent) {
    return createControl<RadioButton, RadioButtonType>(parent, "BUTTON", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON);
}