/**
*   TODO:
*   - Display current window size as text
*   - Add a button to the window
*       - The button should spawn a new window. App closes when all windows are closed.
*/

#include "PBApp.h"

#include "Window.h"

class MyWindow : public Window {
public:
    MyWindow(HWND handle) : Window(handle) { }

    void onPaint() override {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(handle, &ps);

        FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW+1));
        TextOut(hdc, 0, 0, "I'm painting!", 15);

        // Making a solid red brush
        auto redBrush = CreateSolidBrush(RGB(255, 0, 0));
        SelectObject(hdc, redBrush);

        Rectangle(hdc, 20, 20, 50, 50);
        Ellipse(hdc, 50, 20, 80, 50);

        POINT triangle[3] = {{80,50}, {95,20}, {110,50}};
        Polygon(hdc, triangle, 3);

        DeleteObject(redBrush);

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