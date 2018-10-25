#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Player
{
private:
    int health = 100;
    char dir = 'S';
    int spriteNum = 0;
    float changeTimer = 0;
    sf::RectangleShape body;
    sf::Texture image;

public:
    Player();
    void movePlayer(char dir, float deltaTime);
    void createPlayer(float x_pos, float y_pos);
    sf::RectangleShape getPlayerBody();
};


#endif // PLAYER_H_INCLUDED
