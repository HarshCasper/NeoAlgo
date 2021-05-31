/*Problem Statement:
You are given a graph with N vertices and M edges.
Master parent is the vertex which has no parent but may have 0 or more children. 
In any connected component of the graph, 
vertex with the lowest value in that component serves as the master parent.
Count the total no of vertices which have more children than its parent. 
The graph has no cycles or self loops. */

#include <bits/stdc++.h>
using namespace std;

class graph
{
    public:
        int V;
    list<int> *adjList;
    list<int> *realList;

    graph(int V)
    {
        this->V = V;
        adjList = new list < int>[V];
        realList = new list < int>[V];
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    void Make_edges()
    {
        set<int> s;
        for (int i = 0; i < V; i++)
        {
            s.insert(i);
        }

        while (s.empty() == false)
        {
            bool visited[V];
            for (int i = 0; i < V; i++)
            {
                visited[i] = false;
            }

            set<int>::iterator it = s.begin();

            queue<int> q;
            q.push(*it);
            while (q.empty() == false)
            {
                int x = q.front();
                q.pop();
                visited[x] = true;
                s.erase(x);
                int size = adjList[x].size();
                for (int i = 0; i < size; i++)
                {
                    int k = adjList[x].front();
                    adjList[x].pop_front();
                    if (visited[k] == false)
                    {
                        q.push(k);
                        realList[x].push_back(k);
                    }
                }
            }
        }
    }

    int total_vertices()
    {
        int child[V];
        for (int i = 0; i < V; i++)
        {
            child[i] = 0;
        }

        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            child[i] = realList[i].size();
        }

        for (int i = 0; i < V; i++)
        {
            int size = realList[i].size();
            for (int k = 0; k < size; k++)
            {
                if (child[realList[i].front()] > child[i] && child[i] != 0)
                {
                    cnt++;
                }

                realList[i].pop_front();
            }
        }

        return cnt;
    }
};

int main()
{
    int n;
    cout << "Enter the total vertices: " << endl;
    cin >> n;
    graph g(n);
    int m;
    cout << "Enter the total edges: " << endl;
    cin >> m;
    int u;
    int v;
    cout << "Enter edges: " << endl;
    while (m--)
    {
        cin >> u >> v;
        u--;
        v--;
        g.addEdge(u, v);
        g.addEdge(v, u);
    }

    g.Make_edges();
    cout << "Total vertices with more than total children than the parents: " << g.total_vertices();
    return 0;
}
/*Example:-
Input:-
Enter the total vertices: 
4
Enter the total edges: 
3
Enter edges: 
1 2
2 3
2 4

Output:-
Total vertices with no more than total children than the parents: 1 

Time Complexity: O(n)
Space Complexity: O(n)
*/

