/*
Ninja decided to find the distance between the neighbouring cities and then store them for future use. 
He took data from the map and developed an input format. He is given an integer ‘N’ denoting the number 
of cities and then he has an array of size ‘N - 1’ that stores a pair of numbers at each index. Let the 
pair be ‘I1’ and ‘I2’, which will denote a bidirectional edge between the two cities ‘I1’ and ‘I2’.
A subtree is a subset of cities, where each city can be reached from every other city of the subset. 
The path between each pair passes only though the cities present in the subset. Two subtrees are taken 
differently if there are one or more cities in one subtree not present in the other.
Now, you need to create an array of ‘N - 1’ elements where the ‘ith’ element is the number of subtrees 
in which the maximum distance between any two cities is equal to ‘i’.
*/

#include <bits/stdc++.h>
#include <vector>
#include <climits>
using namespace std;

vector<int> countSubtreesMaxDistance(int n, vector<vector<int>>& edges) 
{
    
    // Create the adjaceny matrix in form of graph
    vector<vector<int>> graph(n, vector<int>(n, INT_MAX / 2 - 1));
    for (auto e : edges) 
    {
        int u = e[0] - 1, v = e[1] - 1;
        graph[u][v] = graph[v][u] = 1;
    }
        
    // floyd-warshall algorithm for calculating shortest distance
    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    
    // initialise vector to store result 
    vector<int> res(n - 1, 0);
        
    /* Check for each combination of nodes and see if it's a subtree or not.
     If it's a subtree then see maximum distance that can be reached.*/
        
    // Each subtree
    // sub = subtree
    for (int sub = 0; sub < (1 << n); sub++) 
    {
        // Number of nodes = nodes
        int nodes = __builtin_popcount(sub);
        
        // edges
        int edges = 0;
        
        //  dist = distance
        int dist = 0;
        for (int i = 0; i < n; i++)
        {
         	if (sub & (1 << i)) 
            {
                for (int j = i + 1; j < n; j++) 
                {
                    if (sub & (1 << j)) 
                    {
                            
                        // if i to j edge increment e
                        edges += graph[i][j] == 1;
                            
                        // maximum distance
                        dist = max(dist, graph[i][j]);
                    }
                }
            }
        }
            
        // chech its a subtree and distance > 0 if it's then its a subtree having max d distance
        if (edges == nodes - 1 && dist > 0) 
        {
            res[dist - 1] = res[dist - 1] + 1;
        }
    }
    
    // return result
    return res;
}
int main()
{
    int N;
    cout<<"Enter number of cities: "<<endl;
    cin>>N;
    cout<<"Enter paths: "<<endl;
    vector<vector<int>> arr;
    int val;
    for(int i = 0; i < N-1; i++){
        vector<int> temp;
        for(int j = 0; j < 2; j++){
            cin >> val;
            temp.push_back(val);
        }
        arr.push_back(temp);
        temp.clear();
    }
    cout<<"Maximum distance is: "<<endl;
    vector<int> ans = countSubtreesMaxDistance(N, arr);
    for(int i=0; i<N-1; i++){
        cout<<ans[i]<<" ";
    }
    
}

/*
    Sample Input:
    Enter number of cities: 
    4
    Enter paths: 
    1 2
    1 3
    2 4 
    
    Sample Output:
    Maximum distance is: 
    3 2 1
    
    Time complexity: O(2 ^ N) 
	Space complexity: O(N * N)
    where N is the number of cities.
*/
