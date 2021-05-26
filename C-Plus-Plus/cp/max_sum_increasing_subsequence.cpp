/*Problem Statement: 
You are given a sequence of N integers A denoted by A[1] , A[2]…..A[N].
Each integer in the sequence has a value associated with it W[1],W[2]…. W[N].
You have to select a subsequence of given array A such that all the elements in A are in 
strictly increasing order and sum of values of elements in this selected subsequence is maximum. 
You have to print this maximum value. */

#include <bits/stdc++.h>
using namespace std;

void compress(int arr[], int n, map<int, int> &m, map<int, int> &rm)
{
    sort(arr, arr + n);
    int ind = 1;
    for (int i = 0; i < n; i++)
    {
        if (m[arr[i]])
        {
            continue;
        }

        m[arr[i]] = ind;
        rm[ind] = arr[i];
        ind++;
    }
}

void update(int max_elements[], int arr[], int n, int index)
{
    //traversing to get the largest value
    for (int i = arr[index]; i <= n; i += (i &(-i)))
    {
        max_elements[i] = max(max_elements[i], arr[index]);
    }
}

int query(int bit[], int max_elements[], int arr[], int w[], int n, int index)
{
    bit[arr[index]] = max(bit[arr[index]], int(w[index]));
    int maxel = 0;
    /*Traversing the max value before the current value, 
    so that it could be added to the max sum */
    for (int i = arr[index] - 1; i > 0; i -= (i &(-i)))
    {
        maxel = max(maxel, max_elements[i]);
    }

    bit[arr[index]] += bit[maxel];
    return bit[arr[index]];
}

int main()
{
    int n;
    cout << "Enter total integers: " << endl;
    cin >> n;
    int arr[n + 1], w[n + 1], max_elements[1000], array[n];
    int bit[1000];
    cout << "Enter the associated values: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        array[i - 1] = arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    map<int, int> m;
    map<int, int> rm;
    compress(array, n, m, rm);
    for (int i = 1; i <= n; i++)
    {
        arr[i] = m[arr[i]];
    }
    for (int i = 0; i <= n + 3; i++)
    {
        max_elements[i] = 0;
        bit[i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        update(max_elements, arr, n, i);
        ans = max(ans, query(bit, max_elements, arr, w, n, i));
    }
    cout << "Max value with strictly increasing order is: " << ans << endl;
    return 0;
}
/*
Example:-

Input:-
Enter total integers: 
4
Enter the associated values: 
1 2 3 4
100 200 300 400

Output:-
Max value with strictly increasing order is: 1000

Time Complexity: O(n)
Space Complexity: O(n)
*/

