#include "RangedEnemy.h"
#include "EnemyAttack.h"
//#include "ProcessManager.h"
#include <cstdlib>
#include <cmath>

RangedEnemy::RangedEnemy(shared_ptr<sf::RenderWindow> window_ptr, int attackElement, shared_ptr<EnemyAttackManager> enemyPM)
{
    init();
    this -> window_ptr = window_ptr;
    this -> enemyPM = enemyPM;
    this -> attackElement = attackElement;
}

void RangedEnemy::init()
{
    if( !itemImg.loadFromFile( "../Assets/Images/items.png" ))
        cout<<"Cannot load items"<<endl;


    body.setTextureRect(sf::IntRect(playerW * 1, playerH * 0, playerW, playerH));
}

void RangedEnemy::createRangedEnemy(GameLogic* gameLogic)
{
    switch(attackElement)
    {
        case 0:
            if( !image.loadFromFile( "../Assets/Images/fireBender.png" ))
                cout<<"Cannot load fireBender"<<endl;
            break;
        case 1:
            if( !image.loadFromFile( "../Assets/Images/airBender.png" ))
                cout<<"Cannot load airBender"<<endl;
            break;
        case 2:
            if( !image.loadFromFile( "../Assets/Images/earthBender.png" ))
                cout<<"Cannot load earthBender"<<endl;
            break;
        case 3:
            if( !image.loadFromFile( "../Assets/Images/waterBender.png" ))
                cout<<"Cannot load waterBender"<<endl;
            break;
    }

    this -> healthBar.setSize(sf::Vector2f( 50, 10 ));
    this -> healthBar.setFillColor(sf::Color::Red);
    this -> healthBg.setSize(sf::Vector2f( 54, 14 ));
    this -> healthBg.setFillColor(sf::Color::Black);

    this -> randF = (((float) (rand() % 100))/ 1000.0f);

    this -> randNum = (((float) (rand() % 1900)));
    this -> switchTime += randNum;

    this -> body.setSize( sf::Vector2f( playerW, playerH ) );
    float loc_x = (rand() % (1200 - 200) + 100);
    float loc_y = (rand() % (900 - 200) + 100);
    this -> body.setPosition(loc_x, loc_y);
    this -> body.setTexture(&image);
    this -> game = gameLogic;
    this -> state = Process::UNINITIALIZED;
    this -> type = Process::R_ENEMY;
}

void RangedEnemy::initialize()
{
 this -> state = Process::RUNNING;
}

sf::RectangleShape RangedEnemy::getEnemyBody() {
    return body;
}

void RangedEnemy::reset(float x_pos, float y_pos)
{
    body.setPosition(x_pos,y_pos);
}

void RangedEnemy::update(float deltaTime)
{
    sf::Vector2f toPlayer = findPlayer(deltaTime);

    healthBg.setPosition(body.getPosition().x + 5,body.getPosition().y -15);
    healthBar.setPosition(body.getPosition().x + 7,body.getPosition().y - 13 );
    healthBar.setSize(sf::Vector2f(health/2.0, 10));
    if( changeTimer > 10 )
        {
          spriteNum = (spriteNum + 1) % 4;
          changeTimer = 0;
      }


    changeTimer += 0.04f * deltaTime;
    setDirection(getDirection(toPlayer), spriteNum);
    window_ptr -> draw(this -> body);
    window_ptr -> draw(healthBg);
    window_ptr -> draw(healthBar);
    switchTime -= deltaTime;

    if (switchTime < 0) {
        switchTime = 2000;
        shared_ptr<EnemyAttack> eAttack = make_shared<EnemyAttack>(window_ptr, findPlayerAttack(deltaTime), rotation,
            body.getPosition().x, body.getPosition().y, enemyPM,
            game -> getStartingElement() +  game -> getLevel() % 4);
        enemyPM -> attachProcess((shared_ptr<Process>) eAttack);
    }
}

sf::Vector2f RangedEnemy::findPlayer(float deltaTime)
{
    float xComp = (game -> getPlayerCoord().x) - this -> body.getPosition().x;
    float yComp = (game -> getPlayerCoord().y) - this -> body.getPosition().y;

    rotation = atan(yComp / xComp) * 180/3.1415;

    if(xComp < 0)
    {
        rotation = rotation + 180;
    }
    if(xComp > 0 && yComp < 0)
    {
        rotation = rotation + 360;
    }

    sf::Vector2f toPlayer;

    toPlayer.x = (xComp/(abs(xComp) + abs(yComp))) * (.2 + randF) * deltaTime;
    toPlayer.y = (yComp/(abs(xComp) + abs(yComp))) * (.2 + randF) * deltaTime;

    if (abs(xComp) > 250 || abs(yComp) > 250)
    {
        this -> body.move(toPlayer.x, toPlayer.y);
    }

    if(body.getGlobalBounds().intersects(game->getPlayer().getGlobalBounds()))
        game->player.healPlayer(-1);

    return toPlayer;
}

sf::Vector2f RangedEnemy::findPlayerAttack(float deltaTime)
{
    float xComp = (game -> getPlayerCoord().x) - this -> body.getPosition().x;
    float yComp = (game -> getPlayerCoord().y) - this -> body.getPosition().y;

    float rotation = atan(yComp / xComp) * 180/3.1415;

    if(xComp < 0)
    {
        rotation = rotation + 90;
    }
    if(xComp > 0 && yComp < 0)
    {
        rotation = rotation + 360;
    }

    sf::Vector2f toPlayerAttack;

    toPlayerAttack.x = (xComp/(abs(xComp) + abs(yComp)));
    toPlayerAttack.y = (yComp/(abs(xComp) + abs(yComp)));

    return toPlayerAttack;
}

int RangedEnemy::getDirection(sf::Vector2f toPlayer)
{
    if (toPlayer.x > 0 && toPlayer.y > 0)
    {
        if (abs(toPlayer.x) < abs(toPlayer.y))
        {
            //Face East
            return 0;
        }
        else
        {
            //Face South
            return 2;
        }
    }
    else if (toPlayer.x > 0 && toPlayer.y < 0)
    {
        if (abs(toPlayer.x) < abs(toPlayer.y))
        {
            //Face East
            return 3;
        }
        else
        {
            //Face North
            return 2;
        }
    }
    else if (toPlayer.x < 0 && toPlayer.y > 0)
    {
        if (abs(toPlayer.x) < abs(toPlayer.y))
        {
            //Face West
            return 0;
        }
        else
        {
            //Face South
            return 1;
        }
    }
    else
    {
        if (abs(toPlayer.x) < abs(toPlayer.y))
        {
            //Face West
            return 3;
        }
        else
        {
            //Face North
            return 1;
        }
    }
}

void RangedEnemy::setDirection(int dir, int spriteNum)
{
    switch(spriteNum )
    {
        case 0:
            body.setTextureRect(sf::IntRect(playerW * 1 ,playerH * dir, playerW, playerH));
            break;
        case 1:
            body.setTextureRect(sf::IntRect(playerW * 0 ,playerH * dir, playerW, playerH));
            break;
        case 2:
            body.setTextureRect(sf::IntRect(playerW * 1 ,playerH * dir, playerW, playerH));
            break;
        case 3:
            body.setTextureRect(sf::IntRect(playerW * 2 ,playerH * dir, playerW, playerH));
            break;
    }
}
