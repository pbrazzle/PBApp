/**
*   Displays the current size of the window as text on the screen
*/

#include "PBApp/PBApp.h"
#include "PBApp/Window.h"
#include "PBApp/PBAssert.h"

#include <string>
#include <wingdi.h>
#include <iostream>
#include <cassert>

class MyWindow : public Window {
public:
    MyWindow(HWND handle) : Window(handle) { }

protected:
    void onPaint() override {
        RECT windowSize;
        GetClientRect(handle, &windowSize);

        FillRect(screenBuffer, &windowSize, reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)));

        auto sizeText = std::string("Width: " + std::to_string(windowSize.right) + " Height: " + std::to_string(windowSize.bottom));
        TextOut(screenBuffer, 0, 0, sizeText.c_str(), sizeText.size());
    }
};

class ExampleApp : public PBApp {
public:
    ExampleApp() {
        myWindow = createWindow<MyWindow>();
        myWindow->show();
    }

private:
    std::unique_ptr<Window> myWindow;
};

PBApp* createApp() {
    return new ExampleApp;
}