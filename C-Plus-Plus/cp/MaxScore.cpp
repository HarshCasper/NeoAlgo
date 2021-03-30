/*  
Problem Link:https://www.codechef.com/problems/MAXSCOR

*There are N chapters and only K minutes are left before the exam. 
*Chapter i will be worth Mi marks in the exam, and shall take Ti minutes to study. 
*Person can study the chapters in any order but needs to study them completely and at most once.
*He knows that he will forget the first chapter that he will prepare (due to lack of sleep) 
 and won’t be able to score any marks in it. 
*Find the maximum marks that person can score in the exam.

**Input:
*First line is T, number of testcases.
*Each testcase contain N+1 lines of input.
*First line contains 2 space separated integers N and K
 total number of chapters and total time left before the exam respectively.
*Each of the next N lines contain 2 space separated integers Mi and Ti w
 eightage and time for the ith chapter respectively.

**Output: Maximum score.
*/

#include<bits/stdc++.h>
using namespace std;
//Function Code
void find(int arr[],int T[],int n,int t)
{
	        //variable to store max score
		int x=0,
		//initializing it to Max value possible
		min=INT_MAX;
		//checking condition 
		for(int i=0;i<n;i++)
		{
	        //if time is still left
		if(t>0)
		{
		x+=arr[i];
		t-=T[i];
		if(arr[i]<min)
		min=arr[i];	
		}	
		}
		//we will start with chapter having lowest score so that less mark will be deducted.
		//Max Score after decreasing chapter with first chapter score
		x=x-min;
		cout<<x<<endl;
}
//Driver Code
int main()
{
	int t;
	//no of test cases
	cin>>t;
	while(t--)
	{
		int n,t;
		//no of chapters left
		cin>>n;
		//time left before exam
		cin>>t;
		int T[n],arr[n];
		for(int i=0;i<n;i++)
		{   //making array of chapters
			cin>>arr[i];
			//Making array of Time 
			cin>>T[i];
		}
		//function to find max score.
	    find(arr,T,n,t);		
	}
}
/*
Sample Input:
3
2 2
1 1
2 1
3 3
1 1
2 2
3 3
5 6
5 1
4 2
3 3
2 4
1 5
Smaple Output:
2
2
9
Time Complexity: 1 sec
Space Complexity: 50000 Bytes
*/
