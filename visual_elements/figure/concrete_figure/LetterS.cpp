#include "LetterS.h"

Letter_S::Letter_S()
{
    figure_coord.row[0] = -1;
    figure_coord.column[0] = 13;

    figure_coord.row[1] = -1;
    figure_coord.column[1] = 12;

    figure_coord.row[2] = 0;
    figure_coord.column[2] = 12;

    figure_coord.row[3] = 0;
    figure_coord.column[3] = 11;
}

void Letter_S::rotate(bool rotate_back)
{
    save_old_coord();

    switch (current_position_)
    {
    case position::horizontal:
        rotate_S_to_vertical();
        current_position_ = position::vertical;
        break;
    case position::vertical:
        rotate_S_to_horizontal();
        current_position_ = position::horizontal;
        break;
    default:
        break;
    }
}

void Letter_S::rotate_S_to_vertical()
{
    int row = figure_coord.row[1];
    int column = figure_coord.column[1];

    figure_coord.row[0] = row - 1;
    figure_coord.column[0] = column - 1;

    figure_coord.row[3] = row;
    figure_coord.column[3] = column - 1;
}

void Letter_S::rotate_S_to_horizontal()
{
    int row = figure_coord.row[1];
    int column = figure_coord.column[1];

    figure_coord.row[0] = row;
    figure_coord.column[0] = column + 1;

    figure_coord.row[3] = row + 1;
    figure_coord.column[3] = column - 1;
}