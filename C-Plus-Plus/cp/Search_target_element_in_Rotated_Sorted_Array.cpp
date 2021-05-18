
/*
Problem:
Given an array of size n sorted in ascending order is rotated at an unknown pivot index x (0 <= x<n), 
such that the resulting array is [arr[x], arr[x+1], ..., arr[n-1], arr[0], arr[1], ..., arr[x-1]](0-indexed).
Given the array arr[] after the rotation and an integer target, return the index of target if it is in array,
 or -1 if it is not in array.

Write an algorithm with O(log n) runtime complexity.
*/

/*
  Explanation:
     Use Binary search to reduce run time.
*/

#include <bits/stdc++.h>
using namespace std;

// function to search target element
 int search(vector<int>& arr, int target) {
       int answer=-1;
        
        int i=0;
        int j=arr.size()-1;
        
        if(arr[i]==target)
                return i;
            
            if(arr[j]==target)
                return j;
            
        // Binary Search    
        while(i<j)
        {
            int mid= i+(j-i)/2;
            
            if(arr[mid]==target)
                return mid;
            
            if(arr[i]==target)
                return i;
            
            if(arr[j]==target)
                return j;
            
            if(arr[mid]>arr[mid+1] && mid+1<arr.size())
            {
                if(target>=arr[i] && target<=arr[mid])
                {
                    j=mid;
                }
                else
                {
                    i=mid+1;
                }
            }
            else
            {
                i++;
                j--;
            }
            
        }
        
        return answer;
    }

int main()
{
    int n;  // Number of Element
    cin>>n;

    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x;    // input given array element 
        cin>>x;
        arr.push_back(x);
    }
   
     int target;    //input target element
     cin>>target;
  
     int result= search(arr,target);

     cout<<result<<endl;

  return 0; 
}

/*
  Time Complexity: O(log n)
*/

/*
   Example:
     Input: arr = [4,5,6,7,0,1,2], target = 0
     Output: 4

     Input: arr=[4,5,6,7,0,1,2], target = 3
     Output: -1

     Input: arr=[1], target=0
     Output: -1
*/


