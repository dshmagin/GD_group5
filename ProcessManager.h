#ifndef PROCESSMANAGER_H_INCLUDED
#define PROCESSMANAGER_H_INCLUDED
#include "Process.h"
#include <list>



class ProcessManager
{
    private:

    public:
        std::list <Process*> processList;
        updateProcessList(float deltaMs);
        attachProcess(Process* p);
        abortAllProcess();
        removeProcess(Process* p);

        ProcesManager(){};
};

#endif // PROCESSMANAGER_H_INCLUDED
