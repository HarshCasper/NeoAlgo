#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define pb push_back

#define loop(x,n) for(ll x = 0; x < n; ++x)

 
ll capacity[100][100];
vl adj[100];

ll bfs(ll s, ll t, vl& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    ll inf=INT_MAX;
    q.push({s, inf});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (ll next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t, ll n) {
    ll flow = 0;
    vl parent(n);
    ll new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        ll cur = t;
        while (cur != s) {
            ll prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll n,e;
      cout<<"enter the number of nodes and edges\n"; 
    cin>>n>>e; 
    
    ll source, sink,u,v,w;
     cout<<"enter the source and sink\n";
    cin>>source>>sink;

   loop(i,e){
      cin>>u>>v>>w;
      capacity[u][v] = w;
      adj[u].pb(v);
      adj[v].pb(u);
   }
     
   cout<<"Max Flow: "<<maxflow(source,sink,n);
	
	return 0;
}

/*
Input:
First line contains two space separated integers,(n,e) 
n- no of vertices, e- no of edges.
Then 2 space separated integers source and sink ie, starting and ending point.
Then e lines follow, each line has 3 space separated integers u ,v, w which denotes edge from vertex u to v with capcity w.


TEST CASE
6 10
0 5
0 1 16
0 2 13
1 2 10
2 1 4
1 3 12
3 2 9
2 4 14
4 3 7
4 5 4
3 5 20

OUTPUT
Max Flow: 23

Time- complexity: O(n*e*e)

Space Complexity: O(n+e)
*/
