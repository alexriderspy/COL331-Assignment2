#include "types.h"
#include "stat.h"
#include "user.h"

// TC#3: EDF Non-schedulable test case
// Total no of processes spawned = 5
// No of non-schedulable processes = 2
// Processes with pids 5 and 7 are non-schedulable
int main(int argc, char *argv[])
{   
    int num_procs = 4;
    int deadline_value[4] = {16, 14, 18, 21};
    int exectime[4] = {4, 9, 6, 8};

    int parent_pid = getpid();

    // Set the scheduling policy to EDF
    deadline(parent_pid, 23);
    exec_time(parent_pid, 5);
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
