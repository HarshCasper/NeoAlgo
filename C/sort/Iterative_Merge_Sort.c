/* program for executing merge sort in a iterative manner*/
/* TIME COMPLEXITY: O(nlogn) */

#include <stdio.h>
#include<stdlib.h>

//function for taking input
void input(int a[],int n)
{
    for(int i=1; i<=n; i++)
    {
      printf("\nElement: " );
      scanf("%d",&a[i] );
    }
}

//function for swapping
void swap(int *x,int *y)
{
  int temp=*x;
  *x=*y;
  *y=temp;
}

//function for merging element
void Merge(int A[],int l,int mid,int h)
{
  //variable declaration
  int i=l,j=mid+1,k=l;
  int B[100];

  //loop for merging element
  while(i<=mid && j<=h)
  {
    if(A[i]<A[j])
    {
      B[k++]=A[i++];
    }
    else
    {
      B[k++]=A[j++];
    }
  }

  //loops for leftover element
  for(;i<=mid;i++)
  {
    B[k++]=A[i];
  }
  for(;j<=h;j++)
  {
    B[k++]=A[j];
  }
  for(i=l;i<=h;i++)
  {
     A[i]=B[i];
  }
}
void IMergeSort(int A[],int n)
{
  //variable declaring
  int p,l,h,mid,i;

  //loop for executing iterative merge sort
  for(p=2;p<=n;p=p*2)
  { for(i=0;i+p-1<=n;i=i+p)
    {
      //calculating value for low, high and mid
      l=i;
      h=i+p-1;
      mid=(l+h)/2;
      //function calling
      Merge(A,l,mid,h);
    }
  }

  //if p/2 is less than n
  if(p/2<n)
  {
    //function calling
    Merge(A,0,p/2-1,n);
  }

}
int main()
{
  //declaring and inputting array
  int size,*p;
  printf("\nEnter size of array: " );
  scanf("%d",&size );
  p=(int * )malloc(size*sizeof(int));
  input(p,size);

  //calling iterative merge sort
  IMergeSort(p,size);

  //loop for displaying
  printf("\nSorted Array:\n " );
  for(int i=0;i<size;i++)
  {
    printf("%d ",p[i]);
  }
  printf("\n");

  return 0;
}

/*sample input/output */
/*
Enter size of array: 5

Element: 80

Element: 100

Element: 20

Element: 60

Element: 40

Sorted Array:
 20 40 60 80 100

Press any key to continue . . .
*/
