#include "PBApp.h"

#include "Window.h"

class MyWindow : public Window {
public:
    MyWindow(HWND handle) : Window(handle) { }

    void onPaint() override {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(handle, &ps);

        FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));

        EndPaint(handle, &ps);
    }
};

class ExampleApp : public PBApp {
public:
    ExampleApp() {
        auto myWindow = createWindow<MyWindow>();

        myWindow->show();
    }
};

PBApp* createApp() {
    return new ExampleApp;
}