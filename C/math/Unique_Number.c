#include <stdio.h>

int Unique(int *array, int n)
{
    int unique = 0;
    for(int i=0; i<n; i++)
        unique ^= array[i];

    return unique;
}

int main()
{
    int n;
    scanf("%d", &n);

    int array[n];
    for(int i=0; i<n; i++)
        scanf("%d", &array[i]);

    printf("%d", Unique(array, n));

    return 0;
}

/*
Sidharth Sethi
TechSpiritSS
Time Complexity - O(N)
Space Complexity - O(N)
****************************************
Input - 1
9
4 5 6 4 5 6 4 4 2
Output - 1
2
Input - 2
11
1 5 3 3 5 1 8 5 5 8 4
Output - 2
4
****************************************
*/