#pragma once

#include <windows.h>

class Button {
public:
    Button(HWND handle);

    virtual void onClick() = 0;

private:
    HWND handle;
};