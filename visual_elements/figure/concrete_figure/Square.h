#pragma once

#include "Figure.h"

class Square : public Figure
{
public:
    Square();
    void rotate(bool rotate_back = false) override;
};