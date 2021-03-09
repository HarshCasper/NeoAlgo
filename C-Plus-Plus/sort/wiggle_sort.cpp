/* WIGGLE SORT
   *This program accepts an array of unsorted numbers and
    sorts the array such that arr[0]<arr[1]>arr[2]<arr[3]...

   Time Complexity : O(nlogn)   (Sorting takes O(n logn) and traversal takes O(n))
   Space Complexity : O(n)   (New array to store the wiggle sorted elements)
*/

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void wiggle_sort(int n,vector<int> arr){
    int left,right;
    vector <int> res(arr);          //A new vector res is initialized to store sorted array
    sort(res.begin(), res.end());   //res is sorted with the built-in sort() function.

    //res is partitioned into two such that left sub-array contains elements less than the elements in right sub-array
    
    left=(n-1)/2;                   // left and right points to the end of left and right sub-arrays of res resepectively
    right=n-1;

    for(int k = 0; k < n; k +=2)    //Elements in the left sub-array  are added to the even indices of vector res
        arr[k] = res[left--];       // left is decremented
    for(int k = 1; k < n; k +=2)    //Elements in the right sub-array are added to the odd indices of vector x
         arr[k] = res[right--];     // right is decremented
         
    cout << "[";
    for(int i = 0; i<n; i++){       //for printing the wiggle sorted array
        cout << arr[i];
        if(i!=n-1)
            cout<< ", ";
    }
    cout << "]"<<"\n";
}

int main(){
    int a,i,n;
    cin>>n;
    vector<int> arr ;
    for(int i=0;i<n;i++){       //The given array is stored in a vector arr
        cin>>a;
        arr.push_back(a);
    }
    wiggle_sort(n,arr) ;         //to wiggle sort arr
    return 0;
}

/*1. Sample input:
     6
     1 3 2 2 3 1
     Sample output:
     [2,3,1,3,1,2]

  2. Sample input:
     10
     1 4 6 2 3 7 9 2 1 0
     [2, 9, 2, 7, 1, 6, 1, 4, 0, 3]
*/
