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
  size_t n;
  cout << "Enter the size of array\n";
  cin >> n;
  vector<int> arr(n);

  cout << "Enter the Elemnets of Array\n";
  for (size_t i = 0; i < n; i++)
    cin >> arr[i];

  size_t k;
  cout << "Enter the size of Sub-Array\n";
  cin >> k;
  cout << "Outupt\n";
  cout << maxSum(arr, k);
  return 0;
}