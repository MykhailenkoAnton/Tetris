#pragma once

#include "Figure.h"

class Stick : public Figure
{
private:
    enum class position
    {
        vertical = 0,
        horizontal = 1
    };
public:
    Stick();
    void rotate(bool rotate_back = false) override;
    void rotate_stick_to_horizontal();
    void rotate_stick_to_vertical();
private:
    position current_position_ = position::vertical;
};
