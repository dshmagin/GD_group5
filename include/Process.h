#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED
#define NULL nullptr

class Process
{
    public:
        enum state {RUNNING,DEAD, PAUSED, FAIL, SUCCESS, ABORT, UNINITIALIZED};
        int state;
        Process* child = nullptr;

        Process(){};
        virtual void initialize();
        virtual void update(float deltaTime) = 0;
        //virtual void postSuccess();
       // virtual void postFailed();
       // virtual void postAbort();

        void Pause();
        void Unpause();
        bool isDead();
        virtual int getState();
        bool hasChild();
        Process* getChild();
};


#endif // PROCESS_H_INCLUDED
