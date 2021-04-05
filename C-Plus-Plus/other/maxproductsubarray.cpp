#include<bits/stdc++.h>
using namespace std;
 int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxVal=nums[0];
        int minVal=nums[0];
        int maxpro=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<0)
            {
                swap(maxVal,minVal);
            }
            
            maxVal=max(nums[i],nums[i]*maxVal);
            minVal=min(nums[i],minVal*nums[i]);
            maxpro=max(maxpro,maxVal);
        }
        
        return maxpro;    
 }

 int main()
 {
     int n;
     cin>>n;
     vector<int> nums(n);
     int p;
     for(int i=0;i<n;i++)
     {
         cin>>p;
         nums.push_back(p);
     }
     cout<<maxProduct(nums);

 }