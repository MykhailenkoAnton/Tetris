#include "Menu.h"
#include <iostream>
#include <time.h>
#include <string>
int gametime = 0;
int getTime(int gametime);
extern unsigned long gamepoints;
Menu::Menu()
{
    menu[0].line = "<<< MENU >>>";
    menu[0].x = 0;
    menu[0].y = 38;

    menu[1].line = "Press \'W\' to TURN OVER figure";
    menu[1].x = 2;
    menu[1].y = 30;

    menu[2].line = "Press \'S\' to SPEED UP figure";
    menu[2].x = 4;
    menu[2].y = 30;

    menu[3].line = "Press \'A\' to MOVE LEFT figure";
    menu[3].x = 6;
    menu[3].y = 30;

    menu[4].line = "Press \'D\' to MOVE RIGHT figure";
    menu[4].x = 8;
    menu[4].y = 30;

    menu[5].line = "Press \'0\' to EXIT";
    menu[5].x = 10;
    menu[5].y = 36;

    menu[6].line = "Game time: ";
    menu[6].x = 14;
    menu[6].y = 30;

    menu[7].line = "Game points: ";
    menu[7].x = 16;
    menu[7].y = 30;

    gametime = getTime(gametime);
    std::string gm_points = std::to_string(gamepoints);
    std::string gm_time = std::to_string(gametime);

    menu[8].line = gm_time + " second"; //
    menu[8].x = 14;
    menu[8].y = 41;

    menu[9].line = gm_points;
    menu[9].x = 16;
    menu[9].y = 43;

    menu[10].line = "GAME IS OVER, GOOD BYE!";
    menu[10].x = 7;
    menu[10].y = 35;

    menu[11].line = "Your gametime: " + gm_time + " second";
    menu[11].x = 9;
    menu[11].y = 35;

    menu[12].line = "You have points: " + gm_points;
    menu[12].x = 11;
    menu[12].y = 35;
}

void Menu::getMenu(MenuLine * mn)
{
    for (int i = 0; i < SIZE_MENU_LINE; i++)
    {
        mn[i].line = menu[i].line;
        mn[i].x =  menu[i].x;
        mn[i].y = menu[i].y;
    }
}

int getTime(int gametime)
{
    int int_time;
    clock_t end = clock() / CLOCKS_PER_SEC;
    int_time = static_cast<int> (end);
    return int_time;
}