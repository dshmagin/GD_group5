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

void GameLogic::initialize()
{
    player = Player();
    player.createPlayer(400,300);
}

sf::RectangleShape GameLogic::getPlayer()
{
    return player.getPlayerBody();
}
void GameLogic::setDirection(char dir,float deltaTime)
{
    player.setDirection(dir,deltaTime);
}
void GameLogic::playerAttack(char dir,float deltaTime)
{

}
void GameLogic::update(float deltaTime)
{
    player.update(deltaTime);
}
void GameLogic::idle()
{
    player.moveKeyIsPressed=false;
}
