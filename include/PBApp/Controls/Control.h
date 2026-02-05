#pragma once

#include <windows.h>
#include <string>

class Control {
public:
    Control(HWND handle);

    void setPosition(unsigned int x, unsigned int y);

    void setSize(unsigned int width, unsigned int height);

    void setText(const std::string& text);

private:
    HWND handle;
};

template <typename ControlBase, typename ControlDerived>
ControlBase* createControl(HWND parent, const std::string& className, DWORD style) {
    HWND handle = CreateWindow(className.c_str(), 
            "", 
            style, 
            0, 
            0, 
            1,
            1, 
            parent, 
            NULL, 
            GetModuleHandle(NULL), 
            NULL);

    ControlBase* control = new ControlDerived(handle);
    SetWindowLongPtr(handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(control));
        
    return control;
}