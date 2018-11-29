#ifndef RANGEDENEMY_H_INCLUDED
#define RANGEDENEMY_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Process.h"
#include "ProcessManager.h"
#include "GameLogic.h"

using namespace std;

class RangedEnemy : public Process
{
private:
	float speed = 0.2;

public:
    shared_ptr<sf::RenderWindow> window_ptr;
    int attackElement;
    char dir = 'S';
    int spriteNum = 0;
    float changeTimer = 0;
    float totalTime=0;
    float switchTime=100.0f;
    float enemyH, enemyW;
    sf::Texture image;
    sf::Texture itemImg;
    float playerH = 128;
    float playerW = 64;
    bool ifItemNotSet = false;
    GameLogic* game;

    RangedEnemy(){};
    RangedEnemy(shared_ptr<sf::RenderWindow> window_ptr, int startingElement);
    sf::Vector2f findPlayer(float deltaTime);
    void update(float deltaTime);
    void setDirection(int dir);
    //void animation( float deltaTime, char dir);
    void createRangedEnemy(GameLogic* gameLogic);
    sf::RectangleShape getEnemyBody();
    //float getXPos();
    //float getYPos();
    void reset(float x_pos, float y_pos);
    //void rangedAttack(int attackElement);
    void initialize();
};

#endif
