#ifndef BASICATTACK_H_INCLUDED
#define BASICATTACK_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Process.h"
#include "ProcessManager.h"

#include <memory>
using namespace std;

class BasicAttack : public Process
{
private:

public:

    shared_ptr<sf::RenderWindow> window_ptr;
    int startingElement;
    char dir = 'S';
    int spriteNum = 0;
    int spellWidth = 128;
    int spellHeight = 64;
    float distance = 0;
    sf::Texture image;
    ProcessManager* pm;
    BasicAttack(){};
    BasicAttack(shared_ptr<sf::RenderWindow> window_ptr, int startingElement);

    ~BasicAttack();
    void createAttack(float x_pos, float y_pos, char dir);
    void update(float deltaTime);
    void initialize();
    sf::RectangleShape getAttackElement();

};



#endif // BASICATTACK_H_INCLUDED
