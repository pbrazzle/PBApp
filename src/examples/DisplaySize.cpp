/**
*   Displays the current size of the window as text on the screen
*/

#include "PBApp/PBApp.h"
#include "PBApp/Window.h"
#include "PBApp/PBAssert.h"

#include <string>
#include <wingdi.h>

class MyWindow : public Window {
public:
    MyWindow(HWND handle) : Window(handle) { }

protected:
    void onPaint() override {
        auto sizeText = std::string("Width: " + std::to_string(getWidth()) + " Height: " + std::to_string(getHeight()));

        // TODO: Wrap in easier function
        TextOut(screenBuffer, 0, 0, sizeText.c_str(), sizeText.size());
    }
};

class ExampleApp : public PBApp {
public:
    ExampleApp() {
        createWindow<MyWindow>();
    }
};

PBApp* createApp() {
    PBAPP_ASSERT(false, "What that stack do?");
    return new ExampleApp;
}