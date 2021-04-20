/*
Approach :
Swap pairs of elements except the first element.
As - keep a[0], swap a[1] with a[2], swap a[3] with a[4], and so on.
*/

#include <bits/stdc++.h>
using namespace std;

void zigzag(int a[] , int n)
{
    for(int i=1 ; i<n ; i+=2)
    {
        if(i < n-1)
            swap(a[i] , a[i+1]);
    }

    cout<<"\nZig-Zag array is : ";
    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";
}

//Driver Program
int main()
{
    int a[] = {4,3,7,8,6,2,1};
    int n = sizeof(a)/sizeof(a[0]);
    sort(a , a+n);

    cout<<"Original array is : ";
    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<"  ";

    zigzag(a , n);

    return 0;
}

/*
	Time Complexity : O(n)

    Sample Input-Output :
    ---------------------
    Input --> 4,3,7,8,6,2,1
    Output: Original array  : 4  3  7  8  6  2  1
            Zig - Zag array : 4  7  3  6  8  1  2

    NOTE : If we want a sorted data we can first sort the array
    using sort() and then call the zigzag() function.
*/
