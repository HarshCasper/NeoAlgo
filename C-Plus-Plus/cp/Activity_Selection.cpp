/**
You are given n activities (from 0 to n-1) with their start and finish times.
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a time.

Input Format
The first line consists of an integer T, the number of test cases.
 For each test case, the first line consists of an integer N, the number of activities. 
 Then the next N lines contain two integers m and n, the start and end time of each activity.

Output Format
For each test case find the maximum number of activities that you can do.

Sample Input
1 
3
10 20
12 15
20 30

Sample Output
2

Explanation
Person can only do 0th and 2nd activities.
**/
#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

bool compare(pair<int,int> a,pair <int ,int> b)         //made compare function for sorting
{
	return a.second<b.second;
}

int main() 
{
	int testcases;
	
	cout<<"Enter no. of Testcases:";                      //no.of test cases to be tested
	cin>>testcases;

	while(testcases--)
	{
		int num,count;                                     //counter for answer
		count=1;                                           // Initialize count with 1
		
		cout<<"Enter no. of Activities:";
		cin>>num;
		
		pair<int,int>* arr = new pair<int,int>[num];      //An dynamic Array of Pairs
        
		cout<<"Enter activities:"<<endl;
		for(int i=0;i<num;i++)
		{
			cin>>arr[i].first>>arr[i].second;
		}

		sort(arr,arr+num,compare);                        // Inbuilt Sorting Function taking compare function as a parameter 

		int prev=0;

		for(int curr=1;curr<num;curr++)
		{
			if(arr[prev].second<=arr[curr].first)
			{
				count++;
				prev=curr;
			}
		}
		
        cout<<"Person can do only "<<count<<" activities at a time"<<endl;    //Result
		delete[] arr;  
	}
	return 0;
}
