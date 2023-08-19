#include <stdio.h>
#include <unistd.h>
int main()
{
    int pid, ppid;
    pid = getpid();
    ppid = getppid();
    printf("Process ID: %d\n", pid);
    printf("Parent ID: %d\n", ppid);
    return 0;
}
