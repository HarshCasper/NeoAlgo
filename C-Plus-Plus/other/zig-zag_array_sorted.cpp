/*
Approach :First sort the array then, swap pairs of elements
except the first element. Example - keep a[0], swap a[1] with a[2], swap a[3] with a[4], and so on.
So, we will take array and its size as parameters, run a loop from i to size of the array 
and swap every pair of element using swap function. At the end of loop, we will print the array.
*/
#include <bits/stdc++.h>
using namespace std;
/*helper function that converts given array in zig-zag form*/
void zigzag(int a[] , int n)
{
    for(int i=1; i<n; i+=2)
    {
        if(i+1<n)
            swap(a[i],a[i+1]);
    }
    cout<<"\nZig-Zag array is : ";
    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";
}
/*Driver Program*/
int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int a[n];
    cout<<"Enter array : "<<endl;
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    zigzag(a,n);
    return 0;
}

/*

Sample Input/Output:

Input: Enter size of array : 7
       Enter array :
       4
       3
       7
       8
       6
       2
       1

Output:Zig-Zag array is : 1  3  2  6  4  8  7

Time Complexity : O(n log n); because we are using sorting.
Space Complexity : O(1)

*/

