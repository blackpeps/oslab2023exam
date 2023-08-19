#include <stdio.h>
#include <unistd.h>
void main()
{
    printf("Executing exec.c\n");
    char *args[] = {"./hello", NULL};
    execv(args[0], args);
    printf("This line will not be executed");
}
// rename this file to exec.c