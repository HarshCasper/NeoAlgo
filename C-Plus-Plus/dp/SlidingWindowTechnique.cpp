#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxSum(vector<int> arr, int k)
{
  int n = arr.size();
  // If size of sub-arry k is greater than original array size n
  if (k >= n)
    return -1;
  // computing sum for window size of k from begining
  int curr_sum = 0;
  for (int i = 0; i < k; i++)
    curr_sum += arr[i];
  // Computing sum of other windows of size k present in the array
  int max_sum = curr_sum;
  for (int i = k; i < n; i++)
  {
    curr_sum += (arr[i] - arr[i - k]);
    max_sum = max(max_sum, curr_sum);
  }
  return max_sum;
}