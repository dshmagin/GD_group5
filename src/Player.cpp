#include "Player.h"

Player::Player(float playerH, float playerW,shared_ptr<sf::RenderWindow> &window_ptr)
{
    this -> window_ptr = window_ptr;
    this -> playerH = playerH;
    this -> playerW = playerW;
    if( !image.loadFromFile( "../Assets/Images/Simu.png" ) )
        cout<<"Cannot PlayerSprite"<<endl;

    body.setTextureRect(sf::IntRect(playerW*1 ,playerH * 0,playerW ,playerH ));

}

void Player::createPlayer(float x_pos, float y_pos)
{
    this -> healthBar.setSize(sf::Vector2f( 50, 10 ));
    this -> healthBar.setFillColor(sf::Color::Green);
    this -> healthBg.setSize(sf::Vector2f( 54, 14 ));
    this -> healthBg.setFillColor(sf::Color::Black);

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
    float moveVal = speed * deltaTime;
    switch(dir)
    {
    case NORTH:
        if(body.getPosition().y - moveVal >= 128 )
            body.move(0,-moveVal);
        break;
    case SOUTH:
        if(body.getPosition().y + moveVal <= 1800 -256 )
            body.move(0,moveVal);
        break;
    case EAST:
        if(body.getPosition().x + moveVal <= 2400 - 128 )
            body.move(moveVal,0);
        break;
    case WEST:
        if(body.getPosition().x - moveVal >= 64 )
            body.move(-moveVal,0);
        break;
    }
}
void Player::update(float deltaTime)
{
    healthBg.setPosition(body.getPosition().x + 5,body.getPosition().y -15);
    healthBar.setPosition(body.getPosition().x + 7,body.getPosition().y -13 );
    healthBar.setSize(sf::Vector2f(health/2.0, 10));
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
            spriteNum = (spriteNum +1) % 4;
            changeTimer = 0;
        }
    }

        changeTimer += 0.04f *deltaTime;
        window_ptr -> draw(body);
        window_ptr -> draw(healthBg);
        window_ptr -> draw(healthBar);
        sf::FloatRect boundingBox = body.getGlobalBounds();
        sf::RectangleShape bb(sf::Vector2f(boundingBox.width, boundingBox.height));
        bb.setPosition(boundingBox.left, boundingBox.top);
        bb.setOutlineColor(sf::Color::Red);
        bb.setOutlineThickness(3.0);
        bb.setFillColor(sf::Color::Transparent);
        //window_ptr -> draw(bb);
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

void Player::setSpeed(float s) {
	speed = s;
}

void Player::updateSpeed(float multiplier) {
	speed *= multiplier;
}

float Player::getSpeed() {
	return speed;
}

void Player::updateDM(float multiplier) {
	damageMultiplier *= multiplier;
}

void Player::setDM(float multiplier) {
	damageMultiplier = multiplier;
}
float Player::getDM() {
	return damageMultiplier;
}

void Player::updateDRM(float multiplier) {
	damageReceivedMultiplier *= multiplier;
}

float Player::getDRM() {
	return damageReceivedMultiplier;
}

void Player::updateDodge(float multiplier) {
	dodge *= multiplier;
}

float Player::getDodge() {
	return dodge;
}

void Player::healPlayer(float amount)
{
    if(amount < 0 && shieldPoints > 0)
    {
        cout<<"shieldPoints "<< shieldPoints<<endl;
        shieldPoints+=amount;
        if(shieldPoints < 0)
            health += shieldPoints;
    }
    else
    {

        if(health + amount > 100)
        {
            health = 100;
        }
        else if(health + amount < 0)
        {
            health = 0;
        }
        else
            health += amount;
    }
}


void Player::movePlayer(float x, float y) {
	body.move(x, y);
};

int Player::getDirection() {
	return (int)dir;
}

void Player::knockBack(int dir) {
	int moveVal = 30;
    switch(dir)
    {
    case 3:
        if(body.getPosition().y - moveVal >= 128 )
            body.move(0,-moveVal);
        break;
    case 0:
        if(body.getPosition().y + moveVal <= 1800 -256 )
            body.move(0,moveVal);
        break;
    case 2:
        if(body.getPosition().x + moveVal <= 2400 - 128 )
            body.move(moveVal,0);
        break;
    case 1:
        if(body.getPosition().x - moveVal >= 64 )
            body.move(-moveVal,0);
        break;
    default:
    	break;
    }
}

void Player::setElement(int element) {
	this->element = element;
}

int Player::getElement() {
	return element;
}
