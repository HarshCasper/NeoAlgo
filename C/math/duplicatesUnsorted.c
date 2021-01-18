#include <stdio.h>
int main()
{

    int arr[10], hrr[9];

    printf("Enter elements in array: \n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i <= 8; i++)
    {
        hrr[i] = 0;
    }

    for (int i = 0; i < 10; i++)
    {
        hrr[arr[i]]++;
    }

    for (int i = 0; i <= 8; i++)
    {
        if (hrr[i] > 1)
            printf(" \n %d ", i);
    }
    return 0;
}