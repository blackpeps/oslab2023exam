#include <stdio.h>

#define MAX_BLOCKS 10
#define MAX_FILES 10

typedef struct {
    int id;
    int size;
    int allocated;
} MemoryBlock;

void worstFit(MemoryBlock blocks[], int numBlocks, int files[], int numFiles) {
    int i, j;
    int worstIndex;
    
    for (i = 0; i < numFiles; i++) {
        worstIndex = -1;
        
        for (j = 0; j < numBlocks; j++) {
            if (!blocks[j].allocated && blocks[j].size >= files[i]) {
                if (worstIndex == -1 || blocks[j].size > blocks[worstIndex].size) {
                    worstIndex = j;
                }
            }
        }
        
        if (worstIndex != -1) {
            blocks[worstIndex].allocated = 1;
            printf("Process %d allocated to block %d\n", i, blocks[worstIndex].id);
        } else {
            printf("No block available to allocate process %d\n", i);
        }
    }
}

int main() {
    MemoryBlock blocks[MAX_BLOCKS];
    int numBlocks, numFiles;
    int files[MAX_FILES];
    int i;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    for (i = 0; i < numBlocks; i++) {
        blocks[i].id = i + 1;
        printf("Enter the size of block %d: ", blocks[i].id);
        scanf("%d", &blocks[i].size);
        blocks[i].allocated = 0;
    }

    printf("Enter the total number of processes: ");
    scanf("%d", &numFiles);

    printf("Enter the size of each process:\n");
    for (i = 0; i < numFiles; i++) {
        printf("Process %d: ", i);
        scanf("%d", &files[i]);
    }

    worstFit(blocks, numBlocks, files, numFiles);

    return 0;
}