#ifndef MELEEENEMY_H_INCLUDED
#define MELEEENEMY_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Process.h"
#include "ProcessManager.h"
#include "GameLogic.h"

using namespace std;

class MeleeEnemy : public Process
{
private:
    sf::RectangleShape healthBar;
    sf::RectangleShape healthBg;
    float attackCd = 600;
    float attackTimer = 600;

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

    MeleeEnemy(){};
    MeleeEnemy(shared_ptr<sf::RenderWindow> window_ptr, int startingElement);
    void init();
    sf::Vector2f findPlayer(float deltaTime);
    void update(float deltaTime);
    void setDirection(int dir, int spriteNum);
    int getDirection(sf::Vector2f toPlayer);
    void createMeleeEnemy(GameLogic* gameLogic);
    sf::RectangleShape getEnemyBody();
    void reset(float x_pos, float y_pos);
    void initialize();
    //void rangedAttack(int attackElement);
    //void animation( float deltaTime, char dir);
};

#endif
