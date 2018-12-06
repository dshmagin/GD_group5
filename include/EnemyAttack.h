#ifndef ENEMYATTACK_H_INCLUDED
#define ENEMYATTACK_H_INCLUDED
#include "Process.h"
#include "Player.h"
#include "EnemyAttackManager.h"
using namespace std;

class EnemyAttack : public Process
{
private:
    sf:: Texture texture;
	sf::RectangleShape* boss;
	float rotation;
    sf::Vector2f rotationV;
	float timeRemaining;
	float speed = 0.5;
	float moveDistance;
	float x_pos;
	float y_pos;
	int spriteNum = 0;
    int element;
    shared_ptr<sf::RenderWindow> window_ptr;
    shared_ptr<EnemyAttackManager>  enemyPM;
public:
	EnemyAttack(){};
	EnemyAttack(shared_ptr<sf::RenderWindow> window_ptr, sf::Vector2f rotationV, float rotation, float x_pos, float y_pos, shared_ptr<EnemyAttackManager>  enemyPM, int element);
    ~EnemyAttack(){};

    void update(float deltaTime);
    void initialize();
};



#endif // SPLITATTACK_H_INCLUDED
