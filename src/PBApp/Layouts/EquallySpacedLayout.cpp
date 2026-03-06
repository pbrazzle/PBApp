#include <PBApp/Layouts/EquallySpacedLayout.h>

#include <PBApp/Controls/Button.h>

void EquallySpacedLayout::add(Button* button) {
    buttons.push_back(button);
}

// Equally spaced horizontally, use full height
void EquallySpacedLayout::update(unsigned int width, unsigned int height) {
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