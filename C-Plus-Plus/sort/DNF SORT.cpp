/*Dutch National Flag Algorithm
At first, the full array is unknown. There are three indices - low, mid and high. Initially, the value of low = mid = 1 and high = N.
If the ith element is 0 then swap the element to the low range, thus shrinking the unknown range.
Similarly, if the element is 1 then keep it as it is but shrink the unknown range.
If the element is 2 then swap it with an element in high range.
Algorithm:
1.Keep three indices low = 1, mid = 1 and high = N and there are four ranges, 1 to low (the range containing 0), low to mid (the range containing 1), mid to high (the range containing unknown elements) and high to N (the range containing 2).
2.Traverse the array from start to end and mid is less than high. (Loop counter is i)
3.If the element is 0 then swap the element with the element at index low and update low = low + 1 and mid = mid + 1
4.If the element is 1 then update mid = mid + 1
5.If the element is 2 then swap the element with the element at index high and update high = high - 1 and update i = i - 1. As the swapped element is not processed
6.Print the output array.
*/

#include<iostream>
using namespace std;

void swap(int arr[],int i,int j){
  int temp=arr[i];
  arr[i]=arr[j];
  arr[j]=temp;
}

void dnfSort(int arr[],int n){
  int low=0;
  int mid=0;
  int high=n-1;
  
  while(mid<=high){
    if(arr[mid]==0){
      swap(arr,low,mid);
      low++;
      mid++;
    }
    else if(arr[mid]==1){
      mid++;
    }
    else{
      swap(arr,mid,high);
      high--;
    }
  }
}

int main(){
  int arr[]={1,0,2,1,0,1,2,1,2};
  dnfSort(arr,9);
  
  for(int i=0;i<9;i++){
    cout << arr[i] <<" ";
  }
  
  return 0;
  
}

/*
OUTPUT: 0 0 1 1 1 1 2 2 2

TIME COMPLEXITY:
O(N)
AS IN EACH OPERATION,EITHER MID GETS INCREMENTED OR HIGH GETS DECREMENTED.
    
*/    
    
    
    
    
    
  
