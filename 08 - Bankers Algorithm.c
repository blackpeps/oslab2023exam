#include <stdio.h>
struct pro
{
    int all[10], max[10], need[10];
    int flag;
};
int i, j, pno, r, id, k = 0, safe = 0, exec, count = 0, wait = 0;
struct pro p[10];
int aval[10], seq[10];
void safeState()
{
    while (count != pno)
    {
        safe = 0;
        for (i = 0; i < pno; i++)
            if (p[i].flag)
            {
                exec = r;
                for (j = 0; j < r; j++)
                {
                    if (p[i].need[j] > aval[j])
                    {
                        exec = 0;
                    }
                }
                if (exec == r)
                {
                    for (j = 0; j < r; j++)
                    {
                        aval[j] += p[i].all[j];
                    }
                    p[i].flag = 0;
                    seq[k++] = i;
                    safe = 1;
                    count++;
                }
            }

        if (!safe)
        {
            printf("System is in Unsafe State\n");
            break;
        }
    }
    if (safe)
    {
        printf("\n\nSystem is in safestate \n");
        printf("Safe State Sequence \n");
        for (i = 0; i < k; i++)
            printf("P[%d]   ", seq[i]);
        printf("\n\n");
    }
}
int main()
{
    printf("Enter no of process: ");
    scanf("%d", &pno);

    printf("Enter no. of resources: ");
    scanf("%d", &r);

    printf("Enter Available Resource of each type: ");
    for (i = 0; i < r; i++)
        scanf("%d", &aval[i]);

    printf("\n---Resource Details---");
    for (i = 0; i < pno; i++)
    {
        printf("\nProcess %d\n", i);
        printf("Allocation Matrix:\t\t");
        for (j = 0; j < r; j++)
            scanf("%d", &p[i].all[j]);

        printf("Maximum Resource Request:\t");
        for (j = 0; j < r; j++)
            scanf("%d", &p[i].max[j]);

        p[i].flag = 1;
    }

    for (i = 0; i < pno; i++)
        for (j = 0; j < r; j++)
            p[i].need[j] = p[i].max[j] - p[i].all[j];

    printf("\nProcess Details\n");
    printf("Pid\t\tAllocation\t\tMax\t\tNeed\n");
    for (i = 0; i < pno; i++)
    {
        printf("%d\t\t", i);
        for (j = 0; j < r; j++)
            printf("%d  ", p[i].all[j]);
        printf("\t\t");
        for (j = 0; j < r; j++)
            printf("%d  ", p[i].max[j]);
        printf("\t\t");
        for (j = 0; j < r; j++)
            printf("%d  ", p[i].need[j]);
        printf("\n");
    }

    safeState();
    return 0;
}
