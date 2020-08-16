#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//find out the maximum number in the array specified

int maximumNumber(int arr[], int curr_size)
{
  int max =0, index =0;
  
      for (int i = 0; i < curr_size; i++)
      {
        if (arr[i]>max)
        {
          max = arr[i];
          index = i;
        }
      }
  return index;
}

// Flip the array from start till the maximum index

int flip(int arr[], int max) 
{  
  int temp;
  
      for(int i = 0; i< max; i++)
      {
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        max--;
      } 
}

//initiating the sorting algorithm

int PancakeSort(int arr[], int number)
{
  for (int curr_size = number; curr_size > 1 ; curr_size--)
  {
    int max = maximumNumber(arr, curr_size);
    
        if (max != curr_size -1)
        {
          flip(arr, max);               //flipping till the max element inclusive of max element
          flip(arr, curr_size-1);       // To place the max element at the end of the array and reduce the size by 1
        }
  }
  
  //Printing the sorted array
  
  cout<<"The sorted array is :  ";
      
      for (int i = 0; i < number; ++i)
          cout<<arr[i]<<" ";
     
  }

int main()
{
    int number;
    cin>>number;

    int arr[number];                          //creating an array
    for (int i = 0; i < number; ++i)         //input the array elements
        cin>>arr[i];
      
    PancakeSort(arr,number);
    return 0;
}
