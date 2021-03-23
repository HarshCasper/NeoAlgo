
#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef vector<ll> vl; 
#define pb push_back 

#define loop(x,n) for(ll x = 1; x <= n; ++x)

//Adjacency List of an Undirected Graph
vl graph[100001];  

bool vis[100001];

ll in[100001],low[100001];

ll timer=1;  

void dfs(ll source,ll parent){
   vis[source]=true;
   in[source]=low[source]=timer;
   timer++;
   for(auto child:graph[source]){
       
       //if child equal to parent
       if(parent==child) continue;
       
       if(vis[child]==true)
       //back edge
        low[source]=min(low[source],in[child]);
        
        else{
            dfs(child,source);
            
            //condition for having a bridge
            if(low[child]>in[source])
             cout<<source<<"-"<<child<<" is a bridge\n";
             
             //visited forward edge
             low[source]=min(low[source],low[child]);
        }
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
     graph[b].pb(a);
     }

     loop(i,n){
        //initialise visited array as false;
     vis[i]=false;    
     }
    
    loop(i,n){
       //dfs call
      if(vis[i]==false) dfs(i,-1);  
    } 
    return 0; 
}

/*
Input:
First line contains two space separated integers,(n,m) 
n- no of vertices, m- no of edges.
Then m lines follow, each line has 2 space separated integers ui ,vi which denotes edge between vertex ui to vi.


TEST CASE
4 4
1 2
2 3
2 4
3 4

OUTPUT
1-2 is a bridge

Time- complexity: O(n+m)

Space Complexity: O(n)

*/

