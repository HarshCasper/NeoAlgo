/*
You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K 
painters available and you are also given how much time a painter takes to
 paint 1 unit of board. You have to get this job done as soon as possible
 under the constraints that any painter will only paint contiguous sections
  of board. Return the ans % 10000003

Input Format
First line contains three space seperated integers N,K and T ,where
N = Size of array,
K = No of painters available ,
T = Time taken to print each board by one painter
Next line contains N space seperated positive integers denoting size of N boards.

Constraints
1<=N<=100000
1<=K<=100000
1<=T<=1000000
1<=Li<=100000

Output Format
Return minimum time required to paint all boards % 10000003.

Sample Input
2 2 5
1 10
Sample Output
50
Explanation
The first painter can paint the first board in 5 units of time and the second painter 
will take 50 units of time to paint the second board. Since both can paint simultaneously,
 the total time required to paint both the boards is 50.
*/

#include<iostream>
#include <bits/stdc++.h>

using namespace std;

bool painters(int* arr,long long int maxtime,int n,int k)
{
	long long int time=0;
	int p_used=1;
	for(int i=0;i<n;i++)
	{
		time += arr[i];
		if(time > maxtime)
		{
			time=arr[i];
			p_used++;
			if(p_used>k)
			{
				return false;
			}
		}
	}
	return true;
}


long int minimum_time(int* arr,int n ,int k,int t,long long int sum)
{
	long long int start = *max_element(arr, arr + n);
	long long int end   = sum;
	long long int ans;
	while(start<=end)
	{
		long long mid = (start+end)/2;
		if(painters(arr,mid,n,k))
		{
			ans=mid;
			end=mid-1;
		}
		else
        {
            start=mid+1;
        }
    }
    return (ans*t)%10000003;
}


int main()
{
	int n,k,t;
	long long int sum=0;
	cin>>n>>k>>t;
	int* arr=new int[n];
	for(int i=0;i<n;i++)
    {
		cin>>arr[i];
        sum += arr[i];
	}
	cout<<minimum_time(arr,n,k,t,sum);	
	delete[] arr;
	return 0;
}
