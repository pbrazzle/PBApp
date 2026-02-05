#pragma once

#include <PBApp/Controls/Control.h>

#include <windows.h>

class TextField : public Control {
public:
    TextField(HWND handle) : Control(handle) { }

    virtual void onClick() { }
};

template <typename TextFieldType>
TextField* createTextField(HWND parent) {
    return createControl<TextField, TextFieldType>(parent, "EDIT", WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT);
}