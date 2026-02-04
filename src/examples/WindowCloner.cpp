/**
*   One button on the screen. It creates another identical window when pressed. The app closes when all windows have been closed.
*/

#include "PBApp/PBApp.h"
#include "PBApp/Window.h"
#include "PBApp/Button.h"
#include "PBApp/PBAssert.h"

class CloningWindow;

class CloningButton : public Button {
public:
    CloningButton(HWND handle) : Button(handle) { }

    void onClick() override {
        createWindow<CloningWindow>();
    }
};

class CloningWindow : public Window {
public:
    CloningWindow(HWND handle) : Window(handle) {
        createButton<CloningButton>(handle);
    }

protected:
    void onPaint() override {
        // TODO: Wrap in easier function
        RECT windowSize = { 0, 0, static_cast<LONG>(getWidth()), static_cast<LONG>(getHeight()) };
        int bgResult = FillRect(screenBuffer, &windowSize, reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1));
        PBAPP_ASSERT(bgResult, "Failed to clear window");
    }
};

class ExampleApp : public PBApp {
public:
    ExampleApp() {
        createWindow<CloningWindow>();
    }
};

PBApp* createApp() {
    return new ExampleApp;
}