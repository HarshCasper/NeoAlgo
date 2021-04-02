/* Sorting an array of 0's and 1's

Given an array of size n which contains only 0's and 1's in any order,we have to modify the array in such a way that 0's are on left side and 1's on the right side.
Test case-1:
Input-1:
N = 5
arr[] = {0, 0, 1, 1, 0}
Output-1: 0 0 0 1 1

*/
//CODE
#include <iostream>
using namespace std;
//Function to sort an array of 0's and 1's
void sort()
{
	//Input n= Size of array
    int n;
    cin >> n;
    int a[n];
    //Input elements in array
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    /*  Two counters to count number of 0's and 1's respectively
	    which are initialized to 0*/
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++)
    {
    	//checking whether the array element is equal to 0
        if (a[i] == 0)
        {
            c0++;
            continue;
        }

        c1++;
    }
    while (c0--)
    {
        cout << 0 << " "; //printing 0 for c0 times
    }
    while (c1--)
    {
        cout << 1 << " "; //printing 1 for c1 times
    }
    cout << endl;
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    //Input T= Number of test case
    int T;
    cin >> T;
    while (T--)
        sort(); //function will be called for the number of test cases
    return 0;
}
/*
Test case-1:
Input:
N = 4
Arr[] = {0, 0, 0, 0}
Output: 0 0 0 0
There are no 1's in the given array,
so the modified array is 0 0 0 0.

Test case-2:
Input:
N==6
arr[]={0,1,1,0,1,0}
Output:0 0 0 1 1 1
*/
