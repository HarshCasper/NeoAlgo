//Finding minimum and maximum element using divide and conquer technique
#include<iostream>
using namespace std;

struct min_max
{
	int minimum;
	int maximum;
};

struct min_max find(int arr[], int low,
								int high)
{
	struct min_max minmax, ml, mr;	
	int mid;
	
	// Checking if only one element is present
	if (low == high)
	{
		minmax.maximum = arr[low];
		minmax.minimum = arr[low];	
		return minmax;
	}
	
	// Checking if two elements are present
	if (high == low + 1)
	{
		if (arr[low] > arr[high])
		{
			minmax.maximum = arr[low];
			minmax.minimum = arr[high];
		}
		else
		{
			minmax.maximum = arr[high];
			minmax.minimum = arr[low];
		}
		return minmax;
	}
	
	// Checking for more than 2 elements 
	mid = (low + high) / 2;
	ml = find(arr, low, mid);
	mr = find(arr, mid + 1, high);
	
	// Comparing minimums of two parts
	if (ml.minimum < mr.minimum)
		minmax.minimum = ml.minimum;
	else
		minmax.minimum = mr.minimum;	
	
	// Comparing maximums of two parts
	if (ml.maximum > mr.maximum)
		minmax.maximum = ml.maximum;
	else
		minmax.maximum = mr.maximum;	
	
	return minmax;
}


int main()
{
	int n;
	cout<<"Enter size of array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements for array: ";
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	int arr_size=sizeof(arr)/sizeof(arr[0]);
	
	struct min_max minmax = find(arr, 0,
							arr_size - 1);
							
	cout << "Minimum element is "
		<< minmax.minimum << endl;
	cout << "Maximum element is "
		<< minmax.maximum;
		
	return 0;
}
/*  
EXAMPLES:-  
Example 1:  
Input--  
Enter size of array: 5  
Enter the elements for array: 45 66 89 11 36  
Output--  
Minimum element is 11
Maximum element is 89

Example 2:  
Input--  
Enter  size of array: 6  
Enter the elements for array: 500 545 376  455 345 567
Output--  
Minimum element is 345
Maximum element is 567 
 
Time Complexity ->  O(n)
Algorithmic Paradigm -> Divide and Conquer
Total number of comparisons -> let the number of comparisons be T(n). T(n) can be written as follows: 

             
  T(n) = T(floor(n/2)) + T(ceil(n/2)) + 2  
  T(2) = 1
  T(1) = 0
  
*/  


