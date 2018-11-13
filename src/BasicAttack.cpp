#include "BasicAttack.h"
#include "ProcessManager.h"

BasicAttack::BasicAttack(shared_ptr<sf::RenderWindow> window_ptr, int startingElement)
{
    this -> window_ptr = window_ptr;
    this -> pm = pm;
    if( !image.loadFromFile( "../Assets/Images/elemental_attack.png" ))
        cout<<"Cannot load AttackSprite"<<endl;

    element.setTextureRect(sf::IntRect(128 * 0 ,64 * startingElement,128 * 1,64 * 1));
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
        element.setTextureRect(sf::IntRect(128 * 1 ,64 * startingElement,128 * 1,64 * 1));
        break;
    case 8:
        element.setTextureRect(sf::IntRect(128 * 2 ,64 * startingElement,128 * 1,64 * 1));
        break;
    case 16:
        element.setTextureRect(sf::IntRect(128 * 3 ,64 * startingElement,128 * 1,64 * 1));
        break;
    case 24:
        element.setTextureRect(sf::IntRect(128 * 0 ,64 * startingElement,128 * 1,64 * 1));
        break;
    }

    switch(dir)
    {
    case 'N':
        element.move(0,-moveDistance);
        break;
    case 'S':
        element.move(0,moveDistance);
        break;
    case 'E':
        element.move(moveDistance,0);
        break;
    case 'W':
        element.move(-moveDistance,0);
        break;
    }

        distance += moveDistance;

    if (this -> element.getPosition().x > 2400 ||
            this -> element.getPosition().x < 0 ||
            this -> element.getPosition().y > 1600 ||
            this -> element.getPosition().y < 0)
    {
        this -> state = Process::DEAD;
    }
    // if(distance > 600)
    // {
    //     this -> state = Process::DEAD;
    //     distance = 0;
    // }
    
        spriteNum = (spriteNum + 1) % 32;
        window_ptr -> draw(element);

    }
}


void BasicAttack::createAttack(float x_pos, float y_pos, char dir)
{

    this -> element.setSize( sf::Vector2f( 128, 64 ) );
    this -> element.setTexture(&image);
    this -> spriteNum = 0;
    this -> dir = dir;
    switch(dir)
    {
    case 'N':
        element.rotate(270);
        this -> element.setPosition(x_pos, y_pos + 128);
        break;
    case 'S':
        element.rotate(90);
        this -> element.setPosition(x_pos + 64, y_pos);
        break;
    case 'E':
        this -> element.setPosition(x_pos, y_pos + 32);
        break;
    case 'W':
        element.rotate(180);
        this -> element.setPosition(x_pos + 32, y_pos + 96);
        break;
    }
    this -> state = Process::RUNNING;

}
void BasicAttack::initialize()
{
 this -> state = Process::RUNNING;
}
