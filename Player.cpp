#include "Player.h"

Player::Player()
{
    if( !image.loadFromFile( "../Assets/Images/MainPlayer3.png" ) )
        cout<<"Cannot PlayerSprite"<<endl;

        body.setTextureRect(sf::IntRect(64*1 ,64 * 0,64 * 1,128 * 1));
}

void Player::createPlayer(float x_pos, float y_pos)
{

    this -> body.setSize( sf::Vector2f( 64, 128 ) );
    this -> body.setPosition(x_pos, y_pos);
    this -> body.setTexture(&image);
}

sf::RectangleShape Player::getPlayerBody()
{
    return body;
}

void Player::movePlayer(char dir, float deltaTime)
{
    cout<<"moving "<<dir<<endl;
    if(this -> dir != dir )
    {
        this -> dir = dir;
        switch(this -> dir)
        {
        case 'S':
            body.setTextureRect(sf::IntRect(64*1 ,128 * 0,64 * 1,128 * 1));
            spriteNum = 0;
            changeTimer = 1.9;
            break;

        case 'N':
            body.setTextureRect(sf::IntRect(64*1 ,128 *3 ,64 * 1,128 * 1));
            spriteNum = 0;
            changeTimer = 1.9;
            break;

        case 'E':
            body.setTextureRect(sf::IntRect(64*1 ,128 * 2,64 * 1,128 * 1));
            spriteNum = 0;
            changeTimer = 1.9;
            break;

        case 'W':
            body.setTextureRect(sf::IntRect(64*1 ,128 * 1,64 * 1,128 * 1));
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
            body.setTextureRect(sf::IntRect(64*1 ,128 * 0,64 * 1,128 * 1));
            break;
        case 1:
            body.setTextureRect(sf::IntRect(64*0 ,128 * 0,64 * 1,128 * 1));
            break;
        case 2:
            body.setTextureRect(sf::IntRect(64*1 ,128 * 0,64 * 1,128 * 1));
            break;
        case 3:
            body.setTextureRect(sf::IntRect(64*2 ,128 * 0,64 * 1,128 * 1));
            break;

        }


    }
    else if( dir == 'E')
    {
        switch(spriteNum )
        {
        case 0:
            body.setTextureRect(sf::IntRect(64*1 ,128 * 2,64 * 1,128 * 1));
            break;
        case 1:
            body.setTextureRect(sf::IntRect(64*0 ,128 * 2,64 * 1,128 * 1));
            break;
        case 2:
            body.setTextureRect(sf::IntRect(64*1 ,128 * 2,64 * 1,128 * 1));
            break;
        case 3:
            body.setTextureRect(sf::IntRect(64*2 ,128 * 2,64 * 1,128 * 1));
            break;

        }


    }
    else if( dir == 'W')
    {
        switch(spriteNum )
        {
        case 0:
            body.setTextureRect(sf::IntRect(64*1 ,128 * 1,64 * 1,128 * 1));
            break;
        case 1:
            body.setTextureRect(sf::IntRect(64*0 ,128 * 1,64 * 1,128 * 1));
            break;
        case 2:
            body.setTextureRect(sf::IntRect(64*1 ,128 * 1,64 * 1,128 * 1));
            break;
        case 3:
            body.setTextureRect(sf::IntRect(64*2 ,128 * 1,64 * 1,128 * 1));
            break;

        }


    }
    else if( dir == 'N')
    {
        switch(spriteNum )
        {
        case 0:
            body.setTextureRect(sf::IntRect(64*1 ,128 *3 ,64 * 1,128 * 1));
            break;
        case 1:
            body.setTextureRect(sf::IntRect(64*0 ,128 *3 ,64 * 1,128 * 1));
            break;
        case 2:
            body.setTextureRect(sf::IntRect(64*1 ,128 *3 ,64 * 1,128 * 1));
            break;
        case 3:
            body.setTextureRect(sf::IntRect(64*2 ,128 *3 ,64 * 1,128 * 1));
            break;

        }


    }
      if( changeTimer > 1 )
        {
            spriteNum = (spriteNum +1) % 4;
            cout<<"sprite num :"<<spriteNum<<endl;
            changeTimer = 0;
        }


        changeTimer += 0.04f *deltaTime;
}
