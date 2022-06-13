#include "Piramide.h"

Piramide::Piramide()
{
    //  0
    // 213
    figure_coord.row[0] = -1;
    figure_coord.column[0] = 12;

    figure_coord.row[1] = 0;
    figure_coord.column[1] = 12;

    figure_coord.row[2] = 0;
    figure_coord.column[2] = 11;

    figure_coord.row[3] = 0;
    figure_coord.column[3] = 13;
}

void Piramide::rotate(bool rotate_back)
{
    save_old_coord();

    if (rotate_back)
    {
        current_position_PR = before_prev_position_PR;
    }

    switch (current_position_PR)
    {
    case position::original:
        rotate_to_the_right_side();
        current_position_PR = position::right_side;
        before_prev_position_PR = position::left_side;
        break;
    case position::right_side:
        rotate_to_the_down();
        current_position_PR = position::down;
        before_prev_position_PR = position::original;
        break;
    case position::down:
        rotate_to_the_left_side();
        current_position_PR = position::left_side;
        before_prev_position_PR = position::right_side;
        break;
    case position::left_side:
        rotate_to_the_original_new();
        current_position_PR = position::original;
        before_prev_position_PR = position::down;
        break;
    default:
        break;
    }
}

void Piramide::rotate_to_the_right_side()
{
    int row = figure_coord.row[1];
    int column = figure_coord.column[1];

    figure_coord.row[0] = row - 1;
    figure_coord.column[0] = column;

    figure_coord.row[2] = row;
    figure_coord.column[2] = column + 1;

    figure_coord.row[3] = row + 1;
    figure_coord.column[3] = column;
}

void Piramide::rotate_to_the_down()
{
    int row = figure_coord.row[1];
    int column = figure_coord.column[1];

    figure_coord.row[0] = row;
    figure_coord.column[0] = column + 1;

    figure_coord.row[2] = row + 1;
    figure_coord.column[2] = column;

    figure_coord.row[3] = row;
    figure_coord.column[3] = column - 1;
}

void Piramide::rotate_to_the_left_side()
{
    int row = figure_coord.row[1];
    int column = figure_coord.column[1];

    figure_coord.row[0] = row - 1;
    figure_coord.column[0] = column;

    figure_coord.row[2] = row + 1;
    figure_coord.column[2] = column;

    figure_coord.row[3] = row;
    figure_coord.column[3] = column - 1;
}

void Piramide::rotate_to_the_original_new()
{
    int row = figure_coord.row[1];
    int column = figure_coord.column[1];

    figure_coord.row[0] = row - 1;
    figure_coord.column[0] = column;

    figure_coord.row[2] = row;
    figure_coord.column[2] = column + 1;

    figure_coord.row[3] = row;
    figure_coord.column[3] = column - 1;
}