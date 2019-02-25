#ifndef MENU_H
#define MENU_H
#include "GameControl.h"

struct Menu: public MiniGame
{
    
    int total_options = 2;
    char Choose[17] = "Alege un joc: ";
    char Options[2][17] =  {"AsteroidStorm|1P", "Coming soon.."};

    void init();
    void update();
    void gameOver() {}
}M;

int game_index = 0;
int menu_index = 1;


void Plus() 
{
    if(menu_index < M.total_options)
    menu_index++;
}

void Minus()
{
    if(menu_index > 1)
        menu_index --;
}

void select() {game_index = menu_index;}

void Menu::init()
{
    menu_index = 1;
    Ctrl->Joy->initV (Minus, Plus);
    Ctrl->set_buttons_actions (select, select);
    Ctrl->set_joy_buttons_actions(select, select);
    Ctrl->LCD->setString(0,Choose);

    currState = UPDATE;
}

void Menu::update() 
{
    Ctrl->checkAll();
    Ctrl->LCD->setString(1, Options[menu_index-1]);
}

#endif //MENU_H