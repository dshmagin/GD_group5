#ifndef BOSSATTACK_H_INCLUDED
#define BOSSATTACK_H_INCLUDED
#include "Process.h"
#include "Player.h"
#include "EnemyAttackManager.h"
using namespace std;

class BossAttack : public Process
{
private:
    sf:: Texture texture;
	sf::RectangleShape* boss;
	int rotation;
	float timeRemaining;
	float speed = 0.3;
	float moveDistance;
	float x_pos;
	float y_pos;
	int spriteNum = 0;
    shared_ptr<sf::RenderWindow> window_ptr;
    shared_ptr<EnemyAttackManager>  enemyPM;
public:
	BossAttack(){};
	BossAttack(shared_ptr<sf::RenderWindow> window_ptr, float rotation, float x_pos, float y_pos, shared_ptr<EnemyAttackManager>  enemyPM);
    ~BossAttack(){};

    void update(float deltaTime);
    void initialize();
};



#endif // SPLITATTACK_H_INCLUDED
