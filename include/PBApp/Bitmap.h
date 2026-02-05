#pragma once

#include <windows.h>

class Bitmap {
public:
    Bitmap(HWND windowHandle, unsigned int width, unsigned int height);

    Bitmap(const Bitmap&) = delete;
    Bitmap& operator=(const Bitmap&) = delete;

    ~Bitmap();

    void resize(HWND windowHandle, unsigned int width, unsigned int height);

    HDC getDC() const noexcept;

private:
    HDC hdc;
    HGDIOBJ old;
    unsigned int width;
    unsigned int height;
};