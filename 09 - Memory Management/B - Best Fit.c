#include <stdio.h>
#define MAX 10
int main()
{
    int bsize[MAX], psize[MAX], pno, bno, temp, low;
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
    printf("\nProcess No.\tSize\t\tBlock No\tSize\t\tRemaining\n");
    for (int i = 0; i < pno; i++)
    {
        low = 10000;
        allocation[i] = -1;
        for (int j = 0; j < bno; j++)
            if (flag[j] != 1)
            {
                temp = bsize[j] - psize[i];
                if (temp >= 0 && temp < low)
                {
                    allocation[i] = j;
                    low = temp;
                }
            }
        if (allocation[i] != -1)
        {
            printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, psize[i], allocation[i] + 1, bsize[allocation[i]], low);
            flag[allocation[i]] = 1;
        }
    }
    return 0;
}
