#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "BasicAttack.h"
#include "Buff.h"
#include "Dash.h"
#include "SplitAttack.h"
//#include "RangedEnemy.h"
#include "ProcessManager.h"
#include "EnemyAttackManager.h"
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

        bool abilityOnCd = false;
        int score = 0;
        int enemyCounter;
        float bckgW, bckgH, screenW, screenH, bckgPixSize;
        float playerW,playerH;
        int GameState = 0;
        int level = 4;
        int wave = 1;
        float basicAttackCd = 600;
        float abilityCd;
        float abilityTimer;
        float basicAttackTimer= 600;
        float airShieldTimer = 20000;
        float dashTimer = 8000;
        float healTimer = 10000;
        float splitAttackTimer = 6000;
        float redPotion = 25.0;
        float waterHeal = 50.0;
        bool paused = false;
        shared_ptr<ProcessManager> pm;
        shared_ptr<sf::RenderWindow> window_ptr;
        shared_ptr<EnemyAttackManager> enemyPM;
        bool changing_level = false;
        bool changed_background = false;
        float transition = 0;
        bool game_completed = false;

    public:
        Player player;
        int totalEnemies;
        int meleeEnemies;
        int bossEnemies;
        int rangedEnemies;
        //BasicAttack bAttack;

        GameLogic();
        GameLogic(shared_ptr<sf::RenderWindow> &window_ptr, shared_ptr<ProcessManager> &pm, shared_ptr<EnemyAttackManager> &enemyPM);
        void createBossAttackCircle( float x_pos, float y_pox);
        bool isBasicAttackOnCd();
        bool isAbilityOnCd();
        int getStartingElement();
        int  getGameState( void );
        sf::RectangleShape getPlayer();
        sf::RectangleShape getAttack();
        sf::Vector2f getPlayerCoord();
        void setGameState( int GameState );
        void initiliaze(float bckgW, float bckgH, float screenW, float screenH, float bckgPixSize, float playerW, float playerH);
        void setDirection(int dir, float deltaTime );
        void idle();
        int getScore();
        void setScore(int score);
        void update(float deltaTime);
        int createPlayerAttack(char, float);
        void createBuff(int buffType);
        void createHeal();
        void createDash(sf::View* playerView_ptr, sf::RectangleShape* UIIcon_ptr,
        		sf::CircleShape* elementalIcon_ptr, sf::CircleShape* abilityIcon_ptr,
				sf::CircleShape* itemIcon_ptr);
        void createSplitAttack();
        void createRangedEnemy();
        void createMeleeEnemy();
        void createBossEnemy();
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
        bool completedGame();

        void resetCd();
        void updateCd(float deltaTime);




};

#endif // GAMELOGIC_H_INCLUDED
