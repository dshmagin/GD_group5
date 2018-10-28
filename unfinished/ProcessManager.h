#ifndef PROCESSMANAGER_H_INCLUDED
#define PROCESSMANAGER_H_INCLUDED
#include "Process.h"
#include <list>



class ProcessManager
{
    private:

    public:
        std::list <Process*> processList;
        void updateProcessList(float deltaMs);
        void attachProcess(Process* p);
        void abortAllProcess();
        void removeProcess(Process* p);

        ProcesManager(){};
};

#endif // PROCESSMANAGER_H_INCLUDED
