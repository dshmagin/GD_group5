#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "BasicAttack.h"
//#include "RangedEnemy.h"
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
        int level = 1;
        int wave = 1;
        float basicAttackCd = 300;
        shared_ptr<ProcessManager> pm;
        shared_ptr<sf::RenderWindow> window_ptr;



    public:
        Player player;
        int totalEnemies;
        //BasicAttack bAttack;

        GameLogic();
        GameLogic(shared_ptr<sf::RenderWindow> &window_ptr, shared_ptr<ProcessManager> &pm);

        bool isBasicAttackOnCd();
        int getStartingElement();
        int  getGameState( void );
        sf::RectangleShape getPlayer();
        sf::RectangleShape getAttack();
        sf::Vector2f getPlayerCoord();
        void setGameState( int GameState );
        void initiliaze(float bckgW, float bckgH, float screenW, float screenH, float bckgPixSize, float playerW, float playerH);
        void setDirection(int dir, float deltaTime );
        void idle();
        void update(float deltaTime);
        void createPlayerAttack(char, float);
        void createRangedEnemy();
        void setStartingElement(int startingElement);
        void resetPlayer();
        void grabItem();
        void clearGame();
        void startWave();
        void setLevel(int level);
        int  getLevel();
        //void dropItem(loc_x, loc_y);




};

#endif // GAMELOGIC_H_INCLUDED
