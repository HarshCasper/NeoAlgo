/* A star graph is an undirected graph that has n nodes in which one is center node and  has exactly n - 1 edges.

    4
    |
    2
   / \
  1   3 
  
 Here 2 is the answer.
 
 Approach: Store the nodes in vector that are connected to partciular node, if size of that vector equals to nodes-1 then print it is the centre. */

#include <iostream>
#include<vector>
#include<climits>
using namespace std;

int findCenter(vector<vector<int>>& edges)
{
        int n=edges.size()+1;
        
        vector<int>l[n+1];
        
        // Store th destintaion edges into source node vector
        for(int i=0;i<edges.size();i++)
        {
                l[edges[i][0]].push_back(edges[i][1]);
                l[edges[i][1]].push_back(edges[i][0]);
        }
         
        // Check if vector size is equal to nodes-1, to find the center
        int center;
        for(int i=0;i<=n;i++)
        {
            if(l[i].size()==n-1)
                center=i;
        }
        return center;
}

int main()
{
    int src,dest,no_of_edges;
    cin>>no_of_edges;
    vector<vector<int>>edges;
    
    for(int i=0;i<no_of_edges;i++)
    {
        vector<int>temp;
        
        cin>>src;
        temp.push_back(src);
        cin>>dest;
        temp.push_back(dest);
        
        edges.push_back(temp);
    }
    cout<<(findCenter(edges));
    return 0;
}


/* 
INPUT:
3
1
2
2
3
4
2
OUTPUT:
2

INPUT:
4
1
2
5
1
1
3
1
4
OUTPUT:
1

Time Complexity: O(no_of_edges)
*/
