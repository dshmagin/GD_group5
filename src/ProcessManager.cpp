#include "ProcessManager.h"
#include <SFML/Graphics.hpp>
#include "Process.h"
#include "iostream"
#include <vector>

using namespace std;
//                 0     1     2       3      4       5         6
// enum state {RUNNING,DEAD, PAUSED, FAIL, SUCCESS, ABORT, UNINITIALIZED};
void ProcessManager::updateProcessList(float deltaMs)
{

    vector <shared_ptr<Process>> liveProcess;
    shared_ptr<Process> p;
    for (vector<shared_ptr<Process>>::iterator it = processList.begin(); it != processList.end(); it++)

    {
        p = *it;
        if(p != nullptr)
        {
            if( p->getState()== Process::UNINITIALIZED)
                p->initialize();

            if(p->getState()== Process::RUNNING)
                p->update(deltaMs);

            if(!p->getState()== Process::DEAD)
            {
                liveProcess.push_back(p);
            }
        }
    }
    processList.swap(liveProcess);
}

void ProcessManager::attachProcess(shared_ptr<Process> process)
{
    cout<<" THE TYPE IS " << process -> type <<endl;
    if(process -> type == Process::R_ENEMY)
    {
        cout<<"ADDED A NEW ENEMY\n";
        enemyList.push_back(process);
    }
    processList.push_back(process);
}

