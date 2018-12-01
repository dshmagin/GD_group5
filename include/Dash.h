#ifndef DASH_H_INCLUDED
#define DASH_H_INCLUDED
#include "SpecialAbility.h"
#include "Player.h"

using namespace std;

class Dash : public SpecialAbility
{
private:
    Player* player_ptr;
    sf::View* playerView_ptr;
    sf::RectangleShape* UIIcon_ptr;
	sf::CircleShape* elementalIcon_ptr;
	sf::CircleShape* itemIcon_ptr;

	bool dashed = false;
    int dir;
    float distance;
    float x;
    float y;

public:
    Dash(){};
    Dash(shared_ptr<sf::RenderWindow> window_ptr, Player* player_ptr, sf::View* playerView_ptr,
    		sf::RectangleShape* UIIcon_ptr, sf::CircleShape* elementalIcon_ptr, sf::CircleShape* itemIcon_ptr);

    ~Dash(){};
    void initialize();
    void update(float deltaTime);
};



#endif // DASH_H_INCLUDED
