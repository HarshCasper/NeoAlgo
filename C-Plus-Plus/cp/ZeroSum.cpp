/**
Given an array of integers,
find the largest continuous subarray 
with sum zero
**/

#include <bits/stdc++.h>
using namespace std;

vector<int> lszero(vector<int> &A) {
    int start = -1, end = -1, m = 0, l = 0;
    unordered_map<int, int> umap;
    int sum = 0, n = A.size();
    for(int i=0; i<n; i++) {
        sum += A[i];
        if(sum == 0) {
            start = 0;
            end = i;
            m = i+1;
        } else {
            if(umap.find(sum) != umap.end()) {
                l = i-umap[sum];
                if(l > m) {
                    m = l;
                    start = umap[sum]+1;
                    end = i;
                } 
            } else 
                umap[sum] = i;
        }
    }
    
    if(start == -1)
        return vector<int> (0);
    
    vector<int> res(m);
    for(int i=start; i<=end; i++)
        res[i-start] = A[i];
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans = lszero(arr);
    cout << "The longest subarray with sum zer is : \n";
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}

/**

Input :
5
1 2 -2 4 -4
Output:
The longest subarray with sum zer is : 
2 -2 4 -4 

Time Complexity : O(n)
Space Complexity : O(n)

**/