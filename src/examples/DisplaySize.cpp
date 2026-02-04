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
        // Clear background 
        // TODO: Wrap in easier function
        RECT windowSize = { 0, 0, static_cast<LONG>(width), static_cast<LONG>(height) };
        int bgResult = FillRect(screenBuffer, &windowSize, reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1));
        PBAPP_ASSERT(bgResult, "Failed to clear window");

        auto sizeText = std::string("Width: " + std::to_string(getWidth()) + " Height: " + std::to_string(getHeight()));
        // Draw text
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
    return new ExampleApp;
}