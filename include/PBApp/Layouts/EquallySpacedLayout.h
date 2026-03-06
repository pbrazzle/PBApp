#pragma once

#include <PBApp/Layouts/Layout.h>

#include <PBApp/Controls/Control.h>

#include <vector>

class Button;

class EquallySpacedLayout : public Layout {
public:
    EquallySpacedLayout() = default;

    void add(Control* control);

    // Equally spaced horizontally, use full height
    void update(unsigned int width, unsigned int height);

private:
    std::vector<Control*> controls;
};