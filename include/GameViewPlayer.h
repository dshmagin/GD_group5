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
        sf::Texture bckgText;
        sf::RectangleShape background;
        sf::View playerView;
        GameLogic* game;
        float bckgW = 2400.0f;
        float bckgH = 1800.0f;
        float screenW = 800.0f;
        float screenH = 600.0;
        float bckgPixSize = 32.0f;
        float playerW = 64.0f;
        float playerH = 128.0f;
        float camXview = bckgW/2;
        float camYview = bckgH/2;
        float camMoveSpeed = 0.3f;
        bool movingX;
        bool movingY;
        shared_ptr<sf::RenderWindow> window_ptr;

    public:

        GameViewPlayer(){};
        GameViewPlayer(GameLogic* game, shared_ptr<sf::RenderWindow> &window_ptr);
        void checkKeyEvents( float deltaTime);
        void setTitleScreen(TitleScreen* screen);
        void update(float deltaTime);

};

#endif






