/**
*   TODO: (v1) - Make an app that lets the user draw on the screen with the mouse. 1pt black pen only is fine.
*/

#include "PBApp/PBApp.h"
#include "PBApp/Window.h"

class PaintWindow : public Window {
public:
    PaintWindow(HWND handle) : Window(handle) { }
};

class PaintApp : public PBApp {
public:
    PaintApp() {
        createWindow<PaintWindow>();
    }
};

PBApp* createApp() {
    return new PaintApp;
}