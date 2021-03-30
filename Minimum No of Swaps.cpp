#include<bits/stdc++.h>
 
 using namespace std;
 
int minSwaps(int arr[], int n)
{
    
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
 
   
    sort(arrPos, arrPos + n);
 
    vector<bool> vis(n, false);
    
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        
        if (vis[i] || arrPos[i].second == i)
            continue;
            
        int cycle_size = 0;
        
        for(int j=i; !vis[j]; cycle_size++)
        {
            vis[j] = 1;
            j = arrPos[j].second;
        }

        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }
    return ans;
}
 

int main()
{
	cout<<" Enter no of elements in array : ";
	int n;
	cin>>n;
	int arr[n];
    for(int i=0; i<n; i++)
	{
     	cin>>arr[i];
     }
    cout <<"Minimum number of swap : "<< minSwaps(arr, n);
    return 0;
}
