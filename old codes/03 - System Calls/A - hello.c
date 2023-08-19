#include <stdio.h>
#include <unistd.h>
void main()
{
    printf("Now in hello.c\n");
    printf("The PID is %d\n", getpid());
}
// rename this file to hello.c