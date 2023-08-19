#include <stdio.h>
int i, j, k, n, tq, tct, rear, f = 0;
float atat, awt;
struct process
{
    int pid, at, bt, rt, ct, tat, wt;
};
struct process p[20], temp, q[100];
void main()
{
    printf("Enter the no. of processes : ");
    scanf("%d", &n);
    printf("Enter the time quantum : ");
    scanf("%d", &tq);
    for (i = 0; i < n; i++)
    {
        printf("\nprocess %d \n", i + 1);
        printf("Enter the arrival time : ");
        scanf("%d", &p[i].at);
        printf("Enter the burst time : ");
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].pid = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].at > p[j].at)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    tct = p[0].at;
    i = tct + 1;
    j = 0;
    q[0] = p[0];
    rear = 0;
    while (rear != -1)
    {
        temp = q[0];
        if (rear != 0)
        {
            for (int m = 0; m < rear; m++)
            {
                q[m] = q[m + 1];
            }
        }
        rear--;
        if (temp.rt >= tq)
        {
            tct = tct + tq;
            temp.rt = temp.rt - tq;
        }
        else
        {
            tct = tct + temp.rt;
            temp.rt = 0;
        }
        if (temp.rt == 0)
        {
            f = 1;
            temp.ct = tct;
        }
        if (j < n)
        {
            for (; i <= tct; i++)
            {
                if (p[j + 1].at == i)
                {
                    j++;
                    rear++;
                    q[rear] = p[j];
                }
            }
        }
        if (f == 0)
        {
            rear++;
            q[rear] = temp;
        }
        for (k = 0; k < n; k++)
        {
            if (temp.pid == p[k].pid)
                p[k] = temp;
        }
        f = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].pid > p[j].pid)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        atat = atat + p[i].tat;
        p[i].wt = p[i].tat - p[i].bt;
        awt = awt + p[i].wt;
    }
    printf("PID\tArrival\tBurst\tCompletion\tTurnAround\tWaiting\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", i + 1, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    atat = atat / n;
    awt = awt / n;
    printf("Average waiting time is %f\nAverage turnaround time is %f\n", awt, atat);
}
