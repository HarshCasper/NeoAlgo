/*Prims Algorithm to find Minimum Spanning of a Graph using Priority Queue.
It is  greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. 
A minimum spanning tree (MST) or minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define inf INT_MAX

void addEdge(vector<pair<int, int>> adjList[], int u, int v, int wt)
{
    adjList[u].push_back(make_pair(v, wt)); //edges between u & v vertices
    adjList[v].push_back(make_pair(u, wt)); 
}

void primsMinSpammingTree(vector<pair<int, int>>  adjList[], int vertices)

{

   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;


   vector<int> key(vertices, inf); //vector to store minimum edge value b/w two vertices

   vector<int> parent(vertices, -1); //vector to store parent vertices

   vector<bool> isMST(vertices, false); //vector to store vertices that have been traversed

   int src = 0; 
   pq.push(make_pair(0, src));
    key[src] = 0;
 
    /*till priority queue becomes empty*/
    while (!pq.empty())
    {
        
        int u = pq.top().second;     
        pq.pop();
 
        isMST[u] = true;      // Include vertex in MST
 
      // Traverse all adjacent vertices of u
        for (auto x : adjList[u])
        {
           
            int v = x.first;                               // vertex label of current adjacent of u
            int weight = x.second;                          // weight of current adjacent of u
 
        // If v is not in MST and weight of (u,v) is smaller than current key of v
            if (isMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    cout<<"ParentV  SourceV  Weight"<<endl;
    
    for (int i = 1; i < vertices; ++i)
        cout << string(2, ' ') << parent[i] << string(10, ' ') << i << string(9, ' ') << key[i] << endl;

}

int32_t main()
{
    int vertices;
    cin>>vertices;
    vector<pair<int, int>> adjList[vertices];

                                                                    
    int edges;      //count of edges of graph
    cin>>edges;
    int source, destination, wt;
    for(int i =0 ; i < edges; i++)
    {
        cin>>source>>destination>>wt;
        addEdge(adjList, source, destination, wt);
    }

    primsMinSpammingTree(adjList, vertices);

    return 0;
}


/* Test case1 : 
	Input :
    9           number of vertices
    14          count of edges of graph
    0 1 4       source vertex, destination vertex, weight
    0 7 8
    1 2 8
    1 7 11
    2 3 7
    2 8 2
    2 5 4
    3 4 9
    3 5 14
    4 5 10
    5 6 2
    6 7 1
    6 8 6
    7 8 7        

Output1:
ParentV   SourceV  Weight
  0          1         4
  1          2         8
  2          3         7
  3          4         9
  2          5         4
  5          6         2
  6          7         1
  2          8         2




Test case2 :
	Input :
    6      // number of vertices
    8    //count of edges of graph
    0 1 4 //source vertex, destination vertex, weight
    0 2 3
    1 2 1
    1 7 11
    1 3 2
    2 3 4
    3 4 2
    4 5 6
  

 Output2	
 ParentV   SourceV  Weight
  1          2         1
  2          0         3
  3          1         2
  4          3         2
  5          4         6



   Time Complexity: O(edgesLog(Vertices))
   Space Complexity: O(Vertices)
*/
 