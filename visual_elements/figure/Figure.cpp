#include "Figure.h"


coord Figure::get_figure_coord() const
{
    return figure_coord;
}

coord Figure::get_figure_coord_old() const
{
    return figure_coord_old;
}

void Figure::move_down()
{
    save_old_coord();

    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        figure_coord.row[i]++;
    }
}

void Figure::move_left()
{
    save_old_coord();

    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        figure_coord.column[i]--;
    }
}

void Figure::move_right()
{
    save_old_coord();

    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        figure_coord.column[i]++;
    }
}

void Figure::save_old_coord()
{
    for (int i = 0; i < BLOCK_COUNT; i++)
    {
        figure_coord_old.row[i] = figure_coord.row[i];
        figure_coord_old.column[i] = figure_coord.column[i];
    }
}

bool Figure::is_block_from_same_figure(int row_to_check, int column_to_check) const
{
    // Check that block below not from current figure.
    for (int other_block_index = 0; other_block_index < BLOCK_COUNT; other_block_index++)
    {
        const int other_block_row = figure_coord.row[other_block_index];
        const int other_block_column = figure_coord.column[other_block_index];

        const bool same_row = row_to_check == other_block_row;
        const bool same_column = column_to_check == other_block_column;
        if (same_row && same_column)
        {
            return true;
        }
    }

    return false;
}

