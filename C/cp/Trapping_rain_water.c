/* Given n non-negative integers representing an elevation map where the 
width of each bar is 1, compute how much water it can trap after raining. */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int trap(int * arr, int n);
int main() {
  int n, m;
  // accepting the sizes
  printf("Enter size of array: ");
  scanf("%d", & n);
  int * arr = (int *) malloc(sizeof(int) * n);

  // accepting the array elements
  printf("Enter the elements: ");

  for (int i = 0; i < n; i++) {
    scanf("%d ", arr + i);
  }

  // print the trapped water value
  printf("Water trapped is %d",
         trap(arr, n));
  return 0;
}

// function to find the water trapped
int trap(int * arr, int n){
    int Sum = 0, water = 0, top = 0;
    for(int i = 0; i < n; i++)
    {
        // Collect the higher bars //
        if(top < arr[i])
        {
            water += Sum;
            top = arr[i];
            Sum = 0;
        }
        else
            Sum += top - arr[i];
    }
    // resetting the values to zero
    top=0, Sum=0;
    for(int i = n - 1; i > -1; i--)
    {
        // collect both the equal and higher bar
        if(top <= arr[i])
        {
            water += Sum;
            top = arr[i];
            Sum = 0;
        }
        else
            Sum += top - arr[i];
    }
    // return the answer
    return water;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)

Example 1:

Input:
Enter size of array: 
12
Enter the elements: 
0 1 0 2 1 0 1 3 2 1 2 1

Output:
Water trapped is: 6

Example 2:

Input:
Enter size of array:
5
Enter the elements: 
1 4 2 0 1

Output:
Water trapped is: 1

*/
