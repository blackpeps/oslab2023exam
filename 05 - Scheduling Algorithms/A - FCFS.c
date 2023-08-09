#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct process
{
    int pid, at, bt, ct, ta, wt;
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
        {
            if (arr[j].at > arr[j + 1].at)
                swap(&arr[j], &arr[j + 1]);
        }
}
void sort_pid(struct process arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].pid > arr[j + 1].pid)
                swap(&arr[j], &arr[j + 1]);
        }
}
int main()
{
    int pid;
    float avwt = 0, avta = 0;

    do
    {
        printf("Enter the number of process (upto %d): ", MAX);
        scanf("%d", &pid);
    } while (pid <= 0 || pid > MAX);

    struct process fcfs[pid];

    printf("Enter process details:\n");
    for (int i = 0; i < pid; i++)
    {
        printf("\nProcessID: %d\n", i + 1);
        fcfs[i].pid = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &fcfs[i].at);

        printf("Burst Time: ");
        scanf("%d", &fcfs[i].bt);
    }

    sort_at(fcfs, pid);

    int current_time = 0;

    fcfs[0].ct = 0;

    for (int i = 0; i < pid; i++)
        fcfs[i + 1].ct = fcfs[i].ct + fcfs[i].bt;

    for (int i = 0; i < pid; i++)
    {
        if (current_time < fcfs[i].at)
            current_time = fcfs[i].at;

        fcfs[i].ct = current_time + fcfs[i].bt;
        fcfs[i].ta = fcfs[i].ct - fcfs[i].at;
        fcfs[i].wt = fcfs[i].ta - fcfs[i].bt;

        avwt += fcfs[i].wt;
        avta += fcfs[i].ta;

        current_time = fcfs[i].ct;
    }

    avta /= pid;
    avwt /= pid;

    sort_pid(fcfs, pid);

    printf("Process table:\n");
    printf("PID\tAT\tBT\tCT\tTA\tWT\n");
    for (int i = 0; i < pid; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", fcfs[i].pid, fcfs[i].at, fcfs[i].bt, fcfs[i].ct, fcfs[i].ta, fcfs[i].wt);

    printf("\nAverage WT: %d", avta);
    printf("Average TA: %d", avwt);

    return 0;
}
