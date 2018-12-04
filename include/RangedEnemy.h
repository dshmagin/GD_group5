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
    sf::RectangleShape healthBar;
    sf::RectangleShape healthBg;

public:
    shared_ptr<sf::RenderWindow> window_ptr;
    int attackElement;
    int dir = 0;
    int spriteNum = 0;
    float changeTimer = 0;
    float totalTime=0;
    float switchTime=100.0f;
    sf::Texture image;
    sf::Texture itemImg;
    float playerH = 128;
    float playerW = 64;
    GameLogic* game;
    float randF;
    float randNum;
    RangedEnemy(){};
    RangedEnemy(shared_ptr<sf::RenderWindow> window_ptr, int startingElement);
    void init(int element);
    sf::Vector2f findPlayer(float deltaTime);
    void update(float deltaTime);
    void setDirection(int dir, int spriteNum);
    int getDirection(sf::Vector2f toPlayer);
    char getDirectionChar(sf::Vector2f toPlayer);
    void createRangedEnemy(GameLogic* gameLogic);
    sf::RectangleShape getEnemyBody();
    void reset(float x_pos, float y_pos);
    void initialize();

    //void rangedAttack(int attackElement);
    //void animation( float deltaTime, char dir);
};

#endif
