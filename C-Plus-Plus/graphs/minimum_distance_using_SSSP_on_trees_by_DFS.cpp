/*

*/

#include <bits/stdc++.h>
using namespace std;
vector < int > adj[10009];
int visited[10009];
int distance_array[10009];



// this get_number_of_divisors will count the number of divisors of the number
void dfs(int node, int dist)
{
    visited[node] = 1;
    distance_array[node] = dist;
    for(auto child : adj[node])
    {
        if(visited[child] == 0)
            dfs(child , distance_array[node] + 1);
    }

}

int main()
{
    cout << "Enter the nodes and edges of the graph :\n";
	int nodes, edges;
	cin >> nodes >> edges;
	cout << "Enter the start and end points that have edges \n";
	for(int i = 1; i <= edges; i++)
    {
        int point1, point2;
        cin >> point1 >> point2;
        adj[point1].push_back(point2);
        adj[point2].push_back(point1);

    }
    /* here dfs call(1, 0)
    from 1th node distance is 0
    */
    dfs(1, 0);

    cout << "Minimum Distance of Each Nodes: \n";
//    void print_minimum_distance_of_each_nodes(int nodes)
//{
   for(int i = 1; i <= nodes; i++)
    {
        cout << distance_array[i] << ' ';
    }
    cout << endl;
//}
    //print_minimum_distance_of_each_nodes(nodes);
}

/*
Standard Input and Output



Time Complexity : O( sqrt(N) )
Space Complexity : O( 1 )

*/
