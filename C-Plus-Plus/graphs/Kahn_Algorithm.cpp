/**
	*Program to print the topological sort using Kahn's Algorithm in Directed Graph

	*Read more about Topological sort: https://en.wikipedia.org/wiki/Topological_sorting

	*Time Complexity O(V+E), where V=no. of vertex and E=no. of edges

	*Space Complexity O(V)
*/

#include <bits/stdc++.h>
using namespace std;

//Declaring global adjacency list
vector<int> adj[100001];
//It counts the number of nodes in graph pointing to specific nodes
vector<int> in(100001, 0);

bool KahnAlgorithm(int numOfVertex)
{

    queue<int> q;
    vector<int> res; //This stores the result

    for (int i = 1; i <= numOfVertex; i++)
    {
        if (in[i] == 0) //If no other vertex is pointing towards it we will print it first
            q.push(i);
    }

    while (!q.empty())
    {

        int curVertex = q.front();
        q.pop();
        res.push_back(curVertex);

        for (int node : adj[curVertex])
        {
            in[node]--;
            if (in[node] == 0)
                q.push(node); //We have stored all vertex pointing to it
        }
    }

    //If this condition satisfies that means there is a cycle and Topological sort
    //is not possible
    if (res.size() != numOfVertex)
        return false;

    //Printing elements in Topological order
    for (int elem : res)
        cout << elem << " ";
    return true;
}

int main()
{

    //Declaring variables
    int numOfVertex, numOfEdges;
    int fromVertex, toVertex;

    cin >> numOfEdges >> numOfVertex;

    //Making a directed graph

    while (numOfEdges--)
    {
        cin >> fromVertex >> toVertex;

        adj[fromVertex].push_back(toVertex);

        in[toVertex]++;
    }

    if (!KahnAlgorithm(numOfVertex))
        cout << "There is a cycle in graph so topological sort is not possible";
}

/**
	Test case used
	6 6
	6 1
	5 1
	5 2
	6 3
	3 4
	2 4

	Result:
	5 6 2 1 3 4
*/