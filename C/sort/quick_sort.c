//   QuickSort is  Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. 
// There are many different versions of quickSort that pick pivot in different ways. 
// 1.Always pick first element as pivot
// 2.Always pick last element as pivot (implemented below)
// 3.Pick a random element as pivot.
// 4.Pick median as pivot.
//The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, 
//put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, 
// put all greater elements (greater than x) after x. All this should be done in linear time.
#include<stdio.h>
void QuickSort(int array[],int start,int end);
 int main()
{
 int i,j,array[100],num;
 printf("Enter Number of Elements in Array\n");
 scanf("%d",&num);      //number of elements in the array is scanned here
 printf("Enter Elements of Array\n");
 for(i=0;i<num;i++)     //elments of array is scanned through this loop
 scanf("%d",&array[i]);
 QuickSort(array,0,num); //Quicksort function is called
 printf("Array after Sorting\n");
 for(i=0;i<num;i++)  //loop for printing the array after sorting
 printf("%d ",array[i]);
 printf("\n");
}
void QuickSort(int array[],int start,int end)
{
 int index=start,i,pivot=array[end],temp;//taking the last number in array as pivot
 if(start<end)
 {
  for(i=start;i<end;i++)
  {
   if(array[i]<=pivot)//swapping index element and element at ith position if ith element is lesser than pivot element
   {
    temp=array[i];
    array[i]=array[index];
    array[index]=temp;
    index++;
   }
  }
  //finally after this loop we will get the position to interchange the pivot with index so that all the
  //elements greater than pivot wil be right side and lesser than pivot will be left side
  temp=array[index];
  array[index]=array[end];//we are taking  end element as pivot every time the quick sort function is called
  array[end]=temp;
  QuickSort(array,start,index-1);
     QuickSort(array,index+1,end);
 }
}
//**SAMPLE INPUT**
//Enter numbers of elements in Array
//5
//Enter Elements of Array
//35
//30
//45
//12
//90
//Array after Sorting 
//12 30 35 45 90
//complexity : exited with code=1 in 13.872 seconds