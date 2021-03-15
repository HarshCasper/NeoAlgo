/*
Problem Statement:-
	An array containining n positive integers and an integer k is given.We need to find the length of longest Sub-Array with sum of the elements equal to given value k
	Always keep in mind, subarray is continuous with no element excluded in betweeen

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
	//taking input from user
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int k;
	cin>>k;
	//length of longest subarray with sum k
	int maxx=INT_MIN;
	//initialisinh start and end pointer
	int i=0,j=0;
	//sum of elements
	long long sum=0;
	//iterate loop until end pointer doesn't reach to the end index of array
	while(j<n){
		sum=sum+a[j];
		//sum not equal to required then increase the window size
		if(sum<k)
			j++;
		//sum equal to required store at as possible answer
		else if(sum==k){
				maxx=max(maxx,j-i+1);
				//moving end pointer
				j++;

		}//sum greater than required sum
		else if(sum>k){
			//delete no. until greater than k
			while(sum>k)
			{sum=sum-a[i];
				//move forward
				i++;

		}
		j++;

	}
}//output answer
cout<<maxx<<endl;
}

/*
Input Format:
	n
	n elements
	k

Output Format:
	length of logest sub-array

 Test Cases:
    Input 1:
    8
    5 4 1 1 1 2 3 1
    5

    Output 1:
    4
	
	Explaination:-
    5 {4,1} {1,1,1,2} {2,3} have sum 5
    max length =4
	
	Time complexity: O(n)
	Space complexity: O(1)
  

 */
