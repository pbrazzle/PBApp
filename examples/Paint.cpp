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

    void onMouseLeave() override { 
        drawing = false;
    }

    void onMouseMove(unsigned int x, unsigned int y) override {
        if (!drawing) return;

        auto result = SetPixel(buffer.getDC(), x, y, RGB(255, 0, 0));
        PBAPP_ASSERT(result != -1, "Failed to draw pixel");

        InvalidateRect(handle, NULL, FALSE);
    }

    void onPaint() override {

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