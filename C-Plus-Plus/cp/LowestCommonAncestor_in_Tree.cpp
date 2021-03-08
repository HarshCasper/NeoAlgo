#include<bits/stdc++.h>
using namespace std;
vector<long long int> adj[100005];
long long int height_of_node[100005];
long long int parent_node[100005][18];

void calculate_parent_and_height_node(long long int node, long long int first_parent,long long int current_height=1)
{
  height_of_node[node]=current_height;
  parent_node[node][0]=first_parent;
  for(int i=1;i<18;i++)
  {
    parent_node[node][i]=parent_node[parent_node[node][i-1]][i-1];
  }
  for(auto adjacent_node: adj[node])
  {
     if(adjacent_node!=first_parent)
       calculate_parent_and_height_node(adjacent_node,node,current_height+1);
  }
}
long long int LCA(int node1, int node2)
{

    // considering that height of node1 is always the maximum
      if(height_of_node[node1]< height_of_node[node2]) swap(node1,node2);

      long long int difference_in_level=height_of_node[node1]-height_of_node[node2];
      // we are bring node1 and node 2 in the same level using binary lifting technique
      long long int count=0;
      while(difference_in_level)
      {
        if(difference_in_level&1)
        {
           node1=parent_node[node1][count];
        }
        count++;
        difference_in_level=difference_in_level>>1;
      }
      // if after bringing both nodes at same level, node1=node2 , then that is only the lca .
      if(node1==node2)
      {
        return node1;  // we could return any of the node as both are same.
      }
      //Applying binary lifing and trying to reach the fartherst unequal nodes 
      for(int powers_of_two=17;powers_of_two>=0;powers_of_two--)
      {
        if(parent_node[node1][powers_of_two]!=parent_node[node2][powers_of_two])
        {
          node1=parent_node[node1][powers_of_two];
          node2=parent_node[node2][powers_of_two];
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
  cin>>total_no_node;
  for(int i=2;i<=total_no_node;i++)
  {
      int node1;
      cin>>node1;
      // creating a bi- directional tree
      adj[node1].push_back(i);
      adj[i].push_back(node1);
  }
  // we are calculating the parent of all nodes and there height 
  // Assuming 1 to the root node , as root node has no parent so we 
  // consider it as 0.
  calculate_parent_and_height_node(1,0);
  int query;
  cin>>query;
  while(query-->0)
  {
     int node1, node2;
     cin>>node1>> node2;
     int lca=LCA(node1,node2);
     cout<<lca<<"\n";
  }

    return 0;
}                 
