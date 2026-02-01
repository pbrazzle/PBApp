/**
*   TODO: Make the following app:
*
*   One button on the screen. It creates another identical window when pressed. The app closes when all windows have been closed.
*
*   Current TODOs:
*   - Closing a Window shouldn't exit the program
*/

#include "PBApp/PBApp.h"
#include "PBApp/Window.h"
#include "PBApp/Button.h"
#include <winuser.h>

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