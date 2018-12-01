#include "RangedEnemy.h"
//#include "ProcessManager.h"
#include <cstdlib>
#include <cmath>

RangedEnemy::RangedEnemy(shared_ptr<sf::RenderWindow> window_ptr, int attackElement)
{
    this -> window_ptr = window_ptr;
    if( !image.loadFromFile( "../Assets/Images/waterBender.png" ))
        cout<<"Cannot load BenderAi"<<endl;
    if( !itemImg.loadFromFile( "../Assets/Images/items.png" ))
        cout<<"Cannot load items"<<endl;

    body.setTextureRect(sf::IntRect(playerW*1 ,playerH * 0,playerW ,playerH ));
    this -> attackElement = attackElement;
}

void RangedEnemy::createRangedEnemy(GameLogic* gameLogic)
{

    this -> body.setSize( sf::Vector2f( playerW, playerH ) );
    float loc_x = (rand() % (1200 - 200) + 100);
    float loc_y = (rand() % (900 - 200) + 100);
    this -> body.setPosition(loc_x, loc_y);
    this -> body.setTexture(&image);
    this -> game = gameLogic;
    initialize();
}

sf::RectangleShape RangedEnemy::getEnemyBody()
{
    return body;
}

void RangedEnemy::reset(float x_pos, float y_pos)
{
    body.setPosition(x_pos,y_pos);
}

void RangedEnemy::initialize()
{
 this -> state = Process::RUNNING;
 this -> type  = Process::R_ENEMY;
}

void RangedEnemy::update(float deltaTime)
{
    if(!ifItemNotSet && type == Process::ITEM)
    {
        cout<<"ITEM HERE"<< this -> toDrop <<endl;
        ifItemNotSet = true;
        body.setPosition(body.getPosition().x + 16, this -> body.getPosition().y + 64);
        body.setSize(sf::Vector2f(32 ,32));
        body.setTextureRect(sf::IntRect(32* this -> toDrop,32 * 1,32 ,32 ));
        body.setTexture(&itemImg);
    }

    if (this -> type != Process::ITEM){
        sf::Vector2f toPlayer = findPlayer(deltaTime);
        if( changeTimer > 10 )
            {
              spriteNum = (spriteNum + 1) % 4;
              changeTimer = 0;
            }
        changeTimer += 0.04f *deltaTime;
        this -> body.move(toPlayer.x, toPlayer.y);
        setDirection(getDirection(toPlayer), spriteNum);
    }

    window_ptr -> draw(this -> body);
}

sf::Vector2f RangedEnemy::findPlayer(float deltaTime)
{
    float xComp = (game -> getPlayerCoord().x) - this -> body.getPosition().x;
    float yComp = (game -> getPlayerCoord().y) - this -> body.getPosition().y;

    //std::cout << xComp << "\n";
    //std::cout << yComp << "\n";

    sf::Vector2f toPlayer;

    toPlayer.x = (xComp/(abs(xComp) + abs(yComp))) * .2 * deltaTime;
    toPlayer.y = (yComp/(abs(xComp) + abs(yComp))) * .2 * deltaTime;

    return toPlayer;
}

int RangedEnemy::getDirection(sf::Vector2f toPlayer)
{
    if (toPlayer.x > 0 && toPlayer.y > 0)
    {
        if (abs(toPlayer.x) < abs(toPlayer.y))
        {
            //Face East
            //this.setDirection(2);
            return 0;
        }
        else
        {
            //Face South
            //this.setDirection(0);
            return 2;
        }
    }
    else if (toPlayer.x > 0 && toPlayer.y < 0)
    {
        if (abs(toPlayer.x) < abs(toPlayer.y))
        {
            //Face East
            //this.setDirection(2);
            return 3;
        }
        else
        {
            //Face North
            //this.setDirection(3);
            return 2;
        }
    }
    else if (toPlayer.x < 0 && toPlayer.y > 0)
    {
        if (abs(toPlayer.x) < abs(toPlayer.y))
        {
            //Face West
            //this.setDirection(1);
            return 0;
        }
        else
        {
            //Face South
            //this.setDirection(0);
            return 1;
        }
    }
    else
    {
        if (abs(toPlayer.x) < abs(toPlayer.y))
        {
            //Face West
            //this.setDirection(1);
            return 3;
        }
        else
        {
            //Face North
            //this.setDirection(3);
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
            body.setTextureRect(sf::IntRect(playerW * 0 ,playerH * dir, playerW ,playerH ));
            break;
        case 2:
            body.setTextureRect(sf::IntRect(playerW * 1 ,playerH * dir, playerW ,playerH ));
            break;
        case 3:
            body.setTextureRect(sf::IntRect(playerW * 2 ,playerH * dir, playerW ,playerH ));
            break;
    }
}
