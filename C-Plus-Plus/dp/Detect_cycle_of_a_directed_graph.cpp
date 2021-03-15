/* Question:
Given a directed graph, check whether the graph contains a cycle or not. Your function should print "Cyclic" if the given graph 
contains at least one cycle, else print "Non Cyclic".
Input:
Enter the number of vertices : 4
Enter the number of edges : 4
Enter edge 1 : 0 1
Enter edge 2 : 2 3
Enter edge 3 : 1 2
Enter edge 4 : 1 3
Output:
Non Cyclic
*/
// Time Complexity : O(n+e)
#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph
{
	int V;//Vertices
	list<int> *adj;//Adjacency List
public:
	Graph(int V);//Constructor
	void addEdge(int u,int v);// Method to add edge
	int bfs(int s,int visited[]);// Implement BFS
};
Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}
void Graph::addEdge(int u,int v){
	adj[u].push_back(v);//Directed graph
}
int Graph::bfs(int s,int visited[]){
	visited[s]=0;
	queue<int>q;// Queue data structure to BFS
	q.push(s);
	int f=0;
	list<int>::iterator it;
	while(!q.empty())// Checks if Queue is empty
	{
		int y=q.front();// Get first element in queue
		if(visited[y]==1 || f==1)// If yth vertice is already visited or f==1
		{
			f=1;
			break;
		}
		visited[y]=1;
		q.pop();// pop the first element
		for(it=adj[y].begin();it!=adj[y].end();++it)// Adjacent vertices of the yth vertex
		{
			if(visited[*it]==-1)// if vertex *it is not visited
			{
				visited[*it]=0;
				q.push(*it);
			}

			if(visited[*it]==1)//Cycle exists 
			{
				f=1;
				break;
			}
		}
	}
	return f;
}
int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
	cout<<"Enter the number of vertices : ";
	int n;
	cin>>n;//Number of vvertices
	Graph g(n);
	int e,u,v;
	cout<<"Enter the number of edges : ";
	cin>>e;//Number of edges
	for(int i=0;i<e;i++){
		cout<<"Enter edge "<<(i+1)<<" : ";
		cin>>u>>v;// Edges
		g.addEdge(u,v);
	}
	int *visited=new int[n];// Array to keep track of the number of visited vertices
	for(int i=0;i<n;i++)
		visited[i]=-1;// Intialize the elements of visited by -1
	int f=0;// variable to detect the presence of cycle
	for(int i=0;i<n;i++){
		if(visited[i]==-1){// if i th vertice is not visited
			f=g.bfs(i,visited);
		}
		if(f==1)//Cycle present
			break;
		}
		if(f==1)
			cout<<"Cyclic"<<endl;
		else
			cout<<"Non Cyclic"<<endl;
}
