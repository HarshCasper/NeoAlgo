
//Code to find Minimum Sanning Tree using Prim's Algorithm

#include<bits/stdc++.h>

using namespace std;
//default value for no of vertices
const int V=6;

//function to find vertex with min key value
int MinKey(int key[],bool set[])
{
	int min=INT_MAX;
	int minIndex;
	//v is vertex index
	for(int v=0;v<V;v++)
	{
		if(set[v]==false && key[v]<min)
		{
		min=key[v];
		minIndex=v;
     	}
	}
	
	return minIndex;
}


//function to print final Tree
void print(int Par[],int cost[V][V])
{
	int min_cost=0;
	cout<<"Edge \tWeight \n";
	for(int v=0;v<V;v++)
	{
		cout<<Par[v]<<" - "<<v<<" \t "<<cost[v][Par[v]]<<"\n";
		min_cost+=cost[v][Par[v]];
	}
	cout<<"Total Cost is: "<<min_cost;
}


//function to find MST using Adjacency Matrix Representation
void findMST(int cost[V][V])
{
	int Par[V],key[V];
	bool vis[V];
	
	//Initialising array
	for(int i=0;i<V;i++)
	{
		key[i]=INT_MAX;  //dafault value for key
		vis[i]=false;
		Par[i]=-1;
	}
	key[0]=0;  //including first vertex of MST
	Par[0]=-1;  //First i.e. root node of MST
	
	//Initializing Matrix
	for(int v=0;v<V-1;v++)
	{
		//Finding minimum key from set of values
		//not included in MST
		int x=MinKey(key,vis);
		
		vis[x]=true; //Adding min key vertex to MST
		//update key and Par array
		for(int v=0;v<V;v++)
		{
			if(cost[x][v]!=0 && vis[v]==false&& cost[x][v]<key[v])
			{
			Par[v]=x;
			key[v]=cost[x][v];
			}
		}
	}
	print(Par,cost);
}

//Driver Code
int main()
{
	
	int cost[V][V];
	cout<<"Enter the graph with V vertices";
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			cin>>cost[i][j];
		}
	}
	findMST(cost);
	return 0;
}


/*
Sample Input:
6
0 4 0 0 0 2
4 0 6 0 0 3
0 6 0 3 0 1
0 0 3 0 2 0
0 0 0 2 0 4
2 3 1 0 4 0

Sample Output:
Edge      Weight
5 - 1      3
5 - 2      1
2 - 3      3
3 - 4      2
0 - 5      2
Total Cost is 11

Time Complexity: O(n^2),  n is no of vertices
Space Complexity: O(n)
*/
