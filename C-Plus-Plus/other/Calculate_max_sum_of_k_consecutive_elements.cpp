/*
Given an array of N elements and a value K (K <= N) , calculate maximum summation of K consecutive elements in the array.
We can solve this problem by using Sliding Window Technique. This technique will allow us to solve this problem in O(N)
*/

#include <bits/stdc++.h>
using namespace std;
int ar[100009];

int max_sum_by_sliding_window(int ar[] , int N , int K)
{
    int sum = 0;
    if(N == K)
    {
        // max_sum will be the sum of all elements of array.
        for(int i = 0; i < N; i++)
            sum += ar[i];
        return sum;
    }
    if(N > K)
    {
        // calculate sum of first window of size K
        int max_sum = 0, win_sum = 0;
        for(int i = 0; i < K; i++)
            max_sum += ar[i];

        /*calculate sum of remaining windows
         by removing elements from first window simultaneously add elements to current window */
        win_sum = max_sum;
        for(int i = K; i < N; i++)
        {
            win_sum += (ar[i] - ar[i - K]);
            if(win_sum > max_sum)
            {
                max_sum = win_sum;
            }
        }
        return max_sum;
      }
}

int main()
{
	int N, K;
	cout << "Input array size and value\n";
	cin >> N >> K;
	for(int i = 0; i < N; i++)
    {
        cin >> ar[i];
    }
    int solve = max_sum_by_sliding_window(ar, N , K);
    cout << "maximum summation of K consecutive elements in the array is " << solve << endl;

}
/*

Standard Input and Output
1. if N == K
Input array size and value
5 5
1 2 3 4 5
maximum summation of K consecutive elements in the array is 15
2. if N > K
Input array size and value
5 3
5 2 -1 0 3
maximum summation of K consecutive elements in the array is 6
Time Complexity : O(N)
Space Complexity : O(1)

*/
