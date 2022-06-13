#pragma once
#include <iostream>
const int BLOCK_COUNT = 4;

struct coord
{
    int row[BLOCK_COUNT] = {-1, -1, -1, -1};
    int column[BLOCK_COUNT] = {-1, -1, -1, -1};
};

class Figure
{
public:
    virtual void rotate(bool rotate_back = false) = 0;

    coord get_figure_coord() const;
    coord get_figure_coord_old() const;

    void move_down();
    void move_left();
    void move_right();

    void save_old_coord();

    bool is_block_from_same_figure(int row_to_check, int column_to_check) const;

protected:
    coord figure_coord;
    coord figure_coord_old;
};