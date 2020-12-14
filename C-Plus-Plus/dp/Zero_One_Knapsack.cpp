#include <iostream>
using namespace std;
int n,k;
int *profit=NULL;
int *weight=NULL;
int **table=NULL;
int max_profit=0;

void input()			//Taking input
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
	if(k==0||n==0)			//When knapsack size and number of items are 0
	{			
		return 0;
	}	
			
	else if(weight[n]>k)	//When Knapsack size is greater than weight of nth item
	{   
		return knapsack(n-1,k);
    }
    else					//Max profit among n-1 item and n items
	{	int temp1 = knapsack(n-1,k);
		int temp2 = knapsack(n-1,k-weight[n])+profit[n];
		return max(temp2,temp1);
    }
}
void display()
{
    cout<<"Number of items: "<<n;
    cout<<endl<<"knapsack Size: "<<k;
    for(int i=1; i<=n; i++)
    	cout<<endl<<"Item "<<i<<" (Profit,Weight) is: ("<<profit[i]<<","<<weight[i]<<")";
	cout<<endl<<"Max Profit in the knapsack is: "<<max_profit;
}
int main() {
	// your code goes here
	input();				//Take the inputs
	max_profit=knapsack(n,k);		//find Maximum profit
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

*/