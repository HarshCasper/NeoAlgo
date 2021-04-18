#include <iostream>
#include <bits/stdc++.h>
using namespace std;
    // Function to find majority element in the array
    // arr is the array 
    //start is the starting index of array
    //end is the ending index of the array
	/*  solvef function will give us the starting index of majority element

	*/ 
	/* 
	Approach: The basic solution is to find the majority element form the array of size n.
	          1:First sort the array 
	          2:keep the mid element of array as the element which we have to find 
			  3:solve the array using binary search and keep track of count of element
			  4:If the count of element is greater than tha n/2 of the size of element than return the 
			  element as the majority 
			  5:If not than return -1 "as no majority element"  
			  
			My approach: 1:sort the array 
			            2:keep the mid element as the findele 
			            3:now to use modified search to find the first occurence of findele
			            4:Same as find the last occurence of findele
			            5:ans=last-first+1 use this formula and 
			            6:check if the ans is greater than n/2 size of element
						7:if yes then return the mid element of the sorted array
						8:else return -1 "No Majority Element found"  
			   
		      
		      
	Algorithm: 
			Create a variable to store the max count, count = 0
			Traverse through the array from start to end.
			For every element in the array run another loop to find the count of similar elements in the given array.
			If the count is greater than the max count update the max count and store the index in another variable.
			If the maximum count is greater than the half the size of the array, print the element. Else print there is no majority element.
	
   */
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
    
    /*  solvel function will give us the  endling  index of majority element

	*/ 
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
        else{
            
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
			cin>>n;
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
    
    /*  
    Input:
     N = 3 
     A[] = {1,2,3} 
     
    Output: -1
    Explanation:
				Since, each element in 
				{1,2,3} appears only once so there 
				is no majority element.
		
		
	Input:
		N = 5 
		A[] = {1,4,4,4,2} 
		Output: 4
		Explanation:
					Since, 4 is present more
					than N/2 times, so it is 
					the majority element.	
				
	*/
