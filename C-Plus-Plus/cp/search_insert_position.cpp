/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.
*/
#include <iostream>
using namespace std;

int search_insert_position(int arr[], int n, int target){
    int l=0,r=n-1;
    int mid;
    while(l<=r){
        mid = (l+r)/2;
        if(target > arr[mid])
            l = mid+1;
        else if(target < arr[mid])
            r = mid-1;
        else
            return mid;
    }
    return l;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int target;
    cin>>target;
    int ans = search_insert_position(arr,n,target);
    cout<<ans;
    return 0;
}


/*
OUTPUT :- 
5
2 3 4 5 6
4
2
*/
