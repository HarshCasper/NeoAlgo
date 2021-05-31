
/*
Problem:
Given an array of size n sorted in ascending order is rotated at an unknown pivot index x (0 <= x<n), 
such that the resulting array is [arr[x], arr[x+1], ..., arr[n-1], arr[0], arr[1], ..., arr[x-1]](0-indexed).
Given the array arr[] after the rotation and an integer target, return the index of target if it is in array,
 or -1 if it is not in array.

Write an algorithm with O(log n) runtime complexity.
*/


#include <iostream>
#include <vector>
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
    int n;  
    cout<<"Enter number of Element: ";
    cin>>n;

    vector<int> arr;
    
    cout<<"Enter array Elements: ";  
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
   
     int target;
     cout<<"Enter the traget element: ";   
     cin>>target;
  
     int result= search(arr,target);

     cout<<"Target Element found at index: ";
     cout<<result<<endl;

  return 0; 
}

/*
Sample Input/Output:

Input: Enter number of Element: 7
       Enter array Elements: 4 5 6 7 0 1 2
       Enter the traget element: 0

Output: Target Element found at index: 4


Time complexity:  O(log n)
Space complexity: O(1)

*/

