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


void Player::setDirection(char dir,float deltaTime)
{
    this -> dir = dir;
    moveKeyIsPressed = true;
    float moveVal = .3 *deltaTime;
    switch(dir)
    {
    case 'N':
        if(body.getPosition().y - moveVal >= 100 )
            body.move(0,-moveVal);
        break;
    case 'S':
        if(body.getPosition().y + moveVal <= 1550 )
            body.move(0,moveVal);
        break;
    case 'E':
        if(body.getPosition().x + moveVal <= 2285 )
            body.move(moveVal,0);
        break;
    case 'W':
        if(body.getPosition().x - moveVal >= 55 )
            body.move(-moveVal,0);
        break;
    }
}
void Player::update(float deltaTime)
{
    if(this -> dir != dir )
    {
        this -> dir = dir;
        switch(this -> dir)
        {
        case 'S':
            body.setTextureRect(sf::IntRect(playerW*1 ,playerH * 0,playerW ,playerH ));
            spriteNum = 0;
            changeTimer = 1.9;
            break;

        case 'N':
            body.setTextureRect(sf::IntRect(playerW*1 ,playerH *3 ,playerW,playerH ));
            spriteNum = 0;
            changeTimer = 1.9;
            break;

        case 'E':
            body.setTextureRect(sf::IntRect(playerW*1 ,playerH * 2,playerW,playerH ));
            spriteNum = 0;
            changeTimer = 1.9;
            break;

        case 'W':
            body.setTextureRect(sf::IntRect(playerW*1 ,playerH * 1,playerW ,playerH ));
            spriteNum = 0;
            changeTimer = 1.9;
            break;
        }
    }
    else if( dir == 'S')
    {
        switch(spriteNum )
        {
        case 0:
            body.setTextureRect(sf::IntRect(playerW * 1 ,playerH * 0, playerW, playerH));
            break;
        case 1:
            body.setTextureRect(sf::IntRect(playerW * 0 ,playerH * 0,playerW ,playerH ));
            break;
        case 2:
            body.setTextureRect(sf::IntRect(playerW * 1 ,playerH * 0,playerW ,playerH ));
            break;
        case 3:
            body.setTextureRect(sf::IntRect(playerW * 2 ,playerH * 0,playerW ,playerH ));
            break;

        }


    }
    else if( dir == 'E')
    {
        switch(spriteNum )
        {
        case 0:
            body.setTextureRect(sf::IntRect(playerW * 1 ,playerH * 2, playerW , playerH ));
            break;
        case 1:
            body.setTextureRect(sf::IntRect(playerW * 0 ,playerH * 2, playerW , playerH ));
            break;
        case 2:
            body.setTextureRect(sf::IntRect(playerW * 1 ,playerH * 2, playerW , playerH ));
            break;
        case 3:
            body.setTextureRect(sf::IntRect(playerW * 2 ,playerH * 2, playerW , playerH ));
            break;

        }


    }
    else if( dir == 'W')
    {
        switch(spriteNum )
        {
        case 0:
            body.setTextureRect(sf::IntRect(playerW * 1 ,playerH * 1, playerW , playerH ));
            break;
        case 1:
            body.setTextureRect(sf::IntRect(playerW * 0 ,playerH * 1, playerW , playerH ));
            break;
        case 2:
            body.setTextureRect(sf::IntRect(playerW * 1 ,playerH * 1, playerW , playerH ));
            break;
        case 3:
            body.setTextureRect(sf::IntRect(playerW * 2 ,playerH * 1, playerW , playerH ));
            break;

        }


    }
    else if( dir == 'N')
    {

        switch(spriteNum )
        {
        case 0:
            body.setTextureRect(sf::IntRect(playerW * 1 , playerH * 3 ,64 , playerH ));
            break;
        case 1:
            body.setTextureRect(sf::IntRect(playerW * 0 , playerH * 3 ,64 , playerH ));
            break;
        case 2:
            body.setTextureRect(sf::IntRect(playerW * 1 , playerH * 3 ,64 , playerH ));
            break;
        case 3:
            body.setTextureRect(sf::IntRect(playerW * 2 , playerH * 3 ,64 , playerH ));
            break;

        }


    }


    if(moveKeyIsPressed)
    {
      if( changeTimer > 10 )
        {
            spriteNum = (spriteNum +1) % 4;
            changeTimer = 0;
        }
    }


        changeTimer += 0.04f *deltaTime;
}

void Player::reset(float x_pos, float y_pos)
{
    body.setPosition(x_pos,y_pos);
}
