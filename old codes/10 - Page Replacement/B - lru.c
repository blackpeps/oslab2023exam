#include <stdio.h>
int main() {
    int pages[100], n, capacity, frame[10], page_faults = 0, frame_index = 0, page_age[10];
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the reference string (RS): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    printf("Enter the capacity of frames: ");
    scanf("%d", &capacity);
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
        page_age[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int page_found = 0;
        for (int j = 0; j < capacity; j++)
            if (frame[j] == pages[i]) {
                page_found = 1;
                page_age[j] = i + 1;
                break;
            }
        if (!page_found) {
            int lru_index = 0, min_age = page_age[0];
            for (int j = 1; j < capacity; j++) {
                if (page_age[j] < min_age) {
                    lru_index = j;
                    min_age = page_age[j];
                }
            }
            frame[lru_index] = pages[i];
            page_age[lru_index] = i + 1;
            page_faults++;
        }
        printf("RS: %d |: ", pages[i]);
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == -1)
                printf(" _");
            else
                printf(" %d", frame[j]);
        }
        printf("\n");
    }
    printf("Page faults: %d\n", page_faults);
    printf("Page Hits: %d\n", n-page_faults);
    printf("Page Fault Ratio: %d\n", page_faults*100/n);
    printf("Page Hit Ratio: %d", (n-page_faults)*100/n);
    return 0;
}