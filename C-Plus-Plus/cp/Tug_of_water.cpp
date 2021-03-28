/*
Given a set of n integers, divide the set in two subsets of n/2 sizes each such that the difference of the sum of two subsets is as minimum as possible. 
If n is even, then sizes of two subsets must be strictly n/2 and 
if n is odd, then size of one subset must be (n-1)/2 and size of other subset must be (n+1)/2.

 A C++ PROGRAM TO FIND TUG OF WATER USING BACKTRACKING
*/

#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void traverse(int* arr, int i, int n, int no_of_selected, int sum, int& diff, bool* take, vector<int>& result, vector<int> current, int current_sum)
{
    //if the current position is greater than or equals to n
    if (i >= n)
        return;
    /* if the value of difference is greater than
       Sum/2-current sum of the elements of Subset no.1 */
    
	if ((diff > abs(sum / 2 - current_sum)) && (no_of_selected == (n + 1) / 2 || no_of_selected == (n - 1) / 2)) 
	{
        diff = abs(sum / 2 - current_sum);
        //store the subset no. 1
        result = current;
    }
    //taking the elemets after the current element one by one
    for (int j = i; j < n; j++) 
	{
        take[j] = true;
        current.push_back(arr[j]);
        traverse(arr, j + 1, n, no_of_selected + 1, sum, diff, take, result, current, current_sum + arr[j]);
        current.pop_back();
        take[j] = false;
    }
}
void find(int* arr, int n)
{
    //array to distinguished the elements those are in subset no. 1
    bool take[n];
    int sum = 0;
    for (int i = 0; i < n; i++) 
	{
        sum += arr[i];
        take[i] = false;
    }
    int diff = INT_MAX;
    int no_of_selected = 0;
    vector<int> result;
    vector<int> current;
    int current_sum = 0;
    int i = 0;
    traverse(arr, i, n, no_of_selected, sum, diff, take, result, current, current_sum);
    set<int> s;
    //elements those are in subset no.1
    cout << "Set1 : { ";
    for (int j = 0; j < result.size(); j++) 
	{
        cout << result[j] << " ";
        s.insert(result[j]);
    }
    cout << "}" << endl;
    //elements those are in subset no.2
    cout << "Set2 : { ";
    for (int j = 0; j < n; j++) 
	{
        if (s.find(arr[j]) == s.end()) 
		{
            cout << arr[j] << " ";
        }
    }
    cout << "}" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--) 
	{
        int n;
        cout << "Enter the value of n : ";
        cin >> n;
        int arr[n];
        cout << "Enter the values: ";
        //taking the set elements
        for (int i = 0; i < n; i++) 
		{
            cin >> arr[i];
        }
        find(arr, n);
    }
    return 0;
}
/*
TIME COMPLEXITY OF TUG OF WAR IS O(N^2) and SPACE COMPLEXITY IS O(1)  
T=3
N=3
1 2 3
Output:  set1: {1, 2} set2: {3}
N=4
1 2 3 4
Output: set1: {1, 4} set2: {2, 3}
N=10
1 4 8 6 -7 -10 87 54 16 100
Output: set1: {{ 4, -7, -10, 87, 54 } set2: {1, 8, 6, 16, 100 }
*/
   
