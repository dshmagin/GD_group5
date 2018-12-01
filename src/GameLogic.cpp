#include "GameLogic.h"
#include "RangedEnemy.h"

using namespace std;

GameLogic::GameLogic(shared_ptr<sf::RenderWindow> &window_ptr, shared_ptr<ProcessManager> &pm)
{
    this -> window_ptr = window_ptr;
    this -> pm = pm;
    this -> pm -> setRenderWindow(window_ptr);
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
    // need to refactor
    pm->setPlayer(&player);
}

sf::RectangleShape GameLogic::getPlayer()
{
    return player.getPlayerBody();
}
sf::RectangleShape GameLogic::getAttack()
{
    //return (Attack) attack -> getAttackElement();
}
void GameLogic::setDirection(int dir,float deltaTime)
{
    player.setDirection(dir,deltaTime);
}
void GameLogic::createPlayerAttack(char dir, float deltaTime)
{
    if(basicAttackCd > basicAttackTimer)
    {
        basicAttackCd = 0;
        shared_ptr<BasicAttack> bAttack =make_shared<BasicAttack>(window_ptr,startingElement);
        bAttack->createAttack(player.getXPos(), player.getYPos(), dir);
        pm ->  attachProcess((shared_ptr<Process>) bAttack);
    }

}

void GameLogic::createBuff(int buffType) {


	if (airShieldCd > 30000) {
		airShieldCd = 0;
		shared_ptr<Buff> buff = make_shared<Buff>(window_ptr, &player);
		buff->createBuff(buffType);
		pm->attachProcess((shared_ptr<Process>)buff);
	}
}

void GameLogic::createRangedEnemy()
{
    shared_ptr<RangedEnemy> rEnemy = make_shared<RangedEnemy>(window_ptr,startingElement);
    rEnemy->createRangedEnemy(this);
    pm ->  attachProcess((shared_ptr<Process>) rEnemy);
}
void GameLogic::update(float deltaTime)
{
    basicAttackCd += deltaTime;
    airShieldCd += deltaTime;

    player.update(deltaTime);

    if(basicAttackCd > basicAttackTimer)
      basicAttackOnCd = false;
    else
        basicAttackOnCd = true;

    if(airShieldCd > airShieldTimer)
        airShieldOnCd = false;
    else
        airShieldOnCd = true;

    if(pm -> checkEnemies() <= 0)
    {
        wave++;
        startWave();
        level++;
    }

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

int GameLogic::getStartingElement()
{
    return startingElement;
}
bool GameLogic::isBasicAttackOnCd()
{
    return basicAttackOnCd;
}
bool GameLogic::isAirShieldOnCd()
{
    return airShieldOnCd;
}
void GameLogic::setStartingElement(int startingElement)
{
    this -> startingElement = startingElement;
}
void GameLogic::resetPlayer()
{
    player.reset(bckgW/2 + (screenW/2 - playerW/2) ,bckgH/2 + (screenH/2 - playerH/2) );
}
void GameLogic::grabItem()
{
    int curItem = pm ->itemNearBy(getPlayer());
    if(curItem > 0)
    {
        player.item(curItem);
    }
}

void GameLogic::clearGame()
{
    pm -> clearManager();
    player.item( Process::NONE );
}

void GameLogic::setLevel(int level)
{
    this -> level = level;
    this -> wave = 1;
}
int GameLogic::getLevel()
{
    return level;
}

void GameLogic::startWave()
{
    totalEnemies = 1 * wave;

    cout<<"totalEnemies enemy " << totalEnemies << endl;
    for (int enemies = 0; enemies<totalEnemies; enemies++)
    {
        cout<<"Created enemy " << enemies << endl;
        createRangedEnemy();
    }

}

bool GameLogic::isPaused() {
	return paused;
}
