#include "Player.h"

Player::Player(float playerH, float playerW)
{
    this -> playerH = playerH;
    this -> playerW = playerW;
    if( !image.loadFromFile( "../Assets/Images/Simu.png" ) )
        cout<<"Cannot PlayerSprite"<<endl;

        body.setTextureRect(sf::IntRect(playerW*1 ,playerH * 0,playerW ,playerH ));
}

void Player::createPlayer(float x_pos, float y_pos)
{

    this -> body.setSize( sf::Vector2f( playerW, playerH ) );
    this -> body.setPosition(x_pos, y_pos);
    this -> body.setTexture(&image);
}

sf::RectangleShape Player::getPlayerBody()
{
    return body;
}

float Player::getXPos()
{
    return this -> body.getPosition().x;
}

float Player::getYPos()
{
    return this -> body.getPosition().y;
}


void Player::setDirection(int dir,float deltaTime)
{
    this -> dir = dir;
    moveKeyIsPressed = true;
    float moveVal = .3 *deltaTime;
    switch(dir)
    {
    case NORTH:
        if(body.getPosition().y - moveVal >= 100 )
            body.move(0,-moveVal);
        break;
    case SOUTH:
        if(body.getPosition().y + moveVal <= 1550 )
            body.move(0,moveVal);
        break;
    case EAST:
        if(body.getPosition().x + moveVal <= 2285 )
            body.move(moveVal,0);
        break;
    case WEST:
        if(body.getPosition().x - moveVal >= 55 )
            body.move(-moveVal,0);
        break;
    }
}
void Player::update(float deltaTime)
{
    //Grab the players direction and display the correct column in the sprite sheet.
    this -> dir = dir;
    switch(spriteNum )
    {
    case 0:
        body.setTextureRect(sf::IntRect(playerW * 1 ,playerH * dir, playerW, playerH));
        break;
    case 1:
        body.setTextureRect(sf::IntRect(playerW * 0 ,playerH * dir,playerW ,playerH ));
        break;
    case 2:
        body.setTextureRect(sf::IntRect(playerW * 1 ,playerH * dir,playerW ,playerH ));
        break;
    case 3:
        body.setTextureRect(sf::IntRect(playerW * 2 ,playerH * dir,playerW ,playerH ));
        break;
    }
    /* moveKeyIsPressed is set to false in gameLogic whenever a
    * key is no longer pressed
    * updates the changeTimer by deltaTime * movespeed.
    * when the spriteNum is updated reset changeTimer to 0 again
    */
    if(moveKeyIsPressed)
    {
      if( changeTimer > 10 )
        {
            spriteNum = (spriteNum + 1) % 4;
            changeTimer = 0;
        }
    }

        changeTimer += 0.04f *deltaTime;
}

void Player::reset(float x_pos, float y_pos)
{
    body.setPosition(x_pos,y_pos);
}
void Player::item(int curItem)
{
    this -> curItem = curItem;
}
int Player::currentItem()
{
    return curItem;
}
