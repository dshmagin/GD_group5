#ifndef PROCESSMANAGER_H_INCLUDED
#define PROCESSMANAGER_H_INCLUDED
#include "Process.h"
#include <list>
#include <vector>
#include <memory>
#include <list>
using namespace std;
class ProcessManager
{
    private:

    public:
        //std::vector <shared_ptr<Process>> processList;
        std::list <shared_ptr<Process>> processList;
        void updateProcessList(float deltaMs);
        void attachProcess(shared_ptr<Process> bAttack);
        void abortAllProcess();
        void removeProcess(shared_ptr<Process> bAttack);

        ProcesManager(){};
};

#endif // PROCESSMANAGER_H_INCLUDED
