/*Bead sort, also called as gravity sort, is a natural sorting algorithm since this algorithm was inspired from natural phenomenons
and was designed keeping in mind objects(or beads) falling under the influence of gravity.The bead sort operation can be compared
to the manner in which beads slide on parallel poles, such as on an abacus. However, each pole may have a distinct number of beads.*/
#include <bits/stdc++.h>        // Header file to include STL library
using namespace std;            //For cin and cout

#define BEAD(i, j) beads[i * max + j]    //macro definition with parameters for BEAD

int main()
{
    int len;                    //Declarartion of length of array
    cout<<"Enter the number of elements of the array: ";
    cin>>len;                   //Getting the number of elements of the array from the user
    int arr[len];               //Declarartion of array with size len
    cout<<"Enter the elements of the array to be sorted: " <<"\n";
    for (int i = 0; i < len; i++){
    cin>>arr[i];               //For loop for taking elements of the array from the user, can be space-seperated as well
    }
    int max = arr[0];
    for (int i = 1; i < len; i++){
        if (arr[i] > max)       // Find the maximum element
           max = arr[i];
    }
    unsigned char beads[max*len];           // allocating memory
    memset(beads, 0, sizeof(beads));
    for (int i = 0; i < len; i++)           // mark the beads
        for (int j = 0; j < arr[i]; j++)
            BEAD(i, j) = 1;
    for (int j = 0; j < max; j++)
    {
        int sum = 0;                // count how many beads are on each post
        for (int i=0; i < len; i++)
        {
            sum += BEAD(i, j);
            BEAD(i, j) = 0;
        }
        for (int i = len - sum; i < len; i++)    // Move beads down
            BEAD(i, j) = 1;
    }
    for (int i = 0; i < len; i++)           // Put sorted values in array using beads
    {
        int j;
        for (j = 0; j < max && BEAD(i, j); j++);

        arr[i] = j;
    }
    cout<<"Array after sorting is : ";
    for (int i = 0; i < len; i++)           //For loop for printing out the array after sorting
        cout<<arr[i]<<" ";

    return 0;
}
/*
Input:
Enter the number of elements of the array: 5
Enter the elements of the array to be sorted:
4 6 3 2 8

Output:
Array after sorting is: 2 3 4 6 8

Time Complexities:
Bead sort can be implemented with four general levels of complexity, among others:
O(1): The beads are all moved simultaneously in the same time unit, as would be the case with the simple physical example above.
This is an abstract complexity, and cannot be implemented in practice.
O(√N): In a realistic physical model that uses gravity, the time it takes to let the beads fall is proportional to the
square root of the maximum height, which is proportional to n.
O(n): The beads are moved one row at a time. This is the case used in the analog and digital hardware solutions.
O(S), where S is the sum of the integers in the input set: Each bead is moved individually. This is the case when
bead sort is implemented without a mechanism to assist in finding empty spaces below the beads, such as in software implementations.*/
