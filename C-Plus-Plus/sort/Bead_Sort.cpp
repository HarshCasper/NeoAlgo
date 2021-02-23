/* Bead sort, also called as gravity sort, is a natural sorting algorithm since this algorithm was inspired
from natural phenomenons and was designed keeping in mind objects(or beads) falling under the influence of gravity.
The bead sort operation can be compared to the manner in which beads slide on parallel poles, such as on an abacus.
However, each pole may have a distinct number of beads. */

// Header file to include STL library
#include <bits/stdc++.h>
//For cin and cout
using namespace std;

void beadSort(vector<int>& nums)
{
    // find maximum element in vector
    auto max = *max_element(nums.begin(), nums.end());

    // declare beads vector for sorting
    vector<unsigned char> beads(max * nums.size(), 0);

    // initialize the beads accordingly
    for(auto i = 0; i < nums.size(); i++)
        for(auto j = 0; j < nums[i]; j++)
            beads[i * max + j] = 1;

    // Use gravity to let beads fall
    for(auto j = 0; j < max; j++)
    {
        int sum = 0;
        // assign beads for each post
        for(auto i = 0; i < nums.size(); i++)
        {
            sum += beads[i * max + j];
            beads[i * max + j] = 0;
        }
        // Use gravity to bring beads down
        for(auto i = nums.size() - sum; i < nums.size(); i++)
            beads[i * max + j] = 1;
    }
    // put sorted beads back into vector
    for(auto i = 0; i < nums.size(); i++)
    {
        for(auto j = 0; j < max && beads[i * max + j]; ++j)
            nums[i] = j+1;
    }

}

int main()
{
    // initialize a vector of integers
    vector<int> nums;
    // Declaration of required variables
    int a,n;
    cout<<"Enter the number of elements :";
    cin>>n;
    cout<<"Enter the elements to be sorted : ";
    //For loop for taking elements from the user, can be space-separated as well
    for(int i=0;i<n;i++){
        cin>>a;
        nums.push_back(a);
    }

    // reserve static vector for optimal performance gain
    nums.reserve(n);

    // Print vector before sorting
    cout << "\nBefore sorting" << endl;
    for(auto const& i: nums)
        cout<<i<<" ";
    cout<<"\n";

    beadSort(nums);

    //For loop for printing out the array after sorting
    cout << "After sorting" << endl;
    for(auto const& i: nums)
        cout << i << " ";
    cout << endl;

    // Free memory space of vector
    nums.shrink_to_fit();
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
O(n): in best case
O(S): in worst case, where S is the sum of all beads

*/
