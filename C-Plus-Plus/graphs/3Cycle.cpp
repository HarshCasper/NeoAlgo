/*
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges,
then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which
(P,Q), (Q,R) and (R,P) are connected by an edge.
*/

/* 
V is the number of vertices in the input graph and E is the number of edeges in
the input graph.
*/

#include <bits/stdc++.h>
using namespace std;

int getCycles(bool** graph, int vertices){
    int cycleCount = 0;
    for(int i=0; i<vertices-2; ++i){
        for(int j=i+1; j<vertices-1; ++j){
            for(int k=j+1; k<vertices; ++k){
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
    int vertices, edeges;
    
    cout<<"Enter the number of vertices and number of edeges in the graph"<<endl;
    
    cin >> vertices >> edeges;
    
    bool** graph = new bool*[vertices];
    
    for(int i=0; i<vertices; ++i){
        graph[i] = new bool[vertices]();
    }
    
    cout<<"Enter the path vertices"<<endl;
    
    for(int i=0, a, b; i<edeges; ++i){
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    
    cout<<"The number of distinct 3-cycles in the graph is/are: ";
    
    cout << getCycles(graph, vertices);
    
    for(int i=0; i<vertices; ++i){
        delete[] graph[i];
    }
    
    delete[] graph;
}

/*
Sample Input 1:
Enter the number of vertices and number of edeges in the graph                                                                                  
3 3                                                                                                                                                                                                                                                                                            
Enter the path vertices                                                                                                                         
0 1
1 2
2 0

Sample Output 1:
The number of distinct 3-cycles in the graph is/are: 1 

Time Complexitiy: O(V^3)

Space Complexity: O(V^2)
*/
