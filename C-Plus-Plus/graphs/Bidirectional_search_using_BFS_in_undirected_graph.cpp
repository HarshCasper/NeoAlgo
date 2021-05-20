/*
Bidirectional search is an algorithm in which we find the Smallest Path from the source to the
target vertex of a graph.
In this algorithm, we perform the search operation from two sides, i,e. from the source
vertex(Forward Search) and the target vertex(Backward Search) simultaneously.
It divides the graph into two smaller sub-graphs, one starting at the source
vertex and other at the target vertex.
As the searching operation proceeds, the two graphs grow and the search terminates when two graphs
intersect.
To perform the searching operation, we implement Breadth-first search on both source vertex and
target vertex.

Bidirectional search is faster in many cases as compared to normal one-directional search as it
dramatically reduces the amount of required exploration.
*/

typedef long long int ll;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define mod 1000000007

void bfs(queue<int>& q, vector<bool>& visited, vector<int>& parent, vector<int> graph[])
{
    int current = q.front();
    q.pop();

    for (auto i : graph[current])
    {

        // If adjacent vertex is not visited earlier
        // mark it visited by assigning true value
        if (!visited[i])
        {
            // set current as parent of this vertex
            parent[i] = current;
            
            // Mark this vertex visited
            visited[i] = true;
            
            // Push to the end of queue
            q.push(i);
        }
    }
}

// Print the path from source to target
void printShortestPath(vector<int>& parentF, vector<int>& parentB, int sv, int tv, int inode)
{
    vector<int> path;
    path.push_back(inode);
    int i = inode;
    while (i != sv)
    {
        path.push_back(parentF[i]);
        i = parentF[i];
    }
    reverse(path.begin(), path.end());
    i = inode;
    while (i != tv)
    {
        path.push_back(parentB[i]);
        i = parentB[i];
    }

    for (auto x : path)
        cout << x << " ";
    cout << endl;
}

// Helper Method for bidirectional searching
int bidirectional_search_helper(int sv, int tv, vector<int> graph[], int n, vector<bool>& visitedF,
    vector<bool>& visitedB, vector<int>& parentF, vector<int>& parentB)
{
    // queue for front and backward search
    queue<int> qF, qB;

    qF.push(sv);
    visitedF[sv] = true;

    qB.push(tv);
    visitedB[tv] = true;

    // parent of source is set to -1
    parentF[sv] = -1;

    // parent of target is set to -1
    parentB[tv] = -1;

    while (!qF.empty() && !qB.empty())
    {

        // Forward Breadth first search
        bfs(qF, visitedF, parentF, graph);

        // Backward Breadth first search
        bfs(qB, visitedB, parentB, graph);

        // checks for intersecting vertex
        int inode = -1;
        int i, flag = 0;
        for (i = 0; i < n; i++)
        {
            if (visitedF[i] && visitedB[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            inode = i;

        // If intersecting vertex is found
        // that means there exist a path
        if (inode != -1)
            return inode;
    }
    return -1;
}

// Method for bidirectional searching
void bidirectional_search(int vertices, vector<int> graph[], int sv, int tv)
{
    // visited array for forward search
    vector<bool> visitedF(vertices, false);

    // visited array for backward search
    vector<bool> visitedB(vertices, false);

    // parent array for forward search
    vector<int> parentF(vertices);

    // parent array for backward search
    vector<int> parentB(vertices);

    int intersection_node = bidirectional_search_helper(
        sv, tv, graph, vertices, visitedF, visitedB, parentF, parentB);

    // If intersection node does not exist then the path between the source vertex and target vertex
    // doesn't exist
    if (intersection_node == -1)
    {
        cout << "Path between " << sv << " and " << tv << " does not exists" << endl;
    }
    else
    {
        cout << "Path exist between " << sv << " and " << tv << endl;
        cout << "Intersection at: " << intersection_node << endl;
        printShortestPath(parentF, parentB, sv, tv, intersection_node);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int vertices, edges;
    cin >> vertices >> edges;

    vector<int> graph[vertices];

    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // source vertex
    int sv;
    // target vertex
    int tv;

    cin >> sv >> tv;

    bidirectional_search(vertices, graph, sv, tv);

    return 0;
}

/*
Example:

input:
15 14
0 4
1 4
2 5
3 5
4 6
5 6
6 7
7 8
8 9
8 10
9 11
9 12
10 13
10 14
3 10

output:
Path exist between 3 and 10
Intersection at: 7
3 5 6 7 8 10

Time Complexity : O(bd/2)
Space Complexity : O(bd/2)

{ b = branching factor of tree
  d = distance of goal vertex from source }
*/

