#include <stdio.h>
#define MAX 10
void main()
{
    int bsize[MAX], psize[MAX], bno, pno, flag[MAX], allocation[MAX];
    for (int i = 0; i < MAX; i++)
    {
        flag[i] = 0;
        allocation[i] = -1;
    }
    printf("Enter no. of blocks: ");
    scanf("%d", &bno);
    printf("Enter size of each block:\t");
    for (int i = 0; i < bno; i++)
        scanf("%d", &bsize[i]);
    printf("Enter no. of process: ");
    scanf("%d", &pno);
    printf("Enter size of each process:\t");
    for (int i = 0; i < pno; i++)
        scanf("%d", &psize[i]);

    for (int i = 0; i < pno; i++)
        for (int j = 0; j < bno; j++)
            if (flag[j] == 0 && bsize[j] >= psize[i])
            {
                allocation[j] = i;
                flag[j] = 1;
                break;
            }
    printf("\nBlock No\tSize\tProcess No.\t\tSize\t\tRemaining");
    for (int i = 0; i < bno; i++)
    {
        printf("\n%d\t\t%d\t\t", i + 1, bsize[i]);
        if (flag[i] == 1)
            printf("%d\t\t%d\t\t%d", allocation[i] + 1, psize[allocation[i]], bsize[i] - psize[allocation[i]]);
        else
            printf("Not Allocated");
    }
}
