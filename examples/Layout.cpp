#include "PBApp/PBApp.h"
#include "PBApp/Window.h"

#include "PBApp/Controls/Button.h"
#include "PBApp/Layouts/EquallySpacedLayout.h"

class LayoutWindow : public Window {
public:
    LayoutWindow(HWND handle) : Window(handle) {
        button1 = createButton<Button>(handle);
        button2 = createButton<Button>(handle);

        equallySized.add(button1);
        equallySized.add(button2);

        setLayout(handle, &equallySized);
    }

private:
    Button* button1;
    Button* button2;

    EquallySpacedLayout equallySized;
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