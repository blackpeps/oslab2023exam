#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct process
{
    int pid, at, bt, prio, ct, ta, wt, rt;
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
    int pid;
    float avta = 0, avwt = 0;

    do
    {
        printf("Enter process upto %d: ", MAX);
        scanf("%d", &pid);
    } while (pid <= 0 || pid > MAX);

    struct process pprio[pid]; // pprio stands for preemptive priority

    printf("Enter Process Details: ");
    for (int i = 0; i < pid; i++)
    {
        printf("\nProcess ID: %d", i + 1);
        pprio[i].pid = i + 1;

        printf("\nArrival Time: ");
        scanf("%d", &pprio[i].at);

        printf("Burst Time: ");
        scanf("%d", &pprio[i].bt);

        printf("Priority: ");
        scanf("%d", &pprio[i].prio);

        pprio[i].rt = pprio[i].bt;
    }

    sort_prio(pprio, pid);

    int i = 0, j, completed = 0, max_prio, time = 0;

    while (completed != pid)
    {
        max_prio = 10000;
        int max_rt = -1;

        for (i = 0; i < pid; i++)
            if (pprio[i].at <= time && pprio[i].rt > 0 && pprio[i].prio < max_prio)
            {
                max_prio = pprio[i].prio;
                max_rt = pprio[i].rt;
                j = i;
            }
        if (max_rt == -1)
        {
            time++;
            continue;
        }
        pprio[j].rt--;
        if (pprio[j].rt == 0)
        {
            pprio[j].ct = time + 1;
            completed++;
            pprio[j].ta = pprio[j].ct - pprio[j].at;
            pprio[j].wt = pprio[j].ta - pprio[j].bt;
            avta += pprio[j].ta;
            avwt += pprio[j].wt;
        }
        time++;
    }

    sort_pid(pprio, pid);

    printf("\nProcess Table:\n");
    printf("PID\tAT\tBT\tPrio\tCT\tTA\tWT\n");
    for (int i = 0; i < pid; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", pprio[i].pid, pprio[i].at, pprio[i].bt, pprio[i].prio, pprio[i].ct, pprio[i].ta, pprio[i].wt);

    printf("\nAverage Waiting Time: %.2f\n", avwt / pid);
    printf("Average Turnaround Time: %.2f\n", avta / pid);

    return 0;
}
