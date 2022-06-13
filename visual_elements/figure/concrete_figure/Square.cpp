#include "Square.h"
Square::Square()
{
    figure_coord.row[0] = 0;
    figure_coord.column[0] = 13;

    figure_coord.row[1] = 0;
    figure_coord.column[1] = 12;

    figure_coord.row[2] = 1;
    figure_coord.column[2] = 13;

    figure_coord.row[3] = 1;
    figure_coord.column[3] = 12;
}
void Square::rotate(bool rotate_back)
{
    // nothing to rotate
}