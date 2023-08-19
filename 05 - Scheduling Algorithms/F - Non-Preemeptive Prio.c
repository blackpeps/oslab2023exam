#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct process
{
    int pid, at, bt, prio, ct, ta, wt;
};

void swap(struct process *a, struct process *b)
{
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

void sort_prio(struct process arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].prio > arr[j + 1].prio)
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
    int pid, i, j, min_at = INT_MAX;

    do
    {
        printf("Enter process upto %d: ", MAX);
        scanf("%d", &pid);
    } while (pid <= 0 || pid > MAX);

    struct process npprio[pid]; // npprio stands for non-preemptive priority

    printf("Enter Process Details: ");
    for (int i = 0; i < pid; i++)
    {
        printf("\nProcess ID: %d", i + 1);
        npprio[i].pid = i + 1;

        printf("\nArrival Time: ");
        scanf("%d", &npprio[i].at);

        printf("Burst Time: ");
        scanf("%d", &npprio[i].bt);

        printf("Priority: ");
        scanf("%d", &npprio[i].prio);

        if (min_at > npprio[i].at)
            min_at = npprio[i].at;
    }

    sort_prio(npprio, pid);

    npprio[0].wt = 0;
    npprio[0].ct = npprio[0].bt + npprio[0].at;
    npprio[0].ta = npprio[0].ct - npprio[0].at;
    float avta = npprio[i].ta, avwt = npprio[i].wt;

    for (i = 1; i < pid; i++)
    {
        npprio[i].wt = npprio[i - 1].ct - npprio[i].at;
        if (npprio[i].wt < 0)
            npprio[i].wt = 0;

        npprio[i].ct = npprio[i].bt + npprio[i - 1].ct;
        npprio[i].ta = npprio[i].ct - npprio[i].at;

        avta += npprio[i].ta;
        avwt += npprio[i].wt;
    }

    sort_pid(npprio, pid);

    printf("\nProcess Table:\n");
    printf("PID\tAT\tBT\tPrio\tCT\tTA\tWT\n");
    for (int i = 0; i < pid; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", npprio[i].pid, npprio[i].at, npprio[i].bt, npprio[i].prio, npprio[i].ct, npprio[i].ta, npprio[i].wt);

    printf("Average TA: %f\n", avta / pid);
    printf("Average WT: %f\n", avwt / pid);

    return 0;
}
