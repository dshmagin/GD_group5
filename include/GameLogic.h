#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "BasicAttack.h"
#include "Buff.h"
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
        bool airShieldOnCd = false;
        bool dashOnCd = false;
        bool splitAttackOnCd = false;
        float bckgW, bckgH, screenW, screenH, bckgPixSize;
        float playerW,playerH;
        int GameState = 0;
        int level = 1;
        int wave = 1;
        float basicAttackCd = 600;
        float airShieldCd= 30000;
        float basicAttackTimer= 600;
        float airShieldTimer = 30000;
        float dashCd = 8000;
        float dashTimer = 8000;
        float splitAttackCd = 5000;
        float splitAttackTimer = 5000;
        bool paused = false;
        shared_ptr<ProcessManager> pm;
        shared_ptr<sf::RenderWindow> window_ptr;
        bool changing_level = false;
        bool changed_background = false;
        float transition = 0;

    public:
        Player player;
        int totalEnemies;
        //BasicAttack bAttack;

        GameLogic();
        GameLogic(shared_ptr<sf::RenderWindow> &window_ptr, shared_ptr<ProcessManager> &pm);

        bool isBasicAttackOnCd();
        bool isAirShieldOnCd();
        bool isDashOnCd();
        bool isSplitAttackOnCd();
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
        int createPlayerAttack(char, float);
        void createBuff(int buffType);
        void createDash(sf::View* playerView_ptr, sf::RectangleShape* UIIcon_ptr,
        		sf::CircleShape* elementalIcon_ptr, sf::CircleShape* itemIcon_ptr);
        void createSplitAttack();
        void createRangedEnemy();
        void setStartingElement(int startingElement);
        void resetPlayer();
        void grabItem();
        void clearGame();
        void startWave();
        void setLevel(int level);
        int  getLevel();
        bool isPaused();
        void useItem();
        //void dropItem(loc_x, loc_y);
        bool changingLevel();



};

#endif // GAMELOGIC_H_INCLUDED
