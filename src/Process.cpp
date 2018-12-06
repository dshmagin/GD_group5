#include "Process.h"



void Process::initialize() {}
void Process::update(float deltaTime){}
//void Process::postSuccess(){};
//void Process::postFailed(){};
//void Process::postAbort(){};
void Process::Pause(){}
void Process::Unpause(){}
bool Process::isDead(){return state = SUCCESS | FAIL | ABORT;}
int  Process::getState(){
    return state;
    }
bool Process::hasChild(){return child != nullptr;}
Process* Process::getChild() {return child;}

void Process::setType(enum type)
{
    this->type = type;
}

int Process::getAttackElement() {
	return attackElement;
}
