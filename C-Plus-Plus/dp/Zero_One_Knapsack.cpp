#include <iostream>

using namespace std;
int n, k;
int * profit = NULL;
int * weight = NULL;
int ** table = NULL;
int max_profit = 0;
void input() {
  cin >> n;
  cin >> k;
  profit = new int[n];
  weight = new int[n];
  for (int i = 1; i <= n; i++) {
    cin >> profit[i];
    cin >> weight[i];
  }
  table = new int * [k + 1];
  for (int i = 0; i <= n; ++i)
    table[i] = new int[k + 1];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++)
      table[i][j] = -1;
  }
}

//finding maximum profit in iterative way
void knapsack() {
  for (int j = 0; j <= k; j++)
    table[0][j] = 0;
  for (int i = 0; i <= n; i++)
    table[i][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j < weight[i]) //when size of knapsack is less than weight of item i
        table[i][j] = table[i - 1][j];
      else
        table[i][j] = max(table[i - 1][j], table[i - 1][j - weight[i]] + profit[i]);
    }
  }
  max_profit = table[n][k];
}

void display() {
  cout << "Number of items: " << n;
  cout << endl << "knapsack Size: " << k;
  for (int i = 1; i <= n; i++)
    cout << endl << "Item " << i << " (Prifit,Weight) is: (" << profit[i] << "," << weight[i] << ")";
  cout << endl << "Max Profit in the knapsack is: " << max_profit;
}
int main() {
  // your code goes here
  input();
  knapsack();
  display();
  return 0;
}

/*
Input:
3
50
60 10
100 20
120 30

output:
Number of items: 3
knapsack Size: 50
Item 1 (Profit,Weight) is: (60,10)
Item 2 (Profit,Weight) is: (100,20)
Item 3 (Profit,Weight) is: (120,30)
Max Profit in the knapsack is: 220

Complexity:
Time: O(n*k)
Space: O(n*k)
*/