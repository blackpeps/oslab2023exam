#include <stdio.h>
#include <unistd.h>
int main()
{
    int pid, pid1, pid2;
    pid = fork();
    if (pid == -1)
    {
        printf("Error in process \n");
    }
    if (pid != 0)
    {
        pid1 = getpid();
        printf("The parent process id is %d\n", pid1);
    }
}
