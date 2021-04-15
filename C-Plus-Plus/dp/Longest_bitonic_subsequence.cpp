/*
The longest bitonic subsequence is a sequence in which the sequence is first increasing then decreasing ,
The below program finds the length of the longest bitonic subsequence.
*/
#include <bits/stdc++.h>

using namespace std;

int longest_bitonic_subsequence(vector<int> v, int n)
{
    vector<int> v_i;
    for (int i = 0; i < n; i++)
    {
        v_i.push_back(1);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                if (v_i[i] <= v_i[j])
                {
                    v_i[i] = v_i[j] + 1;
                }
            }
        }
    }
    vector<int> v_d;
    for (int i = 0; i < n; i++)
    {
        v_d.push_back(1);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (v[i] > v[j])
            {
                if (v_d[i] <= v_d[j])
                {
                    v_d[i] = v_d[j] + 1;
                }
            }
        }
    }
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        int temp = v_i[i] + v_d[i] - 1;
        if (temp > max)
        {
            max = temp;
        }
    }
    return max;
}

int main()
{
    cout << "Enter the number of elements in the sequence" << endl;
    int n;
    cin >> n;
    vector<int> v;
    cout << "Enter the elements of the sequence" << endl;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cout << "The length of longest bitonic subsequence is : " << longest_bitonic_subsequence(v, n);
    return 0;
}

/*
Sample I/O:

Enter the number of elements in the vay
10
Enter the elements of the vay
1 2 6 3 12 14 4 9 10 7
The length of longest bitonic subsequence is : 7

Time Complexity : O(n^2)
Space Complexity : O(n)
*/
