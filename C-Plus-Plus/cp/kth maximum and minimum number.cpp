#include <bits/stdc++.h>
using namespace std;
int kthmaximum(int arr[], int n, int k)
{
    // Sort the given array
    sort(arr, arr + n);
 // Return k'th number in the sorted array
    return arr[k +1];
}
 int kthminimum(int arr[], int n, int k)
{
    // Insert all numbers into the set
//set is used in C++ STL library
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);
  // Traverse set and print k-th number
    auto it = s.begin();
    for (int i = 0; i < k - 1; i++)
        it++;
    return *it;
}
// Driver program to test above methods
  int main()
{
    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]), k = 2;
    cout<<"K'th maximum number is"<<kthmaximum(arr, n,k)<<endl;
cout << "K'th minimum number is "<< kthminimum(arr, n, k)<<endl;
    return 0;
}