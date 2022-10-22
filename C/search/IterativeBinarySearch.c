// C program to implement Binary Search using Iterative Approach i.e Using Loop
#include <stdio.h>
#include <stdlib.h>

// base utility function to create the array
int *create(int n)
{
  int *a = (int *)malloc(n * sizeof(int));

  printf("\nEnter the elements of Array : ");
  for (int i = 0; i < n; i++)
  {

    scanf("%d", (a + i));
  }

  return a;
}

// key is the element to be searched
int BinarySearch(int array[], int length, int key)
{
  int high = length - 1;
  int low = 0;
  if (low <= high)
  {
    while (low <= high)
    {
      int mid = (low + high) / 2;

      if (key == array[mid])
      {
        return mid;
      }
      else if (key < array[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
  }

  return -1;
}

// printing the array function
void display(int *a, int n)
{
  for (int i = 0; i < n; i++)
  {

    printf("%d ", *(a + i));
  }
}

int main()
{
  int n;

  printf("\nEnter the size of the array : ");
  scanf("%d", &n);

  int *arr = create(n);

  printf("\nThe array is : ");
  display(arr, n);

  int element; // element to search

  printf("\nEnter the element to search : ");
  scanf("%d", &element);

  int flag = BinarySearch(arr, n, element);

  if (flag == -1)
  {
    printf("\nElement not found\n");
  }
  else
  {
    printf("\nElement found at index : %d\n", flag);
  }
  return 0;
}

// Time Complexity: O(logn)
// Space Complexity: O(n)

/* Sample Test Case:
Test-1:
        If searched value is 19
        i.e val=19
        ------
        Output
        ------
        Element found at index :  4

Test-2:
        If searched value is 29
        i.e val=29
        ------
        Output
        ------
        Element not found
 */
