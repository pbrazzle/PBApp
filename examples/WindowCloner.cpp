/**
*   One button on the screen. It creates another identical window when pressed. The app closes when all windows have been closed.
*/

#include "PBApp/PBApp.h"
#include "PBApp/Window.h"
#include "PBApp/Controls/Button.h"

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
        auto button = createButton<CloningButton>(handle);
        button->setSize(100, 40);
        button->setPosition(0, 0);
        button->setText("Clone");
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