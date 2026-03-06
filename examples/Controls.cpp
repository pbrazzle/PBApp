#include "PBApp/PBApp.h"
#include "PBApp/Window.h"
#include "PBApp/Graphics.h"

#include "PBApp/Controls/Button.h"
#include "PBApp/Controls/Checkbox.h"
#include "PBApp/Controls/Listbox.h"
#include "PBApp/Controls/TextBox.h"
#include "PBApp/Controls/RadioButton.h"

class ControlWindow : public Window {
public:
    ControlWindow(HWND handle) : Window(handle) {
        auto button = createButton<Button>(handle);
        button->setPosition(0, 0);
        button->setSize(100, 40);
        button->setText("A button");
        
        auto checkbox = createCheckbox<Checkbox>(handle);
        checkbox->setPosition(100, 0);
        checkbox->setSize(100, 40);
        checkbox->setText("A checkbox");

        auto listbox = createListbox<Listbox>(handle);
        listbox->setPosition(200, 0);
        listbox->setSize(100, 40);
        listbox->sendMessage(LB_ADDSTRING, 0, reinterpret_cast<LPARAM>("A thing"));
        listbox->sendMessage(LB_ADDSTRING, 0, reinterpret_cast<LPARAM>("Thing 2"));

        auto textField = createTextField<TextBox>(handle);
        textField->setPosition(0, 40);
        textField->setSize(100, 20);
        textField->setText("A text box");

        auto radioButton = createRadioButton<RadioButton>(handle);
        radioButton->setPosition(100,40);
        radioButton->setSize(100, 20);
        radioButton->setText("Option 1");

        auto radioButton2 = createRadioButton<RadioButton>(handle);
        radioButton2->setPosition(100,60);
        radioButton2->setSize(100, 20);
        radioButton2->setText("Option 2");
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