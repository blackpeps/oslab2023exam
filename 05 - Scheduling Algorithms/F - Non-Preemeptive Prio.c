#include <stdio.h>
#include <limits.h>
int main()
{
    int burst_time[20], process[20], waiting_time[20], turnaround_time[20], priority[20], arrival_time[20], completion_time[20];
    int i, j, limit, sum_wt = 0, sum_tat = 0, position, temp, remaining_t, min_arrival_time = INT_MAX;
    float average_wait_time, average_turnaround_time;
    printf("Enter Total Number of Processes:\t");
    scanf("%d", &limit);
    printf("\nEnter Arrival Time, Burst Time and Priority For %d Processes\n", limit);
    for (i = 0; i < limit; i++)
    {
        printf("\nProcess[%d]\n", i + 1);
        printf("Arrival Time:\t");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time:\t");
        scanf("%d", &burst_time[i]);
        printf("Priority:\t");
        scanf("%d", &priority[i]);
        process[i] = i + 1;
        if (min_arrival_time > arrival_time[i])
        {
            min_arrival_time = arrival_time[i];
        }
    }
    for (i = 0; i < limit; i++)
    {
        position = i;
        for (j = i + 1; j < limit; j++)
        {
            if (priority[j] < priority[position])
            {
                position = j;
            }
        }
        temp = priority[i];
        priority[i] = priority[position];
        priority[position] = temp;
        temp = burst_time[i];
        burst_time[i] = burst_time[position];
        burst_time[position] = temp;
        temp = process[i];
        process[i] = process[position];
        process[position] = temp;
        temp = arrival_time[i];
        arrival_time[i] = arrival_time[position];
        arrival_time[position] = temp;
    }
    remaining_t = limit;
    waiting_time[0] = 0;
    completion_time[0] = burst_time[0] + arrival_time[0];

    for (i = 1; i < limit; i++)
    {
        waiting_time[i] = 0;
        for (j = 0; j < i; j++)
        {
            waiting_time[i] += burst_time[j];
        }
        waiting_time[i] -= arrival_time[i] - min_arrival_time;

        if (waiting_time[i] < 0)
        {
            waiting_time[i] = 0;
        }

        sum_wt += waiting_time[i];
        completion_time[i] = burst_time[i] + waiting_time[i] + arrival_time[i];
    }
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\t\tCompletionTime\n");
    for (i = 0; i < limit; i++)
    {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        sum_tat += turnaround_time[i];
        printf("\nProcess[%d]\t\t %d\t\t %d\t\t %d\t\t %d\t\t\t %d\n", process[i], arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i], completion_time[i]);
    }
    average_wait_time = (float)sum_wt / limit;
    average_turnaround_time = (float)sum_tat / limit;
    printf("\nAverage Waiting Time:\t%.2f", average_wait_time);
    printf("\nAverage Turnaround Time:\t%.2f\n", average_turnaround_time);
    return 0;
}
