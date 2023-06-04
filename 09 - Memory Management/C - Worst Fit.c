#include <stdio.h>
void main()
{
    int i, j, nblocks, nfiles, temp, top = 0;
    int frag[10], blocks[10], files[10];
    static int block_arr[10], file_arr[10];
    printf("\nEnter the total number of blocks:");
    scanf("%d", &nblocks);
    printf("\nEnter the total number of Processes:");
    scanf("%d", &nfiles);
    printf("\nEnter the size of blocks:\n");
    for (i = 0; i < nblocks; i++)
        scanf("%d", &blocks[i]);
    printf("\nEnter the size of files:\n");
    for (i = 0; i < nfiles; i++)
        scanf("%d", &files[i]);
    for (i = 0; i < nfiles; i++)
    {
        for (j = 0; j < nblocks; j++)
        {
            if (block_arr[j] != 1)
            {
                temp = blocks[j] - files[i];
                if (temp >= 0)
                {
                    if (top < temp)
                    {
                        file_arr[i] = j;
                        top = temp;
                    }
                }
            }
            frag[i] = top;
            block_arr[file_arr[i]] = 1;
            top = 0;
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock number\tBlock size\tFragment ");
    for (i = 0; i < nfiles; i++)
    {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, files[i], file_arr[i], blocks[file_arr[i]], frag[i]);
    }
    printf("\n");
}