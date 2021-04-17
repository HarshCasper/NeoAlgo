/*
The Ford–Fulkerson method or Ford–Fulkerson algorithm (FFA) is a greedy algorithm that computes the maximum flow in a flow network. 
The goal here is to calculate the maximum amount of stuff that can be pushed from source(s) to the sink(t) vertex in a directed 
weighted graph. Hence, it is the maximum flow problem.

Given constraints:
a) Flow on an edge doesn’t exceed the given capacity of the edge.
b) Incoming flow is equal to outgoing flow for every vertex except s and t.

This algorithm is also known as the Edmonds-Karp Algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

//Function to implement breadth first search
//Stores the path from source to sink in the parent vector
int breadthFirstSearch(int source, int sink, vector<int>& parent, vector<vector<int> >& residual)
{

    //Initialize parent array by -1
    fill(parent.begin(), parent.end(), -1);

    int v = residual.size();

    //Parent of source vertex is set as -2
    parent[source] = -2;

    //Queue is created to store vertices and their capacity
    queue<pair<int, int> > q;

    //Source vertex is inserted
    q.push(make_pair(source, INT_MAX));

    //Loop for the standard bfs traversal
    while (!q.empty()) {
        int temp = q.front().first;
        int cap = q.front().second;
        q.pop();
        for (int i = 0; i < v; i++) {

            //If adjacent vertex is not visited
            if (temp != i && parent[i] == -1 && residual[temp][i] != 0) {
                parent[i] = temp;

                int min_rcap = min(cap, residual[temp][i]);

                //If the sink vertex is found , we stop the bfs and return the minimum residual capacity in path
                if (i == sink)
                    return min_rcap;

                q.push(make_pair(i, min_rcap));
            }
        }
    }
    return 0;
}

//Function to implement ford fulkerson algorithm and print maximum flow form source to the sink
void fordFulkersonAlgorithm(vector<vector<int> >& graph, int source, int sink)
{

    //Parent array to store the path and initialize it to -1
    vector<int> parent(graph.size(), -1);

    //A residual graph which is the copy of the origimal graph is created.
    vector<vector<int> > residual = graph;

    //Minimimum residual capacity in the path
    int min_rcap = 0;

    //Initially the flow is zero
    int max_flow = 0;

    //While there is minimum residual capacity in the bfs traversal path from source to sink in the residual graph
    while (min_rcap = breadthFirstSearch(source, sink, parent, residual)) {

        //Add the Minimimum residual capacity of path to maximum flow
        max_flow = max_flow + min_rcap;
        int u = sink;

        // Traverse all the nodes in the path and update the residual capacities
        while (u != source) {
            int v = parent[u];
            residual[u][v] += min_rcap;
            residual[v][u] -= min_rcap;
            u = v;
        }
    }
    cout << "Maximum Flow: " << max_flow << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int vertices, edges;

    cout << "Input number of vertices and edges" << endl;
    cin >> vertices >> edges;

    vector<vector<int> > graph(vertices, vector<int>(vertices, 0));

    cout << "Input edges: start vertex, end vertex and capacity of edge between them" << endl;
    for (int i = 0; i < edges; i++) {
        int st, en, capacity;
        cin >> st >> en >> capacity;
        graph[st][en] = capacity;
    }

    int source, sink;

    cout << "Enter Source vertex and sink vertex" << endl;
    cin >> source >> sink;

    fordFulkersonAlgorithm(graph, source, sink);

    return 0;
}

/*
Sample Output:

Input number of vertices and edges
6 10
Input edges: start vertex, end vertex and weight of edge between them
0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
Enter Source vertex and sink vertex
0 5

Output:
Maximum Flow: 23

Time Complexity: O(E*(V^3))
Space Complexity: O(V^2)
where,
    V = Number of vertices
    E = Number of edges
*/
