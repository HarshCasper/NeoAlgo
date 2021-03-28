/*
Code : Kruskal's Algorithm

Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int start;
    int end;
    int weight;
};
struct DisjSet
{
    int parent;
    int rank;
};
int find(DisjSet *ds, int x)
{
    if(ds[x].parent != x)
        ds[x].parent = find(ds,ds[x].parent);
    return ds[x].parent;
}
void Union(DisjSet *ds, int x, int y)
{
    int rootX = find(ds,x);
    int rootY = find(ds,y);
    if(ds[rootX].rank < ds[rootY].rank)
    {
        ds[rootX].parent = rootY;
    }
    else if(ds[rootX].rank > ds[rootY].rank)
    {
        ds[rootY].parent = rootX;
    }
    else
    {
        ds[rootX].parent = rootY;
        ds[rootY].rank++;
    }
}
bool isUnion(DisjSet *ds, int x, int y)
{
    return find(ds,x) == find(ds,y);
}
void KruskalsMST(Edge *graph, DisjSet *ds, int n, int m)
{
    vector<Edge> MST;
    int j = 0;
    for(int i = 0; i < m && j < n-1 ; i++)
    {
        if(!isUnion(ds,graph[i].start,graph[i].end))
        {
          Union(ds,graph[i].start,graph[i].end);
            MST.push_back(graph[i]);
            j++;
        }
    }
    for(auto it : MST)
    {
      if(it.start <= it.end)
        cout << it.start << " " << it.end << " " << it.weight << endl;
      else
          cout << it.end << " " << it.start << " " << it.weight << endl;
    }
}
bool compare(Edge a,Edge b)
{
    return a.weight < b.weight;
}
int main()
{
    int n,m,cost;
    cin >> n >> m;
    Edge *graph = new Edge[m];
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        graph[i] = {a,b,c};
    }
    DisjSet *ds = new DisjSet[n];
    for(int i = 0; i < n; i++)
    {
        ds[i].parent = i;
        ds[i].rank = 0;
    }
    sort(graph, graph + m, compare);
    KruskalsMST(graph,ds,n,m);
    return 0;
}


/*
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
1 2 1
0 1 3
0 3 5

Time Complexity: O(ElogV)
*/
