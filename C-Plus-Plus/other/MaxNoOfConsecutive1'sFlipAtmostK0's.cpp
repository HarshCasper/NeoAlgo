/* 
Given a binary array i.e consisting of only 0's and 1's and an integer k.
We need to return the maximum number of consecutive 1's in the array if we can flip at most k 0's.

Approach : Need to handle 3 cases for every element in the array

Case 1: value is 1, increment count
Case 2: value is 0 and K is non zero, decrement K and increment count
Case 3: value is 0 and K is also zero, need to acquire this zero and 
        release the first zero from left to right, achieved using min heap

Maintain a max_count at each step.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int MaxConsecutiveOnes(int arr[], int n, int k)
{
    int curr_count = 0;
    int max_count = 0;
    int originalK = k;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        { //case 1
            curr_count++;
        }
        /* Handles the test case when we are not allowed to flip 0, 
            set current count=0 as this point act as the breaking point of consecutive sequence  */
        else if (arr[i] == 0 && originalK == 0)
        {
            curr_count = 0;
        }
        else if (arr[i] == 0 && originalK > 0)
        {
            /* Till we are allowed to flip 0's add them in current count and decrease k .
                A min heap is maintained containing indices of all k zeroes so that we can pop
                the zero with minimum index whenever k reduces to 0. (case 2) */
            if (k != 0)
            {
                k--;
                curr_count++;
                pq.push(i);
            }
            /* This is case 3 , need to acquire this zero to continue the sequence. Pop the index of zero 
                that appeared first in the array from left to right and push the current index in the 
                priority queue. */
            else
            {
                int v = pq.top();
                pq.pop();
                pq.push(i);
                curr_count = i - v;
            }
        }
        max_count = max(max_count, curr_count);
    }
    return max_count;
}
int main()
{
    int size, k;
    cout << "Enter size of array: ";
    cin >> size;
    int arr[size];
    cout << "\nEnter elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "\nEnter value of k: ";
    cin >> k;
    int ans = MaxConsecutiveOnes(arr, size, k);
    cout << "\nMaximum number of consecutive 1's by flipping atmost k 0's are: " << ans;
    return 0;
}

/*
Sample input 1:
Enter size of array: 19
Enter elements of array: 0 0 1 1 0 0 1 1 1 0 1 1 0 0 0 1 1 1 1
Enter value of k: 3

Output 1:
Maximum number of consecutive 1's by flipping atmost k 0's are: 10

Sample input 2:
Enter size of array: 11
Enter elements of array: 1 1 1 0 0 0 1 1 1 1 0
Enter value of k: 2

Output 2:
Maximum number of consecutive 1's by flipping atmost k 0's are: 6

Time complexity: O(nlogk)   logk is the time taken to push and pop from min heap
Space complexity: O(k)   
*/
