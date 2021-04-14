// C++ Program to Merge two sorted arrays without using extra space

//Time Complexity : O((n+m)log(n+m))
//Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;

//Function to merge two sorted arrays
void merge(int arr1[], int arr2[], int n, int m) {
	int i=n-1, j=0;
	while(i>=0 && j<m){                         //Iterate through every element of arr1 and arr2 and compare elements of the arrays
		if(arr2[j]<arr1[i]){
	           swap(arr1[i], arr2[j]);
	        }
	           i--;
	           j++;
	    
	}
	sort(arr1, arr1+n);                         //sort the first array
        sort(arr2, arr2+m);                         //sort the second array
}



int main() {
        cout<<"Enter the size of the first array : ";
        int n, m, i;
        
        cin >> n;
        cout<<endl;
        cout<<"Enter the size of the second array : ";
        cin >> m;
      
        int arr1[n], arr2[m];
        cout<<"Enter the elements of the first array : ";
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        cout<<endl;
        cout<<"Enter the elements of the second array : ";
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        merge(arr1, arr2, n, m);                            //call the merge function on both the arrays
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

SAMPLE 1

Enter the size of the first array : 4
Enter the size of the first array : 5
Enter the elements of the first array : 1 3 5 7
Enter the elements of the first array : 0 2 6 8 9
Sorted Array : 0 1 2 3 5 6 7 8 9

SAMPLE 2

Enter the size of the first array : 6
Enter the size of the first array : 4
Enter the elements of the first array : 1 5 9 10 15 20
Enter the elements of the first array : 2 3 8 13
Sorted Array : 1 2 3 5 8 9 10 13 15 20

*/
