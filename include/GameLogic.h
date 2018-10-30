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

        int GameState = 0;



    public:
        Player player;
        Attack attack;

        GameLogic();

        void  setGameState( int GameState );
        int  getGameState( void );
        void initialize();
        sf::RectangleShape getPlayer();
        void setDirection(char dir, float deltaTime );
        void idle();
        void update(float deltaTime);
        void createPlayerAttack(char, float);


};

#endif // GAMELOGIC_H_INCLUDED
