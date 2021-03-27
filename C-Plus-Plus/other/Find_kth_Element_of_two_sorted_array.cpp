/* Find kth Element of two sorted array.

  Given two sorted arrays of size m and n respectively,
  your task is to finding the element that would be
  at the k’th position of the final sorted array.

  Examples 1 : 

  Input 1 : Array 1 - 2 3 6 7 9
            Array 2 - 1 4 8 10
            k = 5

  Output 1 : 6

  Explanation: The final sorted array would be -
               1, 2, 3, 4, 6, 7, 8, 9, 10
               The 5th element of this array is 6.


  Examples 2 : 
    
  Input 2 : Array 1 - 100 112 256 349 770
            Array 2 - 72 86 113 119 265 445 892
            k = 7

  Output 2 : 256

  Explanation: Final sorted array is -
               72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892
               The 7th element of this array is 256.

  Algorithm :-

  1) All two arrays are push into the vector.
  2) Then, sort the vector
  3) After Print the vector of (k - 1) index Element.

*/

//CODE :-
#include<bits/stdc++.h>
using namespace std;


// Function to find kth element of two sorted array
int solve()
{
    // Input m = size of arr1.
    // Input n = size of arr2.
    int m,n;
    cin>>m>>n;

    int arr1[m],arr2[n];

    // Input Elements in array 1
    for (int i = 0; i < m; ++i)
    {
        cin>>arr1[i];
    }

    // Input Elements in array 2
    for (int i = 0; i < n; ++i)
    {
        cin>>arr2[i];
    }

    int k;
    cin>>k;

    // Create a Vector and push arr1 and
    // arr2 elements in a vector

    vector<int> v;
    for (int i = 0; i < m; ++i)
    {
        v.push_back(arr1[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        v.push_back(arr2[i]);
    }

    // Sort the Vector
    sort(v.begin(),v.end());

    // return v[k - 1] value
    return v[k - 1];

}

int main()
{
    // Input the test cases.
    int t;
    cin>>t;
    while(t--)
    {
        int k = solve();
        cout<<"kth Element is : "<<k<<endl;
    }
    return 0;
}

/*
Test cases :

    Input :

        2
        5 4
        2 3 6 7 9
        1 4 8 10
        5
        5 7
        100 112 256 349 770
        72 86 113 119 265 445 892
        7

    Output :

        kth Element is : 6
        kth Element is : 256


    Time complexity: O(nlogn)
    Space Complexity: O(n)
*/
