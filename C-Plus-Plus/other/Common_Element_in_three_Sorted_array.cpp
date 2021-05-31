/* Find Common elements in three sorted arrays. */

#include<bits/stdc++.h>
using namespace std;

/* Function to Find common elements in three sorted arrays. */
void solve()
{
    /* Input n1 = size of array 1
       Input n2 = size of array 2
       Input n3 = size of array 3 */
    int n1,n2,n3;
    cin >> n1 >> n2 >> n3;

    int a1[n1],a2[n2],a3[n3];

    /* Input values in a1 */
    for (int i = 0; i < n1; ++i)
    {
        cin>>a1[i];
    }

    /* Input values in a2 */
    for (int i = 0; i < n2; ++i)
    {
        cin>>a2[i];    }

    /* Input values in a1 */
    for (int i = 0; i < n3; ++i)
    {
        cin>>a3[i];
    }

    /* Create a unordered_map to store */
    unordered_map<int,int> m1,m2,m3;

    for (int i = 0; i < n1; ++i)
    {
        m1[a1[i]]++;
    }

    for (int i = 0; i < n2; ++i)
    {
        m2[a2[i]]++;
    }

    for (int i = 0; i < n3; ++i)
    {
        m3[a3[i]]++;
    }

    vector<int> v;

    for (int i = 0; i < n1; ++i)
    {
        /* Check if the element in present in all three
           hashmap so print that element */
        if(m1[a1[i]] & m2[a1[i]] & m3[a1[i]])
        {
            v.push_back(a1[i]);
        }
    }

    cout << "Common element is : ";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
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
        
        6 5 8
        1 5 10 20 40 80 
        6 7 20 80 100 
        3 4 15 20 30 70 80 120

    Output 1 :

        Common elements are : 20 80

    Input 2 :

        3 5 4
        1 5 5 
        3 4 5 5 10
        5 5 10 20
    
    Output 2 :
    
        Common elements are : 5 5
    
    Time complexity: O(n1+n2+n3)
    Space Complexity: O(n1+n2+n3)
*/
