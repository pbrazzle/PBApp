#include "PBApp/PBApp.h"
#include "PBApp/Window.h"
#include "PBApp/Graphics.h"

#include "PBApp/Controls/Button.h"
#include "PBApp/Layouts/Layout.h"

class LayoutWindow : public Window {
public:
    LayoutWindow(HWND handle) : Window(handle) {
        button1 = createButton<Button>(handle);
        button2 = createButton<Button>(handle);

        equallySized.add(button1);
        equallySized.add(button2);
    }

    void onResize(unsigned int width, unsigned int height) override {
        // TODO: User should not have to update Layout themselves
        equallySized.update(width, height);
    }

protected:
    void onPaint() override {
        clearScreen(buffer.getDC(), getWidth(), getHeight());
    }

private:
    Button* button1;
    Button* button2;

    Layout equallySized;
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