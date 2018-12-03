#ifndef SPLITATTACK_H_INCLUDED
#define SPLITATTACK_H_INCLUDED
#include "SpecialAbility.h"
#include "Player.h"

using namespace std;

class SplitAttack : public SpecialAbility
{
private:
	Player* player_ptr;
	int rotation;
	float timeRemaining;
	float speed = 0.4;
	float moveDistance;
	int spriteNum = 0;

public:
	SplitAttack(){};
	SplitAttack(shared_ptr<sf::RenderWindow> window_ptr, float rotation, Player* player_ptr);
    ~SplitAttack(){};

    void update(float deltaTime);
    void initialize();
};



#endif // SPLITATTACK_H_INCLUDED
