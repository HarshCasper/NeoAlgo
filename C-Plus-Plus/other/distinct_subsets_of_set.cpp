/*Finding all distinct subsets of a given set using BitMasking Approach
Examples:

Input:  S = {1, 2, 2}
Output:  {}, {1}, {2}, {1, 2}, {2, 2}, {1, 2, 2}

Explanation:
The total subsets of given set are -
{}, {1}, {2}, {2}, {1, 2}, {1, 2}, {2, 2}, {1, 2, 2}
Here {2} and {1, 2} are repeated twice so they are considered only once in the output*/


#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &s, char ch)
{
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, ch))
        elems.push_back(item);

    return elems;
}

// Function to find all subsets of given set(repeated subset is considered only once)
int printPowerSet(vector<int> arr, int n)
{
    vector<string> list;

    for (int i = 0; i < (int) pow(2, n); i++)
    {
        string subset = "";
        for (int j = 0; j < n; j++)
        {
            // Check if jth bit in the i is set. If the bit is set, we consider jth element from set
            if ((i & (1 << j)) != 0)
                subset += to_string(arr[j]) + "|";
        }

        // if subset is encountered for the first time, If we use set<string>, we can directly insert
        if (find(list.begin(), list.end(), subset) == list.end())
            list.push_back(subset);
    }

    for (string subset : list)
    {
        // split the subset and print its elements
        vector<string> a = split(subset, '|');
        for (string str: a)
            cout << str << " ";
        cout << endl;
    }
}

int main()
{
    vector<int> arr;
    int n = arr.size();

    printPowerSet(arr, n);

    return 0;
}

/*Input: 10 12 12
Output:
10
12
10 12
12 12
10 12 12 */

/*Time complexity
For every index, we make 2 recursion calls and there are n elements so total time complexity is O(2^n).

Space complexity
There are 2^n-1 subsets and for every subset, we need O(n) space on average so total space complexity is O(2^n * n). */