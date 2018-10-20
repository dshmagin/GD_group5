#ifndef PROCESSMANAGER_H_INCLUDED
#define PROCESSMANAGER_H_INCLUDED

class PROCESSMANAGER_H_INCLUDED
{
    public:

        list<Process*> processList;
        updateProcessList(float deltaMs);
        attachProcess(Process* p);
        abortAllProcess();
        removeProcess(Process* p);
};

#endif // PROCESSMANAGER_H_INCLUDED
