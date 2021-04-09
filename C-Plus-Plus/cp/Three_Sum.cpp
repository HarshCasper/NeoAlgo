/*
Description :
    
	TThree Sum Problem - In this problem, user will provide an array and we
                         have find wether there is any "three" numbers are 
                         present in the array who's sum is equal to the target 
		                 provided. If it is present then it will show true else 
                         it will show false.
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
	// n= size of an array
	int n; 
	cin>>n;
	//target = the number who's sum we have find.
	int target; 
	cin>>target;

    //n size of array
	vector<int> a(n); 
    //taking input in the array
	for(auto &i : a){ 
		cin>>i;
	}
	bool found = false;
	sort(a.begin(),a.end());

	for(int i=0;i<n;i++){   
		int lo =i+1, hi = n-1;
		while(lo<hi){
			int current = a[i]+a[lo]+a[hi];
			if(current == target){
				found = true;
			}
			if(current<target){
				lo++;
			}
			else{
				hi--;
			}
		}
	}
	if(found){
		cout<<"True";
	}
	else{
		cout<<"False";
	}
}


/*
Time Complexity  : O(n2)
Space Complexity : O(n)

Test Cases :


 Test Case  1: 
    Input : 6 24 102 3 6 9 34 24
	Output : True

 Test Case 2:
    Input : 6 24 2 3 6 9 3 25
	Output : False
*/

