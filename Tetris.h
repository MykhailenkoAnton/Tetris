#pragma once

#include "Field.h"
#include "Figure.h"

enum class eActions
{
    NO_ACTION = 0,
    LEFT = 1,
    RIGHT = 2,
    UP = 3,
    DOWN = 4
};

class Tetris
{
public:
    Tetris();
    void run();
    
private:
    void update_figure_on_field(Figure *figure);
    void sleep_and_proccess_user_action(Figure *active_figure);
    eActions read_user_input();
    Figure * get_random_figure();
private:
    Field field_;
};