#include "Dash.h"

Dash::Dash(shared_ptr<sf::RenderWindow> window_ptr, Player* player_ptr, sf::View* playerView_ptr,
		sf::RectangleShape* UIIcon_ptr, sf::CircleShape* elementalIcon_ptr,
		sf::CircleShape* abilityIcon_ptr, sf::CircleShape* itemIcon_ptr) {
    // would be much easeir if we had a ui class
	// still needs to be modified one we have a health bar
	this -> window_ptr = window_ptr;
    this -> player_ptr = player_ptr;
    this -> playerView_ptr = playerView_ptr;
    this -> UIIcon_ptr = UIIcon_ptr;
    this -> elementalIcon_ptr = elementalIcon_ptr;
    this -> abilityIcon_ptr = abilityIcon_ptr;
    this -> itemIcon_ptr = itemIcon_ptr;
    initialize();
}

void Dash::initialize() {
	distance = 200;
	damage = 20;
	type  = Process::ATTACK;
	state = Process::RUNNING;
	hitLimit = 32;
}

void Dash::update(float deltaTime) {
	if (dashed) state = Process::DEAD;
    if(state == Process::RUNNING) {
    	dir = player_ptr->getDirection();
    	x = player_ptr->getXPos();
    	y = player_ptr->getYPos();
    	switch (dir) {
    	case 0:
    		//south
    		if (y + distance >= 1800 - 256)  distance = 1800 - 256 - y;
    		player_ptr->movePlayer(0, distance);
    		if (playerView_ptr->getCenter().y + distance >= 1374) distance = 1374 - playerView_ptr->getCenter().y;
    		moveCam(0, distance);
    		this->body.setPosition(x, y);
    		this->body.setSize(sf::Vector2f(64, 128 + distance));
    		break;
    	case 1:
    		//west
    		if (x - distance <= 64) distance = x - 64;
    		player_ptr->movePlayer(-distance, 0);
    		if (playerView_ptr->getCenter().x - distance <= 464) distance = playerView_ptr->getCenter().x - 464;
    		moveCam(-distance, 0);
    		this->body.setPosition(x - distance, y);
    		this->body.setSize(sf::Vector2f(64 + distance, 128));
    		break;
    	case 2:
    		//east
    		if (x + distance >= 2400 - 128)  distance = 2400 - 128 - x;
    		player_ptr->movePlayer(distance, 0);
    		if (playerView_ptr->getCenter().x + distance >= 1932) distance = 1932 - playerView_ptr->getCenter().x;
    		moveCam(distance, 0);
       		this->body.setPosition(x, y);
       		this->body.setSize(sf::Vector2f(64 + distance, 128));
    		break;
    	case 3:
    		//north
    		if (y - distance <= 128 )  distance = y - 128;
    		player_ptr->movePlayer(0, -distance);
    		if (playerView_ptr->getCenter().y - distance <= 430) distance = playerView_ptr->getCenter().y - 430;
    		moveCam(0, -distance);
    		this->body.setPosition(x, y - distance);
       		this->body.setSize(sf::Vector2f(64, 128 + distance));
    		break;
    	default:
    		cout<<"direction mismatch"<<endl;
    		break;
    	}
    	window_ptr->setView(*playerView_ptr);
    }
    dashed = true;
}

void Dash::moveCam(float x, float y) {
	playerView_ptr->move(x, y);
	UIIcon_ptr->move(x, y);
	elementalIcon_ptr->move(x, y);
	abilityIcon_ptr->move(x, y);
	itemIcon_ptr->move(x, y);
}



