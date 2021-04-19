/*
Best First Search Algorithm is a search algorithm that is used to find a path between source vertex 
and target vertex in an undirected weighted graph. It is a search algorithm that works on a specific
rule. It is an example of "Informed Search" algorithm as it uses an evaluation function to decide 
which adjacent is most promising and then explores it.
It uses the concept of a priority queue (min heap) to store costs of nodes.
*/

#include <bits/stdc++.h>
using namespace std;

//Function to implement best first search algorithm
void bestFirstSearchAlgorithm(int sv, int tv, int n, vector<vector<pair<int, int> > > graph)
{

    //array for keeping track of visited vertices
    vector<bool> visited(n, false);

    //min heap priority queue for storing cost of nodes
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    //inserted source position in the priority queue
    pq.push(make_pair(0, sv));

    //mark source vertex as visited
    visited[sv] = true;

    //array to store path from the source to the target vertex
    vector<int> path;

    while (!pq.empty()) {

        int temp = pq.top().second;

        path.push_back(temp);
        pq.pop();

        //If target vertex is found then exit from the loop
        if (temp == tv)
            break;

        for (int i = 0; i < graph[temp].size(); i++) {
            //For each neighbouring vertex of temp
            // Continue if it is already visited
            if (visited[graph[temp][i].second])
                continue;
            //Else mark it visited and insert it in the priority queue
            else {
                visited[graph[temp][i].second] = true;
                pq.push(graph[temp][i]);
            }
        }
    }

    cout << "Path between source vertex and target vertex: " << endl;
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<pair<int, int> > > graph;

    int vertices, edges;

    cout << "Input number of vertices and edges" << endl;
    cin >> vertices >> edges;

    graph.resize(vertices);

    cout << "Input edges: start vertex, end vertex and weight of edge between them" << endl;
    for (int i = 0; i < edges; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back(make_pair(cost, b));
        graph[b].push_back(make_pair(cost, a));
    }

    int sv, tv;

    cout << "Input Source vertex and target vertex" << endl;
    cin >> sv >> tv;

    bestFirstSearchAlgorithm(sv, tv, vertices, graph);

    return 0;
}

/*

Sample Output:

Input number of vertices and edges
14 13
Input edges: start vertex, end vertex and weight of edge between them
0 1 3
0 2 6
0 3 5
1 4 9 
1 5 8
2 6 12
2 7 14
3 8 7
8 9 5
8 10 6
9 11 1
9 12 10
9 13 2
Input Source vertex and target vertex
0 9

Output:
Path between source vertex and target vertex:
0 1 3 2 8 9

Time Complexity: O(V log V)
Space Complexity: O(V^2)
where,
    V = Number of vertices
*/

