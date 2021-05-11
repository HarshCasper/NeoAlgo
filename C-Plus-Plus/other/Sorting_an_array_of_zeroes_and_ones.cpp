/* Sorting an array of 0's and 1's

Given an array of size n which contains only 0's and 1's
in any order,we have to modify the array in such a way
that 0's are on left side and 1's on the right side.

*/

#include <bits/stdc++.h>
using namespace std;
//Function to sort an array of 0's and 1's
void sort()
{
    int size_of_array;
    cout<<"Enter size of array: ";
    cin >> size_of_array;
    int array[size_of_array];
    cout<<"Enter array elements: ";
    for (int i = 0; i < size_of_array; i++)
    {
        cin >> array[i];
    }
    /*  Two counters to count number of 0's and 1's respectively
	    which are initialized to 0*/
    int counter_for_0 = 0, counter_for_1 = 0;
    for (int i = 0; i < size_of_array; i++)
    {
        if (array[i] == 0)
        {
	    counter_for_0++;
            continue;
        }
        counter_for_1++;
    }
    cout<<"Sorted array of 0's and 1's is: ";
    while (counter_for_0--)
    {
	cout << 0 << " "; 
    }
    while (counter_for_1--)
    {
        cout << 1 << " "; 
    }
    cout << endl;
}

int main()
{
    sort(); 
    return 0;
}
/*
Input:
Enter size of array: 6
Enter array elements: 0 1 0 1
Output:
Sorted array of 0's and 1's is: 0 0 1 1

Space Complexity-O(N)
Time Complexity-0(1)
*/
