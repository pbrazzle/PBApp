#include <PBApp/Bitmap.h>

#include <PBApp/PBAssert.h>

// windows.h min macro
#undef min

#include <algorithm>

Bitmap::Bitmap(HWND windowHandle, unsigned int width, unsigned int height) { 
    auto windowDC = GetDC(windowHandle);
    hdc = CreateCompatibleDC(windowDC);
    PBAPP_ASSERT(hdc != NULL, "Failed to create bitmap DC");

    auto bitmap = CreateCompatibleBitmap(windowDC, width, height);
    PBAPP_ASSERT(bitmap != NULL, "Failed to create buffer bitmap");

    old = SelectObject(hdc, bitmap);
    PBAPP_ASSERT(old != NULL, "Failed to switch to new buffer bitmap");
}

Bitmap::~Bitmap() {
    auto bitmap = SelectObject(hdc, old);
    DeleteObject(bitmap);
    DeleteDC(hdc);
}

void Bitmap::resize(HWND windowHandle, unsigned int width, unsigned int height) {
    auto windowDC = GetDC(windowHandle);
    auto newBitmap = CreateCompatibleBitmap(windowDC, width, height);

    auto oldDC = CreateCompatibleDC(NULL);
    auto oldBitmap = SelectObject(hdc, newBitmap);
    auto nullBitmap = SelectObject(oldDC, oldBitmap);

    unsigned int copyWidth = std::min(this->width, width);
    unsigned int copyHeight = std::min(this->height, height);

    auto result = BitBlt(hdc, 0, 0, copyWidth, copyHeight, oldDC, 0, 0, SRCCOPY);

    SelectObject(oldDC, nullBitmap);
    DeleteObject(oldBitmap);
    DeleteDC(oldDC);
}

HDC Bitmap::getDC() const noexcept { return hdc; }