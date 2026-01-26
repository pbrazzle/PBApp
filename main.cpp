#include "PBWindow.h"

#include "Window.h"

class ExampleApp : public PBApp {
public:
    ExampleApp() {
        Window myWindow = createWindow();

        myWindow.show();
    }
};

PBApp* createApp() {
    return new ExampleApp;
}