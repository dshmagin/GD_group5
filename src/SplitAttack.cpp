#include "SplitAttack.h"

SplitAttack::SplitAttack(shared_ptr<sf::RenderWindow> window_ptr, float rotation, Player* player_ptr, int element) {
    this -> window_ptr = window_ptr;
    this -> player_ptr = player_ptr;
    this -> rotation = rotation;
    this -> element = element;
    initialize();
}

void SplitAttack::initialize() {
	attackElement = 0;
	type  = Process::ATTACK;
	state = Process::RUNNING;
	hitLimit = 3;
	timeRemaining = 5000;
	damage = 20;
	body.setSize(sf::Vector2f(128, 64));
    body.setOrigin(0, 32);
    body.setPosition(player_ptr->getXPos() + 32, player_ptr->getYPos() + 64);
    if( !texture.loadFromFile( "../Assets/Images/elemental_attack.png" ))
            cout<<"Cannot load AttackSprite"<<endl;
    body.setTexture(&texture);
    body.rotate(rotation);
}

void SplitAttack::update(float deltaTime) {
    if(state == Process::RUNNING) {
        timeRemaining -= deltaTime;
        if (timeRemaining <= 0) {
        	state = Process::DEAD;
        } else {
        	switch (spriteNum) {
        	case 0:
        		body.setTextureRect(sf::IntRect(128 * 1 ,64 * 0 ,128 * 1,64 * 1));
        	    break;
        	case 8:
                body.setTextureRect(sf::IntRect(128 * 2 ,64 * 0 ,128 * 1,64 * 1));
       	        break;
       	    case 16:
       	        body.setTextureRect(sf::IntRect(128 * 3 ,64 * 0 ,128 * 1,64 * 1));
       	        break;
       	    case 24:
       	        body.setTextureRect(sf::IntRect(128 * 0 ,64 * 0 ,128 * 1,64 * 1));
       	        break;
       	    }

        	moveDistance = speed * deltaTime;
        	switch ((int)rotation) {
        	case 30:
        		body.move(moveDistance * .866, moveDistance / 2);
        		break;
        	case 150:
        		body.move(-moveDistance * .866, moveDistance / 2);
        		break;
        	case 270:
        		body.move(0, -moveDistance);
        		break;
        	default:
        		break;
        	}
        	spriteNum = (spriteNum + 1) % 32;
        	window_ptr->draw(body);
        }
    }
}
