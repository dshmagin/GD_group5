#ifndef BUFF_H_INCLUDED
#define BUFF_H_INCLUDED
#include "SpecialAbility.h"
#include "Player.h"
using namespace std;

class Buff : public SpecialAbility
{
private:
	float timeLimit;
	float timeRemaining;
	float shieldPoint;
    bool spellBuff = true;
	int stacks;
	int stackLimit;
	int spriteNum;
    Player* player_ptr;
    int buffType;
    bool Debuff;
public:
    Buff(){};
    Buff(shared_ptr<sf::RenderWindow> window_ptr, Player* player_ptr);

    ~Buff(){};
    void initialize();
    void createBuff(int buffType);
    void update(float deltaTime);
    bool isDebuff();
};



#endif // BUFF_H_INCLUDED
