#include <stdio.h>
#include <math.h>

int main()
{

    int arr[6];
    int i;
    int l = 1, h = 1000; // h is a big number to accomodate the hrr array

    for (i = 0; i < 6; i++)
    {
        printf("Enter element:");
        scanf("%d", &arr[i]);
    }
    int hrr[h];
    for (i = l; i < h; i++)
    {
        hrr[i] = 0;
    }

    for (i = 0; i < 6; i++)
    {
        hrr[arr[i]]++;
    }

    printf("Missing elements: \n");
    for (i = l; i <= h; i++)
    {
        if (hrr[i] == 0)
            printf("\n %d", i);
    }
}
