/*
Given a sorted array A, size of N ( N elements) and a target value X,
find if there exists any pair of elements in the Array such that their total sum is equal to X.
we can solve this by using Two pointers Method.
Two pointers Method is a method where one pointer starts from beginning
and other from the end and they proceed towards each other simultaneously.
*/

#include <stdio.h>

// this Pair_exist_by_Two_Pointer_Method will tell us whether pair exists or not
int Pair_exist_by_Two_Pointer_Method(int ar[], int N, int X)
{
    int i = 0, j = N - 1, cur_sum = 0;
    while(i < j)
    {
        cur_sum = ar[i] + ar[j];
        if(cur_sum == X)
        {
            // means you got our expected pair
            return 1;
        }
        else if(cur_sum < X)
        {
            // we will move in right direction
            i++;
        }
        else if (cur_sum > X )
        {
            // we will move in left direction
            j--;
        }
    }
    // we don't get our pair
    return 0;
}

int main()
{
    int N, X;
    printf("Enter array size and target value\n");
    scanf("%d %d", &N, &X);
    int ar[N + 1];
    printf("Enter array elements \n");
    int i;
    for(i = 0; i < N; i++)
    {
        scanf("%d", &ar[i]);
    }
    int solve = Pair_exist_by_Two_Pointer_Method(ar , N , X);
    if(solve)
    {
        printf("Pair found and their total sum is equal to target value\n");
    }
    else
    {
       printf("Pair doesn't exist in the array\n");
    }
}

/*
Standard Input and Output

Enter array size and target value
6 70
10 20 35 50 75 80
Pair found and their total sum is equal to target value

Time Complexity : O(N)
Space Complexity : O(1)

*/
