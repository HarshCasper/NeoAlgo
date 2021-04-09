/* This program prints the starting and ending index of the subarrays
   which have sum as 0.
   The given approach uses hashing to solve the problem
*/

#include<bits/stdc++.h>
using namespace std;
vector< pair<int, int> > printSubArrays(vector<int> arr, int n)
{
    unordered_map<int, vector<int> > map;
    vector <pair<int, int>> result;
    
    int sum = 0;
   
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
            result.push_back(make_pair(0, i));

        if (map.find(sum) != map.end())
        {
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                result.push_back(make_pair(*it + 1, i));
        }
   
        map[sum].push_back(i);
    }

    return result;
}
   
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr;
        for(int i = 0; i < n; i++) {
            int item;
            cin>>item;
            arr.push_back(item);
        }
        vector<pair<int, int>> result = printSubArrays(arr, n);
        for (auto it = result.begin(); it != result.end(); it++)
        cout << "Subarray found from Index " <<
            it->first << " to " << it->second << endl;
    } 
}

/*
    Input format contains t - number of test cases
    Next t lines contains two lines with n as number of elements in the array 
    and the next line contains n elements.
    Sample input:
    1
    11
    6 3 -1 -3 4 -2 2 4 6 -12 -7
    
    Sample output:
    Subarray found from Index 2 to 4
    Subarray found from Index 2 to 6
    Subarray found from Index 5 to 6
    Subarray found from Index 6 to 9
    Subarray found from Index 0 to 10
    
    Complexity:
    Time Complexity: O(n)
    Space Complexity: O(n)