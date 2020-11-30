#include <stdio.h>
#include <stdlib.h>

int rob(int num[], int n) {
    if (n == 0) return 0;
    int *d = (int *)calloc(n + 2, sizeof(int));
    int i;
    d[0] = d[1] = 0; 
    for (i = 2; i < n + 2; i++) {
        if (d[i - 2] + num[i - 2] > d[i - 1]) {
            d[i] = d[i - 2] + num[i - 2];
        }
        else {
            d[i] = d[i - 1];
        }
    }
    return d[n + 1];
}

int main() {
    int num;
    printf("Enter number of houses: ");
    scanf("%d",&num);
    int money[num];
    printf("\nEnter money in each house: ");
    for(int i=0;i<num;i++)
    {
           scanf("%d",&money[i]);
    }
    printf("\nTotal amount that can be robbed: %d", rob(money, num));

    return 0;
}

/*
Time Complexity: n(log(n))
Space Complexity: n
Sample input: 
Enter number of houses: 4
Enter money in each house: 1 2 3 1 
Total amount that can be robbed: 4
*/
