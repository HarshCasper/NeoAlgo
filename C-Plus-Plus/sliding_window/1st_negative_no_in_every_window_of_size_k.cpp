/*
Problem Statement:
An array and a positive integer k is given, we need to find 1st negative integer for each and every window(contiguous subarray) of size k


Brute force:-
	take two pointers say i,j 
	Initialise i from 0 and  j from i to k and find the 1st negative.
	In this , we are doing repetitive work 
	therefore it's time complexity O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	//declaring a variable n to store size of array
	int n;
	//taking array size as input
	cin>>n;
	//declaring an array
	int arr[n];
	//taking array element as input
	for(int i=0;i<n;i++)
		cin>>arr[i];
	//taking window size as input
	int k;
	cin>>k;
	//dynamic array for storing negative elements
	vector<int>list;
	//dymanice array for storing 1st negative of each window
	vector<int>ans;
	int i=0,j=0;
	//if j non negative then we don.t need it
	//if negative, store it in array
	while(j<n){
		//element is negative then push it into list
		if(arr[j]<0)
			list.push_back(arr[j]);
		//window size not reached then increment j
		if(j-i+1<k)
			j++;
		//on hitting window size
		else if(j-i+1==k)
		{	//no negative element in current window 
			if(list.size()==0)
			ans.push_back(0);
			else 
				{//push the 1st negative of every window
					ans.push_back(list.front());
					//negative element is included in list only if it is in starting
					//we need to remove that element which is nit in window	
					if(arr[i]==list.front())
					//delete that	
					list.erase(list.begin());
			    }

			    //slide the window
				i++;
				j++;

		}

	}
	//printing elements of dynamic array ans
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	    //new line
		cout<<endl;
	return 0;
}

/*
 Input format:-
 size
 array elements
 k

 Output format:-
 size-k+1 elements

 Test cases:
  Input 1:-
  8
  12 3 -7 8 -15 39 15 20
  3

  Output 1:-
  0 -7 -7 -15 -15 0


  Input 2:-
  5
  -9 -5 8 -5 10
  2

  Output 2:-
  -9 -5 -5 -5

  Time complexity: O(n)
  Space complexity: O(k)
*/

