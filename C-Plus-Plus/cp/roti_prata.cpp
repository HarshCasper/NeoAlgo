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

/*
The question states that there are L stalls and each stall has a cook which have a
particular rank (Chef with rank 2 can cook 1st parata in 2 mins, second parata in 4 mins..)
We have to obtain P no of paratas, so we have to find out the minimum time in which the order is ready.
*/

/* The idea is to use Binary search in an optimised way where we can apply the same
concept on an answer space of 0-low to 10e6-high, and in all the itertions we divide the
search space into half by checking if within mid = (low_high)/2 amount of time the no of parats are made.
*/


// This function is to check whether p number of paratas are made within the mid amuount of time
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

int binarysearch(int a[], int p, int n){
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
      return ans;
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
        cout<<binarysearch(a,p,n)<<endl; 
     }
   return 0;
}

/* 
Time complexity - O(log	n)
Space Complexity - O(1)
*/


/*
SAMPLE INPUT AND OUTPUT

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
