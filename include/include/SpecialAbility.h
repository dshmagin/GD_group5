#ifndef SPECIALABILITY_H_INCLUDED
#define SPECIALABILITY_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Process.h"
#include "ProcessManager.h"

using namespace std;

class SpecialAbility : public Process
{
private:
public:
	sf::Texture texture;
	shared_ptr<sf::RenderWindow> window_ptr;
    SpecialAbility(){};
    ~SpecialAbility(){};
};



#endif // SPECIALABILITY_H_INCLUDED
