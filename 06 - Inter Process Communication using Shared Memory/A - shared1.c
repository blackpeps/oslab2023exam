#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SHMSZ 1024
int main()
{
    int shmid;
    key_t key;
    char *shm, *s;
    char message[] = "Hello, World!";
    key = 5678;
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }
    if ((shm = shmat(shmid, NULL, 0)) == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }
    strncpy(shm, message, SHMSZ);
    exit(0);
}