/* Sorting a Queue without using extra space */

#include<bits/stdc++.h>
using namespace std;

/* Function for Sorting a Queue without using extra space */
void solve()
{
    /* Input n = size of array */
    int n;
    cin >> n;

    /* Create an empty array */
    int a[n];

    /* Create an empty queue */
    queue<int> q;

    /* Input values in a queue */
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        q.push(a[i]);
    }

    /* Find the index of smallest element from the unsorted queue */
    for (int i = 1; i <= n; i++)
    {
        int min_index = -1;
        int min_value = INT_MAX;
        int sortedIndex = n - i;

        for (int i = 0; i < n; i++)
        {
            int current = q.front();
            q.pop();

            /* Find the minimum value index only from unsorted queue */
            if (current <= min_value && i <= sortedIndex)
            {
                min_index = i;
                min_value = current;
            }
            q.push(current);
        }

        /* Remove min value from queue */
        int min_val;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            int curr = q.front();
            q.pop();
            if (i != min_index)
                q.push(curr);
            else
                min_val = curr;
        }
        /* Add min value to the end of the queue */
        q.push(min_val);
    }

    /* Print the sorted queue */
    while (q.empty() == false)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    solve();

    return 0;
}

/*
Test cases :

    Input 1 :

        4
        30 11 15 4

    Output 1 :

        4 11 15 30


    Input 2 :

        4
        3  2  1  2

    Output 2 :

        1 2 2 3

    Time complexity: O(n*n)
    Space Complexity: O(1)
*/
