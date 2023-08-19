#include <stdio.h>
int main() {
    int i, j, page[100], n, capacity, frame[10];
    int pagefault = 0, frameindex = 0, frameavailable = 0, pagefound = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the reference string (RS): ");
    for (i = 0; i < n; i++)
        scanf("%d", &page[i]);
    printf("Enter the capacity of frames: ");
    scanf("%d", &capacity);
    for (i = 0; i < capacity; i++)
        frame[i] = -1;
    for (i = 0; i < n; i++) {
        pagefound = 0;
        for (j = 0; j < capacity; j++)
            if (frame[j] == page[i]) {
                pagefound = 1;
                break;
            } 
        if (!pagefound) {
            if (frameavailable < capacity) {
                frame[frameavailable] = page[i];
                frameavailable++;
            } else {
                frame[frameindex] = page[i];
                frameindex = (frameindex + 1) % capacity;
            }
            pagefault++;
        } 
        printf("RS: %d |", page[i]); 
        for (j = 0; j < capacity; j++) {
            if (frame[j] == -1)
                printf(" _");
            else
                printf(" %d", frame[j]);
        }
        printf("\n");
    }
    printf("Page faults: %d\n", pagefault);
    printf("Page Hits: %d\n", n-pagefault);
    printf("Page Fault Ratio: %d\n", pagefault*100/n);
    printf("Page Hit Ratio: %d", (n-pagefault)*100/n);
    return 0;
}
