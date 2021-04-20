/*
Approach :
First sort the array then, swap pairs of elements
except the first element.
Example - keep a[0], swap a[1] with a[2], swap a[3] with a[4], and so on.
*/

#include <bits/stdc++.h>
using namespace std;

void zigzag(int a[] , int n)
{
    for(int i=1 ; i<n ; i+=2)
    {
        if(i+1 < n)
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
	TTime Complexity : O(n log n); because we are using sorting.

	Sample Input - Output:
	----------------------
	Input --> 4,3,7,8,6,2,1
	Output:	Original array is : 1  2  3  4  6  7  8
			Zig-Zag array is : 1  3  2  6  4  8  7

*/
