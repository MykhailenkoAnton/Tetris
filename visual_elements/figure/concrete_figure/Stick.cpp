#include "Stick.h"

Stick::Stick()
{
    figure_coord.row[0] = -3;
    figure_coord.column[0] = 12;

    figure_coord.row[1] = -2;
    figure_coord.column[1] = 12;

    figure_coord.row[2] = -1;
    figure_coord.column[2] = 12;

    figure_coord.row[3] = 0;
    figure_coord.column[3] = 12;
}

void Stick::rotate(bool rotate_back)
{
    save_old_coord();

    switch (current_position_)
    {
    case position::vertical:
        rotate_stick_to_horizontal();
        current_position_ = position::horizontal;
        break;
    case position::horizontal:
        rotate_stick_to_vertical();
        current_position_ = position::vertical;
        break;
    default:
        break;
    }
}

void Stick::rotate_stick_to_horizontal()
{
    const int static_block_index = 2;

    figure_coord.row[0] = figure_coord.row[static_block_index];
    figure_coord.column[0] = figure_coord.column[static_block_index] - 2;

    figure_coord.row[1] = figure_coord.row[static_block_index];
    figure_coord.column[1] = figure_coord.column[static_block_index] - 1;

    figure_coord.row[3] = figure_coord.row[static_block_index];
    figure_coord.column[3] = figure_coord.column[static_block_index] + 1;
    
}

void Stick::rotate_stick_to_vertical()
{
    const int static_block_index = 2;

    figure_coord.row[0] = figure_coord.row[static_block_index] - 2;
    figure_coord.column[0] = figure_coord.column[static_block_index];

    figure_coord.row[1] = figure_coord.row[static_block_index] - 1;
    figure_coord.column[1] = figure_coord.column[static_block_index];

    figure_coord.row[3] = figure_coord.row[static_block_index] + 1;
    figure_coord.column[3] = figure_coord.column[static_block_index];
}