/*This algorithm uses deque. Only the significant elements of the current window are stored in the deque in decreasing
order. The elements which are lesser than any of the elements of the deque and are to the left of that particular element
are insignificant. As the current window changes, significant values are updated. */

#include <bits/stdc++.h>
using namespace std;

//Function to find the maximum element in each subaaray of size k
void func(int arr[], int n, int k)
{
    deque<int> dq;
//Initially we store the significant values from the first k indices    
for(int i=0;i<k;i++)
    {
        while(dq.empty()==false && arr[dq.back()]<=arr[i])
        dq.pop_back();
        dq.push_back(i);
    }
    int max;
    max=dq.front(); //maximum value for any subarray is stored at dq.front()
    cout<<arr[max]<<" ";
    //Traversing through the rest pf the array elements 
    for(int i=k;i<n;i++)
    {
        /*Checking whether on moving to the next window, dq.front() still remains the member of the current window or not.
          If not, then that element is removed from the current window*/
        if(i-k==max)
        dq.pop_front();
        //For the element at ith position, the previous smaller element is insignificant. Thus, remove it
        while(dq.empty()==false && arr[dq.back()]<=arr[i])
        dq.pop_back();
        dq.push_back(i);//Adding new element to the current window
        max=dq.front();
        cout<<arr[max]<<" ";
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
    int k;
    cin>>k;
    func(arr,n,k);
    return 0;
}

/*Time Complexity: O(n)
  Space Complexity: O(n)
  Sample Input: 10
                5 6 7 4 1 2 5 8 9 3
                4
  Sample Output: 7 7 7 5 8 9 9 */ 
