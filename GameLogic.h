#ifndef GAMELOGIC_H_INCLUDED
#define GAMELOGIC_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class GameLogic
{
    private:

        bool gameStatus = false;

        int GameState = 0;


    public:

        GameLogic();

        int  setGameState( int GameState );
        int  getGameState( void );


};

#endif // GAMELOGIC_H_INCLUDED
