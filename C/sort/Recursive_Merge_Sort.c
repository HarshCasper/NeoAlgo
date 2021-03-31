/* program for executing merge sort in a recursive manner*/
/* TIME COMPLEXITY: O(nlogn) */
/* SPACE COMPLEXITY: O(nlogn) */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//function for taking input
void input(int a[],int n)
{
    for(int i=1; i<=n; i++)
    {
      printf("\nElement: " );
      scanf("%d",&a[i] );
    }
}

//function for printing values
void Display(int a[], int n)
{
    printf("\nSorted Array: \n" );
    for(int i=0; i<n; i++)
    {
      printf("%d ",a[i] );
    }
    printf("\n" );
}


//MERGE SORT
void merge(int a[], int l, int mid, int h)
{
  //variable declaration
  int i,j,k;
  i=l; j=mid+1; k=l;

  //another array
  int b[100];

  //loop for merging
  while(i<=mid && j<=h)
  {
    if(a[i]<a[j])
    {
      b[k]=a[i];
      k++; i++;
    }
    else
    {
      b[k]=a[j];
      k++; j++;
    }
  }
  //loops for the leftover values
  for(; i<=mid; i++)
  {
    b[k]=a[i];
    k++;
  }
  for(; j<=h; j++)
  {
    b[k]=a[j];
    k++;
  }
  for(i=l; i<=h; i++)
  { a[i]=b[i]; }
}

void Rmergesort(int a[], int l, int h)
{
  //Variable
  int mid;

  //if low is less than high
  if(l<h)
  {
    //calculating mid
    mid=(l+h)/2;

    //recursively calling Rmergesort
    Rmergesort(a,l,mid);
    Rmergesort(a,mid+1,h);

    //calling merge to merge all the elements
    merge(a,l,mid,h);
  }
}

int main()
{
      //Variable declaration
      int size,*p;

      //taking input
      printf("\nEnter size of array: " );
      scanf("%d",&size );

      //Creating array
      p=(int * )malloc(size*sizeof(int));

      //calling function for input
      input(p,size);

      //calling function for performing Mergesort
      Rmergesort(p,0,size);

      //calling function for displaying the values
      Display(p,size);
}

//sample input/output
/*

Enter size of array: 5

Element: 80

Element: 60

Element: 100

Element: 140

Element: 20

Sorted Array:
20 60 80 100 140

Press any key to continue . . .

*/
