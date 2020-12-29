/*
Tarjan's Algo is an algorithm which helps to find the number of strongly connected components 
in a directed graph with a Depth First Search function call.

It's idea is based on the implementation of in time and low time of a graph.  

During execution of DFS & calculation of low time value, this algo keeps track of active nodes.
*/


#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef vector<ll> vl; 
#define pb push_back 

#define loop(x,n) for(ll x = 1; x <= n; ++x)

vl graph[100001];  //Adjacency List of Graph

bool vis[100001],onstack[100001];

ll in[100001],low[100001];

stack<ll> st;

ll timer=1,scc=0;  //scc=no. of strongly connected components

void dfs(ll source){
  vis[source]=1;
  in[source]=low[source]=timer++;  //increase in time and low time
  
  onstack[source]=true;
  st.push(source);     // push into stack
  
  for(auto child:graph[source]){
    if(vis[child]==true && onstack[child]==true)
          low[source]=min(low[source],in[child]);  //change low time if back edge
    
    else if(vis[child]==false){
       dfs(child);
    
      if(onstack[child]==true)
       low[source]=min(low[source],low[child]);   //change low time if visited forward edge
      }
  }
  
  //case for scc if in=low
  if(in[source]==low[source]){  
   scc++;
    cout<<"Strongly Connected Component #"<<scc<<":\n";

    ll s;
    while(1){
       s=st.top();
       st.pop();          //delete all elements from stack till it top element equal to scc node
       onstack[s]=false;
       
       cout<<s<<" ";
       if(s==source) break;   
      
     }
    cout<<"\n";
  }
    
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    
    ll n,m,a,b;
    cin>>n>>m;     //n=no. of vertices, m=no. of edges
    
    loop(i,m){
     cin>>a>>b;
     graph[a].pb(b);
     }

     loop(i,n){
     vis[i]=onstack[i]=false;     //initialise visited array as false;
     }
    
    loop(i,n){
      if(vis[i]==false) dfs(i);   //dfs call
    } 
    return 0; 
}

/*
Input:
First line contains two space separated integers,(n,m) 
n- no of vertices, m- no of edges.
Then m lines follow, each line has 2 space separated integers ui ,vi which denotes edge from vertex ui to vi.

TEST CASE
8 12
1 2
2 3
3 1
2 8
3 4
8 4
4 8
7 8
5 4
5 7
7 6
6 5

OUTPUT
Strongly Connected Component #1:
8 4 
Strongly Connected Component #2:
3 2 1 
Strongly Connected Component #3:
6 7 5

Time- complexity: O(n+m)

Space Complexity: O(n)
*/