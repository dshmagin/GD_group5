#include "Process.h"

void Process::initialize() {state = RUNNING;}
void Process::update(float deltaMs){}
void Process::postSuccess(){};
void Process::postFailed(){};
void Process::postAbort(){};
void Process::Pause(){}
void Process::Unpause(){}
bool Process::isDead(){return state = SUCCESS | FAIL | ABORT;}
int  Process::getState(){return state;}
bool Process::hasChild(){return child != nullptr;}
Process* Process::getChild() {return child;}


