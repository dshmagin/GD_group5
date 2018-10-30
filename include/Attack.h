#ifndef ATTACK_H_INCLUDED
#define ATTACK_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Attack
{
private:
    int damage = 25;
    char dir = 'S';
    int spriteNum = 0;
    sf::RectangleShape element;
    sf::Texture image;

public:
    Attack();
    ~Attack();
    void update(float deltaTime);
    void createAttack(float x_pos, float y_pos, char dir);
    sf::RectangleShape getAttackElement();

};

#endif
