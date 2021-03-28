/*
Find the Unique Element
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
First line of each test case or query contains an integer 'N' representing the size of the array/list.
Second line contains 'N' single space separated integers representing the elements in the array/list.
Output Format :
For each test case, print the unique element present in the array.
Output for every test case will be printed in a separate line.
*/

#include <bits/stdc++.h> 
#include <iostream>
using namespace std; 
//declare function
int findUnique(int *arr, int n) {    
    if(n==1)
        return arr[0];
    sort(arr,arr+n);
    if (arr[0]!=arr[1])
            return arr[0];
    
    for (int i=0; i<n; i++){
        if(arr[i]!=arr[i-1] && arr[i]!=arr[i+1])
            return arr[i];
    }
       
}

//main function
int main() {
    int t;
    cin >> t;
    
    //taking input for "t" test cases
    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}

/*
Sample input:
2
5
2 4 7 2 7
9
1 3 1 3 6 6 7 10 7

Sample output:
4
10
*/
