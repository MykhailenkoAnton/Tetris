#pragma once

#include "Figure.h"

class Piramide : public Figure
{
private:
    enum class position
    {
        original = 0,
        right_side = 1,
        down = 2,
        left_side = 3,
        undefine = 4
    };
public:
    Piramide();
    void rotate(bool rotate_back = false) override;
    void rotate_to_the_right_side();
    void rotate_to_the_down();
    void rotate_to_the_left_side();
    void rotate_to_the_original_new();
private:
    position current_position_PR = position::original;
    position before_prev_position_PR = position::undefine;
};

