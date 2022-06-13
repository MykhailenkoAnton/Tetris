#pragma once

#include "Figure.h"

class Letter_S : public Figure
{
private:
    enum class position
    {
        horizontal = 0,
        vertical = 1
    };
public:
    Letter_S();
    void rotate(bool rotate_back = false) override;
    void rotate_S_to_vertical();
    void rotate_S_to_horizontal();
private:
    position current_position_ = position::horizontal;
};
