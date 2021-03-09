/*
The algorithm gives us a topological sort for the given directed graph. If the graph is cyclic it returns as no topological sort for the graph is possible.

Steps:

1: Firstly compute in-degree (number of incoming edges) for each of the vertex present in the DAG and initialize the count of visited nodes as 0.

2: Pick all the vertices with in-degree as 0 and add them into a queue.

3: Remove a vertex from the queue and then increment count of visited nodes by 1.
Decrease in-degree by 1 for all its neighboring nodes.
If in-degree of any neighboring node is reduced to zero, then add that node to the queue.

4: Repeat 3 until the queue is empty.

5: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not possible for the given graph.
*/

#include<bits/stdc++.h>
using namespace std;

void kahn_topological_sort(vector <int> adj[], int n){
    //Array for keeping a track for indegree of all nodes
    int in_degree[n]; 
    
    memset(in_degree,0,sizeof(in_degree));
    
    queue <int> q; 

    //Computing in degree of each node
    for(int i=0;i<n;i++){
        for(auto s: adj[i]){
            in_degree[s]++;
        }
    }

    //Pushing nodes with in degree zero into the queue
    for(int i=0;i<n;i++){
        if(!in_degree[i]){
            q.push(i);
        }
    }

    int count_of_visited_nodes{};
    
    //This vector will store the order
    vector <int> topological_order; 
   
    while(!q.empty()){
        //Storing the front i.e. the first node of the queue in curr
        int curr = q.front();
        //Pushing the node curr into the order
        topological_order.push_back(curr);
        //Poping that node from the queue
        q.pop();
        //Traversing to all adjacents of the curr node and decreasing there indegree by one
        for(auto s: adj[curr]){
            in_degree[s]--;
            //If any node's indegree becomes zero pushing it into the queue
            if(!in_degree[s]) q.push(s);
        }
        //increasing the count of visited nodes
        count_of_visited_nodes++;
    }

    if(count_of_visited_nodes!=n){
        cout<<"No topological sort possible, there exists a cycle"<<endl;
    }
    else{
        cout<<"Topological Order:"<<endl;
        for(auto s:topological_order){
            cout<<s<<" ";
        }cout<<endl;
    }
    
}

int main(){
    int n,m; cin>>n>>m;
    vector <int> adj[n];
    
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    kahn_topological_sort(adj,n);
    return 0;
}
/*
Test cases:

1.
Input:->
5 7
0 1
0 2
0 3
1 3
1 4
4 3
Output:->
Topological Order:
0 1 2 4 3

Time complexity: O(n+m) //Order of Sum of number of edges and vertices

Auxillary Space: O(n)   //Order of number of vertices

*/
