#include <stdio.h>
#define MAX 10
int main()
{
    int bsize[MAX], psize[MAX], pno, bno, temp, high;
    static int flag[MAX], allocation[MAX];
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
    {
        high = -1;
        for (int j = 0; j < bno; j++)
            if (flag[j] == 0 && bsize[j] >= psize[i])
                if (high == -1 || bsize[j] > bsize[high])
                    high = j;

        if (high != -1)
        {
            allocation[i] = high;
            flag[high] = 1;
        }
        else
            allocation[i] = -1;
    }
    printf("\nProcess No.\tSize\t\tBlock No\tSize\t\tRemaining\n");
    for (int i = 0; i < pno; i++)
    {
        if (allocation[i] == -1)
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, psize[i]);
        else
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, psize[i], allocation[i] + 1, bsize[allocation[i]], bsize[allocation[i]] - psize[i]);
    }
    return 0;
}
