/*
description:
to find all subarray with sum equal to zero with the help of hash function
*/
#include <bits/stdc++.h>
using namespace std;

//to find the all pair and return the number
int all_subarray(int arr[], int n)
{
    //count integer is to count the number of subarray
    int count = 0, sum = 0;
    //hash function
    unordered_map<int, int> mp;
    //here sum = 0 is updated in map so that to detect if any zero element present in array
    mp[sum] = 1;

    for (int i = 0; i <= n; i++)
    {
        sum += arr[i];
        //updating all sum in map
        mp[sum] += 1;

        //if the same sum occur again that mean we got subarray
        if (mp[sum] > 1)
            count += mp[sum] - 1;
    }
    return count;
}
//driver code
int main()
{
    int arr[] = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr) / sizeof(arr[0]);

    //This function is to find all subarray
    cout<<all_subarray(arr, n);
}
/*
sample input:
  int arr[] = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};

sample output
   4

   ->TC=O(n);
   ->SC=O(n); 
*/
