#include "GameLogic.h"

using namespace std;

GameLogic::GameLogic()
{

}



void  GameLogic::setGameState( int GameState )
{
    this -> GameState = GameState;
}
int  GameLogic::getGameState()
{
    return this -> GameState;
}

