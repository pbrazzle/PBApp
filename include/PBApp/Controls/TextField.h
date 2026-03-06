#pragma once

#include <PBApp/Controls/Control.h>

#include <windows.h>

class TextField : public Control {
public:
    TextField(HWND handle);

    virtual void onClick() { }
};

template <typename TextFieldType>
TextField* createTextField(HWND parent) {
    return createControl<TextField, TextFieldType>(parent, "STATIC", WS_TABSTOP | WS_VISIBLE | WS_CHILD | SS_LEFT);
}