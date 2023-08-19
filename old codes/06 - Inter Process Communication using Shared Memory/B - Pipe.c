#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    int fd[2], child;
    char a[10];
    printf("\nEnter the string to enter into the pipe: ");
    scanf("%s", a);
    pipe(fd);
    child = fork();
    if (!child)
    {
        close(fd[0]);
        write(fd[1], a, 5);
    }
    else
    {
        close(fd[1]);
        read(fd[0], a, 5);
        printf("\nThe string retrieved from the pipe is %s\n", a);
    }
    return 0;
}