/*
Rearranging an array in maximum minimum form

For a given sorted array arr[] of N positive integers,
your task is to rearrange the array such that
the first element should be the maximum value, 
second element should be minimum value,
third one second maximum, fourth second minimum,
and so on.
It is given that task should be perfrmed in O(1) extra space.
*/

#include <bits/stdc++.h>

using namespace std;

//function to make the vlaue at first position
//maximum, that of second element minimum
//vlaue, at third place second maximum, at fourth 
//second minimum, and so on
void rearrangeAltMaxMin(int arr[], int size)
{
    //we first initialize the indexs for first minimum element
    // and first maximum element
    int maxIndx = size - 1;
    int minIndx = 0;

    //storing maximum element of array
    int maxVal = arr[size - 1] + 1;
    
    for(int pass = 0; pass < size; pass++)
    {
        //putting maximum elements at even positions
        //i.e. 0, 2, 4, ..
        if(pass % 2 == 0)
        {
            //we use over here the multiplication and modular trick
            //which stores two elements at index arr[pass]
            arr[pass] += (arr[maxIndx] % maxVal) * maxVal;
            //decrementing value of maximum element
            maxIndx--;
        }
        //otherwise at odd positions 
        //we put the minimum elements
        else
        {
            arr[pass] += (arr[minIndx] % maxVal) * maxVal;
            //incrementing value of minimum element
            minIndx++;
        }
    }

    //arranging the array elements
    for(int pass = 0; pass < size; pass++)
    {
        arr[pass] = arr[pass] / maxVal;
    }
}

//driver code
int main()
{
    //taking input
    int size; 
    cout << "Enter the size of array: ";
    cin >> size;
    cout << endl;
    int arr[size];
    cout << "Enter the elements of array: ";
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
     
    //for output
    rearrangeAltMaxMin(arr, size);
    cout << "The rearranged array is : ";
    cout << endl;
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

/*
EXAMPLE :-
Input--
Enter the size of array: 6
Enter the elements of array: 1, 3, 5, 8, 20, 36
Output--
The rearranged array is : 
36, 1, 20, 3, 8, 5

TIME COMPLEXITY --> O(N), Where N is the size of array
SPACE COMPLEXITY --> O(1)
*/
