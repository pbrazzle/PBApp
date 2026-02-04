/**
*   TODO: Handle mouse leaving screen
*   TODO: Handle screen clearing when resizing
*/

#include "PBApp/PBApp.h"
#include "PBApp/Window.h"
#include "PBApp/PBAssert.h"

class PaintWindow : public Window {
public:
    PaintWindow(HWND handle) : Window(handle), drawing(false) { }

protected:
    void onMouseDown(unsigned int x, unsigned int y) override {
        drawing = true;
    }

    void onMouseUp(unsigned int x, unsigned int y) override {
        drawing = false;
    }

    void onMouseMove(unsigned int x, unsigned int y) override {
        if (!drawing) return;

        auto result = SetPixel(screenBuffer, x, y, RGB(255, 0, 0));
        auto color = GetPixel(screenBuffer, x, y);
        PBAPP_ASSERT(result != -1, "Failed to draw pixel");

        InvalidateRect(handle, NULL, FALSE);
    }

private:
    bool drawing;
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