/* Question:
Given a undirected graph, check whether the graph contains a cycle or not. Your function should print "Cyclic" if the given graph 
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
class Graph{
	int V;//Vertices
	list<int> *adj;//Adjacency List
public:
	Graph(int V);//Constructor
	void addEdge(int u,int v);// Method to add edge
	bool dfs();// Implement Dfs
	bool dfsUtil(int s,bool visited[],int parent);
};
Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}
void Graph::addEdge(int u,int v){
	adj[u].push_back(v);//UnDirected graph
	adj[v].push_back(u);
}
bool Graph::dfsUtil(int s,bool visited[],int parent){
	visited[s]=true;
	for(auto i:adj[s]){
		if(!visited[i]){
			// cout<<i<<" ";
			if(dfsUtil(i,visited,s))
			return true;
		}
		else if(i!=parent){
			// cout<<i<<" ";
			return true;
		}
	}
	return false;
}
bool Graph::dfs(){
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)// Intialize each element of visited to false 
		visited[i]=false;
	for(int i=0;i<V;i++){
		if(!visited[i])//if vertex not visited
			if(dfsUtil(i,visited,-1))//call dfsUtil and checks if it is true
				return true;
	}
	return false;
}
int main(){
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	cout<<"Enter the number of vertices : ";
	int n;
	cin>>n;//Number of vertices
	Graph g(n);
	int e,u,v;
	cout<<"Enter the number of edges : ";
	cin>>e;//Number of edges
	for(int i=0;i<e;i++){
		cout<<"Enter edge "<<(i+1)<<" : ";
		cin>>u>>v;// Edges
		g.addEdge(u,v);
	}
	if(g.dfs())
		cout<<"Cyclic"<<endl;
	else
		cout<<"Non-Cyclic"<<endl;
}
