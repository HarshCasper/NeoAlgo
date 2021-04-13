/* Find array is Subset of another array */

#include<bits/stdc++.h>
using namespace std;

/* Function for Finding array is subset of another array */
int solve()
{
    /* Input n1 = size of array 1
       Input n2 = size of array 2 */
    int n1,n2;
    cin >> n1 >> n2;

    int a1[n1],a2[n2];

    /* Input values in array 1 */
    for (int i = 0; i < n1; ++i)
    {
        cin >> a1[i];
    }

    /* Input values in array 2 */
    for (int i = 0; i < n2; ++i)
    {
        cin >> a2[i];
    }

    int i = 0, j = 0;

    /* Check if n1 is less then n2 */
    if(n1 < n2)
      return 0; 

    /*Sort the array 1*/
    sort(a1, a1 + n1);

    /*Sort the array 2*/
    sort(a2, a2 + n2);

    while(j < n1 && i < n2 )
    {
        /* If array 1 is less than array 2
           then increament j*/
        if( a1[j] < a2[i] )
        {
            j++;
        }

        /* If array 1 is equal to array 2
           then increament i and j*/
        else if( a1[j] == a2[i] )
        {
            j++;
            i++;
        }

        /* Return if element is not equal and
           smaller than array 2*/
        else if( a1[j] > a2[i] )
            return 0;
    }

        /* Return 0 if array 1 is subset of 
       array 2*/
        if(i < n2)
            return 0;
        else
            return 1;
}

int main()
{
    int k = solve();
    if(k)
        cout << "Array2 is a subset of Array1" ;
    else
        cout << "Array2 is not a subset of Array1" ;
    return 0;
}

/*
/*
Test cases :
    
    Input 1 :
        
        6 4
        11 1 13 21 3 7
        11 3 7 1

    Output 1 :

        Array2 is a subset of Array1

    Input 2 :

        5 3
        10 5 2 23 19
        19 5 3
    
    Output 2 :
    
        Array2 is not a subset of Array1  
    
    Time complexity: O(n)
    Space Complexity: O(1)
*/
