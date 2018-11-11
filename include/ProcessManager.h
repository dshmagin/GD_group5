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

    public:

        std::vector <shared_ptr<Process>> processList;
        void updateProcessList(float deltaMs);
        void attachProcess(shared_ptr<Process> bAttack);
        void abortAllProcess();

        ProcessManager(){};
};

#endif // PROCESSMANAGER_H_INCLUDED
