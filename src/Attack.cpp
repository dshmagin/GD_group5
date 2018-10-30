#include "Attack.h"

Attack::Attack()
{
    if( !image.loadFromFile( "../Assets/Images/water_attack_base_1.png" ))
        cout<<"Cannot load AttackSprite"<<endl;

    element.setTextureRect(sf::IntRect(64*1 ,64 * 0,64 * 1,128 * 1));

}

Attack::~Attack()
{

}

void Attack::update(float deltaTime)
{
    switch(spriteNum)
    {
    case 0:
        element.setTextureRect(sf::IntRect(64*1 ,128 * 1,64 * 1,128 * 1));
        break;
    case 1:
        element.setTextureRect(sf::IntRect(64*0 ,128 * 1,64 * 1,128 * 1));
        break;
    case 2:
        element.setTextureRect(sf::IntRect(64*1 ,128 * 1,64 * 1,128 * 1));
        break;
    case 3:
        element.setTextureRect(sf::IntRect(64*2 ,128 * 1,64 * 1,128 * 1));
        break;
    }

    switch(dir)
    {
    case 'N':
        element.move(0,-.2 *deltaTime);
        break;
    case 'S':
        element.move(0,.2 *deltaTime);
        break;
    case 'E':
        element.move(.2 *deltaTime,0);
        break;
    case 'W':
        element.move(-.2 *deltaTime,0);
        break;
    }

    spriteNum = (spriteNum + 1) % 4;
}


void Attack::createAttack(float x_pos, float y_pos, char dir)
{

    this -> element.setSize( sf::Vector2f( 64, 128 ) );
    this -> element.setPosition(x_pos, y_pos);
    this -> element.setTexture(&image);
    this -> spriteNum = 0;
    this -> dir = dir;
}

sf::RectangleShape Attack::getAttackElement()
{
    return element;
}
