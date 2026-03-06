#pragma once

#include <windows.h>

class Layout {
public:
    Layout() = default;

    virtual void update(unsigned int width, unsigned int height) = 0;
};

void setLayout(HWND handle, Layout* layout);

void updateWindowLayout(HWND handle, unsigned int width, unsigned int height);