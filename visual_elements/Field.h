#pragma once

#include "Figure.h"

const int ROWS = 20;
const int COLUMNS = 25;
const int COLUMNS_FULL_FIELD = 70;


class Field
{
public:
    Field();

    void show_menu(bool menu_status);
    bool check_first_row_to_the_availability_BLOCK();

    void clear_menu_lines();
    void draw_field();
    void update_new_figure_coord(const Figure *figure);
    void clear_old_figure_coord(const Figure *figure);

    bool is_possible_to_move_down(const Figure *figure);
    bool is_possible_to_move_left(const Figure *figure);
    bool is_possible_to_move_right(const Figure *figure);
    bool is_possible_to_rotate(Figure *figure);

    void clear_lines_and_move_BLOCK_down();
    void clear_one_line(int x);
    void move_field_down_after_clear(int x);
private:
    bool is_possible_to_rotate_on_figure(Figure *figure);
    bool is_possible_to_rotate_on_border(Figure *figure);

    bool is_border_from_bottom(const Figure *figure);
    bool is_border_on_left_side(const Figure *figure);
    bool is_border_on_right_side(const Figure *figure);

    bool is_other_figure_from_bottom(const Figure *figure);
    bool is_other_figure_on_left_side(const Figure *figure);
    bool is_other_figure_on_right_side(const Figure *figure);

    void fill_field_by_default();

private:
    char FIELD[ROWS][COLUMNS_FULL_FIELD];
};