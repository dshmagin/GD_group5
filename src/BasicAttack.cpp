#include "BasicAttack.h"
#include "ProcessManager.h"

BasicAttack::BasicAttack(shared_ptr<sf::RenderWindow> window_ptr)
{
    this -> window_ptr = window_ptr;
    this -> pm = pm;
    if( !image.loadFromFile( "../Assets/Images/fire_attack_base_1.png" ))
        cout<<"Cannot load AttackSprite"<<endl;

    element.setTextureRect(sf::IntRect(128 * 0 ,64 * 0,128 * 1,64 * 1));

}

BasicAttack::~BasicAttack()
{

}

void BasicAttack::update(float deltaTime)
{
    if(state == Process::RUNNING)
    {

    switch(spriteNum)
    {
    case 0:
        element.setTextureRect(sf::IntRect(128 * 1 ,64 * 0,128 * 1,64 * 1));
        break;
    case 8:
        element.setTextureRect(sf::IntRect(128 * 2 ,64 * 0,128 * 1,64 * 1));
        break;
    case 16:
        element.setTextureRect(sf::IntRect(128 * 3 ,64 * 0,128 * 1,64 * 1));
        break;
    case 24:
        element.setTextureRect(sf::IntRect(128 * 0 ,64 * 0,128 * 1,64 * 1));
        break;
    }

    switch(dir)
    {
    case 'N':
        element.move(0,-.4 *deltaTime);
        break;
    case 'S':
        element.move(0,.4 *deltaTime);
        break;
    case 'E':
        element.move(.4 *deltaTime,0);
        break;
    case 'W':
        element.move(-.4 *deltaTime,0);
        break;
    }
    //cout<<distance<<endl;
        distance += .4 *deltaTime;
    if(distance > 40)
    {

        this -> state = Process::DEAD;
    }
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

int BasicAttack::getState()
{
    cout<<"state"<<state<<endl;
    return state;
}

