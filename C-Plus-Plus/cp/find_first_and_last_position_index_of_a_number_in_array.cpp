/*
Given a sorted array of N elements and a value, find the first and last index position of the value number.
We can do this with the help of Binary Search.
*/

#include <bits/stdc++.h>
using namespace std;

int f_indx(int ar[], int N , int value)
{
    int low = 0;
    int high = N;
    while (low < high)
    {
        int mid =  low + (high - low) / 2;
        /* here if the mid contains value greater than or equal to our targeted value
        we set that position as high */
        if (value <= ar[mid])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int l_indx(int ar[], int N , int value)
{
    int low = 0;
    int high = N;
    while (low < high)
    {
        int mid =  low + (high - low) / 2;
         /* here if the mid contains value greater than or equal to our targeted value
        we set that position as low */
        if (value >= ar[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low - 1;
}

int main()
{
    cout << "Enter the size of the array : \n";
    int N;
    cin >> N;
    cout << "Enter the target value\n";
    int value;
    cin >> value;
    int ar[N + 1];
    cout << "Enter array elements :\n";
    for(int i = 0; i < N; i++)
    {
        cin >> ar[i];
    }
    int first_index = f_indx(ar, N , value);
    int last_index = l_indx(ar, N , value);
    cout << "First index position is : ";
    cout << first_index << endl;
    cout << "Last index position is : ";
    cout << last_index << endl;
}

/*
Standard Input and Output

Enter the size of the array :
10
Enter the target value
12
Enter array elements :
1 2 4 6 8 10 12 12 12 12
First index position is : 6
Last index position is : 9

Time Complexity : O(logN)
Space Complexity : O(1)

*/
