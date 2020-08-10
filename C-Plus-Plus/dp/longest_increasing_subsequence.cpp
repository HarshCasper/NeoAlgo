//the following program finds length of longest increasing subsequence in the given array using dynamic programming
//the subsequence is a part of given parent array that has same order of elements as of parent array.
#include<iostream>
using namespace std;

int
main ()
{
  
int arr[8] = { 10, 22, 9, 33, 21, 50, 41, 6 };
  
cout << "The elements of array are:";
  
for (int i = 0; i < 8; i++)
    {
      
cout << arr[i] << " ";
    
} 
int n = 8;		//number of elements in array
  int count[n];
  
for (int i = 0; i < n; i++)
    {
      
count[i] = 1;		//initially assign every element as 1 because every element is longest increasing subsequence in itself
  } 
for (int i = 1; i < n; i++)
    {				//loop starts from index 1
      for (int j = 0; j < i; j++)
	{			//next loop runs till one index less than i
	  if (arr[i] > arr[j] && count[j] + 1 > count[i])
	    {			// if it finds number smaller than current ith index and it's next element in count array is greater than ith index by one 
	      count[i] = count[j] + 1;	//then increment the count of ith element in count array by 1
	    }
	
}
    
}
  
int max = 0;			//initially assign max variable as 0
  for (int i = 0; i < n; i++)
    {
      
if (count[i] > max)
	{			//if current element is larger than max
	  max = count[i];	//assign maximum value in max variable
	}
    
}
  
cout << "\n" << "The length of longest increasing subsequence is " << max;

}
