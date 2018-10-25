#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include <SFML/Graphics.hpp>
#include <string>
#include "TitleScreen.h"
#include "GameLogic.h"
#include <string>
#include <sstream>
#include <iostream>
#include <memory>

using namespace std;

class GameViewPlayer
{
    private:
    //AI Movements
        TitleScreen* menu;

        GameLogic* game;
        shared_ptr<sf::RenderWindow> window_ptr;

    public:

        GameViewPlayer(){};
        GameViewPlayer(GameLogic* game, shared_ptr<sf::RenderWindow> &window_ptr);
        void checkKeyEvents( sf::Event Event);
        void setTitleScreen(TitleScreen* screen);

};

#endif






