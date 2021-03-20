/*Problem Statement:
Given an array and a positive integer k, the task is to find 1st negative integer for each and every window(contiguous subarray) of size k.

Input format:-
size(n)
array elements
window_size(k)
 
Output format:-
n-k+1 elements*/

#include <bits/stdc++.h>
using namespace std;

/*function to find the first negative 
 integer in every window of size k*/
void printFirstNegativeInteger(int n, int k, int arr[])
{
    /*A dynamic Array that will store useful array elements for the current window of size k.
      The useful elements are all negative integers.*/
    vector<int> list;
   	//Dynamic array to store 1st negative of each window
    vector<int> ans;
    int start = 0, end = 0;
   	//Process  elements of array
    while (end < n)
    {
        /*Add courrent element at the back of list if it is a negative integer*/
        if (arr[end] < 0)
            list.push_back(arr[end]);
       	//window size not reached then increment end
        if (end - start + 1 < k)
            end++;
       	//reaching window size
        else if (end - start + 1 == k)
        {
        	//if list is empty then the window does not have negative integer
            if (list.size() == 0)
                ans.push_back(0);
            else
            { /*else is not empty then element at the front of list is the first negative integer of previous window*/
                ans.push_back(list.front());
               	// Remove the elements which are out of this window
                if (arr[start] == list.front())
                   	// Remove from front of list
                    list.erase(list.begin());
            }
           	//slide the window
            start++;
            end++;
        }
    }
   	// Print the first negative integer of each window
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    int size_of_array;
    cin >> size_of_array;
    int arr[size_of_array];
    for (int i = 0; i < size_of_array; i++)
        cin >> arr[i];
    int window_size;
    cin >> window_size;
    printFirstNegativeInteger(size_of_array, window_size, arr);
    return 0;
}

/* Test cases:
  Input 1:-
  8
  12 3 -7 8 -15 39 15 20
  3
  Output 1:-
  -7 -7 -7 -15 -15 0

 Time complexity: O(n)
 Space complexity: O(k)*/
