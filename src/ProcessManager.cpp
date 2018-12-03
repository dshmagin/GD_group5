#include "ProcessManager.h"
#include <SFML/Graphics.hpp>
#include "Items.h"
#include "DmgDisplay.h"
#include "Process.h"
#include "iostream"
#include <vector>
#include <cstdlib>

using namespace std;

void ProcessManager::setRenderWindow(shared_ptr<sf::RenderWindow> &window_ptr)
{
    this -> window_ptr = window_ptr;
}

//                 0     1     2       3      4       5         6
// enum state {RUNNING,DEAD, PAUSED, FAIL, SUCCESS, ABORT, UNINITIALIZED};
void ProcessManager::updateProcessList(float deltaMs)
{
    shared_ptr<Process> p;

    for (vector<shared_ptr<Process>>::iterator it1 = itemList.begin(); it1 != itemList.end(); it1++)
    {
        p = *it1;
        if(p->getState()== Process::RUNNING)
            p->update(deltaMs);
    }
    /*
    for (vector<shared_ptr<Process>>::iterator it2 = enemyList.begin(); it2 != enemyList.end(); it2++)
    {
        p = *it2;
        if(p->getState()== Process::RUNNING)
            p->update(deltaMs);
    }
    for (vector<shared_ptr<Process>>::iterator it3 = attackList.begin(); it3 != attackList.end(); it3++)
    {
        p = *it3;
        if(p->getState()== Process::RUNNING)
            p->update(deltaMs);
    }
    */


    vector <shared_ptr<Process>> liveProcess;
    for (vector<shared_ptr<Process>>::iterator it = processList.begin(); it != processList.end(); it++)

    {
        p = *it;
        if(p != nullptr)
        {

            if(p->getState()== Process::RUNNING && p -> type != Process::ITEM)
                p->update(deltaMs);
            if( p->getState()== Process::UNINITIALIZED)
                p->initialize();

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
                    if(p->state !=Process::DEAD)
                        {
                        if(p -> body.getGlobalBounds().intersects(enemy -> body.getGlobalBounds()) && enemy -> state != Process::DEAD )
                        {
                           cout<< "ENEMY Damaged by "<< p -> damage << endl;
                           shared_ptr<DmgDisplay> dmgDisp = make_shared<DmgDisplay>(window_ptr);
                           dmgDisp -> createText(enemy -> body.getPosition().x  , enemy -> body.getPosition().y , Process::ATTACK ,p->damage);
                           enemy -> health -= p-> damage * player_ptr->getDM();
                           liveProcess.push_back((shared_ptr<Process>) dmgDisp);
                           dmgDisp->update(deltaMs);
                           p->state = Process::DEAD;

                        //kill the enemy if health reaches below zero
                            if(enemy -> health <= 0 )
                            {
                                int itemDropRate = rand() % 100;
                                int itemType = (rand() % 3) + 1;
                                if( itemDropRate >= 0 )
                                {
                                    shared_ptr<Items> itemToDrop = make_shared<Items>(window_ptr);
                                    itemToDrop -> toDrop = itemType;
                                    itemToDrop -> initialize();
                                    itemToDrop -> dropItem(enemy -> body.getPosition().x + 16 , enemy -> body.getPosition().y +64);

                                    liveProcess.push_back((shared_ptr<Process>) itemToDrop);
                                    itemList.push_back((shared_ptr<Process>) itemToDrop);

                                    enemy -> state = Process::DEAD;
                                }
                                else
                                {
                                cout<<"Enemy has died!!!!!"<<endl;
                                enemy -> state = Process::DEAD;
                                }

                            }
                        }
                    }
                    if(!enemy->getState()== Process::DEAD )
                    {
                        liveEnemy.push_back(enemy);
                    }
                    // add live enemies to new list
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

  if(process -> type == Process::ATTACK)
    {
        attackList.push_back(process);
    }
    processList.push_back(process);
}

int ProcessManager::itemNearBy(sf::RectangleShape body)
{

    shared_ptr<Process> item;
    //List for enemy who hasnt died when damaged
    vector <shared_ptr<Process>> unpickedItem;
    //Loop through all the enemy to see if the attack hits any of them
    curItem = Process::NONE;
    for (vector<shared_ptr<Process>>::iterator it3 = itemList.begin(); it3 != itemList.end(); it3++)
    {
           item = *it3;
            cout<<"itemList size = " << itemList.size()<<endl;
           if( body.getGlobalBounds().intersects(item -> body.getGlobalBounds()) )
           {
               cout<<"item GRABBED!!!!"<< endl;
               curItem = item ->toDrop;
               item ->state = Process::DEAD;
           }
           if(!item -> state == Process::DEAD)
           {
               unpickedItem.push_back(item);
           }
    }
    itemList.swap(unpickedItem);
    return curItem;
}

void ProcessManager::clearManager()
{
    processList.clear();
    itemList.clear();
    enemyList.clear();
}

int ProcessManager::checkEnemies()
{
    return enemyList.size();
}
void ProcessManager::setPlayer(Player* player) {
	player_ptr = player;
}
