// Cycle Detection in Undirected Graph using BFS
#include <bits/stdc++.h>
using namespace std;

 //Adjacency List storing the graph
vector<int> arr[100000];   
//Visited array, it stores wheather the node is visited or not
vector<int> vis(100000, 0); 

bool checkCycle(int src)
{
    //Initialize  a quueue and insert a pair of node and parent in it
    queue<pair<int, int>> q;
    vis[src] = 1;
    q.push(make_pair(src, -1));
    while (!q.empty())
    {
        //Pop out the front element of queue
        auto pair = q.front();
        int node = pair.first;
        int prev = pair.second;
        q.pop();
        //Iterate over every chilf of popped pair
        for (auto child : arr[node])
        {
            //If the child is not visited then mark it visited and insert in queue
            if (vis[child] == 0)
            {
                vis[child] = 1;
                q.push(make_pair(child, node));
            }
            /*If the node is visited and child is not the previour element
            then it means the child is already reached using other path,
            hence there exist a cycle and we return true*/
            else if (child != prev)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m, res = 0;
    cout << "Enter the nodes and edges: \n";
    cin >> n >> m;
    cout << "Enter the edges\n";
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            if (checkCycle(i))
                res = 1;
    }
    if (res)
    {
        cout << "There exists a cycle in this graph";
    }
    else
    {
        cout << "There does not exists a cycle in this graph";
    }
    return 0;
}

/*
Sample Input Output :-
Enter the nodes and edges: 
11 10
Enter the edges
1 2
2 4
3 5
5 6
5 10
6 7
7 8
10 9
9 8
8 11
There exists a cycle in this graph

Time Complexity : O( N+E) // Nodes and Edges
Space Complexity : O( N+E )+O(N)+O(N)
*/
