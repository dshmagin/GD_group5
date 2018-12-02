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
    player = Player( playerH, playerW, window_ptr);
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

int GameLogic::createPlayerAttack(char dir, float deltaTime)
{
    if(basicAttackCd > basicAttackTimer)
    {
        basicAttackCd = 0;
        shared_ptr<BasicAttack> bAttack =make_shared<BasicAttack>(window_ptr,startingElement);
        bAttack->createAttack(player.getXPos(), player.getYPos(), dir);
        pm ->  attachProcess((shared_ptr<Process>) bAttack);
	return 1;
    }
    return 0;

}

void GameLogic::createBuff(int buffType)
{
    if (airShieldCd > airShieldTimer) {
        airShieldCd = 0;
        shared_ptr<Buff> buff = make_shared<Buff>(window_ptr, &player);
    	buff->createBuff(buffType);
    	pm->attachProcess((shared_ptr<Process>)buff);
    }
}

void GameLogic::createDash(sf::View* playerView_ptr, sf::RectangleShape* UIIcon_ptr,
		sf::CircleShape* elementalIcon_ptr, sf::CircleShape* itemIcon_ptr) {
	if (dashCd > dashTimer) {
		dashCd = 0;
		shared_ptr<Dash> dash = make_shared<Dash>(window_ptr, &player, playerView_ptr, UIIcon_ptr,
				elementalIcon_ptr, itemIcon_ptr);
		pm->attachProcess((shared_ptr<Process>)dash);
	}
}

void GameLogic::createSplitAttack() {
	if (splitAttackCd > splitAttackTimer) {
		splitAttackCd = 0;
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
    dashCd += deltaTime;
    splitAttackCd += deltaTime;

    player.update(deltaTime);

    if(basicAttackCd > basicAttackTimer)
      basicAttackOnCd = false;
    else
        basicAttackOnCd = true;

    if(airShieldCd > airShieldTimer)
        airShieldOnCd = false;
    else
        airShieldOnCd = true;

    if (dashCd > dashTimer) dashOnCd = false;
    else dashOnCd = true;

    if (splitAttackCd > splitAttackTimer) splitAttackOnCd = false;
    else splitAttackOnCd = true;

    if(pm -> checkEnemies() <= 0)
    {
        changing_level = true;
        transition += deltaTime;

        if(transition >= 1000.0 && !changed_background){
            level++;
            changed_background = true;
        }

        if(transition >= 1500.0){
            wave++;
            startWave();
            transition = 0;
            changing_level = false;
            changed_background = false;
        }
    }
}

void GameLogic::idle()
{
    player.moveKeyIsPressed=false;
}

sf::Vector2f GameLogic::getPlayerCoord()
{
    sf::Vector2f coords(player.getPlayerBody().getPosition().x, player.getPlayerBody().getPosition().y);
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

bool GameLogic::isDashOnCd() {
	return dashOnCd;
}

bool GameLogic::isSplitAttackOnCd() {
	return splitAttackOnCd;
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
    totalEnemies = 10 * wave;

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

bool GameLogic::changingLevel(){
	return changing_level;
}

void GameLogic::useItem()
{
    cout<<"ITEM "<<player.currentItem()<<endl;
    switch(player.currentItem())
    {
        case(Process::RED_ITEM):
            player.healPlayer(25);
            //player
            break;
        case(Process::BLUE_ITEM):
            cout<<" ITEM IS USED"<<endl;
            airShieldCd += 30000;
            basicAttackCd += 30000;
            basicAttackOnCd = false;
            airShieldOnCd = false;
            break;
        case(Process::YELLOW_ITEM):
            shared_ptr<Buff> buff = make_shared<Buff>(window_ptr, &player);
            buff->createBuff(1);
            pm->attachProcess((shared_ptr<Process>)buff);
            break;
    }
    
    player.item(Process::NONE);

    cout<<"ITEM USED"<<endl;
}
