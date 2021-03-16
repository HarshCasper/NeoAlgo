/*
Given an array of N elements , find it's prefix sum array. In Competitive Programming, many times we need to calculate prefix sum array to solve our problem.
*/

#include <bits/stdc++.h>
using namespace std;
int ar[100009];

void prefix_sum_array(int ar[] ,int N)
{
    int pref_ar[N+1] = {0};
    pref_ar[0] = ar[0];
    // we will add the current element of ar[] array and previous element of pref_ar [] array
    for(int i = 1; i < N; i++)
    {
        pref_ar[i] = ar[i] + pref_ar[i - 1];
    }
    cout << "The New Prefix sum array is \n";
    for(int i = 0; i < N; i++)
    {
        cout << pref_ar[i] << ' ';
    }
    cout << endl;
    return;
}

int main()
{
    cout << "Input array size\n";
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> ar[i];
    }
    prefix_sum_array(ar , N);
}
/*
Standard Input and Output

Input array size
7
10 4 16 34 23 5 90
The New Prefix sum array is
10 14 30 64 87 92 182

Time Complexity : O(N)
Space Complexity : O(N)
*/
