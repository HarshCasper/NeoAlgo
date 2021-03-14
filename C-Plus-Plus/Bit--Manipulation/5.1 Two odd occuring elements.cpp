// Only two odd ocurring number

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter number of elements \n";
	cin>>n;
    vector<int>arr;
    int a;
    for(int i=0;i<n;i++)
    {
    	cin>>a;
    	arr.push_back(a);
	}
   int xors = 0, res1 = 0, res2 = 0; 
        
        for (int i = 0; i < n; i++) 
        xors = xors ^ arr[i]; 
  
   
        int sn = xors & (~(xors - 1)); 
  
    
        for (int i = 0; i < n; i++) 
        { 
            if ((arr[i] & sn) != 0) 
                res1 = res1 ^ arr[i]; 
            else
                res2 = res2 ^ arr[i]; 
        } 
        
        
        cout <<  res1 << " " << res2;
	  
}

