/*
Through this algorithm, we can find the maximum element in each of the k sized subarray.
The algorithm uses deque. Only the significant elements of the current window are stored in the deque in decreasing
order. The elements which are lesser than any of the elements of the deque and are to the left of that particular element
are insignificant. As the current window changes, significant values are updated.
*/

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
    max=dq.front(); 
    //maximum value for any subarray is stored at dq.front()
    cout<<arr[max]<<" ";
    //Traversing through the rest part of the array elements 
    for(int i=k;i<n;i++)
    {
        /*Checking whether on moving to the next window, dq.front() still remains the member of the current window or not.
          If not, then that element is removed from the current window*/
        if(i-k==max)
        dq.pop_front();
        //For the element at ith position, the previous smaller element is insignificant. Thus, remove it
        while(dq.empty()==false && arr[dq.back()]<=arr[i])
        dq.pop_back();
        //Adding new element to the current window
        dq.push_back(i);
        max=dq.front();
        cout<<arr[max]<<" ";
    }
    return;
}
//Driver Code
int main()
{   

    int n;
    cout<<"Enter size of the array\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array\n";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"Enter the value of k:\n";
    int k;
    cin>>k;
    cout<<"output:\n";
    func(arr,n,k);
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)

SAMPLE INPUT/OUTPUT:
Enter size of array
10
Enter the elements of the array
5 6 7 4 1 2 5 8 9 3
Enter value of k:
4
output:
7 7 7 5 8 9 9
*/ 
