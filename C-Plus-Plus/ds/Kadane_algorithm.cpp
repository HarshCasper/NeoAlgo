//Kadane's Algorithm is used to solve the maximum subarray sum problem.
//The maximum subarray problem is the task of finding the largest 
//possible sum of a contiguous subarray.

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

	ll int n,maxs;
	cin>>n;
	
	ll int arr[n],i,sum=0,pos=0,neg=0, maxi = INT_MIN;
	    
	for(i=0;i<n;i++)
	{
	    cin>>arr[i];
		sum += arr[i];

	    if(arr[i] >=0 )
	    pos++;
 
	    else
	    neg++;	
	}
   
	if(pos == n){
	    cout<<sum<<endl;
    }
	else if(neg == n){
	    for(i = 0; i<n; i++)
	    maxi = max(maxi , arr[i]);
		   
	    cout<<maxi<<endl;
	}
	else{
	    ll int left = 0;
	    ll int maxs = 0;
	        
	    for(i=0; i<n; i++){
	        if( left + arr[i] <=0 ){        
	            left = 0;
	        }     
	        else{
	            left += arr[i];
	            maxs = max(maxs,left);   
	        }       
	    }
	    cout<<maxs<<endl;
	}
}

/*
	Testcase
	Input :
	5
	4 1 -3 7 12
	Output : 21

	Time complexity : O(n) in average case
	Space complexity : O(1)
*/
