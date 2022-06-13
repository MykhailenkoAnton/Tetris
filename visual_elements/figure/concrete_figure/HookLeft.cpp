#include "HookLeft.h"

Hook_Left::Hook_Left()
{
    figure_coord.row[0] = -2;
    figure_coord.column[0] = 11;

    figure_coord.row[1] = -2;
    figure_coord.column[1] = 12;

    figure_coord.row[2] = - 1;
    figure_coord.column[2] = 12;

    figure_coord.row[3] = 0;
    figure_coord.column[3] = 12;
}
void Hook_Left::rotate(bool rotate_back)
{
    save_old_coord();
    if (rotate_back)
    {
        current_position_HL = before_prev_position_HL;
    }

    switch (current_position_HL)
    {
    case position::original:
        rotate_hook_to_right_side();
        current_position_HL = position::right_side;
        before_prev_position_HL = position::left_side;
        break;
    case position::right_side:
        rotate_hook_to_down();
        current_position_HL = position::down;
        before_prev_position_HL = position::original;
        break;
    case position::down:
        rotate_hook_to_left_side();
        current_position_HL = position::left_side;
        before_prev_position_HL = position::right_side;
        break;
    case position::left_side:
        rotate_to_original_new();
        current_position_HL = position::original;
        before_prev_position_HL = position::down;
        break;
    default:
        break;
    }
}

void Hook_Left::rotate_hook_to_right_side()
{
    int row = figure_coord.row[2];
    int column = figure_coord.column[2];

    figure_coord.row[0] = row;
    figure_coord.column[0] = column - 1;

    figure_coord.row[3] = row;
    figure_coord.column[3] = column - 2;
}

void Hook_Left::rotate_hook_to_down()
{
    int row = figure_coord.row[2];
    int column = figure_coord.column[2];

    figure_coord.row[0] = row - 2;
    figure_coord.column[0] = column;

    figure_coord.row[3] = row;
    figure_coord.column[3] = column + 1;
}

void Hook_Left::rotate_hook_to_left_side()
{
    int row = figure_coord.row[2];
    int column = figure_coord.column[2];

    figure_coord.row[0] = row - 1;
    figure_coord.column[0] = column + 1;

    figure_coord.row[3] = row - 1;
    figure_coord.column[3] = column + 2;
}

void Hook_Left::rotate_to_original_new()
{
    int row = figure_coord.row[2];
    int column = figure_coord.column[2];

    figure_coord.row[0] = row - 1;
    figure_coord.column[0] = column - 1;

    figure_coord.row[3] = row + 1;
    figure_coord.column[3] = column;
}