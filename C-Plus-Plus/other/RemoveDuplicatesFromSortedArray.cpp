/* 
Given a sorted array,remove the duplicates such that each element appears only once and return the new length using two pointers.
Function removeDuplicates returns modified size of vector which is passed in this function initially.
 */

#include<bits/stdc++.h>

using namespace std;


int removeDuplicates(vector<int> &nums) {
    //base case
	if(nums.empty()){
	    return 0;
	}
	// initializing 2 pointers
	int p1=0;
	int p2=1;
	//main logic
	while(p2<nums.size()){
	    if(nums[p2]==nums[p1]){
	        p2++;
	        continue;
	    }
	    else{
	        std::swap(nums[++p1],nums[p2++]);
	    }
	}
nums.erase (nums.begin() + p1 + 1 , nums.end()) ;
return nums.size() ;
}

int main(){
    int size;
    cout<<"Enter size of array";
    cin>>size; //size input
    int arr[size];
    cout<<"Enter array";
    for(int i=0 ; i<size ; i++){
      cin>>arr[i]; // array input
    }
    int ans = removeDuplicates(arr);
    cout<<"Answer is"<<ans;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)

Sample input & output :

Enter size of array 3
Enter array 1 1 2
Answer is 2

*/