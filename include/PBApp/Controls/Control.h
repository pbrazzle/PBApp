#pragma once

#include "PBApp/GUIElement.h"

#include <windows.h>
#include <string>

class Control : public GUIElement {
public:
    Control(HWND handle);

    void setPosition(unsigned int x, unsigned int y);

    void setSize(unsigned int width, unsigned int height);

    void setText(const std::string& text);

    LRESULT sendMessage(UINT msg, WPARAM wParam = 0, LPARAM lParam = 0);

private:
    HWND handle;
};

template <typename ControlBase, typename ControlDerived>
ControlBase* createControl(HWND parent, const std::string& className, DWORD style);

#include <PBApp/Controls/Control.tpp>