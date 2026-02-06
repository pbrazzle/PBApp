#include "PBApp/PBApp.h"
#include "PBApp/Window.h"
#include "PBApp/Graphics.h"

#include "PBApp/Controls/Panel.h"

#include <iostream>

class LayoutWindow : public Window {
public:
    LayoutWindow(HWND handle) : Window(handle) {
        auto panel = createPanel<Panel>(handle);
        std::cout << "Made panel\n";
        panel->setPosition(10, 10);
        panel->setSize(100, 100);
        std::cout << "Positioned and sized panel\n";
    }

protected:
    void onPaint() override {
        clearScreen(buffer.getDC(), getWidth(), getHeight());
    }
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