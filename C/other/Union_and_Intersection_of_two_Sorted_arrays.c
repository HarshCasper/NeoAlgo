/* Find Union and Intersection of two Sorted arrays */

#include<stdio.h>

/* Function for finding Union and Intersection of two Sorted array*/
void solve()
{
  /* Input m = size of array 1
     Input n = size of array 2 */
  int m,n;
  scanf("%d%d",&m,&n);

  /* Create a two empty array */
  int a[m],b[n];

  /* Input values in array 1 */
  for (int i = 0; i < m; ++i)
  {
      scanf("%d",&a[i]);
  }

  /* Input values in array 2 */
  for (int i = 0; i < n; ++i)
  {
      scanf("%d",&b[i]);
  }

  /* Finding Union */
  int i = 0, j = 0; 

  printf("Union : ");
  while (i < m && j < n) 
  { 
    /* If a[i] < b[j] then print a[i] and increment i. */
    if(a[i] < b[j])
    {
      printf(" %d ", a[i]);
      i++; 
    } 

    /* If a[i] > b[j] then print b[j] and increment j. */
    else if(b[j] < a[i]) 
    {
      printf(" %d ", b[j]);
      j++; 
    }  

    /* If a[i] = b[j] then print a[i] increment both i and j. */
    else
    { 
      printf(" %d ", b[j]);
      j++; 
      i++; 
    } 
  } 

  /* Print remaining elements of the larger array. */
  while(i < m)
  {
    printf(" %d ", a[i]);
    i++;
  }
  while (j < n)
  {
    printf(" %d ", b[j]);
    j++;
  }

  printf("\n");

  /* Finding Intersection */
  int k = 0, l = 0; 

  printf("Intersection : ");
  while (k < m && l < n) 
  { 
    /* If a[i] < b[j] then increment i. */
    if(a[k] < b[l]) 
    {
      k++; 
    }
    
    /* If a[i] > b[j] then increment j. */
    else if(b[l] < a[k]) 
    {
      l++; 
    }

    /* If a[i] = b[j] then print a[i] increment both i and j. */
    else
    { 
      printf(" %d ", b[l]);
      l++; 
      k++; 
    } 
  } 
}  

int main()
{
  solve();
  return 0;
}

/*
Test cases :
    
    Input 1 :
        
        5 4
        1 3 4 5 7
        2 3 5 6

    Output 1 :

        Union : 1 2 3 4 5 6 7
        Intersection : 3 5 

    Input 2 :

        3 4
        2 5 6
        4 6 8 10

    Output 2 :
    
        Union : 2 4 5 6 8 10
        Intersection : 6 
    
    Time complexity: O(n)
    Space Complexity: O(n)
*/
