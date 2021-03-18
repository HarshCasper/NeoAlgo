// Added by shubhgupta9
/* This is a code for checking weather a graph is connected or not in C++.

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.

The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.

The first and only line of output contains "true" if the given graph is connected or "false", otherwise.
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//Recursion is used in the algo function.
bool isConnected(int **edges,int n,int node, bool *visited)
{
    visited[node]=true;

  for(int i=0;i<n;i++)
  {
    if(edges[node][i] && !visited[i])
      isConnected(edges,n,i,visited);
  }
}

//Main function
int main() 
{
  int V,E;
    cin>>V>>E;
    
    int **edges=new int*[V];
    
    for(int i=0;i<V;i++)
    {
        edges[i]=new int[V];
        
    for(int j=0;j<V;j++)
    {
        edges[i][j]=0;
    }
    }
    
    for(int i=0;i<E;i++)
    {
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
        edges[b][a]=1;
    }
    
    int s,e;
    cin>>s>>e;
    
    bool *visited = new bool[V];
    
    for(int i=0;i<V;i++)
    {
        visited[i] = false;
    }
    
       isConnected(edges,V,0,visited);
    
     bool b=true;
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            b=false;
            break;
        }
    }
    if(b)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    
    return 0;

}
/*
example input 1:-
4 3
0 1
1 3 
0 3

example output 1:-
false 

example input 2:-
4 4
0 1
0 3
1 2
2 3

example output 2:-
true
*/