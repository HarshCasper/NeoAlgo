#include<iostream>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class Graph {

    int vertices;
    list<int>* adj; //pointer to adjacency list array

    public:
    Graph(int vertices);
    void addEdge(int u, int v);
    void sort();
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adj = new list<int>[vertices];
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Graph::sort() {
    //vector to store all indegrees.
    //initialize all indegrees as 0
    vector<int> in_degree(vertices, 0); 

    //traverse adjacency list to fill indegrees of vertices
    for(int u=0; u<vertices; u++) {
        list<int>::iterator iter;
        for(iter = adj[u].begin(); iter!=adj[u].end(); iter++) {
            in_degree[*iter]++;
        }
    }

    //create a queue and enqueue all vertices with indegree 0
    queue<int> q;
    for(int i=0; i<vertices; i++) {
        if(in_degree[i] == 0) {
            q.push(i);
        }
    }

    //initialize count of visited vertices as 0
    int count = 0;

    //vector to store topologically ordered vertices
    vector<int> ordered;

    //deque vertices and enque adjacents if indegree of adjacent becomes 0
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ordered.push_back(u);

        //iterate through all neighbouring nodes of dequed node u
        //and decrease their in-degree by 1
        list<int>::iterator iter;
        
        for(iter = adj[u].begin(); iter!=adj[u].end(); iter++) {
            //if in-degree becomes 0, add it to queue
            if(--in_degree[*iter]==0) {
                q.push(*iter);
            }
        }
        count++;
    }

    //check if there was a cycle
    if(count!=vertices) {
        cout<<"There exists a cycle in the graph\n"; 
        return;
    }

    for (int i = 0; i < ordered.size(); i++) 
        cout<<ordered[i] << " "; 
    cout<<endl; 
}

int main() 
{ 
	/* 
	int vertices, x, y;
	cout << "Enter the number of vertices in the graph: ";
	cin>>vertices;
	Graph g(vertices); 

	cout << "Enter the edges of the graph: \n";
	for(int i = 0; i < vertices; i++){
        cout<<"Edge "<<i+1<<":\n";
		cin >> x >> y;
        cout<<"\n";
		g.addEdge(x, y);
	}
	*/ 
	Graph g(6); 
	g.addEdge(5, 2); 
	g.addEdge(5, 0); 
	g.addEdge(4, 0); 
	g.addEdge(4, 1); 
	g.addEdge(2, 3); 
	g.addEdge(3, 1);

	cout << "\nTopologically sorted graph via Kahn's Algorithm:\n"; 
	g.sort(); 

	return 0; 
} 