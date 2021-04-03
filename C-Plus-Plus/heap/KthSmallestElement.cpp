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
  Test Case 1:
                n=8
                arr[]=7,8,9,5,7,2,4,10
                k=4
                Kth Smallest Element: 7
*/

/*
Test Case 2:
              n=10
              arr[]=120,110,115,130,46,15,23,48,69,75
              k=10
              Kth Smallest Element: 130
*/

/*
    Time Complexity: O(nlogk)     {as the max heap is of size k}
    Space Complexity: O(k)
*/
