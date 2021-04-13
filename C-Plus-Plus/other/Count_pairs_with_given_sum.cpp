/* Find the number of pairs of integers in the array whose sum is equal to k */

#include<bits/stdc++.h>
using namespace std;

/* Function for Finding the number of pairs of
   integers in the array whose sum is equal to k */
int solve()
{
    /* Input n = size of array */
    int n;
    cin >> n;

    /* Create an empty array */
    int a[n];

    /* Input values in an array */
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    /* Input sum */
    int sum;
    cin >> sum;

    /* Sort the given array */
    sort(a, a + n);
    
    /* Declear count with zero value */
    int count = 0;

    /* Create a map */
    unordered_map<int, int> map_count;
    
    /* Store count of all the element */
    for(int i = 0; i < n; i++)
    {
        map_count[a[i]]++;
    }
 
    /* Iterate and increment the count */
    for(int i = 0; i < n; i++)
    {
        count += map_count[sum - a[i]];
    
        /* If sum - a[i] is equal to a[i] 
           then increment the count */
        if (sum - a[i] == a[i])
        {
            count--;
        }
    }
    
    /* return the count */
    return count / 2;
}

int main()
{
    int count = solve();

    cout << "Pair found is : " << count << endl;
    return 0;
}

/*
Test cases :
    
    Input 1 :
        
        5
        1 5 7 -1 5
        6

    Output 1 :

        Pair found is : 3 

    Input 2 :

        13
        10 12 10 15 -1 7 6 5 4 2 1 1 1 
        11
    
    Output 2 :
    
        Pair found is : 9
    
    Time complexity: O(n)
    Space Complexity: O(1)
*/
