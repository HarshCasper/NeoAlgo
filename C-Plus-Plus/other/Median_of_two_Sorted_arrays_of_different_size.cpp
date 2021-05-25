/* Find a Median of two Sorted arrays of different size. */

#include<bits/stdc++.h>
using namespace std;

/* Function to find Median of two Sorted array of different size */
int solve()
{
    /* Input n1 = size of array 1
       Input n2 = size of array 2 */
    int n1,n2;
    cin >> n1 >> n2;

    int arr1[n1],arr2[n2];

    /* Input values in array 1 */
    for (int i = 0; i < n1; ++i)
    {
        cin >> arr1[i];
    }

    /* Input values in array 2 */
    for (int i = 0; i < n2; ++i)
    {
        cin >> arr2[i];
    }

    /* Create a vector */
    vector<int> v;

    /* Push array 1 element in vector */
    for (int i = 0; i < n1; ++i)
    {
        v.push_back(arr1[i]);
    }

    /* Push array 2 element in vector */
    for (int i = 0; i < n2; ++i)
    {
        v.push_back(arr2[i]);
    }

    /* Sort the given vector */
    sort(v.begin(), v.end());
    
    /* Find medina using this formula */
    int mid = v[v.size()/2];
    
    /* Return Calculated median */
    return mid;
}

int main()
{
    int Median = solve();

    cout << "Median is : " << Median <<endl;
    return 0;
}

/*
Test cases :
    
    Input 1 :
        1 4
        900
        5 8 10 20
        
    Output 1 :

        Median is : 10

    Input 2 :

        5 6 
        1 2 3 4 5
        3 4 5 6 7 8
    
    Output 2 :
    
        Median is : 4
    
    Time complexity: O(nlogn)
    Space Complexity: O(n)
*/
