#include "BossAttack.h"

BossAttack::BossAttack(shared_ptr<sf::RenderWindow> window_ptr, float rotation, float x_pos, float y_pos, shared_ptr<EnemyAttackManager>  enemyPM) {
    this -> window_ptr = window_ptr;
    this -> boss = boss;
    this -> rotation = rotation;
	type  = Process::BOSSATTACK;
    this -> state = Process::UNINITIALIZED;
    this -> x_pos = x_pos;
    this -> y_pos = y_pos;
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
        		body.setTextureRect(sf::IntRect(128 * 1 ,64 * 0,128 * 1,64 * 1));
        	    break;
        	case 8:
                body.setTextureRect(sf::IntRect(128 * 2 ,64 * 0,128 * 1,64 * 1));
       	        break;
       	    case 16:
       	        body.setTextureRect(sf::IntRect(128 * 3 ,64 * 0,128 * 1,64 * 1));
       	        break;
       	    case 24:
       	        body.setTextureRect(sf::IntRect(128 * 0 ,64 * 0,128 * 1,64 * 1));
       	        break;
       	    }

        	moveDistance = speed * deltaTime;
        	switch ((int)rotation) {
        	case 30:
        		body.move(moveDistance * .866, moveDistance / 2);
        		break;
        	case 150:
        		body.move(-moveDistance * 0.88, moveDistance / 2);
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



