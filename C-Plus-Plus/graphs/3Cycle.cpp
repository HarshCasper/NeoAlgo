/*
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges,
then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which
(P,Q), (Q,R) and (R,P) are connected by an edge.
*/

/* 
V is the number of vertices in the input graph and E is the number of edeges in
the input graph.
*/

#include <iostream>
using namespace std;

int getCycles(bool** graph, int v){
    int cycleCount = 0;
    for(int i=0; i<v-2; ++i){
        for(int j=i+1; j<v-1; ++j){
            for(int k=j+1; k<v; ++k){
                if (graph[i][j] && graph[j][k] && graph[k][i]){
                    ++cycleCount;
                }
            }
        }
    }
    return cycleCount;
}
int main()
{
    int v, e;
    
    cin >> v >> e;
    
    bool** graph = new bool*[v];
    
    for(int i=0; i<v; ++i){
        graph[i] = new bool[v]();
    }
    
    for(int i=0, a, b; i<e; ++i){
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    cout << getCycles(graph, v);
    
    for(int i=0; i<v; ++i){
        delete[] graph[i];
    }
    
    delete[] graph;
}

/*
Sample Input 1:
3 3
0 1
1 2
2 0
Sample Output 1:
1

Time Complexitiy: O(V^3)

Space Complexity: O(V^2)
*/
