#include "GameLogic.h"
#include "RangedEnemy.h"
#include "BossEnemy.h"
#include "DmgDisplay.h"
#include "MeleeEnemy.h"
#include "BossAttack.h"

using namespace std;

GameLogic::GameLogic(shared_ptr<sf::RenderWindow> &window_ptr, shared_ptr<ProcessManager> &pm, shared_ptr<EnemyAttackManager> &enemyPM)
{
    this -> window_ptr = window_ptr;
    this -> enemyPM = enemyPM;
    this -> pm = pm;
    this -> pm -> setRenderWindow(window_ptr);
    this -> enemyPM -> setEnemyManager(window_ptr, &player);
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

void GameLogic::createEnemyAttack(float x_pos, float y_pos, char dir, float deltaTime)
{
        shared_ptr<BasicAttack> ebAttack =make_shared<BasicAttack>(window_ptr,startingElement);
        ebAttack->createAttack(x_pos, y_pos, dir);
        enemyPM ->  attachProcess((shared_ptr<Process>) ebAttack);
}

void GameLogic::createDash(sf::View* playerView_ptr, sf::RectangleShape* UIIcon_ptr,
		sf::CircleShape* elementalIcon_ptr, sf::CircleShape* abilityIcon_ptr,
		sf::CircleShape* itemIcon_ptr) {
	if (abilityCd > abilityTimer) {
		abilityCd = 0;
		shared_ptr<Dash> dash = make_shared<Dash>(window_ptr, &player, playerView_ptr, UIIcon_ptr,
				elementalIcon_ptr, abilityIcon_ptr, itemIcon_ptr);
		pm->attachProcess((shared_ptr<Process>) dash);
	}
}
void GameLogic::createHeal() {
	if (abilityCd > abilityTimer) {
		abilityCd = 0;
        shared_ptr<DmgDisplay> displayHeal = make_shared<DmgDisplay>(window_ptr);
        displayHeal -> createText(getPlayer().getPosition().x  , getPlayer().getPosition().y , Process::HEAL , waterHeal);
        pm ->  attachProcess((shared_ptr<Process>) displayHeal);
		player.healPlayer(waterHeal);
	}
}

void GameLogic::createSplitAttack() {
	if (abilityCd > abilityTimer) {
		abilityCd = 0;
		for (int i = 0; i < 3; i++) {
			shared_ptr<SplitAttack> splitAttack = make_shared<SplitAttack>(window_ptr, i *  120 + 30, &player);
			pm -> attachProcess((shared_ptr<Process>) splitAttack);
		}
	}
}

void GameLogic::createBuff(int buffType) {
    if (abilityCd > abilityTimer) {
        abilityCd = 0;
        shared_ptr<Buff> buff = make_shared<Buff>(window_ptr, &player);
    	buff->createBuff(buffType);
    	pm->attachProcess((shared_ptr<Process>)buff);
    }
}
void GameLogic::createBossEnemy()
{
    shared_ptr<BossEnemy> bEnemy = make_shared<BossEnemy>(window_ptr, startingElement, getLevel(), enemyPM);
    bEnemy->createRangedEnemy(this);
    pm ->  attachProcess((shared_ptr<Process>) bEnemy);
}

void GameLogic::createBossAttackCircle( float x_pos, float y_pos) {
    cout<< " why is this called" << endl;
    /*
	if (abilityCd > abilityTimer) {
		abilityCd = 0;
		for (int i = 0; i < 1; i++) {
				shared_ptr<SplitAttack> splitAttack = make_shared<SplitAttack>(window_ptr, i *  120 + 30, &player);
                pm -> attachProcess((shared_ptr<Process>) splitAttack);
		}
	}
	*/
}

void GameLogic::createRangedEnemy()
{
    shared_ptr<RangedEnemy> rEnemy = make_shared<RangedEnemy>(window_ptr, getLevel(), enemyPM);
    rEnemy->createRangedEnemy(this);
    pm ->  attachProcess((shared_ptr<Process>) rEnemy);
}

void GameLogic::createMeleeEnemy()
{
    shared_ptr<MeleeEnemy> mEnemy = make_shared<MeleeEnemy>(window_ptr,getLevel());
    mEnemy->createMeleeEnemy(this);
    pm ->  attachProcess((shared_ptr<Process>) mEnemy);
}
void GameLogic::update(float deltaTime)
{
    player.update(deltaTime);
    updateCd(deltaTime);
    if(enemyCounter > pm -> checkEnemies())
    {
        enemyCounter = pm -> checkEnemies();
        if(level == 4)
        {
            score +=1000;
        }
        else
        {
            score +=25;
        }
    }

    if(pm -> checkEnemies() <= 0)
    {
        changing_level = true;
        transition += deltaTime;

        if(transition >= 1000.0 && !changed_background){
            if(wave % 4 == 0)
            {
                level++;
                changed_background = true;
                wave = 0;

            }

            clearGame();
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


bool GameLogic::isAbilityOnCd()
{
    return abilityOnCd;
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
    pm->clearManager();
    resetCd();
    player.item( Process::NONE );
    player.setSpeed(0.3f);
    player.setDM(1);
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
    if(level % 4 == 0)
    {
        bossEnemies = 1;
        rangedEnemies = 0;
        meleeEnemies = 0;
    }
    else
    {
        bossEnemies = 0;
        rangedEnemies = 1 * wave;
        meleeEnemies = 1 * wave;
    }

    totalEnemies = meleeEnemies + rangedEnemies;

    cout<<"totalEnemies enemy " << totalEnemies << endl;

    for (int enemies = 0; enemies<rangedEnemies; enemies++)
    {
        cout<<"Created ranged enemy " << enemies << endl;
        createRangedEnemy();
    }
    for (int enemies = 0; enemies<meleeEnemies; enemies++)
    {
        cout<<"Created melee enemy " << enemies << endl;
        createMeleeEnemy();
    }

    for (int enemies = 0; enemies<bossEnemies; enemies++)
    {
        cout<<"Created Boss enemy " << enemies << endl;
        createBossEnemy();
    }
    enemyCounter = pm -> checkEnemies();
}

bool GameLogic::isPaused() {
	return paused;
}

bool GameLogic::changingLevel(){
	return changing_level;
}

void GameLogic::useItem()
{

    switch(player.currentItem())
    {
        case(Process::RED_ITEM):
            {
                shared_ptr<DmgDisplay> displayHeal = make_shared<DmgDisplay>(window_ptr);
                player.healPlayer(redPotion);
                displayHeal -> createText(getPlayer().getPosition().x  , getPlayer().getPosition().y , Process::HEAL , redPotion);
                pm ->  attachProcess((shared_ptr<Process>) displayHeal);
            }
            break;
        case(Process::BLUE_ITEM):
            resetCd();
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

void GameLogic::resetCd() {
	switch (startingElement) {
	case 0:
		abilityTimer = splitAttackTimer;
		break;
	case 1:
		abilityTimer = airShieldTimer;
		break;
	case 2:
		abilityTimer = dashTimer;
		break;
	case 3:
		abilityTimer = healTimer;
		break;
	default:
		cout<<"resetCd failed, element mismatch"<<endl;
		break;
	}
	basicAttackCd = basicAttackTimer;
	abilityCd = abilityTimer;
	basicAttackOnCd = false;
	abilityOnCd = false;
}

void GameLogic::updateCd(float deltaTime) {
	basicAttackCd += deltaTime;
	basicAttackOnCd = (basicAttackTimer >= basicAttackCd);
	abilityCd += deltaTime;
	abilityOnCd = (abilityTimer >= abilityCd);
}

int GameLogic::getScore()
{
    return score;
}
