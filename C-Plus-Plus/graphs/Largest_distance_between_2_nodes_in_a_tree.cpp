/*Given an unweighted rooted tree which consists of N nodes, find the largest distance between 2 nodes in a tree.
Since this is a tree, there will be a unique path between any 2 nodes.
The tree is given in the form of an array A, there is an edge connecting A[i] and i.
A[0] will be -1, since it denotes the root node

The approach is to use DFS here, first we will find the node which is at farthest distance from the root node by DFS
After this we will take this new node and run DFS from it to the farthest node.
The distance between these 2 nodes is the answer
It can be proven that the node found to be farthest from root node, has to be one of the end points of the largest distance path*/

#include <bits/stdc++.h>
using namespace std;

/*We maintain a visited array to keep track of what all nodes have already been visited
  And an adjacency list(adj) can be formed using the given input array(A)*/
int visited[40010];
vector<int> adj[40010];
vector<int> A;

//mx stores the answer at all times
int mx;

/*DFS function runs a DFS from the source node (node), and keeps updating the max distance until all nodes are visited
  nd stores the node which is found to be at farthest distance from the source node (node)*/
void dfs(int node, int dist, int& nd)
{
    if (dist > mx) {
        mx = dist;
        nd = node;
    }

    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++) {
        //If any node in the source node's adjacency list is found to be unvisited, we call a DFS with that node as a source and distance dist+1
        int s = adj[node][i];
        if (visited[s]) {
            continue;
        }
        dfs(s, dist + 1, nd);
    }
}

//solve function calls DFS twice as discussed above
int solve(int n)
{

    //If there is only one node, then the largest distance from that node is 0
    if (n == 1) {
        return 0;
    }

    //Call DFS from root node
    mx = 0;
    int nd = -1;
    dfs(0, 0, nd);

    //Reset the visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    //Call DFS from the node found to be farthest from root
    mx = 0;
    int md = -1;
    dfs(nd, 0, md);

    return mx;
}

int main()
{
    int n;
    cin >> n;

    for (int itr = 0; itr < n; itr++) {
        int x;
        cin >> x;
        A.push_back(x);
    }

    //Generate Adjacency list from input array A
    for (int i = 0; i < n; i++) {
        if (A[i] == -1) {
            continue;
        }
        adj[i].push_back(A[i]);
        adj[A[i]].push_back(i);
    }

    cout << solve(n) << endl;
}

/*Test Case 1:
  n= 5
  A= [-1, 0, 0, 0, 3]
  output = 3

  Tree:
        0
      / | \
     1  2  3
            \
             4
  Clearly, largest distance is 3 (from node 1 to 4 or 2 to 4)

  Test Case 2:
  n= 7
  A= [ -1, 0, 0, 1, 2, 1, 5 ]
  output = 5

  Tree:
        0
      /   \
     1     2
    / \      \
   3   5      4
        \
         6
  Clearly, largest distance is 5 (from node 4 to 6)

  Time Complexity: O(n)
  Space Complexity: O(n)*/
