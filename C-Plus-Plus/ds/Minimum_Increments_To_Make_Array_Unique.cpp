

/* Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.
Return the least number of moves to make every value in A unique.

The idea is to sort the input -O(nlogn)- , then we move forward from the beginning of the array till the end.
As soon as we found a condition that the current element is less than or equal to the previous elements then we need to update the current array element.
here is an example of the given input.
A = [3,2,1,2,1,7]
Sorted A = [1,1,2,2,3,7]
After reaching the second 1 on the array since the condition is satisfied A[i]<=A[i-1] so we need to update the A[i] by A[i-1]+1.
At the same time we need to keep track of result by
result += A[i-1]+ 1 - A[i];

The rest of iterations are as following :

A = [1,2,2,2,3,7]
res= 1

A = [1,2,3,2,3,7]
res= 2

A = [1,2,3,4,3,7]
res= 4

A = [1,2,3,4,5,7]
res= 6
*/
#include <bits/stdc++.h>
using namespace std;

int minIncrementForUnique(vector<int> &A, int n)
{

    sort(A.begin(), A.end());
    int cnt = 0;

    for (int i = 1; i < n; i++)
    {
        if (A[i] - A[i - 1] < 1) //compare current element with previous
        {
            cnt += A[i - 1] + 1 - A[i];
            A[i] = A[i - 1] + 1; //update current element to A[i-1]+1
        }
    }

    return cnt;
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int x : arr)
        cin >> x;

    int ans = minIncrementForUnique(arr, n);

    cout << ans << endl;
    return 0;
}

/*
	Test Case1 : 
	Input : 3
	[1,2,2]

	Output : 1

    Test Case2 : 
	Input : 6
	[3,2,1,2,1,7]

	Output : 6
	    

	Time Complexity: O(nlog(n)) sorting takes nlogn
	Space Complexity: O(1)

*/