/** An array element is a peak if it is NOT smaller than
its neighbours. For corner elements, we need to
consider only one neighbour.
Since an array always have a maximum value therefore an peak element always be there.
Eg. :
Input: array[] = {10, 20, 15, 2, 23, 90, 67}
Output: 20 or 90
The element 20 has neighbours 10 and 15, both of
them are less than 20, similarly 90 has neighbours 23
and 67.
A divide-and-conquer algorithm recursively breaks
down a problem into two or more sub-problems of
the same or related type, until these become simple
enough to be solved directly. The solutions to the
sub-problems are then combined to give a solution to
the original problem. **/

#include <bits/stdc++.h>
using namespace std;

// recursive approach
//  Complexity : O(log(N)
int findPeek(vector<int>v,int l,int r)
{
    if(l<r)
    {
        int mid = l+(r-l)/2;
        if(mid == 0 || mid+1 == v.size()) // means we are at corner
        {
            if(mid==0)
            {
                if(v[0] >= v[1])
                return v[0];
                else
                return v[1];
            }
            else{
                if(v[mid] >= v[mid-1])
                return v[mid];
                else
                return v[mid-1];
            }
        }
        
        else if(v[mid]>=v[mid-1] && v[mid]>=v[mid+1])
        return v[mid];
        
        else if(v[mid]<v[mid+1])
        return findPeek(v,mid+1,r);
        
        else 
        return findPeek(v,l,r-1);
    }
    return -1;
}

// using while loop approach
//  Complexity : O(log(N)
int findPeek(vector<int>arr)
{
    
    int start=0,n=arr.size();
    int end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(mid-1>=0&&mid+1<n)
        {
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
            {
                return arr[mid];
            }
            else if(arr[mid]<arr[mid-1])
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        else if(mid==0)
        {
            if(arr[0]>arr[1])
            {
                return arr[0];
            }
            else
            {
                return arr[1];
            }
        }
        else if(mid==n-1)
        {
            if(arr[n-1]>arr[n-2])
            {
                return arr[n-1];
            }
            else
            {
                return arr[n-2];
            }
        }
    }
    return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	cin>>v[i];
	int i = findPeek(v,0,n-1);
	cout << i <<"\n";
	return 0;
}

/** ILLUSTRATION
Input : a[] = { 10, 20, 15, 2, 23, 90, 6 }
       //index = 0   1   2  3   4  5   6 
findPeak(a,0,6)
if 0<6
mid = 3 //a[mid] = a[3] = 2
if 2≥ 15 : false
if a[mid] < a[mid+1] , 2<23 : true
return findPeak(a,4,6)
findPeak(a,4,6)
if 4<6
mid = 5 // a[5] = 90
if 90 ≥ 6 && 90 ≥ 23 : true
return a[5], i.e., 90
∴ Output = 90 ; 

Approach 2 :
// a = { 10, 20, 15, 2, 23, 90, 6 }
// index =0  1   2   3   4   5  6
findPeak (a)
start = 0
n = a.size() = 7
end = n-1 = 6
while start < end
0 < 6 : true
mid = 3
if 3>0 && 4 < 7 : true
if a[3] ≥ a[2] && a[3] ≥ a[4] : false
if a[3] < a[4] ( 2<23) : true
start = mid+1 = 4
4 < 6 : true
mid = 5
if 5>0 && 6<7 : true
if a[5] ≥ a[4] && a[5] ≥ a[6] ( 90>23 ,
90>6 ) : true
return a[5] i.e., 90
∴ Output = 90 ;**/