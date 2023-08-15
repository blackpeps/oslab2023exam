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
            if (arr[j].at > arr[j + 1].at)
                swap(&arr[j], &arr[j + 1]);
}

void sort_bt(struct process arr[], int n)
{
    int k = 1, min = 0, btime = 0;
    for (int i = 0; i < n; i++)
    {
        btime = btime + arr[i].bt;
        min = arr[k].bt;
        for (int j = k; j < n; j++)
            if (btime >= arr[j].at && arr[j].bt < min)
                swap(&arr[j], &arr[j - 1]);
        k++;
    }
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
    int pid, avta = 0, avwt = 0;

    do
    {
        printf("Enter process upto %d: ", MAX);
        scanf("%d", &pid);
    } while (pid <= 0 || pid > MAX);

    struct process sjf[pid];

    printf("Enter process details: ");
    for (int i = 0; i < pid; i++)
    {
        printf("\nProcess ID: %d", i + 1);
        sjf[i].pid = i + 1;

        printf("\nArrival Time: ");
        scanf("%d", &sjf[i].at);

        printf("Burst Time: ");
        scanf("%d", &sjf[i].bt);
    }

    sort_at(sjf, pid);
    sort_bt(sjf, pid);

    int current_time = 0;
    sjf[0].ct = 0;

    for (int i = 0; i < pid; i++)
    {
        if (current_time < sjf[i].at)
            current_time = sjf[i].at;

        sjf[i].ct = current_time + sjf[i].bt;
        sjf[i].ta = sjf[i].ct - sjf[i].at;
        sjf[i].wt = sjf[i].ta - sjf[i].bt;

        avta += sjf[i].ta;
        avwt += sjf[i].wt;

        current_time = sjf[i].ct;
    }

    avwt = avwt / pid;
    avta = avta / pid;

    sort_pid(sjf, pid);

    printf("Process table:\n");
    printf("PID\tAT\tBT\tCT\tTA\tWT\n");
    for (int i = 0; i < pid; i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", sjf[i].pid, sjf[i].at, sjf[i].bt, sjf[i].ct, sjf[i].ta, sjf[i].wt);

    printf("\nAverage WT: %d", avta);
    printf("Average TA: %d", avwt);

    return 0;
}
