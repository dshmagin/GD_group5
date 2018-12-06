#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED
#define NULL nullptr
#include<iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Process
{
    public:
        enum state {RUNNING,DEAD, PAUSED, FAIL, SUCCESS, ABORT, UNINITIALIZED};
        enum type {ATTACK, R_ENEMY, E_ATTACK, ITEM, BUFF, TEXT, HEAL,BOSSATTACK};
        enum itemDropped { NONE, BLUE_ITEM,RED_ITEM, YELLOW_ITEM};
        sf::RectangleShape item;
        int state = UNINITIALIZED;
        int type;
        int toDrop;
        float damage;
        float health = 100;
        int enemyHit = 0;
        int hitLimit;
        int attackElement;
        Process* child = nullptr;
        sf::RectangleShape body;
        Process(){};
        virtual void initialize();
        virtual void update(float deltaTime) = 0;
        //virtual void postSuccess();
       // virtual void postFailed();
       // virtual void postAbort();
        void Pause();
        void Unpause();
        bool isDead();
        void setType(enum type);
        int getState();
        int getAttackElement();
        bool hasChild();
        Process* getChild();
};


#endif // PROCESS_H_INCLUDED
