/*
Problem Statement:
 Given a stack, sort the given stack using recursion such that the greatest element is on the top. 
*/

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

void printStack(stack<int> st)
{
  while (!st.empty())
  {
    int x = st.top();
    st.pop();

    cout << x << " ";
  }

  return;
}

void insert(stack<int> &st, int temp)
{
  // base condition
  if (st.size() == 0 || st.top() < temp)
  {
    st.push(temp);
    return;
  }

  int val = st.top();
  st.pop();

  insert(st, temp);
  st.push(val);

  return;
}

void sortStack(stack<int> &st)
{

  // base condition
  if (st.size() == 0)
    return;

  int temp = st.top();
  st.pop();

  // recursion
  sortStack(st);

  // function to insert element in stack
  insert(st, temp);

  return;
}

int main()
{
  // input number of element in stack
  int n;
  cin >> n;

  stack<int> st;

  // input stack elements
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;

    st.push(x);
  }

  // function to sort stack
  sortStack(st);

  // function to print stack element
  printStack(st);

  cout << endl;

  return 0;
}

/*
  Time Complexity: O(N*N)
  Space complexity: O(N)

*/

/*
   Test Case:

  Input:  10 
          9 2 5 6 0 1 7 3 4 8
  OutPut: 9 8 7 6 5 4 3 2 1 0

  Input: 5
         11 2 32 3 41
  Output: 41 32 11 3 2              

*/
