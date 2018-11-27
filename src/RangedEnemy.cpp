#include "RangedEnemy.h"
#include "ProcessManager.h"
#include <cstdlib>

RangedEnemy::RangedEnemy(shared_ptr<sf::RenderWindow> window_ptr, int attackElement)
{
    this -> window_ptr = window_ptr;
    if( !image.loadFromFile( "../Assets/Images/BenderAi.png" ))
        cout<<"Cannot load BenderAi"<<endl;
    if( !itemImg.loadFromFile( "../Assets/Images/items.png" ))
        cout<<"Cannot load items"<<endl;

    body.setTextureRect(sf::IntRect(playerW*1 ,playerH * 0,playerW ,playerH ));
    this -> attackElement = attackElement;
}

void RangedEnemy::createRangedEnemy()
{

    this -> body.setSize( sf::Vector2f( playerW, playerH ) );
    float loc_x = (rand() % (1200 - 200) + 100);
    float loc_y = (rand() % (900 - 200) + 100);
    this -> body.setPosition(loc_x, loc_y);
    this -> body.setTexture(&image);
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
        body.setPosition(body.getPosition().x + 16, body.getPosition().y + 64);
        body.setSize(sf::Vector2f(32 ,32));
        body.setTextureRect(sf::IntRect(32* this -> toDrop,32 * 1,32 ,32 ));
        body.setTexture(&itemImg);
    }
    window_ptr -> draw(body);
}


