/*
Problem Statement:
An array and a positive integer k is given, we need to find maximum for each and every contiguous subarray of size k.

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	//taking araay input elements
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int k;
	cin>>k;
	//dequeue for storing maximum element
	deque<int>q;
	//maximum of all subarray
	
	vector<int>ans;
	//edge case
	  if(k>n)
    {	//pushing maximum element into the answer
        ans.push_back(*max_element(arr,arr+n));
       
    }
	int i=0,j=0;
	///iterating loop until j reaches to the end
	while(j<n){
		while(q.size()>0 && q.back()<arr[j])
			{//delete elments which are samller than arr[j] as we don't need them(which are on left side)
				q.pop_back();}
		q.push_back(arr[j]);
		//window size not reached then increment j
		if(j-i+1<k)
			j++;
		//on hitting window size
		else if(j-i+1==k)
		{	//1st elemnt is inserted into ans
			ans.push_back(q.front());
			//1st element equals 1st element of current window, remove it
			if(q.front()==arr[i])
				q.pop_front();

			    //slide the window
				i++;
				j++;

			
		}

	} //output answer
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
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
  12 8 8 39 39 39

  Explanation: 
Window position                      Max
---------------                     -----
[12  3  -7] 8  -15  39  15  20       3
 12 [3  -7  8] -15  39  15  20       8     
 12  3 [-7  8  -15] 39  15  20       8     
 12  3  -7 [8  -15  39] 15  20       39     
 12  3  -7  8 [-15  39  15] 20       39     
 12  3  -7  8  -15 [39  15  20]      39    


  Input 2:-
  4
  3 2 1 5
  3

  Output 2:-
  3 5

  Time complexity: O(n*k)
  Space complexity: O(n)

*/

