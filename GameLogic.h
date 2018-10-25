#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.h"

class GameLogic
{
    private:

        bool gameStatus = false;

        int GameState = 0;

        Player player;


    public:

        GameLogic();

        void  setGameState( int GameState );
        int  getGameState( void );
        void initiliaze();
        sf::RectangleShape getPlayer();
        void movePlayer(char dir,float deltaTime);


};

#endif // GAMELOGIC_H_INCLUDED
