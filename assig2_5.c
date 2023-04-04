#include "types.h"
#include "stat.h"
#include "user.h"

// TC#5: RM Non-schedulable test case
// Total no of processes spawned = 5
// No of non-schedulable processes = 1
// Process with pid 6 is non-schedulable
// Processes with pids 3 and 7 have same priority
int main(int argc, char *argv[])
{   
    int num_procs = 4;
    int rate_value[4] = {22, 11, 4, 2};
    int exectime[4] = {1, 3, 5, 4};

    int parent_pid = getpid();

    // Set the scheduling policy to RM
    rate(parent_pid, 2);
    exec_time(parent_pid, 5);
    sched_policy(parent_pid, 1);

    for(int i = 0; i < num_procs; i++)
    {
        int cid = fork();
        if (cid != 0)
        {
            // Set the scheduling policy to RM
            rate(cid, rate_value[i]);
            exec_time(cid, exectime[i]);
            sched_policy(cid, 1);
        }
        else
        {
            /*The XV6 kills the process if the exec time is completed*/
            while(1) {
                
            }
        }
    }

    while(1) {

    }
}
