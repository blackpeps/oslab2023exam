#include <stdio.h>

int main() {
    int ioq[20], i, n, j, ihead, temp, scan, tot;
    float seek = 0, avgs;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the initial head position: ");
    scanf("%d", &ihead);

    ioq[0] = ihead;
    ioq[1] = 0;
    n += 2;

    printf("Enter the I/O queue requests:\n");
    for (i = 2; i < n; i++) {
        scanf("%d", &ioq[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (ioq[j] > ioq[j + 1]) {
                temp = ioq[j];
                ioq[j] = ioq[j + 1];
                ioq[j + 1] = temp;
            }
        }
    }

    ioq[n] = ioq[n - 1];

    for (i = 0; i < n; i++) {
        if (ihead == ioq[i]) {
            scan = i;
            break;
        }
    }

    printf("\nOrder of requests served:\n\n");
    tot = 0;
    for (i = scan; i >= 0; i--) {
        tot = ioq[i] - ioq[i - 1];
        if (i == 0)
            tot = ioq[i] - ioq[scan + 1];
        if (tot < 0)
            tot = tot * -1;
        //printf("%d\t%d\n", ioq[i], tot);
        printf("%d--> ", ioq[i];
    }

    for (i = scan + 1; i < n; i++) {
        tot = ioq[i + 1] - ioq[i];
        if (tot < 0)
            tot = tot * -1;
        //printf("%d\t%d\n", ioq[i], tot);
        printf("%d--> ", ioq[i];
    }

    seek = ioq[scan] + ioq[n - 1];
    avgs = seek / (n - 2);

    printf("\nTotal Seek time:\t\t%.2f\n", seek);
    printf("Average seek time:\t%.2f\n\n", avgs);

    return 0;
}