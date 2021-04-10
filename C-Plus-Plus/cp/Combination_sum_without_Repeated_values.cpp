/*
The problem states that Given a array of distinct integer and a target value Return all the unique combination of array where chosen number sum to target. (You may return combination in ary order)

Note that Same element from given array should not occur more then one time
*/
#include <bits/stdc++.h>
using namespace std;
void find(vector<int> arr,vector<vector<int>>& ans,vector<int>& r,int sum,int start)
    {
        if(sum<0)return;
        else if(sum ==0)
        {
            ans.push_back(r);
            return;
        }
        for(int i=start;i<arr.size();i++)
        {
            if(i>start && arr[i]==arr[i-1])continue;
            if(sum-arr[i] < 0)break;
            r.push_back(arr[i]);
            find(arr,ans,r,sum-arr[i],i+1);
            r.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> r;
        sort(arr.begin(),arr.end());
        find(arr,ans,r,target,0);
        return ans;
    }
    
int main()
{
    int n;
    cin>>n;
    vector<int> arr; 
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int target;
    cin>>target;
    vector<vector<int>> answer=combinationSum2(arr,target);
    for(int i=0;i<answer.size();i++)
    {
        cout<<"[";
        for(int j=0;j<answer[i].size();j++)
        {
            cout<<answer[i][j]<<",";
        }
        cout<<"]\n";
    }
}

/*
Test case 1:
Input:
7
10 1 2 7 6 1 5
8

Output:
[1,1,6,]
[1,2,5,]
[1,7,]
[2,6,]
*/
