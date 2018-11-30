#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <iostream>
#include "Process.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Player
{
private:
    int curItem = Process::NONE;
    int health = 100;
    int dir = SOUTH;
    int spriteNum = 0;
    float changeTimer = 0;
    float totalTime=0;
    float switchTime=100.0f;
    float playerH, playerW;
    sf::RectangleShape body;
    sf::Texture image;
    float speed;
    float damageMultiplier = 1;
    float damageReceivedMultiplier = 1;
    float dodge = 0;

public:
    // Enum that matches the sprite sheets row
    //          0      1    2      3
    enum dir {SOUTH, WEST, EAST, NORTH};
    bool moveKeyIsPressed=false;
    sf::IntRect uvRect;
    Player(){};
    Player(float playerH, float playerW);
    void setDirection(int dir,float deltaTime);
    void update(float deltaTime);
    void animation( float deltaTime, char dir);
    void createPlayer(float x_pos, float y_pos);
    sf::RectangleShape getPlayerBody();
    float getXPos();
    float getYPos();
    void reset(float x_pos, float y_pos);
    void item(int curItem);
    int currentItem();

    void setSpeed(float s);
    void updateSpeed(float multiplier);
    float getSpeed();

    void updateDM(float multilpier); // dm = damage multiplier
    float getDM();
    void updateDRM(float multiplier); // drm = damage received multiplier
    float getDRM();
    void updateDodge(float multiplier);
    float getDodge();
};


#endif // PLAYER_H_INCLUDED
