#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

#define SHMSZ 1024

int main()
{
    key_t key = 5678;
    int shmid = shmget(key, SHMSZ, 0666);
    char *shm = shmat(shmid, NULL, 0);

    printf("Message read from shared memory: %s\n", shm);

    shmdt(shm);
    return 0;
}
