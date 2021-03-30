/*Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. The task is to find the index of the given element K in the array A.
Input:
The first line of the input contains an integer T, denoting the total number of test cases. Then T test cases follow. Each test case consists of three lines. First line of each test case contains an integer N denoting the size of the given array. Second line of each test case contains N space separated integers denoting the elements of the array A. Third line of each test case contains an integer K denoting the element to be searched in the array.
Output:
Corresponding to each test case, output the index of the element found in the array.  If element is not present, then output -1.
*/

#include <iostream>
using namespace std;

int main()
{
	int t,i,j,n,x,l=0,r=0,mid,pos;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>n; //number of elements
	    int arr[n];
	    for(j=0;j<n;j++)
	        cin>>arr[j];

	    cin>>x; //element to be searched

	   l=0;
	   r=n-1;
	   pos=-1; //If element is not present print -1
	   while(l<=r)
	   {
	       mid=l + ((r - l) / 2);;  //find mid
	       if(arr[mid]==x) //if element is found set pos=mid
	       {
	       pos=mid;
	       break;
	       }
	       else if(arr[mid]>=arr[l])
	       {
	           if(x<=arr[mid] && x>=arr[l])
	           r=mid-1;
	           else
	           l=mid+1;
	       }
	       else
	       {
	           if(x>=arr[mid] && x<=arr[r])
	           l=mid+1;
	           else
	           r=mid-1;
	       }
	   }
	   cout<<pos<<endl;
	}
	return 0;
}

/*
INPUT:
1
5
3 2 1 4 5
1
OUTPUT
2
INPUT
1
4
2 1 3 4
5
-1

Time Complexity: O(log n)
Space Complexity: O(1)
*/
