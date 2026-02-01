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
        auto clonedWindow = createWindow<CloningWindow>();
        clonedWindow->show();
    }
};

class CloningWindow : public Window {
public:
    CloningWindow(HWND handle) : Window(handle) {
        HWND buttonHandle = CreateWindow("BUTTON", 
            "CLONE", 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
            0, 
            0, 
            100,
            100, 
            handle, 
            NULL, 
            GetModuleHandle(NULL), 
            NULL);
        
        CloningButton* myButton = new CloningButton(buttonHandle);
    }
};

class ExampleApp : public PBApp {
public:
    ExampleApp() {
        auto window1 = createWindow<CloningWindow>();
        window1->show();

        auto window2 = createWindow<CloningWindow>();
        window2->show();
    }
};

PBApp* createApp() {
    return new ExampleApp;
}