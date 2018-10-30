#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Attack.h"

class GameLogic
{
    private:

        bool gameStatus = false;
        float bckgW, bckgH, screenW, screenH, bckgPixSize;
        float playerW,playerH;
        int GameState = 0;



    public:
        Player player;
        Attack attack;

        GameLogic(){};

        void  setGameState( int GameState );
        int  getGameState( void );

        void initiliaze(float bckgW, float bckgH, float screenW, float screenH, float bckgPixSize, float playerW, float playerH);


        sf::RectangleShape getPlayer();
        void setDirection(char dir, float deltaTime );
        void idle();
        void update(float deltaTime);

        sf::Vector2f getPlayerCoord();

        void createPlayerAttack(char, float);



};

#endif // GAMELOGIC_H_INCLUDED
