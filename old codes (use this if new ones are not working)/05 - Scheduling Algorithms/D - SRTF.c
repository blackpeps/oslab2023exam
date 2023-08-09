#include <stdio.h>
#define MAX 50
int main()
{
    int n, i, j, time = 0, completed = 0, shortest_job;
    float total_wait_time = 0, total_turnaround_time = 0;
    int arrival_time[MAX], burst_time[MAX], completion_time[MAX];
    int remaining_time[MAX], process_id[MAX];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter arrival time and burst time for\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d%d", &arrival_time[i], &burst_time[i]);

        process_id[i] = i + 1;
        remaining_time[i] = burst_time[i];
    }
    while (completed != n)
    {
        shortest_job = -1;

        for (i = 0; i < n; i++)
        {
            if (arrival_time[i] <= time && remaining_time[i] > 0)
            {
                if (shortest_job == -1 || remaining_time[i] < remaining_time[shortest_job])
                {
                    shortest_job = i;
                }
            }
        }
        if (shortest_job != -1)
        {
            remaining_time[shortest_job]--;
            if (remaining_time[shortest_job] == 0)
            {
                completion_time[shortest_job] = time + 1;
                completed++;
                total_wait_time += completion_time[shortest_job] - arrival_time[shortest_job] - burst_time[shortest_job];
                total_turnaround_time += completion_time[shortest_job] - arrival_time[shortest_job];
            }
        }

        time++;
    }
    printf("PID\tArrival\tBurst\tCompletion\tTurnAround\tWaiting\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", process_id[i], arrival_time[i], burst_time[i], completion_time[i], completion_time[i] - arrival_time[i], completion_time[i] - arrival_time[i] - burst_time[i]);
    }
    printf("Average Turnaround Time: %f\n", total_turnaround_time / n);
    printf("Average Wait Time: %f\n", total_wait_time / n);

    return 0;
}
