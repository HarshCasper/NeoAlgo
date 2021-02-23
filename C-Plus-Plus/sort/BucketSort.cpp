/* Bucket sort, or bin sort, is a sorting algorithm that works by distributing the elements of an array into a number of buckets. 
Each bucket is then sorted individually, either using a different sorting algorithm, or by recursively applying the bucket sorting algorithm.
Bucket sort is mainly useful when input is uniformly distributed over a range. Bucket sort can be implemented with comparisons and 
therefore can also be considered a comparison sort algorithm. */

// Header file to include STL library
#include<bits/stdc++.h>
//For cin and cout
using namespace std; 

void bucketSort(float arr[],int n)
{
    // Create n empty buckets
    std::vector<float> bucket[n];         
     
    //Put values in different buckets 
    for (int i=0; i<n; i++) 
    { 
       int bi = n*arr[i];       // Index in bucket 
       bucket[bi].push_back(arr[i]); 
    } 
  
    //Sort individual buckets 
    for (int i=0; i<n; i++) 
       sort(bucket[i].begin(), bucket[i].end()); 

    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < bucket[i].size(); j++) 
          arr[index++] = bucket[i][j]; 
}

int main() 
{ 
    // Declare an array of float numbers
    float arr[10] ;
    // Declare required variables
    int i,n;
    cout<< "Enter the number of elements :\n";
	cin>>n;
	cout<<"Enter the elements:\n";
    for (i=0;i<n;i++)
    { 
      cin>>arr[i];
    }

    bucketSort(arr,n);
    
    cout << "Sorted array is \n"; 
    for (int i=0; i<n; i++) 
       cout << arr[i] << " "; 
    return 0; 
}

/*
Input: 
Enter the number of elements :
4
Enter the elements:
0.123 0.008 0.7 0.4

Output:
Sorted array is 
0.008 0.123 0.4 0.7

--------------------------------
Time Complexities:
O(n+k): average time complexity
O(n²): worst time complexity

Space Complexity: O(n+k)

*/