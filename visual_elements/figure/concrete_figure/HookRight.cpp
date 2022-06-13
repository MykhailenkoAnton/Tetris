#include "HookRight.h"

Hook_Right::Hook_Right()
{
    // -2 12 main BLOCK
    figure_coord.row[0] = -2;
    figure_coord.column[0] = 13;

    figure_coord.row[1] = -2;
    figure_coord.column[1] = 12;

    figure_coord.row[2] = -1;
    figure_coord.column[2] = 12;

    figure_coord.row[3] = 0;
    figure_coord.column[3] = 12;
}
void Hook_Right::rotate(bool rotate_back)
{
    save_old_coord();
    if (rotate_back)
    {
        current_position_HR = before_prev_position_HR;
    }
    
    switch (current_position_HR)
    {
    case position::original:
        rotate_hook_to_right_side();
        current_position_HR = position::right_side;
        before_prev_position_HR = position::left_side;
        break;
    case position::right_side:
        rotate_hook_to_down();
        current_position_HR = position::down;
        before_prev_position_HR = position::original;
        break;
    case position::down:
        rotate_hook_to_left_side();
        current_position_HR = position::left_side;
        before_prev_position_HR = position::right_side;
        break;
    case position::left_side:
        rotate_to_original_new();
        current_position_HR = position::original;
        before_prev_position_HR = position::down;
        break;
    default:
        break;
    }
}


void Hook_Right::rotate_hook_to_right_side()
{
    // 001
    //   0
    int row = figure_coord.row[2];
    int column = figure_coord.column[2];

    figure_coord.row[0] = row - 1;
    figure_coord.column[0] = column - 1;

    figure_coord.row[3] = row - 1;
    figure_coord.column[3] = column - 2;
}

void Hook_Right::rotate_hook_to_down()
{
    //  0
    //  1
    // 00
    int row = figure_coord.row[2];
    int column = figure_coord.column[2];

    figure_coord.row[0] = row - 2; 
    figure_coord.column[0] = column; 

    figure_coord.row[3] = row;
    figure_coord.column[3] = column - 1;
}

void Hook_Right::rotate_hook_to_left_side()
{
    // 0 
    // 010
    int row = figure_coord.row[2];
    int column = figure_coord.column[2];

    figure_coord.row[0] = row;
    figure_coord.column[0] = column + 1;

    figure_coord.row[3] = row;
    figure_coord.column[3] = column + 2;
}

void Hook_Right::rotate_to_original_new()
{
    // 10
    // 0
    // 0
    int row = figure_coord.row[2];
    int column = figure_coord.column[2];

    figure_coord.row[0] = row - 1; 
    figure_coord.column[0] = column + 1;

    figure_coord.row[3] = row + 1;
    figure_coord.column[3] = column;
}