#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef set<ll> sl;
#define pb push_back

#define loop(x,n) for(ll x = 1; x <= n; ++x)

//Adjacency List of an Undirected Graph
vl graph[100001];

bool vis[100001];

ll in[100001], low[100001];

ll timer = 1;

//set to store unique articulation points
sl cut_vertices;
sl::iterator itr;

void dfs(ll source, ll parent) {
	vis[source] = true;
	in[source] = low[source] = timer;
	timer++;
	ll children = 0;
	for (auto child : graph[source]) {

		//if child equal to parent
		if (parent == child) continue;

		if (vis[child] == true)
			//back edge
			low[source] = min(low[source], in[child]);

		else {
			dfs(child, source);

			//visited forward edge
			low[source] = min(low[source], low[child]);

			//condition for having a articulation point
			if (low[child] >= in[source] && parent != -1)
				cut_vertices.insert(source);

			children++;
		}
	}

	//condition for source vertex for having a cut vertex
	if (parent == -1 && children > 1 )
		cut_vertices.insert(source);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m, a, b;
	//n=no. of vertices, m=no. of edges
	cin >> n >> m;

	loop(i, m) {
		cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}

	loop(i, n) {
		//initialise visited array as false;
		vis[i] = false;
	}

	loop(i, n) {
		//dfs call
		if (vis[i] == false) dfs(i, -1);
	}

	//print articulation points
	cout << "Artciulation points:\n";
	for (itr = cut_vertices.begin(); itr != cut_vertices.end(); ++itr)
		cout << *itr << " ";
	return 0;
}

/*
Input:
First line contains two space separated integers,(n,m)
n- no of vertices, m- no of edges.
Then m lines follow, each line has 2 space separated integers ui ,vi which denotes edge between vertex ui to vi.


TEST CASE
5 5
1 2
1 3
2 3
3 4
4 5

OUTPUT
Artciulation points:
3 4

Time- complexity: O(n+m)

Space Complexity: O(n)
*/
