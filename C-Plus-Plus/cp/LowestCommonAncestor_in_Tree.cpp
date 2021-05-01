/* if you are given two nodes of a tree , this program will calculate 
   the Lowest Common Ancestor(LCA) of those two nodes
   Definition of LCA : 
   Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined 
   as the shared ancestor of n1 and n2 that is located farthest from the root T. 
*/
#include <bits/stdc++.h>
using namespace std;
vector<long long int> adj[100005];
long long int height_of_node[100005];
long long int parent_node[100005][18];

void calculate_parent_and_height_node(long long int node, long long int first_parent, long long int current_height = 1)
{
    height_of_node[node] = current_height;
    parent_node[node][0] = first_parent;
    for (int i = 1; i < 18; i++)
    {
        parent_node[node][i] = parent_node[parent_node[node][i - 1]][i - 1];
    }
    for (auto adjacent_node : adj[node])
    {
        if (adjacent_node != first_parent)
            calculate_parent_and_height_node(adjacent_node, node, current_height + 1);
    }
}
long long int LCA(int node1, int node2)
{

    // considering that height of node1 is always the maximum
    if (height_of_node[node1] < height_of_node[node2])
        swap(node1, node2);

    long long int difference_in_level = height_of_node[node1] - height_of_node[node2];
    // we are bring node1 and node 2 in the same level using binary lifting technique
    long long int count = 0;
    while (difference_in_level)
    {
        if (difference_in_level & 1)
        {
            node1 = parent_node[node1][count];
        }
        count++;
        difference_in_level = difference_in_level >> 1;
    }
    // if after bringing both nodes at same level, node1=node2 , then that is only the lca .
    if (node1 == node2)
    {
        // we could return any of the node as both are same.
        return node1; 
    }
    //Applying binary lifing and trying to reach the fartherst unequal nodes
    for (int powers_of_two = 17; powers_of_two >= 0; powers_of_two--)
    {
        if (parent_node[node1][powers_of_two] != parent_node[node2][powers_of_two])
        {
            node1 = parent_node[node1][powers_of_two];
            node2 = parent_node[node2][powers_of_two];
        }
    }
    // after applying binary liftine we know that the first parent of node1 will always be the LCA.
    return parent_node[node1][0];
}
int main()
{
    /*
   Assuming that first line of our input contains N i.e. total no of nodes in a tree.
   next N-1 line contains the parent of each node.
   and then Q queries ,
   where every query contains two nodes and we need to print the LCA between them.
    */
    int total_no_node;
    cout<<"Enter the Total number of nodes in a tree\n";
    cin >> total_no_node;
    cour<<"Enter the parent node of every node starting fron 2\n";
    for (int i = 2; i <= total_no_node; i++)
    {
        int node1;
        cin >> node1;
        // creating a bi- directional tree
        adj[node1].push_back(i);
        adj[i].push_back(node1);
    }
    // we are calculating the parent of all nodes and there height
    // Assuming 1 to the root node , as root node has no parent so we
    // consider it as 0.
    calculate_parent_and_height_node(1, 0);
    cout<<"Enter Total Number of queries\n";
    int query;
    cin >> query;
   cout<<"Enter two nodes for each query \n";
    while (query-- > 0)
    {
        int node1, node2;
        cin >> node1 >> node2;
        int lca = LCA(node1, node2);
        cout<<"LCA of Numbers "<<node1<<" and "<<node2<<" is : ";
        cout << lca << "\n";
    }

    return 0;
}

/* SAMPLE INPUT :
    Enter the Total number of nodes in a tree
    5 
    Enter the parent node of every node starting fron 2
    1 1 3 3
    Enter Total Number of queries
    3
    Enter two nodes for each query
    4 5
    2 5
    1 4
*/
/* Sample OUPUT :
   LCA of Numbers 4 and 5 is 3
   LCA of Numbers 2 and 5 is 1
   LCA of Numbers 1 and 4 is 1
*/
/* Time complexity Ansalysis : 
   Building of Tree takes O(N) time Complexity 
   Calulating the parent and height function takes another O(18*N) time complexity
    Then EACH query TAKES LOG(N) time to process the query and find the LCA
        
   Therefore, TOTAL Time COMPLEXITY O(N+(18*N)+(Q*LOG(N)) which is same as saying O(Q*LOG(N);
   
   SPACE COMPLEXITY :
    we ARE USING SPACE COMPLEXITY OF O(N*18) as maximum value of N can be 10^5, 
    so we have made an fixed Array size of [10^5][18] for the ease and better understanting 
    of the code.
    
    There total Space complexity equals O(N) as 18 is a constant.
*/
