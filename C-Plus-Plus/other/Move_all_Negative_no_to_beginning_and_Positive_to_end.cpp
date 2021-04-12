/* Move all Negative numbers to beginning and Positive to the end */

#include<bits/stdc++.h>
using namespace std;

/* Function for Moving all Negative numbers to beginning and Positive to end */
void solve()
{
    /* Input n = size of array */
    int n;
    cin >> n;

    int a[n];
    
    /* Input elements in an array */
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    /* Create the empty result array
       to store the result */
    int result[n]; 
    
    /* Take a pointer of index of result */  
    int k = 0; 

    /* Traverse the array and store 
       Negative element in result array */
    for (int i = 0 ; i < n ; i++) 
    {
        if (a[i] < 0) 
        {
            result[k++] = a[i];
        }
    }
  
    /* Check if result array contain all positive
       and negative elements then return */
    if (k == n || k == 0) 
        return; 
  
    /* Store positive elements in the result array */  
    for (int i = 0; i < n ; i++)
    { 
        if (a[i] >= 0 )
        { 
            result[k++] = a[i]; 
        }
    }

    /* Print elements form result array*/
    for (int i = 0; i < n; ++i)
    {
        cout << result[i] << " ";
    }
}

int main()
{
    solve();
    return 0;
}

/*
Test cases :
    
    Input 1 :
        
        9
        -12 11 -13 -5 6 -7 5 -3 -6

    Output 1 :

        -12 -13 -5 -7 -3 -6 11 6 5  

    Input 2 :

        8
        1 -1  11 5 -3 -2 7 6
    
    Output 2 :
    
        -1 -3 -2 1 11 5 7 6  
    
    Time complexity: O(n)
    Space Complexity: O(n)
*/
