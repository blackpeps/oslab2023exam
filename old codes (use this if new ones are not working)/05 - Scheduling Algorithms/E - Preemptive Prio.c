#include <stdio.h>
#include <stdlib.h>
#define MAX_PROCESS 10
struct Process
{
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time;
    int remaining_time;
    int priority;
};
typedef struct Process Process;
void sort(Process processes[], int n)
{
    int i, j;
    Process temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (processes[j].priority < processes[i].priority)
            {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}
int main()
{
    int n, t = 0, completed = 0, i, j, max_priority;
    float total_waiting_time = 0.0, total_turnaround_time = 0.0, avg_waiting_time, avg_turnaround_time;
    Process processes[MAX_PROCESS];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst time, arrival time and priority for process\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].burst_time, &processes[i].arrival_time, &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].pid = i + 1;
    }
    sort(processes, n);
    while (completed != n)
    {
        max_priority = 10000;
        int max_remaining_time = -1;
        for (i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= t && processes[i].remaining_time > 0 && processes[i].priority < max_priority)
            {
                max_priority = processes[i].priority;
                max_remaining_time = processes[i].remaining_time;
                j = i;
            }
        }
        if (max_remaining_time == -1)
        {
            t++;
            continue;
        }
        processes[j].remaining_time--;
        if (processes[j].remaining_time == 0)
        {
            processes[j].completion_time = t + 1;
            completed++;
            total_waiting_time += processes[j].completion_time - processes[j].burst_time - processes[j].arrival_time;
            total_turnaround_time += processes[j].completion_time - processes[j].arrival_time;
        }
        t++;
    }
    avg_waiting_time = total_waiting_time / n;
    avg_turnaround_time = total_turnaround_time / n;
    printf("\nPID\tPriority\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t%d\t%d\t\t%d\t%d\n", processes[i].pid, processes[i].priority, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].completion_time - processes[i].burst_time - processes[i].arrival_time, processes[i].completion_time - processes[i].arrival_time);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    return 0;
}
