#include "RangedEnemy.h"
//#include "ProcessManager.h"
#include <cstdlib>
#include <cmath>

RangedEnemy::RangedEnemy(shared_ptr<sf::RenderWindow> window_ptr, int attackElement)
{
    init();
    this -> window_ptr = window_ptr;
    this -> attackElement = attackElement;
}

void RangedEnemy::init()
{
    if( !image.loadFromFile( "../Assets/Images/waterBender.png" ))
        cout<<"Cannot load BenderAi"<<endl;
    if( !itemImg.loadFromFile( "../Assets/Images/items.png" ))
        cout<<"Cannot load items"<<endl;

    body.setTextureRect(sf::IntRect(playerW * 1, playerH * 0, playerW, playerH));
}

void RangedEnemy::createRangedEnemy(GameLogic* gameLogic)
{


    this -> healthBar.setSize(sf::Vector2f( 50, 10 ));
    this -> healthBar.setFillColor(sf::Color::Red);
    this -> healthBg.setSize(sf::Vector2f( 54, 14 ));
    this -> healthBg.setFillColor(sf::Color::Black);

    this-> randF = (((float) (rand() % 100))/ 1000.0f);

    this -> body.setSize( sf::Vector2f( playerW, playerH ) );
    float loc_x = (rand() % (1200 - 200) + 100);
    float loc_y = (rand() % (900 - 200) + 100);
    this -> body.setPosition(loc_x, loc_y);
    this -> body.setTexture(&image);
    this -> game = gameLogic;
    initializeProcess();
}

void RangedEnemy::initializeProcess()
{
 this -> state = Process::RUNNING;
 this -> type  = Process::R_ENEMY;
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

    healthBg.setPosition(body.getPosition().x + 5,body.getPosition().y +3);
    healthBar.setPosition(body.getPosition().x + 7,body.getPosition().y +5 );
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
}

sf::Vector2f RangedEnemy::findPlayer(float deltaTime)
{
    float xComp = (game -> getPlayerCoord().x) - this -> body.getPosition().x;
    float yComp = (game -> getPlayerCoord().y) - this -> body.getPosition().y;

    sf::Vector2f toPlayer;

    toPlayer.x = (xComp/(abs(xComp) + abs(yComp))) * (.2 + randF) * deltaTime;
    toPlayer.y = (yComp/(abs(xComp) + abs(yComp))) * (.2 + randF) * deltaTime;

    if (abs(xComp) > 50 || abs(yComp) > 50)
    {
        this -> body.move(toPlayer.x, toPlayer.y);
    }

    if(body.getGlobalBounds().intersects(game->getPlayer().getGlobalBounds()))
        game->player.healPlayer(-0.05);

    return toPlayer;
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
