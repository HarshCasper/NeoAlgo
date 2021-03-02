//This  algorithm is used to select i_th order statistic from the given data in O(n) time complexity and O(1) space complexity
#include <stdio.h>
#include <stdlib.h>
int arr[100000];

int part(int arr[], int lower, int upper) 
{
    int z = arr[upper];
    int i = lower - 1;
    for (int j = lower; j <= upper - 1; j++)
    {
        if (arr[j] <= z)
        {
            ++i;
            int change = arr[i]; // Now we are swapping arr[i] and arr[j]
            arr[i] = arr[j];
            arr[j] = change;
        }
    }
    int change2 = arr[i + 1]; // now we are swapping arr[i+1] and arr[upper]
    arr[i + 1] = arr[upper];
    arr[upper] = change2;
    return i + 1;
}
int random_type(int minimum, int maximum) 
{                    //this function is used to generate a random number in the given range
    int type = maximum - minimum + 1;
    int number = minimum + (rand() % type);
    return number;
}

int Randomized_type(int arr[], int lower, int upper) 
{
    int i = random_type(lower, upper);
    int change = arr[upper];
    arr[upper] = arr[i];
    arr[i] = change;
    return part(arr, lower, upper);
}

int Randomized_select_algo(int arr[], int lower, int upper, int i) 
{
    if (lower == upper)  //if the array has only one element
        return arr[lower];
    
    int x= Randomized_type(arr, lower, upper);
    int y= x+1-lower ;

    if (i == y)     // The value obtained is the answer
        return arr[x];
    else if (i > y) // the  value required lies on the upper side 
         return Randomized_select_algo(arr, x + 1, upper, i - y);
    else            // the  value required lies on the lower side 
        return Randomized_select_algo(arr, lower, x- 1, i);
}

int main()
{
    int n, i;
    printf("Enter number of elements: \n");
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++)
         scanf("%d",&arr[i]);

    printf("Enter i: \n");
    scanf("%d",&i);
    printf("%d",Randomized_select_algo(arr, 0, n - 1, i));
    return 0;
}
/*
   sample test case
   let n = 6 and array input be [6, 89, 45, 12, 78, 3]  and i =4
   then Randomized_select_algo will give us answer 45 as 4th element of the sorted array or 45 is the next greater element than the first 3 element i.e. 3,6,12
   sorted array [3, 6, 12, 45, 78, 89]
*/
