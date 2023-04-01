#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{

    int parent_pid = getpid();

    // Set the scheduling policy to RM
    rate(parent_pid, 1);
    exec_time(parent_pid, 10);
    deadline(parent_pid, 3);
    printf(1,"successfully called\n");
    exit();
}