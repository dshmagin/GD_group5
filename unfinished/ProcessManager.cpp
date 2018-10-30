#include "ProcessManager.h"
#include <SFML/Graphics.hpp>
#include "Process.h"


void ProcessManager::updateProcessList(float deltaMs)
{
    /*
    Process* p;
    for(std::list<Process*>::iterator it = processList.begin(); it != processList.end(); it++)
    {
        p = *it;
        if( p->getState()== Process::UNINITIALIZED)
            p->initialize();
        if(p->getState()== Process::RUNNING)
            p->update(deltaMs);
        if(p->isDead())
        {
            if(p->getState()==Process::SUCCESS)
            {
                p->postSuccess();
                if(p->hasChild())
                {
                    attachProcess(p->getChild());
                }
            }
            if(p->getState()==Process::FAIL)
                p->postFail();
            if(p->getState()==Process::ABORT)
                p->postAbort();
        }
    }
    */
}

void ProcessManager::attachProcess(Process* p)
{
    processList.push_back(p);
}
