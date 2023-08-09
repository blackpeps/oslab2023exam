#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t p;

    printf("Before fork()\n");
    p = fork();
    if (p == 0)
    {
        printf("*Child ID: %d\n", getpid());
        printf("Parent ID: %d\n", getppid());
    }
    else
    {
        int wstatus;
        int w1 = wait(&wstatus);
        printf("Status is %d \n", WIFEXITED(wstatus));
        printf("The process id of terminated child is %d\n", w1);
    }
    return 0;
}
