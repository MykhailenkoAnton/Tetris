#pragma once
#include <string>
const int SIZE_MENU_LINE = 13;
struct MenuLine
{
    std::string line;
    int x;
    int y;
};

class Menu
{
private:
    MenuLine menu[SIZE_MENU_LINE];
public:
    Menu();
    void getMenu(MenuLine * mn);
};

