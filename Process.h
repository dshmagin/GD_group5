#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED

class Process
{
    enum state {RUNNING, PAUSED, FAILED, SUCCESS, ABORTED, UNINIT};
    int state;
    Process* child = nullptr;

    virtual initialize() {state = RUNNING;}
    virtual update(float deltaMs) = 0;
    virtual postSuccess(){};
    virtual postFailed(){};
    virtual postAbort(){};

    void Pause();
    void Unpause();
    bool isDead(){return state = SUCCESS | FAILED | ABORTED;}
    int getState(){return state;}
    bool hasChild(){return child != nullptr;}
    Process* getChild() {return child;}
};


#endif // PROCESS_H_INCLUDED
