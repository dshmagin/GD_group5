#include "RangedEnemy.h"
#include "ProcessManager.h"

RangedEnemy::RangedEnemy(shared_ptr<sf::RenderWindow> window_ptr, int attackElement)
{
    this -> window_ptr = window_ptr;
    this -> pm = pm;
    if( !image.loadFromFile( "../Assets/Images/BenderAi.png" ))
        cout<<"Cannot load BenderAi"<<endl;

    body.setTextureRect(sf::IntRect(playerW*1 ,playerH * 0,playerW ,playerH ));
    this -> attackElement = attackElement;
}

void RangedEnemy::createRangedEnemy(float x_pos, float y_pos)
{

    this -> body.setSize( sf::Vector2f( playerW, playerH ) );
    this -> body.setPosition(x_pos, y_pos);
    this -> body.setTexture(&image);
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
}

void RangedEnemy::update(float deltaTime)
{
    window_ptr -> draw(body);
}
