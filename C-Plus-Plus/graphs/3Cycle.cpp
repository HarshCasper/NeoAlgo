/*
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct
3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
*/ 

#include <iostream>
using namespace std;

void count(int V, int** edges){
    int count=0;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
           
            if(edges[i][j]==1){
              for(int k=0;k<V;k++){
                  
                  if(edges[j][k]==1&&edges[i][k]==1){
                     count++;
                   
                  }
              }
          }
        }
    }
    cout<< count/6;
}

int main() {
    
    int V,E;
    cin>>V>>E;
    int** edges=new int*[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<E;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    count(V, edges);
    
    return 0;
}

/*
Sample Input 1:
  3 3
  0 1
  1 2
  2 0
Sample Output 1:
  1
  
Time Complexity: O(V+E)
*/
