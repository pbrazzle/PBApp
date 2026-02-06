#pragma once

#include <vector>

class Button;

// TODO: Rename to make type of Layout more clear
class Layout {
public:
    Layout() = default;

    void add(Button* button);

    // Equally spaced horizontally, use full height
    void update(unsigned int width, unsigned int height);

private:
    std::vector<Button*> buttons;
};