#include <stdio.h>
#define MAX 100
int main()
{
	int page[MAX], frame[10], n, capacity;
	int hit = 0, flag, k, mintime, temp, arr[MAX], time[MAX];
	printf("Enter no. of pages: ");
	scanf("%d", &n);
	printf("Enter RS: ");
	for (int i = 0; i < n; i++)
		scanf("%d", &page[i]);
	printf("Enter capacity of frames: ");
	scanf("%d", &capacity);
	for (int i = 0; i < capacity; i++)
		frame[i] = -1;
	for (int i = 0; i < MAX; i++)
		arr[i] = 0;
	for (int i = 0; i < n; i++)
	{
		arr[page[i]]++;
		time[page[i]] = i;
		flag = 0;
		k = frame[0];
		for (int j = 0; j < capacity; j++)
		{
			if (frame[j] == -1 || frame[j] == page[i])
			{
				if (frame[j] != -1)
					hit++;
				flag = 1;
				frame[j] = page[i];
				break;
			}
			if (arr[k] > arr[frame[j]])
				k = frame[j];
		}
		if (!flag)
		{
			mintime = MAX;
			for (int j = 0; j < capacity; j++)
				if (arr[frame[j]] == arr[k] && time[frame[j]] < mintime)
				{
					temp = j;
					mintime = time[frame[j]];
				}
			arr[frame[temp]] = 0;
			frame[temp] = page[i];
		}
		printf("RS: %d |", page[i]);
		for (int j = 0; j < capacity; j++)
		{
			if (frame[j] == -1)
				printf(" _");
			else
				printf(" %d", frame[j]);
		}
		printf("\n");
	}
	printf("Pagefaults: %d\n", n - hit);
	printf("Pagehit: %d\n", hit);
	printf("Pagefault Ratio: %d\n", (n - hit) * 100 / n);
	printf("Pagehit Ratio: %d\n", hit * 100 / n);
	return 0;
}
