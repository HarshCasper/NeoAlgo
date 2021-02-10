/*
You've heard of 0-1 knapsack.Below
is the problem statement for the same.
Given weights and values of n items,
put these items in a knapsack of capacity
cap to get the maximum total value in the
knapsack. In other words, given two integer
arrays val[0..n-1] and wt[0..n-1] which 
represent values and weights associated with
n items respectively. Also given an integer
cap which represents knapsack capacity, find
out the maximum value subset of val[] such 
that sum of the weights of this subset is 
smaller than or equal to cap. You cannot 
break an item, either pick the complete item, 
or don’t pick it (0-1 property).
There is a little twist for 0-N knapsack. You
can pick an element more than once. Now you 
have to find maximum value multi subset of val[]
such that sum of the weights of this subset is
smaller than or equal to cap.
Note: Maximum value subset means the sunset with
maximum sum of all the values in subset.
Sample Input
5 11
3 2 4 5 1
4 3 5 6 1
Sample Output
16
*/
#include<bits/stdc++.h>

using namespace std;

long long int dp[1000] = {
  0
};
long long int KnapSack_2(long long int Capacity_Knapsack,
  long long int Val[], long long int W[], long long int No_Of_Items) {
  for (long long int i = 0; i <= Capacity_Knapsack; i++) {
    for (long long int j = 0; j < No_Of_Items; j++) {
      if (Val[j] <= i) {
        dp[i] = max(dp[i], dp[i - Val[j]] + W[j]);
      }
    }
  }
  return dp[Capacity_Knapsack];
}

int main() {
  long long int No_Of_Items, Capacity_Knapsack, i, j;
  cin >> No_Of_Items >> Capacity_Knapsack;
  long long int Val[No_Of_Items];
  for (i = 0; i < No_Of_Items; i++)
    cin >> Val[i];
  long long int Wt[No_Of_Items];
  for (i = 0; i < No_Of_Items; i++)
    cin >> Wt[i];
  std::map < long long int, long long int > A;
  for (i = 0; i < No_Of_Items; i++) {
    map < long long int, long long int > ::iterator M = A.find(Val[i]);
    if (M != A.end()) {
      if (M -> second < Wt[i])
        M -> second = Wt[i];
    } else {
      A.insert(make_pair(Val[i], Wt[i]));
    }
  }
  long long int T = A.size();
  i = 0;
  cout << KnapSack_2(Capacity_Knapsack, Val, Wt, No_Of_Items);
  return 0;
}

/*
TimeComplexity=O(n*W)
Auxiliary Space=O(W)
n=No. of Items
W=Capacity of Knapsack
*/