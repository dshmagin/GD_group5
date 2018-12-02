#include "Dash.h"

Dash::Dash(shared_ptr<sf::RenderWindow> window_ptr, Player* player_ptr, sf::View* playerView_ptr,
		sf::RectangleShape* UIIcon_ptr, sf::CircleShape* elementalIcon_ptr, sf::CircleShape* itemIcon_ptr) {
    // would be much easeir if we had a ui class
	// still needs to be modified one we have a health bar
	this -> window_ptr = window_ptr;
    this -> player_ptr = player_ptr;
    this -> playerView_ptr = playerView_ptr;
    this -> UIIcon_ptr = UIIcon_ptr;
    this -> elementalIcon_ptr = elementalIcon_ptr;
    this -> itemIcon_ptr = itemIcon_ptr;
    initialize();
}

void Dash::initialize() {
	distance = 300;
	damage = 20;
	type  = Process::ATTACK;
	state = Process::RUNNING;
	enemyHit = 0;
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
    		if (y + distance + 128 >= 1600 )  distance = 1600 - y - 128;
    		player_ptr->movePlayer(0, distance);
    		playerView_ptr->move(0, distance);
    		UIIcon_ptr->move(0, distance);
    		elementalIcon_ptr->move(0, distance);
    		itemIcon_ptr->move(0, distance);
    		this->body.setPosition(x, y);
    		this->body.setSize(sf::Vector2f(64, 128 + distance));
    		break;
    	case 1:
    		//west
    		if (x - distance <= 0) distance = x;
    		player_ptr->movePlayer(-distance, 0);
    		playerView_ptr->move(-distance, 0);
    		UIIcon_ptr->move(-distance, 0);
    		elementalIcon_ptr->move(-distance, 0);
    		itemIcon_ptr->move(-distance, 0);
    		this->body.setPosition(x - distance, y);
    		this->body.setSize(sf::Vector2f(64 + distance, 128));
    		break;
    	case 2:
    		//east
    		if (x + distance + 64>= 2400 )  distance = 2400 - x - 64;
    		player_ptr->movePlayer(distance, 0);
    		playerView_ptr->move(distance, 0);
    		UIIcon_ptr->move(distance, 0);
    		elementalIcon_ptr->move(distance, 0);
       		itemIcon_ptr->move(distance, 0);
       		this->body.setPosition(x, y);
       		this->body.setSize(sf::Vector2f(64 + distance, 128));
    		break;
    	case 3:
    		//north
    		if (y - distance <= 0 )  distance = y;
    		player_ptr->movePlayer(0, -distance);
    		playerView_ptr->move(0, -distance);
    		UIIcon_ptr->move(0, -distance);
    		elementalIcon_ptr->move(0, -distance);
       		itemIcon_ptr->move(0, -distance);
       		this->body.setPosition(x, y - distance);
       		this->body.setSize(sf::Vector2f(64, 128 + distance));
    		break;
    	default:
    		cout<<"direction mismatch"<<endl;
    		break;
    	}
    	window_ptr->setView(*playerView_ptr);
    	player_ptr->draw();
    }
    cout<<"dashed"<<endl;
    dashed = true;
}



