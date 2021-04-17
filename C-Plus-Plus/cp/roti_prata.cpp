#include<bits/stdc++.h>
using namespace std;

// Problem Statement :
/* A person was asked to go to the food connection and get P(P<=1000) pratas packed 
for the function. The stall has L cooks(L<=50) and each cook has a rank R(1<=R<=8)
A cook with a rank R can cook 1 prata in the first R minutes 1 more prata in the 
next 2R minutes, 1 more prata in 3R minutes and so on (he can only cook a complete prata)
(For example if a cook is ranked 2.. he will cook one prata in 2 minutes 
one more prata in the next 4 mins one more in the next 6 minutes hence in 
total 12 minutes he cooks 3 pratas in 13 minutes also he can cook only 3 pratas
as he does not have enough time for the 4th prata). 
The person wants to know the minimum time to get the order done
*/

// The idea is to use Binary search in an optimised way where we can apply the same
// concept on an answer space of 0 to 10e6, and in all the itertions we divide the
// search space into half by checking if the no of parats are made by that particular
// time whose value is given the mid in all the iteartions.

// Time  O(logn)

bool check(int a[], int mid, int p,int n){
	int par=0;
	int time=0;

	for(int i=0;i<n;i++){
        time = a[i];
        int j=2;
        while(time<=mid){
        	par++;
        	time += (j*a[i]);
        	j++;
        }
	}
	return (par>=p);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int p,n;
		cin>>p>>n;
		int a[n];
		for(int i=0;i<n;i++){
            cin>>a[i];
		}

		int low =0;
		int high =10000000;
        int ans = -1;
		while(low<=high){
			int mid = high + (low-high)/2;
			if(check(a,mid,p,n)){
				ans = mid;
				high = mid-1;
			}
			else low = mid+1;
		}
       cout<<ans<<endl;
	}
	return 0;
}

/*
INPUT
3
10 4
1 2 3 4
8 1 
1
8 8
1 1 1 1 1 1 1 1

OUTPUT
12
36
1
*/