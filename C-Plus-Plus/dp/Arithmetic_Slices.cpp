/*
An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.
*/

#include<iostream>
#include<vector>

using namespace std;

//Function takes array and the size of the array as an input, it returns the number of arthemetic slices present in the input array//
int numberOfArithmeticSlices(int A[],int size) {
    if(size<3) return 0;
    vector<int> res (size,0);
    
    /*Since as per the problem minimum size of the arthemetic slice can be 3, we start the loop from the 2nd element and check the previous elements.
    We basically check for a continuous AP if the sequence continues, we change the res[i] value to res[1-1] + 1, if the AP breaks at any point we simply leave that index value at 0.
    Thus restarting the sequence when another continuous AP is found.*/
    for(int i = 2;i<size;i++)
    {
        if(A[i]-A[i-1] == A[i-1]-A[i-2])
        {
            if(res[i-1]>0)
            {
                res[i] = res[i-1]+1;
            }
            else
            {
            res[i]++;
            }
        }
    }
    int ans = 0;
    
    /* Adding the values at all the indices we get the total number of arthemetic slices. */
    for(int i = 0;i<res.size();i++)
    {
        ans = ans+res[i];
    }
    return ans;
}


int main(){

    int size = 0;
    
    cout<<"Enter the size of the array- "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter the values inside the array"<<endl;
    for(int i = 0; i<size ; i++)
    {
        int temp = 0;
        cin >> temp;
        arr[i] = temp;
    }

    cout<<"Number of Arithmetic Slices in the array is- "<<numberOfArithmeticSlices(arr,size)<<endl;
    
    return 0;
}

/*

Time Complexity: O(N)
Space Complexity: O(N)

I/O Example 1:
    Input: nums = [1,2,3,4]
    Output: 3
    Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

I/O Example 2:
    Input: nums = [1]
    Output: 0

*/
