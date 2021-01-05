/*Given weights and Profit of n items, put these items in a knapsack of capacity W to get the maximum total Profit in the knapsack. 
In other words, given two integer arrays profit[0..n-1] and weight[0..n-1] which represent Profit and weights associated with n items 
respectively. Also given an integer W which represents knapsack capacity, find out the maximum Profit subset of val[] such that 
sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
*/

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

//Taking input
void input()			
{
	cin>>n;
	cin>>k;
	profit=new int[n];
	weight=new int[n];
	for(int i=1; i<=n; i++)
    {   
		cin>>profit[i];
		cin>>weight[i];		
	}
 }
int knapsack(int n,int k)
{
	//When knapsack size and number of items are 0
	if(k==0||n==0)			
	{			
		return 0;
	}	
	//When Knapsack size is greater than weight of nth item		
	else if(weight[n]>k)	
	{   
		return knapsack(n-1,k);
    }
	//Max profit among n-1 item and n items
  else					
	{	int temp1 = knapsack(n-1,k);
		int temp2 = knapsack(n-1,k-weight[n])+profit[n];
		return max(temp2,temp1);
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
int main() 
{
	//Take the inputs
	input();
	//find Maximum profit	
	max_profit=knapsack(n,k);		
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