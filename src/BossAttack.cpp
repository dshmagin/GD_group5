#include "BossAttack.h"

BossAttack::BossAttack(shared_ptr<sf::RenderWindow> window_ptr, float rotation, float x_pos, float y_pos, shared_ptr<EnemyAttackManager>  enemyPM, int element) {
    this -> window_ptr = window_ptr;
    this -> boss = boss;
    this -> rotation = rotation;
	type  = Process::BOSSATTACK;
    this -> state = Process::UNINITIALIZED;
    this -> x_pos = x_pos;
    this -> y_pos = y_pos;
    this -> element = element;
}

void BossAttack::initialize() {
	state = Process::RUNNING;
	hitLimit = 3;
	timeRemaining = 5000;
	damage = 20;
	body.setSize(sf::Vector2f(128, 64));
    body.setOrigin(0, 32);
    body.setPosition(x_pos + 32, y_pos + 64);
    if( !texture.loadFromFile( "../Assets/Images/elemental_attack.png" ))
            cout<<"Cannot load AttackSprite"<<endl;
    body.setTexture(&texture);
    body.rotate(rotation);

}

void BossAttack::update(float deltaTime) {


    if(state == Process::RUNNING) {
        timeRemaining -= deltaTime;
        if (timeRemaining <= 0) {
        	state = Process::DEAD;
        } else {
        	switch (spriteNum) {
        	case 0:
        		body.setTextureRect(sf::IntRect(128 * 1 ,64 * element,128 * 1,64 * 1));
        	    break;
        	case 8:
                body.setTextureRect(sf::IntRect(128 * 2 ,64 * element,128 * 1,64 * 1));
       	        break;
       	    case 16:
       	        body.setTextureRect(sf::IntRect(128 * 3 ,64 * element,128 * 1,64 * 1));
       	        break;
       	    case 24:
       	        body.setTextureRect(sf::IntRect(128 * 0 ,64 * element,128 * 1,64 * 1));
       	        break;
       	    }

        	moveDistance = speed * deltaTime;
        	switch ((int)rotation) {
        	case 0:
        		body.move(moveDistance, 0);
        		break;
        	case 45:
                body.move(moveDistance * 0.88, moveDistance / 2);
        		break;
        	case 90:
        		body.move(0, moveDistance);
        		break;
        	case 135:
                body.move(-moveDistance * 0.88, moveDistance / 2);
        		break;
        	case 180:
        		body.move(-moveDistance, 0);
        		break;
        	case 225:
        		body.move(-moveDistance * 0.88, -(moveDistance / 2));
        		break;
        	case 270:
        		body.move(0, -moveDistance);
        		break;
        	case 315:
        		body.move(moveDistance * 0.88, -(moveDistance / 2));
        		break;
        	default:
        		break;
        	}
        	spriteNum = (spriteNum + 1) % 32;
        	window_ptr->draw(body);
            sf::FloatRect boundingBox = body.getGlobalBounds();
            sf::RectangleShape bb(sf::Vector2f(boundingBox.width, boundingBox.height));
            bb.setPosition(boundingBox.left, boundingBox.top);
            bb.setOutlineColor(sf::Color::Red);
            bb.setOutlineThickness(3.0);
            bb.setFillColor(sf::Color::Transparent);
            //window_ptr -> draw(bb);
        }
    }

}
