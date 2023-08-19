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
        wait(NULL);
        printf("Child ID: %d\n", p);
        printf("*Parent ID: %d\n", getppid());
    }
    return 0;
}
