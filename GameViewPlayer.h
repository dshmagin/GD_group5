#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include <SFML/Graphics.hpp>
#include <string>
#include "TitleScreen.h"
#include "GameLogic.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class GameViewPlayer
{
    private:
    //AI Movements
        TitleScreen* menu;

        GameLogic* game;


    public:

        GameViewPlayer(){};
        GameViewPlayer(GameLogic* game);
        void checkKeyEvents( sf::RenderWindow* window , sf::Event Event);
        void setTitleScreen(TitleScreen* screen);

};

#endif

