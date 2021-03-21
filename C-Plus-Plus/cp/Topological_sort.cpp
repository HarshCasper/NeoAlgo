/*
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering
of vertices such that for every directed edge uv, vertex u comes before v in
the ordering. Topological Sorting for a graph is not possible if the graph is
not a DAG.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
stack<int> s;
bool *visited;

// Number of Test Cases (Vertices)
int n;

void createGraph()
{
    int x, y;
    adjList.resize(n);

    for (int j = 0; j < n; j++)
    {
        cin >> x >> y;
        adjList[x].push_back(y);
    }
}

void topoSortFun(int i)
{
    visited[i] = true;
    for (int j = 0; j < adjList[i].size(); j++)
    {
        int key = adjList[i][j];
        if (!visited[key])
            topoSortFun(key);
    }
    s.push(i);
}

void topoSort()
{
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            topoSortFun(i);
    }
}
void display()
{
    for (int i = 0; i < n; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
}
int main()
{
    cin >> n;
    visited = new bool[n];
    createGraph();
    topoSort();
    display();
}

/*
    Test Case:

    Input 1 :
    6
    5 2 
    5 0 
    4 0 
    4 1 
    2 3 
    3 1 

    Output 1 :
    5 4 2 3 1 0 

    Input 2 :
    6
    4 2
    5 1
    4 0
    3 1
    1 3
    3 2

    Output 2 : 
    5 4 1 3 2 0 

    Time Complexity: O(V + E) – where V is the number of vertices and E is the number of edges.

    Space Complexity: O(V)
*/
