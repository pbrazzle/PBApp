#include "PBApp/PBApp.h"
#include "PBApp/Window.h"
#include "PBApp/Graphics.h"

#include "PBApp/Controls/Button.h"

class Layout {
public:
    Layout() = default;

    void add(Button* button) {
        buttons.push_back(button);
    }

    // Equally spaced horizontally, use full height
    void update(unsigned int width, unsigned int height) {
        auto baseWidth = width / buttons.size();
        auto extraWidth = width % buttons.size();

        unsigned int currentX = 0;
        for (auto button : buttons) {
            auto bWidth = baseWidth + (extraWidth ? 1 : 0);
            button->setSize(bWidth, height);
            button->setPosition(currentX, 0);

            extraWidth -= (extraWidth) ? 1 : 0;
            currentX += bWidth;
        }
    }

private:
    std::vector<Button*> buttons;
};

class LayoutWindow : public Window {
public:
    LayoutWindow(HWND handle) : Window(handle) {
        button1 = createButton<Button>(handle);
        button2 = createButton<Button>(handle);

        equallySized.add(button1);
        equallySized.add(button2);
    }

    void onResize(unsigned int width, unsigned int height) override {
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