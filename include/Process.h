#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED
#define NULL nullptr
#include<iostream>

using namespace std;

class Process
{
    public:
        enum state {RUNNING,DEAD, PAUSED, FAIL, SUCCESS, ABORT, UNINITIALIZED};
        enum type {ATTACK, R_ENEMY};
        int state;
        int type;
        Process* child = nullptr;

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
        bool hasChild();
        Process* getChild();
};


#endif // PROCESS_H_INCLUDED
