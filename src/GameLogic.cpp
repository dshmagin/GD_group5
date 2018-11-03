#include "GameLogic.h"

using namespace std;

GameLogic::GameLogic(shared_ptr<sf::RenderWindow> &window_ptr)
{
    this -> window_ptr = window_ptr;
    pm = new ProcessManager();
}

void  GameLogic::setGameState( int GameState )
{
    this -> GameState = GameState;
}
int  GameLogic::getGameState()
{
    return GameState;
}

void GameLogic::initiliaze( float bckgW, float bckgH, float screenW, float screenH, float bckgPixSize, float playerW, float playerH )
{
    this -> playerH = playerH;
    this -> playerW = playerW;
    this -> bckgW = bckgW;
    this -> bckgH = bckgH;
    this -> screenH = screenH;
    this -> screenW = screenW;
    this -> bckgPixSize = bckgPixSize;
    player = Player( playerH, playerW);
    player.createPlayer(bckgW/2 + (screenW/2 - playerW/2) ,bckgH/2 + (screenH/2 - playerH/2) );
}

sf::RectangleShape GameLogic::getPlayer()
{
    return player.getPlayerBody();
}
sf::RectangleShape GameLogic::getAttack()
{
    //return (Attack) attack -> getAttackElement();
}
void GameLogic::setDirection(char dir,float deltaTime)
{
    player.setDirection(dir,deltaTime);
}
void GameLogic::createPlayerAttack(char dir, float deltaTime)
{

    shared_ptr<BasicAttack> bAttack =make_shared<BasicAttack>(window_ptr);

    bAttack->createAttack(player.getXPos(), player.getYPos(), dir);
    cout<<" made an attack " << endl;
    pm ->  attachProcess((shared_ptr<Process>) bAttack);



}
void GameLogic::update(float deltaTime)
{
    player.update(deltaTime);
    //attack.update(deltaTime);
    pm -> updateProcessList(deltaTime);
}
void GameLogic::idle()
{
    player.moveKeyIsPressed=false;
}

sf::Vector2f GameLogic::getPlayerCoord()
{
    sf::Vector2f coords(player.getPlayerBody().getPosition().x,player.getPlayerBody().getPosition().y);
    return coords;
}


