/*
Given an array of integers where each element represents the maximum number of steps
that can be made forward from that element.We need to find the minimum number of jumps 
to reach the end of the array (starting from the first element).
If an element is 0, then we cannot move through that element.

Approach:
-------- Stair and Ladder approach-------
1. At every index, collect a ladder, size of that ladder will be value of element at that index.
Stairs are number of stairs on ladder.

2. After collecting a ladder, keep it if it is large enough ,and throw if it is small.

3. Keep climbing the current ladder if current ladder gets over use the ladder which we have stored 
   in step 2 and increase the count, since we have made a jump to another ladder.
*/
#include <iostream>
using namespace std;

int min_jumps(int arr[], int n)
{
    /* already at end of array ,no need to jump */
    if (n == 1)
    {
        return 0;
    }
   /* if arr[0] is 0 then we can't jump */
    if (arr[0] == 0)
    {
        return -1;
    }
   /* ladder keeps track of largest ladder we have and stairs keep track of stairs
       in the current ladder, initially jump count is 1 as we have to take a ladder
       to start. */
    int ladder = arr[0];
    int stairs = arr[0];
    int jumps_count = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
        { // Reached end of array
            return jumps_count;
        }

        if (i + arr[i] > ladder)
        { /* building up the ladder,i is added to arr[i] as we need to take forward jumps 
           starting from current index ,also we have already traversed till ith index. */
            ladder = i + arr[i];
        }
        //climbing the stairs, hance they are reducing by 1
        stairs--;
        if (stairs == 0)
        { /* When no stairs are left on current ladder,increase the count and jump to our stored ladder.
             new set of stairs will now be ladder-i */
            jumps_count++;
            stairs = ladder - i;
            if (stairs == 0)
            {
                return -1;
            }
        }
    }
    return -1;
}
int main()
{
    int N;
    cout << "Enter size of array: ";
    cin >> N;
    int arr[N];
    cout << "\nEnter elements of array: ";
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    int no_of_jumps = min_jumps(arr, N);
    if (no_of_jumps == -1)
    {
        cout << "Can't reach end of array!!\n";
    }
    else
    {
        cout << "Minimum no. of jumps required to reach end of array: " << no_of_jumps;
    }
}
/*
Sample input 1:
Enter size of array: 5
Enter elements of array: 2 3 1 1 4                  

output 1:
Minimum no. of jumps required to reach end of array: 2

Sample input 2:
Enter size of array: 5
Enter elements of array: 2 2 1 0 4

output 2:
Can't reach end of array!!

Time complexity: O(n)
Space complexity: O(1)
*/
