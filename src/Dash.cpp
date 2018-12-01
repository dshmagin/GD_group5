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
	type  = Process::OTHER;
	state = Process::RUNNING;
}

void Dash::update(float deltaTime) {
    if(state == Process::RUNNING) {
    	dir = player_ptr->getDirection();
    	switch (dir) {
    	case 0:
    		//south
    		if (player_ptr->getYPos() + distance >= 1550 )  distance = 1550 - player_ptr->getYPos();
    		player_ptr->move(0, distance);
    		playerView_ptr->move(0, distance);
    		UIIcon_ptr->move(0, distance);
    		elementalIcon_ptr->move(0, distance);
    		itemIcon_ptr->move(0, distance);
    		break;
    	case 1:
    		//west
    		if (player_ptr->getXPos() - distance <= 55) distance = player_ptr->getXPos() - 55;
    		player_ptr->move(-distance, 0);
    		playerView_ptr->move(-distance, 0);
    		UIIcon_ptr->move(-distance, 0);
    		elementalIcon_ptr->move(-distance, 0);
    		itemIcon_ptr->move(-distance, 0);
    		break;
    	case 2:
    		//east
    		if (player_ptr->getXPos() + distance >= 2285 )  distance = 2285 - player_ptr->getXPos();
    		player_ptr->move(distance, 0);
    		playerView_ptr->move(distance, 0);
    		UIIcon_ptr->move(distance, 0);
    		elementalIcon_ptr->move(distance, 0);
       		itemIcon_ptr->move(distance, 0);
    		break;
    	case 3:
    		//north
    		if (player_ptr->getYPos() - distance <= 100 )  distance = player_ptr->getYPos() - 100;
    		player_ptr->move(0, -distance);
    		playerView_ptr->move(0, -distance);
    		UIIcon_ptr->move(0, -distance);
    		elementalIcon_ptr->move(0, -distance);
       		itemIcon_ptr->move(0, -distance);
    		break;
    	default:
    		cout<<"direction mismatch"<<endl;
    		break;
    	}
    	window_ptr->setView(*playerView_ptr);
    }
    state = Process::DEAD;
}



