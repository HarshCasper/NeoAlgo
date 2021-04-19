/*  Ques: Majority_Element_using_Binary_Search

Given an array A of N elements. Find the majority element in the array.
A majority element in an array A of size N is an element that appears more than N/2 times in the array.    
    
Approach: 
1:First sort the array 
2:keep the mid element of array as the element which we have to find let say (majele)
3:solve the array using modified  binary search and keep track of count of majele
4:find the first occurence of majele and last occurence 
5:now use this formula to find the answer ( ans=last-first+1 )
6:If the count of majele is greater than tha n/2 of the size of element than return the majele as the majority element ans this the answer.
7:If not than return -1 "as no majority element"  
			  
Algorithm: 
Create a variable to store the max_count, count = 0
Traverse through the array from start to end.
For every element in the array run another loop to find the count of similar elements in the given array.
If the count is greater than the max count update the max count and store the index in another variable.
If the maximum count is greater than the half the size of the array, print the element. Else print there is no majority element.
	
Time complexity :O(nlogn)
Space Complexity:O(1)
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 /*  solvef function will give us the  first occurence index of majority element (majele)*/
int solvef(int arr[],int start,int end ,int s)
{
	int fres=-1;
	while(start<=end)
	{
		int mid=start+(end-start)/2;
                if(s==arr[mid])
		{
			fres=mid;
                        end=mid-1;
                }
                else if(s<arr[mid])
		{
			end=mid-1;
		}
		else
		{
			start=mid+1;       
	        } 
	}
	return fres;

}
/*  solvel function will give us the  last occurence index of majority element (majele)*/
int solvel(int arr[],int start,int end, int s)
{
	int lres=-1;
        while(start<=end)
	{
		int mid=start+(end-start)/2;
                if(s==arr[mid])
		{
			lres=mid;
                        start=mid+1;
                }
                else if(s<arr[mid])
                {
                        end=mid-1;
                }
                else
                {
			start=mid+1;
                
                }
            
        }
	return lres;
}
// this is function which will call the solvef,solvel function and check for the count greater than n/2 if or not?
int majorityElement(int a[], int size)
{
	if(size==1)
	{
		return a[0];
        }
	sort(a,a+size);
        int st=0;
        int en=size-1;
        int e=st+(en-st)/2;
        int ele=a[e];
        int la=solvef(a,0,size-1,ele);
        int ra=solvel(a,0,size-1,ele);
        int ans=ra-la+1;
        if(ans>size/2)
	{
		return a[e];
        }
        else
	{
		return -1;
        }
}
int main()
{
//Input number of test cases
	int t;
	cin>>t;
        while(t--)
        {
//enter number of element
		int n;
	        cin>>n
//initializing the array
               int arr[n];
               for(int i=0;i<n;i++)
	       {
		       cin>>arr[i];
               }
		cout<<majorityElement(arr,n)<<endl;
	}
	return 0;
}    
/*____________________________________________________________________________________________________________________________*/
 
/*  
 Input-Output cases

test case : t= 2
Input (1):
     N = 3 
     A[] = {1,2,3} 
     
Output (1): -1
Explanation 1:
Since, each element in {1,2,3} appears only once so there is no majority element.
--------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------
Input (2):
      N = 5 
      A[] = {1,4,4,4,2} 
Output (2): 4
Explanation (2):
Since, 4 is present more than N/2 times, so it is the majority element.	
*/
