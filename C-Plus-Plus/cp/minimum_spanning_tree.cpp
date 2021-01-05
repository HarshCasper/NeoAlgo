/*
There are n vertices and e edges and their weights, 
you need to construct minimum spanning tree.
vertex numbers start from 0.

Input:
first line containes the value of n and e.
next e lines follow 3 space seperated integers u, v, w, which means
there is a path between u and v having weight w.

Output:
First line containing the minimum weight of the tree.
next n-1 lines containes 2 space seperated integer u, v & w.
i.e. u and v have a path between them in the formed MST.
and w denotes the weight.

Efficiency: O(e log e + e alpha e)
Language: C++17
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX_VERTICES 100005

vector <int> parent(MAX_VERTICES);
vector <int> max_depth(MAX_VERTICES);

//optimised find function
int findparent(int u)
{
	while (u != parent[u])
	{
		//path compression technique
		parent[u] = parent[parent[u]];
		u = parent[u];
	}
	return u;
}

//union function
void take_union(int u, int v)
{
	u = findparent(u);
	v = findparent(v);
	if (max_depth[u] > max_depth[v])
		parent[v] = parent[u];
	else if (max_depth[u] < max_depth[v])
		parent[u] = parent[v];
	else
	{
		max_depth[u]++;
		parent[v] = u;
	}
}
int main()
{
	//decale and read the values of number of
	//vertices and edges respectively
	int n, e; 
	cin >> n >> e;
	//declare and read the values of edge list 
	//edge_list.first contains the weight
	//edge_list.second.first contains the value of u
	//edge_list.second.second contains the value of v. 
	vector <pair <int, pair<int, int> > > edges_list(e);
	for (int i = 0; i < e; i++)
	{
		cin >> edges_list[i].second.first >> edges_list[i].second.second;
		cin >> edges_list[i].first;
	}
	//sort the vector in ascending order in order to keep
	//the edge with weight less first.
	sort(edges_list.begin(), edges_list.end());
	//initialize the parent and max_depth vector.
	for (int i = 0; i <= n; i++)
		parent[i] = i, max_depth[i] = 0;
	//check one-by-one whether to add the edge to mst or not.
	int count_of_edge_mst = 0, total_weight = 0;	
	vector <pair <int, pair<int, int> > > final_edge_mst;
	for (int i = 0; i < e and count_of_edge_mst < n - 1; i++)
	{
		//check whether or not to add this edge 
		if (findparent(edges_list[i].second.first) != findparent(edges_list[i].second.second))
		{
			take_union(edges_list[i].second.first, edges_list[i].second.second);
			//add the dge into the final edge vector
			final_edge_mst.push_back(edges_list[i]);
			//increment the total weight
			total_weight += edges_list[i].first;
			count_of_edge_mst++;
		}
	}
	cout << total_weight << endl;
	for (auto val : final_edge_mst)
		cout << val.second.first << " " << val.second.second << " " << val.first << endl;
	return 0;	
}

/*
Sample Input 1:
9 14
0 1 4
0 7 8
1 7 11
1 2 8 
7 6 1
7 8 7
6 5 2
8 6 6
2 8 2
2 3 7
2 5 4
3 5 14
2 4 9
5 4 10

Sample Output:
37
7 6 1
2 8 2
6 5 2
0 1 4
2 5 4
2 3 7
0 7 8
2 4 9

*/
