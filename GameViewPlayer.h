#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Paddle.h"
#include "Ball.h"
#include "GameViewAI.h"
#include "GameLogic.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class GameViewPlayer
{
    private:
    //AI Movements
        float xmovment = 0.02f;
        float xmovment2 = 0.02f;
        float enemyVal = 0.0f;
        bool leftFeet = false;
        bool pause = false;
        bool pauseSound = true;


        //Variables passed by GameApp
        float deltaTime;


        GameLogic* game;

        //Background AI's
        sf::Texture bckgText;
        sf::Texture npcShroom;
        sf::Texture npcEnemy;
        sf::Texture npcEnemy2;
        sf::Sprite  shroom1;
        sf::Sprite  shroom2;
        sf::Sprite  enemy1;

        //Background and score
        sf::Sprite background;
        sf::Font font;
        sf::Text leftScore;
        sf::Text rightScore;

    public:

        GameViewPlayer(){};
        GameViewPlayer(GameLogic* game);

        void setFont(void);
        void updateGVP(float deltaTime,sf::RenderWindow* window);
        void moveAI(float timeDelta);
        void updateScore(int player, int score);
        void checkKeyEvents( sf::RenderWindow* window );
        bool isPaused( void );
        ~GameViewPlayer();
};

#endif

