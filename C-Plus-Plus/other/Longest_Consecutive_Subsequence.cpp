/* Find the length of the longest sub-sequence. */
#include<bits/stdc++.h>
using namespace std;

/* Function to Find the length of the longest sub-sequence. */
int solve()
{
    /* Input n = size of array */
    int n;
    cin >> n;

    int arr[n];

    /* Input values in array */
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    /* Input array element in set*/
    set<int> s;

    for (int i = 0; i < n; ++i)
    {
        s.insert(arr[i]);
    }

    int ans = 0;
    for (int i=0; i<n; i++) 
    { 
        /* Check the element is starting point of subsequences
           simply check arr[i]-1 in set */
        if (s.find(arr[i]-1) == s.end()) 
        { 
            /*check next elements in the sequence */
            int j = arr[i]; 
            while (s.find(j) != s.end()) 
                j++; 
  
            /* Store length in ans*/
            ans = max(ans, j - arr[i]); 
        } 
    } 
    /* Return final Length */
    return ans;


}

int main()
{
    int length = solve();

    cout << "Length of the Longest subsequence is : " << length << endl;
    return 0;
}

/*
Test cases :
    
    Input 1 :
        
        7
        1 9 3 10 4 20 2

    Output 1 :

        Length of the Longest subsequence is : 4

    Input 2 :

        11
        36 41 56 35 44 33 34 92 43 32 42
    
    Output 2 :
    
        Length of the Longest subsequence is : 5
    
    Time complexity: O(n)
    Space Complexity: O(1)
*/
