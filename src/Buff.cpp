#include "Buff.h"

Buff::Buff(shared_ptr<sf::RenderWindow> window_ptr, Player* player_ptr) {
    this -> window_ptr = window_ptr;
    this -> player_ptr = player_ptr;
}

void Buff::initialize() {
	this -> type  = Process::BUFF;
	this -> state  = Process::RUNNING;
    spriteNum = 0;
	switch (buffType) {
	case 0:
		timeLimit = 10000;
		timeRemaining = 10000;
		player_ptr-> shieldPoints += 50;
		if( !texture.loadFromFile( "../Assets/Images/air_shield.png" )) cout<<"Cannot load Shield Sprite"<<endl;
	    player_ptr->updateSpeed(1.5);
	    player_ptr->updateDM(2);
	    break;
    case 1:
        //item buff
		timeLimit = 10000;
		timeRemaining = 10000;
		shieldPoint = 200;
		spellBuff = false;
		//if( !texture.loadFromFile( "../Assets/Images/air_shield.png" )) cout<<"Cannot load Shield Sprite"<<endl;
	    player_ptr->updateSpeed(1.5);
	    player_ptr->updateDM(10);
	    break;

	default:
		cout<<"buff type mismatch"<<endl;
	}

	body.setSize(sf::Vector2f(128,128));
    body.setOrigin(32, 0);
    body.setPosition(player_ptr->getXPos(), player_ptr->getYPos());
	body.setTexture(&texture);
}

void Buff::createBuff(int buffType) {
	state = Process::UNINITIALIZED;
	this->buffType = buffType;

}

void Buff::update(float deltaTime) {
    if(state == Process::RUNNING) {
        timeRemaining -= deltaTime;
        if ( timeRemaining <= 0) {
        	state = Process::DEAD;
        	player_ptr->updateSpeed(2.f/3.f);
        	player_ptr->updateDM(0.5);
            player_ptr-> shieldPoints = 0;
        }

        body.setTextureRect(sf::IntRect(128 * (spriteNum / 8), 0, 128, 128));
        body.setPosition(player_ptr->getXPos(), player_ptr->getYPos());
        if(spellBuff)
            window_ptr -> draw(body);
        spriteNum = (spriteNum + 1) % 64;
    }
}



