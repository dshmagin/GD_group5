#include "DmgDisplay.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>


    DmgDisplay::DmgDisplay(shared_ptr<sf::RenderWindow> &window_ptr)
    {
        this -> window_ptr = window_ptr;
        if( !GameFont.loadFromFile( "../Assets/Fonts/GROBOLD.ttf" ) )
        {
            cout << "Font not found, title screen unable to load. Press 1 for single player, 2 for multiplayer" << endl;
            cout << "Player one control W-up S-down, Player two control I-up K-down" << endl;
        }
    }

    void DmgDisplay::createText(float loc_x, float loc_y, int attack, int dmg)
    {
        this -> type  = Process::TEXT;
        std::stringstream ss;
        ss << dmg;
        std::string s_dmg = ss.str();
        dmgText.setFont(GameFont);
        dmgText.setCharacterSize(20);
        dmgText.setString(s_dmg);
        dmgText.setPosition(loc_x,loc_y);
        dmgText.setOutlineColor( sf::Color( 0, 0, 0 ) );
        dmgText.setOutlineThickness(2);
        switch(attack)
        {
        case Process::ATTACK:
            dmgText.setColor(sf::Color::Yellow);
            break;
        case Process::E_ATTACK:
            dmgText.setColor(sf::Color::Red);
            break;
        case Process::HEAL:
            dmgText.setColor(sf::Color::Green);
        }
    }
    void DmgDisplay::initialize()
    {
     this -> state = Process::RUNNING;
    }
    void DmgDisplay::update(float deltaTime)
    {
        float moveDist = .01f * deltaTime;
        textMoveDist -=moveDist;
        dmgText.move(0,-1);
        if(textMoveDist<=0)
            state = Process::DEAD;
        window_ptr->draw(dmgText);

    }
