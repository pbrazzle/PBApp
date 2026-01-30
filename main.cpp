/**
*   TODO:
*   - Display current window size as text
*   - Add a button to the window
*       - The button should spawn a new window. App closes when all windows are closed.
*/

#include "PBApp.h"

#include "Window.h"

#include <string>
#include <wingdi.h>
#include <iostream>

class MyWindow : public Window {
public:
    MyWindow(HWND handle) : Window(handle), screenBuffer(nullptr), screenBufferBitmap(nullptr) {
        screenBuffer = CreateCompatibleDC(GetDC(handle));
        screenBufferBitmap = CreateCompatibleBitmap(screenBuffer, 1, 1);
        SelectObject(screenBuffer, screenBufferBitmap);
        std::cout << "DC is " << screenBuffer <<'\n';
    }

    ~MyWindow() {
        // DeleteDC(screenBuffer);
        // DeleteObject(screenBufferBitmap);
    }

    void onPaint() override {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(handle, &ps);

        RECT windowSize;
        GetClientRect(handle, &windowSize);

        FillRect(screenBuffer, &windowSize, reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)));

        auto sizeText = std::string("Width: " + std::to_string(windowSize.right) + " Height: " + std::to_string(windowSize.bottom));
        TextOut(screenBuffer, 0, 0, sizeText.c_str(), sizeText.size());

        BitBlt(hdc, 0, 0, windowSize.right, windowSize.bottom, screenBuffer, 0, 0, SRCCOPY);

        EndPaint(handle, &ps);
    }

    void onResize(unsigned int width, unsigned int height) override {
        screenBufferBitmap = CreateCompatibleBitmap(screenBuffer, width, height);
        auto oldBitmap = SelectObject(screenBuffer, screenBufferBitmap);
        DeleteObject(oldBitmap);

        RECT newSize = { 0, 0, static_cast<LONG>(width), static_cast<LONG>(height) };
        InvalidateRect(handle, &newSize, FALSE);
    }

private:
    HDC screenBuffer;
    HBITMAP screenBufferBitmap;
};

class ExampleApp : public PBApp {
public:
    ExampleApp() {
        auto myWindow = createWindow<MyWindow>();

        myWindow->show();
    }
};

PBApp* createApp() {
    return new ExampleApp;
}