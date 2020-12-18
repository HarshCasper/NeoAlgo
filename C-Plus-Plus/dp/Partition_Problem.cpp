//Partition problem
#include <bits/stdc++.h> 
using namespace std;

int size,sum;
int *arr=NULL;
int **table=NULL;
vector<int> set1,set2;

//Taking input from the user
void input()
{	
	cin>>size;
	arr= new int[size] ;
	for(int i=0;i<size;i++)
        cin>>arr[i];
}	

//Calculating sum of the full array and Initializing the DP table
void calSum()
{
	sum = accumulate(arr, arr+size, 0);
		
	table=new int*[sum/2+1];		//Initializing memory for DP Table
	for(int i = 0; i <= size; ++i)
      table[i] = new int[sum/2+1];


	for(int i=0;i<size+1;i++)		//Initializing all the cells of table to -1
    {  
		for(int j=0;j<sum/2+1;j++)
           table[i][j]=-1;           
    }
}

//Finding the subset if it exist or not
int SubSets(int sum, int n) 
{   
	//applying logic of 0/1 knapsack to get the subset
    if(sum==0)
    {
	    table[n][sum]=1;
	    return 1;
	}
	if (n == 0 && sum != 0)
    {
	    table[n][sum]=0;
	    return 0;
	}    
        
    if(table[n][sum]!=-1)
        return table[n][sum];
	
    if(arr[n-1]>sum)
	{    
	    table[n][sum]= SubSets(sum,n-1);
        return table[n][sum];
	}
    else
	{    
	    int x=SubSets(sum-arr[n-1],n-1);
	    int y=SubSets(sum,n-1);
	    table[n][sum]=x||y;
            return table[n][sum];	
	}
}

// Finding sets set1 and set2.
int findsubsets()
{	 
	if (table[size][sum/2]==0)
	  return 0; 
	
	// Start from last element in dp table. 
	int i = size; 
	int currSum = sum/2; 
        
	while (i > 0 && currSum >= 0) 
	{ 
		// If current element does not contribute to k, then it belongs to set 2.
        if (table[i-1][currSum]==1)
		{ 
			i--;  
			set2.push_back(arr[i]); 
		} 

		// If current element contribute to k then it belongs to set 1. 
		else if (table[i-1][currSum - arr[i - 1]]==1) 
		{ 
			i--; 
			currSum -= arr[i]; 
			set1.push_back(arr[i]); 
		} 
    } 
    return 0;   	
}

void display()
{
	   
	if (table[size][sum/2]==0)
	{
		cout<<" False"<<endl;
		cout << "No such Partition exist\n";
	}
	else{
		cout<<" True"<<endl;
		cout << " The array can be partitioned as:  "; 
		for (int i = 0; i < set1.size(); i++) 
			cout << set1[i] << " "; 
		
		cout << "and "; 
		for (int i = 0; i < set2.size(); i++) 
			cout << set2[i] << " ";	
	}
}
// Main program. 
int main() 
{       
	input();
	calSum(); 
	if (sum%2!=0) { 				//If sum is not even then no such partition exist
		cout << " No such partition exist"; 
		return 0;
	}    
	int k=SubSets(sum/2,size); 
	findsubsets();  
	display();	
	return 0; 
} 

/*
Input:
6
1 3 3 2 3 2

Output:
Array Size: 6
Array elements are: 1 3 3 2 3 2
Set 1 elements: 3 3 1
Set 2 elements: 2 3 2

Complexity:
Time:2^n
*/