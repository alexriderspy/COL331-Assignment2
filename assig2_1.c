#include "types.h"
#include "stat.h"
#include "user.h"

// TC#1: EDF Schedulable test case
int main(int argc, char *argv[])
{   
    int num_procs = 3;
    int deadline_value[3] = {18, 24, 21};
    int exectime[3] = {5, 6, 4};

    int parent_pid = getpid();

    // Set the scheduling policy to EDF
    deadline(parent_pid, 19);
    exec_time(parent_pid, 4);
    sched_policy(parent_pid, 0);

    for(int i = 0; i < num_procs; i++)
    {
        int cid = fork();
        if (cid != 0)
        {
            // Set the scheduling policy to EDF
            deadline(cid, deadline_value[i]);
            exec_time(cid, exectime[i]);
            sched_policy(cid, 0);
        }
        else
        {
            /*The XV6 kills the process if th exec time is completed*/
            while(1) {
                
            }
        }
    }

    while(1) {

    }
}
