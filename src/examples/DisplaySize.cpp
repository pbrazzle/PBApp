/**
*   Displays the current size of the window as text on the screen
*/

#include "PBApp/PBApp.h"
#include "PBApp/Window.h"
#include "PBApp/PBAssert.h"
#include "PBApp/Graphics.h"

#include <string>
#include <wingdi.h>

class MyWindow : public Window {
public:
    MyWindow(HWND handle) : Window(handle) { }

protected:
    void onPaint() override {
        clearScreen(screenBuffer, getWidth(), getHeight());

        auto sizeText = std::string("Width: " + std::to_string(getWidth()) + " Height: " + std::to_string(getHeight()));
        drawText(screenBuffer, 0, 0, sizeText);
    }
};

class ExampleApp : public PBApp {
public:
    ExampleApp() {
        createWindow<MyWindow>();
    }
};

PBApp* createApp() {
    return new ExampleApp;
}