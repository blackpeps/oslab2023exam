#include <stdio.h>
#define MAX 20

struct process
{
    int pid, at, bt, ct, ta, wt, rt;
};

void swap(struct process *a, struct process *b)
{
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_at(struct process arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].at > arr[j + 1].at)
                swap(&arr[j], &arr[j + 1]);
}

void sort_pid(struct process arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].pid > arr[j + 1].pid)
                swap(&arr[j], &arr[j + 1]);
}

int main()
{
    int i, j, k, pid, tq, tct, rear, flag = 0;
    float avwt = 0, avta = 0;

    do
    {
        printf("Enter process upto %d:", MAX);
        scanf("%d", &pid);
    } while (pid <= 0 || pid > MAX);

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    struct process rr[pid], temp, q[100];

    printf("Enter process details: ");
    for (int i = 0; i < pid; i++)
    {
        printf("\nProcess ID: %d", i + 1);
        rr[i].pid = i + 1;

        printf("\nArrival Time: ");
        scanf("%d", &rr[i].at);

        printf("Burst Time: ");
        scanf("%d", &rr[i].bt);

        rr[i].rt = rr[i].bt;
    }

    sort_at(rr, pid);

    tct = rr[0].at;
    i = tct + 1;
    j = 0;
    q[0] = rr[0];
    rear = 0;

    while (rear != -1)
    {
        temp = q[0];
        if (rear != 0)
            for (int m = 0; m < rear; m++)
                q[m] = q[m + 1];
        rear--;
        if (temp.rt >= tq)
        {
            tct += tq;
            temp.rt -= tq;
        }
        else
        {
            tct += temp.rt;
            temp.rt = 0;
        }
        if (temp.rt == 0)
        {
            flag = 1;
            temp.ct = tct;
        }
        if (j < pid)
        {
            for (; i <= tct; i++)
                if (rr[j + 1].at == i)
                {
                    j++;
                    rear++;
                    q[rear] = rr[j];
                }
        }
        if (flag == 0)
        {
            rear++;
            q[rear] = temp;
        }
        for (k = 0; k < pid; k++)
            if (temp.pid == rr[k].pid)
                rr[k] = temp;
        flag = 0;
    }

    sort_pid(rr, pid);

    for (i = 0; i < pid; i++)
    {
        rr[i].ta = rr[i].ct - rr[i].at;
        rr[i].wt = rr[i].ta - rr[i].bt;
        avta += rr[i].ta;
        avwt += rr[i].wt;
    }

    printf("Process table:\n");
    printf("PID\tAT\tBT\tCT\tTA\tWT\n");
    for (int i = 0; i < pid; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", rr[i].pid, rr[i].at, rr[i].bt, rr[i].ct, rr[i].ta, rr[i].wt);

    printf("Average TA: %f\n", avta / pid);
    printf("Average WT: %f\n", avwt / pid);

    return 0;
}
