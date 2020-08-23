#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long maxSum(const vector<int> &arr, size_t k)
{
  size_t n = arr.size();
  // If size of sub-arry k is greater than original array size n
  if (k >= n)
    return -1;
  // computing sum for window size of k from begining
  long long curr_sum = 0;
  for (size_t i = 0; i < k; i++)
    curr_sum += arr[i];
  // Computing sum of other windows of size k present in the array
  long long max_sum = curr_sum;
  for (size_t i = k; i < n; i++)
  {
    curr_sum += (arr[i] - arr[i - k]);
    max_sum = max(max_sum, curr_sum);
  }
  return max_sum;
}

int main()
{
  vector<int> arr = {100, 200, 300, 400};
  size_t k = 2;
  cout << maxSum(arr, k);
}