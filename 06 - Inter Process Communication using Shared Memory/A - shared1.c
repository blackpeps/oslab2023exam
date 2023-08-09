#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHMSZ 1024

int main() {
    key_t key = 5678;
    int shmid = shmget(key, SHMSZ, IPC_CREAT | 0666);
    char *shm = shmat(shmid, NULL, 0);

    strncpy(shm, "Hello, World!", SHMSZ);

    shmdt(shm);
    return 0;
}
