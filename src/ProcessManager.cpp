#include "ProcessManager.h"
#include <SFML/Graphics.hpp>
#include "Process.h"
#include "iostream"
#include <vector>
#include <list>

using namespace std;
//                 0     1     2       3      4       5         6
// enum state {RUNNING,DEAD, PAUSED, FAIL, SUCCESS, ABORT, UNINITIALIZED};
void ProcessManager::updateProcessList(float deltaMs)
{

    int counter = 0;
    shared_ptr<Process> p;
    for (list<shared_ptr<Process>>::iterator it = processList.begin(); it != processList.end(); it++)
   // for(shared_ptr<Process> p : processList)
    {
        p = *it;
        if(p != nullptr)
        {
            if( p->getState()== Process::UNINITIALIZED)
                p->initialize();

            if(p->getState()== Process::RUNNING)
                p->update(deltaMs);

            if(p->getState()== Process::DEAD)
            {
                removeProcess(p);
            }


        }

    }
    counter ++;
}

void ProcessManager::attachProcess(shared_ptr<Process> bAttack)
{
    processList.push_back(bAttack);
}

void ProcessManager::removeProcess(shared_ptr<Process> bAttack)
{
    processList.remove(bAttack);
}
