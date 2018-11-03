#include "ProcessManager.h"
#include <SFML/Graphics.hpp>
#include "Process.h"
#include "iostream"
#include <vector>
using namespace std;


void ProcessManager::updateProcessList(float deltaMs)
{

//cout<<Process::UNINITIALIZED<<"  "<<Process::RUNNING<<" "<<Process::DEAD<<endl;
    int counter = 0;

    //for(std::vector<shared_ptr<Process>>::iterator it = processList.begin(); it != processList.end(); it++)
    for(shared_ptr<Process> p : processList)
    {
       // cout<<"stuff here"<< p->getState()<<endl;


        //cout<<"THE STATE IS "<< p->getState() <<endl;
        if( p->getState()== Process::UNINITIALIZED)
            p->initialize();

        if(p->getState()== Process::RUNNING)
            p->update(deltaMs);
           // p->state=Process::DEAD;
        if(p->getState()== Process::DEAD)
        {
            processList.clear();
            //cout<<processList.size()<< "ERAse"<<endl;
            //processList.erase(processList.begin() + counter);
            //counter-=1;
            cout<<"************************"<<endl;
        }
        //it = processList.end();
            /*
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
                p->postFailed();
            if(p->getState()==Process::ABORT)
                p->postAbort();

        }
        */
    }

   // std::cout<<processList.size() << "The size"  <<std::endl;
    counter ++;
}

void ProcessManager::attachProcess(shared_ptr<Process> bAttack)
{
    processList.push_back(bAttack);
    std::cout<<processList.size() << "ADDED" <<std::endl;
}
