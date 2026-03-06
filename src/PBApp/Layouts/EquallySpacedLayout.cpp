#include <PBApp/Layouts/EquallySpacedLayout.h>

#include <PBApp/Controls/Button.h>

void EquallySpacedLayout::add(Control* button) {
    controls.push_back(button);
}

// Equally spaced horizontally, use full height
void EquallySpacedLayout::update(unsigned int width, unsigned int height) {
    auto baseWidth = width / controls.size();
    auto extraWidth = width % controls.size();

    unsigned int currentX = 0;
    for (auto control : controls) {
        auto bWidth = baseWidth + (extraWidth ? 1 : 0);
        control->setSize(bWidth, height);
        control->setPosition(currentX, 0);

        extraWidth -= (extraWidth) ? 1 : 0;
        currentX += bWidth;
    }
}