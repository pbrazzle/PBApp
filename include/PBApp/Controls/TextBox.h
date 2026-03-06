#pragma once

#include <PBApp/Controls/Control.h>

#include <windows.h>

class TextBox : public Control {
public:
    TextBox(HWND handle) : Control(handle) { }

    virtual void onClick() { }
};

template <typename TextFieldType>
TextBox* createTextField(HWND parent) {
    return createControl<TextBox, TextFieldType>(parent, "EDIT", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_LEFT);
}