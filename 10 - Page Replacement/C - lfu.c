#include <stdio.h>
int main() {
	int total_frames, total_pages, hit = 0;
	int m, n, page, flag, k, minimum_time, temp;
	int pages[20], frames[10], arr[20], time[20];
	
	printf("Enter the number of pages: ");
	scanf("%d", &total_pages);
	
	printf("Enter the capacity of frames: ");
	scanf("%d", &total_frames);
	
	for (m = 0;m < total_frames; m++)
		frames[m] = -1;
		
	for (m = 0; m < 25; m++)
		arr[m] = 0;
	
	printf("Enter the reference String (RS): ");
	for (m = 0; m < total_pages; m++)
		scanf("%d", &pages[m]);
	
	printf("\n");
	
	for (m = 0; m < total_pages; m++) {
		arr[pages[m]]++;
		time[pages[m]] = m;
		flag = 0;
		k = frames[0];
		
		for (n = 0; n < total_frames; n++) {
			if (frames[n] == -1 || frames[n] == pages[m]) {
				if (frames[n] != -1)
					hit++;
				flag = 1;
				frames[n] = pages[m];
				break;
			}
			if (arr[k] > arr[frames[n]])
				k = frames[n];
		}
		if (!flag) {
			minimum_time = 25;
			for (n = 0; n < total_frames; n++) {
				if (arr[frames[n]] == arr[k] && time[frames[n]] < minimum_time) {
					temp=n;
					minimum_time = time[frames[n]];
				}
			}
			arr[frames[temp]] = 0;
			frames[temp] = pages[m];
		}
		printf("RS: %d | ", pages[m]);
		for (int j = 0; j < total_frames; j++) {
			if (frames[j] == -1)
				printf(" _");
			else
				printf(" %d", frames[j]);
		}
		printf("\n");
	}
	printf("Page fault: %d \n", total_pages - hit);
	printf("Page hit: %d\n", hit);
	printf("Page fault ratio: %d\n", (total_pages - hit)*100/total_pages);
	printf("Page hit ratio: %d\n", hit*100/total_pages);
	
	return 0;
}
