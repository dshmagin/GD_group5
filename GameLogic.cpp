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
    return GameState;
}

void GameLogic::initiliaze()
{
    player = Player();
    player.createPlayer(400,300);
}

sf::RectangleShape GameLogic::getPlayer()
{
    return player.getPlayerBody();
}
void GameLogic::movePlayer(char dir, float deltaTime)
{
    player.movePlayer(dir,deltaTime);
}
