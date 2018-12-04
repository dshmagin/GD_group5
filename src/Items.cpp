#include "Items.h"
#include <cstdlib>

    Items::Items(shared_ptr<sf::RenderWindow> &window_ptr)
    {
        this -> window_ptr = window_ptr;
        if( !image.loadFromFile( "../Assets/Images/items.png" ))
            cout<<"Cannot load BenderAi"<<endl;
    }

    void Items::dropItem(float loc_x, float loc_y)
    {


        body.setPosition(loc_x, loc_y);
        body.setSize(sf::Vector2f(32 ,32));
        body.setTextureRect(sf::IntRect(32* this -> toDrop,32 * 1,32 ,32 ));
        body.setTexture(&image);
        this -> type  = Process::ITEM;


    }
    void Items::initialize()
    {
     this -> state = Process::RUNNING;
    }
    void Items::update(float deltaTime)
    {
        timer -= deltaTime;
        if(timer < 2000)
        {
            displayItem -=deltaTime;
            if(displayItem < 0)
            {
                displayItem = 250;
            }
        }
        if(timer<=0)
            state = Process::DEAD;
        if(displayItem>125)
            window_ptr -> draw(this -> body);
    }
