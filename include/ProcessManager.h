#ifndef PROCESSMANAGER_H_INCLUDED
#define PROCESSMANAGER_H_INCLUDED
#include "Process.h"
#include <list>
#include <vector>
#include <memory>
using namespace std;
class ProcessManager
{
    private:
        int curItem = Process::NONE;
    public:

        shared_ptr<sf::RenderWindow> window_ptr;
        std::vector <shared_ptr<Process>> processList;
        std::vector <shared_ptr<Process>> itemList;
        std::vector <shared_ptr<Process>> enemyList;
        void updateProcessList(float deltaMs);
        void attachProcess(shared_ptr<Process> process);
        void abortAllProcess();
        int itemNearBy(sf::RectangleShape body);
        void clearManager();
        ProcessManager(){};
};

#endif // PROCESSMANAGER_H_INCLUDED
