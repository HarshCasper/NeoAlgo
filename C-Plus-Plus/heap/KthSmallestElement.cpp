/*
  Following is the code to find the Kth smallest element in an array
  Approach:
      1.  Maintain a max heap of size k.
      2.  Traverse the array and remove the top element if it becomes
          greater than the current element of the array.
      3.  The top element of the heap after the traversal of the array
          is the Kth smallest element of the array.
*/

#include<bits/stdc++.h>
using namespace std;

int findkthsmallest(int arr[],int n,int k)
{
    //creating a max heap pf size k
    priority_queue<int>pq;

    //iterating through the elements and storing them in the max heap
    for(int i=0;i<n;i++)
    {

      //maintaing size of heap as k
      if(i<k)pq.push(arr[i]);
      else
      {
          if(pq.top()>arr[i])
          {
            pq.pop();
            pq.push(arr[i]);
          }
       }
    }
    return pq.top();
}

int main()
{
    cout<<"Enter the size of the array: ";
    int n,k;
    cin>>n;
    cout<<"Enter k: ";
    cin>>k;
    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"The Kth Smallest Element: "<<findkthsmallest(arr,n,k)<<endl;
    return 0;
}

/*
Sample Input:

Enter the size of the array: 8
Enter k: 4
Enter array elements: 7 8 9 5 7 2 4 10

Sample Output:
The Kth Smallest Element: 7

Time Complexity: O(nlogk)
Space Complexity: O(k)
*/
