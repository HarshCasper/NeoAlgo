/*Code to find the first index in which 1 appears in an array of 0 and 1
APPROACH USED -Binary Search
*/
#include<bits/stdc++.h>
using namespace std;
int binSearch(int a[],int n)
{
    int l=0,r=n-1,mid=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]==1 && (mid==0 || a[mid-1]==0))
        return mid+1;
        else if(a[mid]==1)
        r=mid-1;
        else l=mid+1;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter only 1 and 0 in sorted order\n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    cout<<binSearch(a,n);
}
/*
TIME COMPLEXITY: O(nlogn)
INPUT:
5
Enter only 1 and 0 in sorted order
1 1 1 1 1
OUTPUT:1

INPUT:
5
Enter only 1 and 0 in sorted order
0 0 0 0 0
OUTPUT:-1
*/
