/**
*   Displays the current size of the window as text on the screen
*/

#include "PBApp/PBApp.h"
#include "PBApp/Window.h"

#include <string>
#include <wingdi.h>

class MyWindow : public Window {
public:
    MyWindow(HWND handle) : Window(handle) { }

protected:
    void onPaint() override {
        auto sizeText = std::string("Width: " + std::to_string(getWidth()) + " Height: " + std::to_string(getHeight()));
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