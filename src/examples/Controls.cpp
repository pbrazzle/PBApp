/**
*   TODO:
*   - Should be able to set control position, size, and text
*/

#include "PBApp/PBApp.h"
#include "PBApp/Window.h"
#include "PBApp/Button.h"
#include "PBApp/Graphics.h"

class ControlWindow : public Window {
public:
    ControlWindow(HWND handle) : Window(handle) {
        auto button = createButton<Button>(handle);
        button->setPosition(0, 0);
        button->setSize(100, 40);
        button->setText("A button");
        
        // TODO: Checkbox
        // TODO: Radio button
        // TODO: List box
        // TODO: Text field
    }

protected:
    void onPaint() override {
        clearScreen(buffer.getDC(), getWidth(), getHeight());
    }
};

class ExampleApp : public PBApp {
public:
    ExampleApp() {
        createWindow<ControlWindow>();
    }
};

PBApp* createApp() {
    return new ExampleApp;
}