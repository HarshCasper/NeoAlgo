/* This algorithm will print the next greater element for all the indices in an array using stacks.
The procedure is to store the index of the next greater element in an answer array. Incase, there is no next greater element,
-1 will be stored.*/

#include <bits/stdc++.h>
using namespace std;

//Function to print the next greater element
void next_greater(int arr[],int n)
{
   int ans[n]; //declaring an answer array
   for(int i=0;i<n;i++)
   ans[i]=-1;  //marking all the indices with -1 initially

   stack<int> s;
   s.push(0);  //pushing the zeroth index of arr
   
   //iterating through the rest of indices of arr
   for(int i=1;i<n;i++)
   {
       /*If the stack is not empty and the value at cuurent index (arr[i]) is greater than value at s.top(),
        then next greater element for arr[s.top()] will be arr[i]. Once the next greater element for a particular
        index is found, then tha particular index can be popped out*/
     while(s.empty()==false && arr[i]>arr[s.top()]) 
     {                                              
        ans[s.top()]=i;
        s.pop();
     }
    s.push(i); //pushing the current index so that it can be compared with the values to its right in further iterations
   }
   
   //printing the final answer
   for(int i=0;i<n;i++)
   {
     if(ans[i]==-1) //if the value of ans[i] remains -1, it means there is no next greater element for it
     cout<<"-1 ";
     else
     cout<<arr[ans[i]]<<" ";
   }
   return;
}

//Driver Code
int main()
{
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
 cin>>arr[i];
 next_greater(arr,n);
 return 0;
}

/* Time Complexity : o(n)
   Space Complexity: O(n)
   Sample Input    : 4
                      4 5 2 25
   Sample Output   : 5 25 25 -1 */
