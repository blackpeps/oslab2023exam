#include <stdio.h>
#include <stdlib.h>
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
    int pid;
    float avwt = 0, avta = 0;

    do
    {
        printf("Enter the number of processes (up to %d): ", MAX);
        scanf("%d", &pid);
    } while (pid <= 0 || pid > MAX);

    struct process srtf[pid];

    printf("Enter process details:\n");
    for (int i = 0; i < pid; i++)
    {
        printf("\nProcessID: %d\n", i + 1);
        srtf[i].pid = i + 1;

        printf("Arrival Time: ");
        scanf("%d", &srtf[i].at);

        printf("Burst Time: ");
        scanf("%d", &srtf[i].bt);

        srtf[i].rt = srtf[i].bt;
    }

    sort_at(srtf, pid);

    int time = 0, completed = 0, short_job;

    while (completed != pid)
    {
        short_job = -1;
        for (int i = 0; i < pid; i++)
            if (srtf[i].at <= time && srtf[i].rt > 0)
                if (short_job == -1 || srtf[i].rt < srtf[short_job].rt)
                    short_job = i;

        if (short_job != -1)
        {
            srtf[short_job].rt--;
            if (srtf[short_job].rt == 0)
            {
                srtf[short_job].ct = time + 1;
                completed++;
                srtf[short_job].ta = srtf[short_job].ct - srtf[short_job].at;
                srtf[short_job].wt = srtf[short_job].ta - srtf[short_job].bt;
                avta += srtf[short_job].ta;
                avwt += srtf[short_job].wt;
            }
        }
        time++;
    }

    sort_pid(srtf, pid);

    printf("\nProcess Table:\n");
    printf("PID\tAT\tBT\tCT\tTA\tWT\n");
    for (int i = 0; i < pid; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", srtf[i].pid, srtf[i].at, srtf[i].bt, srtf[i].ct, srtf[i].ta, srtf[i].wt);

    printf("Average TA: %f\n", avta / pid);
    printf("Average WT: %f\n", avwt / pid);

    return 0;
}
