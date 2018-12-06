#include "EnemyAttackManager.h"
#include <SFML/Graphics.hpp>
#include "Items.h"
#include "DmgDisplay.h"
#include "Process.h"
#include "iostream"
#include <vector>
#include <cstdlib>
#include "DmgDisplay.h"

using namespace std;

void EnemyAttackManager::setEnemyManager(shared_ptr<sf::RenderWindow> &window_ptr, Player* player)
{
	this-> player = player;
    this -> window_ptr = window_ptr;
}

//                 0     1     2       3      4       5         6
// enum state {RUNNING,DEAD, PAUSED, FAIL, SUCCESS, ABORT, UNINITIALIZED};
void EnemyAttackManager::updateProcessList(float deltaMs)
{
    shared_ptr<Process> p;
   vector <shared_ptr<Process>> liveProcess;
    for (vector<shared_ptr<Process>>::iterator it = processList.begin(); it != processList.end(); it++)
    {

        p = *it;

        if(p != nullptr)
        {
            if( p->getState()== Process::UNINITIALIZED)
                p->initialize();

            if(p->getState()== Process::RUNNING && p -> type != Process::ITEM)
            {
                if(p->type = Process::BOSSATTACK)
                {
                    if(p->body.getGlobalBounds().intersects(player->getPlayerBody().getGlobalBounds()))
                    {
                            //if (attack.x > player.x && attack.x +32 < player.x  && attack.y > player.y && attack.y +32 < player.y)
                    //if (p->body.getPosition().x -50< player -> getPlayerBody().getPosition().x && p->body.getPosition().x +50 > player -> getPlayerBody().getPosition().x
                    //    && p->body.getPosition().y -50< player -> getPlayerBody().getPosition().y && p->body.getPosition().y +50 > player -> getPlayerBody().getPosition().y)
                    //{
                        float elementModifier = 1;
                    	if (p->getAttackElement() == (player->getElement() + 1) % 4) {
                    		elementModifier = 2.f/3.f;
                    	} else if (player->getElement() == (p->getAttackElement() + 1) % 4) {
                    		elementModifier = 1.5;
                    	}
                        
                    	float damage = p->damage * elementModifier;
                        shared_ptr<DmgDisplay> dmgDisp = make_shared<DmgDisplay>(window_ptr);
                        dmgDisp ->initialize();
                        dmgDisp -> createText(player -> getPlayerBody().getPosition().x  , player -> getPlayerBody().getPosition().y , Process::E_ATTACK , damage );
                        liveProcess.push_back((shared_ptr<Process>) dmgDisp);
                        dmgDisp->update(deltaMs);
                        player->healPlayer(-damage);
                        p->state = Process::DEAD;
                    }

                }
                p->update(deltaMs);
            }

            if(!p->getState()== Process::DEAD)
            {
                liveProcess.push_back(p);
            }
    }

    }
    processList.swap(liveProcess);

}

void EnemyAttackManager::attachProcess(shared_ptr<Process> process)
{
    if(process -> type == Process::BOSSATTACK)
    {
        processList.push_back(process);

    }

}
