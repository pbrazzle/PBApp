#include "PBApp/PBApp.h"
#include "PBApp/Window.h"
#include "PBApp/Graphics.h"

#include "PBApp/Controls/Button.h"

class LayoutWindow : public Window {
public:
    LayoutWindow(HWND handle) : Window(handle) {
        button1 = createButton<Button>(handle);
        button1->setPosition(0, 0);

        button2 = createButton<Button>(handle);
    }

    void onResize(unsigned int width, unsigned int height) override {
        auto b1Width = width / 2;

        button1->setSize(b1Width, height);
        button2->setPosition(b1Width, 0);
        button2->setSize(width - b1Width, height);
    }

protected:
    void onPaint() override {
        clearScreen(buffer.getDC(), getWidth(), getHeight());
    }

private:
    Button* button1;
    Button* button2;
};

class ExampleApp : public PBApp {
public:
    ExampleApp() {
        createWindow<LayoutWindow>();
    }
};

PBApp* createApp() {
    return new ExampleApp;
}