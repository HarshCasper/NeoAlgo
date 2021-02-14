/*Bead sort, also called as gravity sort, is a natural sorting algorithm since this algorithm was inspired from natural phenomenons
and was designed keeping in mind objects(or beads) falling under the influence of gravity.The bead sort operation can be compared
to the manner in which beads slide on parallel poles, such as on an abacus. However, each pole may have a distinct number of beads.*/

#include <bits/stdc++.h>            // Header file to include STL library
using namespace std;               //For cin and cout

int main()
{
    vector<int> nums;                           // initialize a vector of integers
    int a,n;                                    // Declaration of required variables
    cout<<"Enter the number of elements :";
    cin>>n;
    cout<<"Enter the elements to be sorted : ";
    for(int i=0;i<n;i++){                       //For loop for taking elements from the user, can be space-seperated as well
        cin>>a;
        nums.push_back(a);
    }

    nums.reserve(n);                        // reserve static vector for optimal performance gain

    cout << "\nBefore sorting" << endl;    // Print vector before sorting
    for(auto const& i: nums)
        cout<<i<<" ";
    cout<<"\n";

    auto max = *max_element(nums.begin(), nums.end());      // find maximum element in vector

    vector<unsigned char> beads(max * nums.size(), 0);       // declare beads vector for sorting

    for(auto i = 0; i < nums.size(); i++)                   // initialize the beads accordingly
        for(auto j = 0; j < nums[i]; j++)
            beads[i * max + j] = 1;

    for(auto j = 0; j < max; j++)                   // Use gravity to let beads fall
    {
        int sum = 0;
        for(auto i = 0; i < nums.size(); i++)       // assign beads for each post
        {
            sum += beads[i * max + j];
            beads[i * max + j] = 0;
        }

        for(auto i = nums.size() - sum; i < nums.size(); i++)   // Use gravity to bring beads down
            beads[i * max + j] = 1;
    }

    for(auto i = 0; i < nums.size(); i++)           // put sorted beads back into vector
    {
        for(auto j = 0; j < max && beads[i * max + j]; ++j)
            nums[i] = j+1;
    }

    cout << "After sorting" << endl;               //For loop for printing out the array after sorting
    for(auto const& i: nums)
        cout << i << " ";
    cout << endl;

    nums.shrink_to_fit();               // Free memory space of vector
}

/*
Input:
Enter the number of elements :5
Enter the elements to be sorted : 4 6 3 2 8

Before sorting
4 6 3 2 8

Output:
After sorting
2 3 4 6 8

Time Complexities:
Bead sort can be implemented with four general levels of complexity, among others:
O(1): The beads are all moved simultaneously in the same time unit, as would be the case with the simple physical example above.
This is an abstract complexity, and cannot be implemented in practice.
O(√N): In a realistic physical model that uses gravity, the time it takes to let the beads fall is proportional to the
square root of the maximum height, which is proportional to n.
O(n): The beads are moved one row at a time. This is the case used in the analog and digital hardware solutions.
O(S), where S is the sum of the integers in the input set: Each bead is moved individually. This is the case when
bead sort is implemented without a mechanism to assist in finding empty spaces below the beads, such as in software implementations.
*/

