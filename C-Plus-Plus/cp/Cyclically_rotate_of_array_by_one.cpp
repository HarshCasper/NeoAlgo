/*
Description : 
        Given an array and rotate it by one position in clock-wise direction.
*/

#include <iostream>
using namespace std;

//function is used to rotate the array
void rotate(int a[], int n)
{
    int x = a[n - 1];
    //starting the loop from backside of array
    for (int i = n - 1; i > 0; i--)
    {
        a[i] = a[i - 1];
    }
    //storing first element in x
    a[0] = x;
}

int main()
{
    int n;
    cout << "Enter the size of an array : " << endl;
    cin >> n;
    int a[n];
    cout << "Enter " << n << " number of elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Cyclically rotate of an array by one : " << endl;
    rotate(a, n);
    //printing array
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

/*
Time complexity : O(n)
Space complexity : O(n)
*/

/*
Test Case :
Test Case 1 :
   Input :
   Enter the size of an array : 
   4
   Enter  4 number of elements : 
   1
   2
   3
   4

   Output :
   Cyclically rotate of an array by one : 
   4 1 2 3
Test Case 2 :
   Input :
   Enter the size of an array : 
   8
   Enter 8 number of elements : 
   9 
   8 
   7
   6
   4 
   2 
   1 
   3

   Output :
   Cyclically rotate of an array by one : 
   3 9 8 7 6 4 2 1
*/

