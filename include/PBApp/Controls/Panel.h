#pragma once

#include <PBApp/Controls/Control.h>

#include <windows.h>

class Panel : public Control {
public:
    Panel(HWND handle) : Control(handle) { }

    virtual void onClick() { }
};

template <typename PanelType>
Panel* createPanel(HWND parent) {
    return createControl<Panel, PanelType>(parent, "STATIC", WS_VISIBLE | WS_CHILD | SS_BLACKFRAME);
}