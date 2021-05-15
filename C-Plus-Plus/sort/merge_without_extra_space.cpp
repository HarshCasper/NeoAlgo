// C++ Program to Merge two sorted arrays without using extra space 
/* Given two sorted arrays, say of size m and n respectively
The merge function will merge these sorted arrays such that the first array has m smallest elements
and the second array has remaining n elements in a sorted manner.
We will simultaneously iterate through both the arrays 
and compare the first element of first array with the last element of second array,
if element of second array is smaller than element of first array then swap it, 
otherwise move on to the next element and repeat the previous step.
*/
#include <bits/stdc++.h>
using namespace std;

//Function to merge two sorted arrays
void merge(int arr1[], int arr2[], int n, int m) {
	//start two pointers, one from first position of arr1 and another from last position of arr2
	int i=n-1, j=0;
	//Iterate through every element of arr1 and arr2 and compare elements of the arrays
	while(i>=0 && j<m){                        
		if(arr2[j]<arr1[i]){
	           swap(arr1[i], arr2[j]);
	        }
	           i--;
	           j++;	    
	}
	//sort the first array
	sort(arr1, arr1+n); 
	//sort the second array
        sort(arr2, arr2+m);                         
}
int main() {
        cout<<"Enter the size of the first array : ";
        int n, m, i;
        
        cin >> n;
        cout<<"Enter the size of the second array : ";
        cin >> m;
      
        int arr1[n], arr2[m];
        cout<<"Enter the elements of the first array : ";
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        cout<<"Enter the elements of the second array : ";
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
	//call the merge function on both the arrays
        merge(arr1, arr2, n, m);                            
        cout<<"Sorted Array : ";
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    return 0;
}  

/*
SAMPLE INPUT AND OUTPUT
INPUT: 
Enter the size of the first array : 4
Enter the size of the first array : 5
Enter the elements of the first array : 1 3 5 7
Enter the elements of the first array : 0 2 6 8 9
OUTPUT: 
Sorted Array : 0 1 2 3 5 6 7 8 9
*/

//Time Complexity : O((n+m)log(n+m))
//Space Complexity : O(1)

