#ifndef RANGEDENEMY_H_INCLUDED
#define RANGEDENEMY_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Process.h"
#include "ProcessManager.h"
#include <memory>

using namespace std;

class RangedEnemy : public Process
{
private:

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
    ProcessManager* pm;
    float playerH = 128;
    float playerW = 64;


    RangedEnemy(){};
    RangedEnemy(shared_ptr<sf::RenderWindow> window_ptr, int startingElement);
    void update(float deltaTime);
    //void animation( float deltaTime, char dir);
    void createRangedEnemy(float x_pos, float y_pos);
    sf::RectangleShape getEnemyBody();
    //float getXPos();
    //float getYPos();
    void reset(float x_pos, float y_pos);
    //void rangedAttack(int attackElement);
    void initialize();
    void damageEnemy( float enemy );
    void killEnemy( void );
};

#endif
