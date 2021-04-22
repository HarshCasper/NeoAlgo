/*
Approach : Swap pairs of elements except the first element.
As - keep a[0], swap a[1] with a[2], swap a[3] with a[4], and so on.
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
        if(i<n-1)
            swap(a[i],a[i+1]);
    }
    cout<<"\nZig-Zag array is : ";
    for(int i=0; i<n; i++)
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

Output:Zig-Zag array is : 4  7  3  6  8  1  2


Time Complexity : O(n)
Space Complexity : O(1)

*/
