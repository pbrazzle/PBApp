#pragma once

#include <PBApp/Controls/Control.h>

#include <windows.h>

class Listbox : public Control {
public:
    Listbox(HWND handle) : Control(handle) { }

    virtual void onClick() { }
};

template <typename ListboxType>
Listbox* createListbox(HWND parent) {
    return createControl<Listbox, ListboxType>(parent, "LISTBOX", WS_TABSTOP | WS_VISIBLE | WS_CHILD | LBS_STANDARD);
}