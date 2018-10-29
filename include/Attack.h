#ifndef ATTACK_H_INCLUDED
#define ATTACK_H_INCLUDED
#include <SFML/Graphics.hpp>

using namespace std;

class Attack
{
private:
    int damage = 25;
    sf::RectangleShape element;
    sf::Texture image;

public:
    Attack();
    void setDirection(char dir,float deltaTime);
    void update(float deltaTime);
    void animation( float deltaTime, char dir);
    void createAttack(float x_pos, float y_pos);
    sf::RectangleShape getPlayerBody();

}
