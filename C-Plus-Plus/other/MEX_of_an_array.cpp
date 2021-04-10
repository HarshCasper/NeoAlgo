/*
Given an array of N elements.
Find MEX ( Minimum Excluded Element ) of input array.

Mex of an array is the minimum positive integer that doesn't appear in this array.
For example, MEX of the array containing 1, 3 and 4 is equal to 2.
*/

#include <bits/stdc++.h>
using namespace std;

// this get_MEX_of_array function will give us MEX of input array
int get_MEX_of_array(int ar[],int N)
{
    /* will insert array's elements into the set
    as set contain unique values in ascending order
    */
    set < int > mex_find;
    for(int i = 0; i < N; i++)
    {
       mex_find.insert(ar[i]);

    }
    // set MEX as 1
    int MEX = 1;
    for(auto i : mex_find)
    {
        /* if current element of Set is equal to MEX
        we will increment MEX by 1
        and if current element of Set is greater to MEX
        means we have got our MEX.
        */
        if(i == MEX)
        {
            MEX++;
        }
        else if(i > MEX)
        {
            //we have got our MEX
            break;
        }
    }
    return MEX;
}

int main()
{
    cout << "Enter the size of the array : \n";
    int N;
    cin >> N;
    int ar[N + 1];
    cout << "Enter array elements :\n";
    for (int i = 0; i < N; i++)
    {
	    cin >> ar[i];
    }
    int MEX_of_array = get_MEX_of_array(ar , N);
    cout << "MEX of the Array is : \n";
    cout << MEX_of_array << endl;

}
/*
Standard Input and Output

Enter the size of the array :
8
Enter array elements :
8 2 7 4 6 2 1 4

MEX of the Array is :
3

Time Complexity : O( logN )
Space Complexity : O(N)

*/
