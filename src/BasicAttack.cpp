#include "BasicAttack.h"
#include "ProcessManager.h"
#include <math.h>

BasicAttack::BasicAttack(shared_ptr<sf::RenderWindow> window_ptr, int startingElement)
{
    this -> window_ptr = window_ptr;
    this -> pm = pm;
    if( !image.loadFromFile( "../Assets/Images/elemental_attack.png" ))
        cout<<"Cannot load AttackSprite"<<endl;

    body.setTextureRect(sf::IntRect(128 * 0 ,64 * 1,128 * 1,64 * 1));
    this -> startingElement = startingElement;
}

BasicAttack::~BasicAttack()
{

}

void BasicAttack::update(float deltaTime)
{
    float moveDistance = .4 *deltaTime;

    if(state == Process::RUNNING)
    {

    switch(spriteNum)
    {
    case 0:
        body.setTextureRect(sf::IntRect(128 * 1 ,64 * startingElement,128 * 1,64 * 1));
        break;
    case 8:
        body.setTextureRect(sf::IntRect(128 * 2 ,64 * startingElement,128 * 1,64 * 1));
        break;
    case 16:
        body.setTextureRect(sf::IntRect(128 * 3 ,64 * startingElement,128 * 1,64 * 1));
        break;
    case 24:
        body.setTextureRect(sf::IntRect(128 * 0 ,64 * startingElement,128 * 1,64 * 1));
        break;
    }

    switch(dir)
    {
    case 'N':
        body.move(0,-moveDistance);
        break;
    case 'S':
        body.move(0,moveDistance);
        break;
    case 'E':
        body.move(moveDistance,0);
        break;
    case 'W':
        body.move(-moveDistance,0);
        break;
    }

    distance += moveDistance;

    if(distance > 1200)
    {
        this -> state = Process::DEAD;
        distance = 0;
    }
    spriteNum = (spriteNum + 1) % 32;
    window_ptr -> draw(body);
    }
}


void BasicAttack::createAttack(float x_pos, float y_pos, char dir)
{
    this -> damage = 25;
    this -> type  = Process::ATTACK;
    this -> body.setSize( sf::Vector2f( 128, 64 ) );
    this -> body.setTexture(&image);
    this -> spriteNum = 0;
    this -> dir = dir;
    switch(dir)
    {
    case 'N':
        body.rotate(270);
        this -> body.setPosition(x_pos, y_pos + 128);
        break;
    case 'S':
        body.rotate(90);
        this -> body.setPosition(x_pos + 64, y_pos);
        break;
    case 'E':
        this -> body.setPosition(x_pos, y_pos + 32);
        break;
    case 'W':
        body.rotate(180);
        this -> body.setPosition(x_pos + 32, y_pos + 96);
        break;
    }
    this -> state = Process::UNINITIALIZED;
}

void BasicAttack::createEnemyAttack(float x_pos, float y_pos, char dir)
{
    this -> damage = 25;
    this -> type  = Process::ATTACK;
    this -> body.setSize( sf::Vector2f( 128, 64 ) );
    this -> body.setTexture(&image);
    this -> spriteNum = 0;
    this -> dir = dir;

    switch(dir)
    {
    case 'N':
        body.rotate(270);
        this -> body.setPosition(x_pos, y_pos + 128);
        break;
    case 'S':
        body.rotate(90);
        this -> body.setPosition(x_pos + 64, y_pos);
        break;
    case 'E':
        this -> body.setPosition(x_pos, y_pos + 32);
        break;
    case 'W':
        body.rotate(180);
        this -> body.setPosition(x_pos + 32, y_pos + 96);
        break;
    }
    this -> state = Process::UNINITIALIZED;
}

void BasicAttack::initialize()
{
	this -> damage = 25;
	this -> hitLimit = 1;
	this -> state = Process::RUNNING;
	this -> type  = Process::ATTACK;
}


sf::RectangleShape BasicAttack::getAttackElement()
{
    return body;
}
