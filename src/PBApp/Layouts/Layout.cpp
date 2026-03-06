#include <PBApp/Layouts/Layout.h>

#include <unordered_map>

namespace {
    std::unordered_map<HWND, Layout*> windowLayouts;
}

void setLayout(HWND handle, Layout* layout) {
    windowLayouts[handle] = layout;
}

void updateWindowLayout(HWND handle, unsigned int width, unsigned int height) {
    if (!windowLayouts.contains(handle)) return;
    windowLayouts[handle]->update(width, height);
}