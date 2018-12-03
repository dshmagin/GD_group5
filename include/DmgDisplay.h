#ifndef DMGDISPLAY_H_INCLUDED
#define DMGDISPLAY_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Process.h"
using namespace std;

class DmgDisplay : public Process
{

private:

    shared_ptr<sf::RenderWindow> window_ptr;
    sf::Texture image;
    sf::Texture itemImg;
    sf::Font GameFont;
    sf::Text dmgText;
    float textMoveDist = 25.0f;
    float moveTimer = 250;
    float itemW = 64;
    float itemH = 64;
    float timer = 7000;





public:

     DmgDisplay(){};
     DmgDisplay(shared_ptr<sf::RenderWindow> &window_ptr);
     void createText(float loc_x, float loc_y, int attack, int dmg);
     void initialize();
     void update(float deltaTime);

};


#endif // ITEMS_H_INCLUDED
