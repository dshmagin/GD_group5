#ifndef ENEMYATTACKMANAGER_H_INCLUDED
#define ENEMYATTACKMANAGER_H_INCLUDED
#include "Process.h"
#include "Player.h"
#include <list>
#include <vector>
#include "EnemyAttackManager.h"
#include <memory>
using namespace std;
class EnemyAttackManager
{
    private:
        Player* player;
        shared_ptr<sf::RenderWindow> window_ptr;
        shared_ptr<EnemyAttackManager> enemyPM;

    public:

        std::vector <shared_ptr<Process>> processList;
        std::vector <shared_ptr<Process>> queueList;
        void updateProcessList(float deltaMs);
        void attachProcess(shared_ptr<Process> process);
        void setEnemyManager(shared_ptr<sf::RenderWindow> &window_ptr, Player* player);
        void abortAllProcess();

};

#endif // PROCESSMANAGER_H_INCLUDED
