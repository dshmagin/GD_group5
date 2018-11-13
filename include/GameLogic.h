#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "BasicAttack.h"
#include "ProcessManager.h"
#include <memory>

#include <string>
#include <sstream>
#include <iostream>
class GameLogic
{
    private:
        int  startingElement ;
        bool gameStatus = false;
        bool basicAttackOnCd = false;
        float bckgW, bckgH, screenW, screenH, bckgPixSize;
        float playerW,playerH;
        int GameState = 0;
        float basicAttackCd = 300;
        shared_ptr<ProcessManager> pm;
        shared_ptr<sf::RenderWindow> window_ptr;



    public:
        Player player;
        //BasicAttack bAttack;

        GameLogic();
        GameLogic(shared_ptr<sf::RenderWindow> &window_ptr, shared_ptr<ProcessManager> &pm);

        void setGameState( int GameState );
        int  getGameState( void );

        void initiliaze(float bckgW, float bckgH, float screenW, float screenH, float bckgPixSize, float playerW, float playerH);


        sf::RectangleShape getPlayer();
        sf::RectangleShape getAttack();
        void setDirection(int dir, float deltaTime );
        void idle();
        void update(float deltaTime);

        sf::Vector2f getPlayerCoord();

        void createPlayerAttack(char, float);
        int getStartingElement();
        bool isBasicAttackOnCd();
        void setStartingElement(int startingElement);
        void resetPlayer();




};

#endif // GAMELOGIC_H_INCLUDED
