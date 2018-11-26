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
            if(p -> type == Process::ATTACK && p -> state != Process::DEAD)
            {
                shared_ptr<Process> enemy;
                //List for enemy who hasnt died when damaged
                vector <shared_ptr<Process>> liveEnemy;
                //Loop through all the enemy to see if the attack hits any of them
                for (vector<shared_ptr<Process>>::iterator it2 = enemyList.begin(); it2 != enemyList.end(); it2++)
                {
                    enemy = *it2;
                    // check the if the attack hits something in the enemy list
                    // damage enemys health by the process's attack
                    // kill the process
                    if(p -> body.getGlobalBounds().intersects(enemy -> body.getGlobalBounds()) && enemy -> state != Process::DEAD)
                    {
                       cout<< "ENEMY Damaged by "<< p -> damage << endl;
                       enemy -> health -= p-> damage;
                       p->state = Process::DEAD;
                    }
                    //kill the enemy if health reaches below zero
                    if(enemy -> health <= 0 )
                    {
                        cout<<"Enemy has died!!!!!"<<endl;
                        enemy -> state = Process::DEAD;
                    }
                    // add live enemies to new list
                    if(!enemy->getState()== Process::DEAD)
                    {
                        liveEnemy.push_back(enemy);
                    }
                }
                // swap list
                enemyList.swap(liveEnemy);
            }
        }

    }
    processList.swap(liveProcess);
}

void ProcessManager::attachProcess(shared_ptr<Process> process)
{
    if(process -> type == Process::R_ENEMY)
    {
        enemyList.push_back(process);
    }
    processList.push_back(process);
}

