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
    		if (y + distance >= 1550 )  distance = 1550 - y;
    		player_ptr->move(0, distance);
    		playerView_ptr->move(0, distance);
    		UIIcon_ptr->move(0, distance);
    		elementalIcon_ptr->move(0, distance);
    		itemIcon_ptr->move(0, distance);
    		this->body.setPosition(x, y);
    		this->body.setSize(sf::Vector2f(player_ptr->getPlayerW(), player_ptr->getPlayerH() + distance));
    		break;
    	case 1:
    		//west
    		if (x - distance <= 55) distance = x - 55;
    		player_ptr->move(-distance, 0);
    		playerView_ptr->move(-distance, 0);
    		UIIcon_ptr->move(-distance, 0);
    		elementalIcon_ptr->move(-distance, 0);
    		itemIcon_ptr->move(-distance, 0);
    		this->body.setPosition(x - distance, y);
    		this->body.setSize(sf::Vector2f(player_ptr->getPlayerW() + distance, player_ptr->getPlayerH()));
    		break;
    	case 2:
    		//east
    		if (x + distance >= 2285 )  distance = 2285 - x;
    		player_ptr->move(distance, 0);
    		playerView_ptr->move(distance, 0);
    		UIIcon_ptr->move(distance, 0);
    		elementalIcon_ptr->move(distance, 0);
       		itemIcon_ptr->move(distance, 0);
       		this->body.setPosition(x, y);
       		this->body.setSize(sf::Vector2f(player_ptr->getPlayerW() + distance, player_ptr->getPlayerH()));
    		break;
    	case 3:
    		//north
    		if (y - distance <= 100 )  distance = y - 100;
    		player_ptr->move(0, -distance);
    		playerView_ptr->move(0, -distance);
    		UIIcon_ptr->move(0, -distance);
    		elementalIcon_ptr->move(0, -distance);
       		itemIcon_ptr->move(0, -distance);
       		this->body.setPosition(x, y - distance);
       		this->body.setSize(sf::Vector2f(player_ptr->getPlayerW(), player_ptr->getPlayerH() + distance));
    		break;
    	default:
    		cout<<"direction mismatch"<<endl;
    		break;
    	}
    	window_ptr->setView(*playerView_ptr);
    }
    dashed = true;
}



