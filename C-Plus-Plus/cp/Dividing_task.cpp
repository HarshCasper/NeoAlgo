/*
The Problem states that Given array arr[n] of integer where each element arr[i] represent number of task given to each student.Your task is to find if it possible to redistribute the task where i'th student assign i number of task. Example is it possible to assign 2 task to 2nd Student. 
*/
#include <bits/stdc++.h>
using namespace std;
void solve(int arr[], int n)
{
  int sum_of_task = 0, sum_of_i = 0;
  for (int i = 1; i <= n; i++)
  {
    sum_of_task = sum_of_task + arr[i];
    sum_of_i += i;
  }
  if (sum_of_i == sum_of_task)
    cout << "Yes It is possible\n";
  else
    cout << "No It is not Possible\n";
}
int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
  }
  solve(arr, n);
}
/*
Test Case
input:
5
7 4 1 1 2
output:
Yes It is possible
*/
