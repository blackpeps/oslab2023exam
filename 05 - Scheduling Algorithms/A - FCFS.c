#include <stdio.h>
void main()
{
    int n, b[20], g[20], p[20], w[20], t[20], a[20];
    float avgw = 0;
    float avgt = 0;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Process ID: ");
        scanf("%d", &p[i]);
        printf("Burst time: ");
        scanf("%d", &b[i]);
        printf("Arrival Time: ");
        scanf("%d", &a[i]);
    }
    int temp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    int i, j;
    g[0] = 0;
    for (i = 0; i < n; i++)
        g[i + 1] = g[i] + b[i];
    int current_time = 0;
    for (i = 0; i < n; i++)
    {
        if (current_time < a[i])
        {
            current_time = a[i];
        }
        g[i] = current_time + b[i];
        current_time = g[i];

        t[i] = g[i] - a[i];
        w[i] = t[i] - b[i];

        avgw += w[i];
        avgt += t[i];
    }
    avgw = avgw / n;
    avgt = avgt / n;

    printf("PID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", p[i], a[i], b[i], g[i], w[i], t[i]);
    printf("\nAverage waiting time: %f", avgw);
    printf("\nAverage Turnaround time: %f\n", avgt);
}
