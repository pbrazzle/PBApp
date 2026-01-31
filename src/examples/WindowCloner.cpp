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

class CloningWindow : public Window {
public:
    CloningWindow(HWND handle) : Window(handle) { }
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