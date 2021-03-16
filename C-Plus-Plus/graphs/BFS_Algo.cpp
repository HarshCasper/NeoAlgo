// Implementation of Breadth-first Search Algorithm
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// traversal function
void traversal(int **adjacencyMatrix, int V, bool* visited, int start)
{
	queue<int>pending;
	visited[start]=true;
	pending.push(start);
	while(!pending.empty())
	{
		int frontvertex=pending.front();
		pending.pop();
		cout<<frontvertex<<" ";
		for(int i=0;i<V;i++)
		{
			if(adjacencyMatrix[frontvertex][i]==1 && !visited[i])
			{
				visited[i]=true;
				pending.push(i);
			}
		}
	}
}

//bfs function
void breadthFirstSearch(int** adjacencyMatrix,int V)
{
	bool* visited=new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		{
			traversal(adjacencyMatrix,V,visited,i);
		}
	}
	delete[] visited;
}

// main function
int main()
{
	int vertex, edges;
	cout<<"Enter Number of Vertices- "<<" ";
	cin>>vertex;
	cout<<endl;
	cout<<"Enter Number of Edges- "<<" ";
	cin>>edges;
	int** adjacencyMatrix=new int*[vertex];
	for(int i=0;i<vertex;i++)
	{
		adjacencyMatrix[i]=new int[vertex];
		for(int j=0;j<vertex;j++)
		{
			adjacencyMatrix[i][j]=0;
		}
	}
	for(int i=0;i<edges;i++)
	{
		// a and b are two numbers having edge between them
		int a,b;
		cin>>a>>b;
		adjacencyMatrix[a][b]=1;
		adjacencyMatrix[b][a]=1;
	}
	breadthFirstSearch(adjacencyMatrix,vertex);
	for(int i=0;i<vertex;i++)
	{
		delete[] adjacencyMatrix[i];
	}
	delete[] adjacencyMatrix;
}
