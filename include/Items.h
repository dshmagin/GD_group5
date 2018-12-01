#ifndef ITEMS_H_INCLUDED
#define ITEMS_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include "Process.h"
using namespace std;

class Items : public Process
{

private:

    shared_ptr<sf::RenderWindow> window_ptr;
    sf::Texture image;
    sf::Texture itemImg;
    float itemW = 64;
    float itemH = 64;





public:

    Items(){};
    Items(shared_ptr<sf::RenderWindow> &window_ptr);
     void dropItem(float loc_x, float loc_y);
     void initialize();
     void update(float deltaTime);

};


#endif // ITEMS_H_INCLUDED
