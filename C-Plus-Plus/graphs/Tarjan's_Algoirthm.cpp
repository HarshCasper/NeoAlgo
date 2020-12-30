
/*
Tarjan's Algo is an algorithm which helps to find the number of strongly connected components 
in a directed graph with a Depth First Search function call.

It's idea is based on the implementation of in time and low time of a graph.  

During execution of DFS & calculation of low time value, this algo keeps track of active nodes.

Refer https://www.youtube.com/watch?v=EDb_TGBZqgg&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=44 to learn the concept and for the testcase
*/


#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef vector<ll> vl; 
#define pb push_back 

#define loop(x,n) for(ll x = 1; x <= n; ++x)

//Adjacency List of Graph
vl graph[100001];  

bool vis[100001],onstack[100001];

ll in[100001],low[100001];

stack<ll> st;

//scc=no. of strongly connected components
ll timer=1,scc=0;  

void dfs(ll source){
  vis[source]=1;
  //increase in time and low time
  in[source]=low[source]=timer++;  
  
  onstack[source]=true;
   // push into stack
  st.push(source);    
  
  for(auto child:graph[source]){
    if(vis[child]==true && onstack[child]==true)
        //change low time if back edge
          low[source]=min(low[source],in[child]);  
    
    else if(vis[child]==false){
       dfs(child);
    
      if(onstack[child]==true)
      //change low time if visited forward edge
       low[source]=min(low[source],low[child]);   
      }
  }
  
  //case for scc if in=low
  if(in[source]==low[source]){  
   scc++;
    cout<<"Strongly Connected Component #"<<scc<<":\n";

    ll s;
    while(1){
       s=st.top();
       //delete all elements from stack till it top element equal to scc node
       st.pop();          
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
    //n=no. of vertices, m=no. of edges
    cin>>n>>m;     
    
    loop(i,m){
     cin>>a>>b;
     graph[a].pb(b);
     }

     loop(i,n){
        //initialise visited array as false;
     vis[i]=onstack[i]=false;    
     }
    
    loop(i,n){
       //dfs call
      if(vis[i]==false) dfs(i);  
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

