/*Problem Statement: 
All the people living in our imaginary world Bitworld are very religious.
There are N cities in Bitworld numbered from 1 to N.
Due to a storm, every road in Bitworld was destroyed and now no temples are left.
There are 2 types of operations :

You can construct a temple by giving away A dollars in ith city.
You can repair an already existing road by giving away B dollars.

Your goal is to make temples such that people of every city have access to some temple.
People of the ith city can visit the temple only if :
A temple exists in that city.
OR
There is a path from that city to a city which contains a temple. 
You have to minimize the total cost such that people in every city can go to a temple and output this minimum cost. */

#include <bits/stdc++.h>
using namespace std;

class graph
{
    public :
    int e,v,cost_temple,cost_road;
    map<int,list<int>> m;
    graph(int edge,int vert, int a , int b)
    {
        e=edge;
        v=vert;
        cost_temple=a;
        cost_road=b;
    } 
    void add(int u,int v)
    {
        m[u].push_back(v);
        m[v].push_back(u);

    }
    int dfshelper(int src,bool visited[])
    {
        visited[(int)src]=true;
        int count=1;
        for(auto i : m[(int)src])
        {
            if(!visited[i])
            {
              count+= dfshelper(i,visited);
            }
        }
       return count;
    }
    
    int dfs()
    {
        bool visited[(int)v]={false};
        int count=0;
        int sum=0;
        for(auto i:m)
        {
            /* If cost of making road is less than the temple,
            then make the road */
            if(!visited[(int)i.first])
            {
                count=dfshelper(i.first,visited);
                count--;
                sum+=(count*cost_road + cost_temple);

            }
        }
        return sum;
    }

};
int main() 
{
    int vertices,edges,cost_temple,cost_road,i,sum;
    cout<<"Enter vertices,total edges,cost of temple and cost of road: "<<endl;
    cin>>vertices>>edges>>cost_temple>>cost_road;
    graph g(edges,vertices,cost_temple,cost_road); 
    sum=0;
    cout<<"Enter edges: "<<endl;
    for(i=0;i<edges;i++)
    {
        int p,q;
        cin>>p>>q; 
        g.add(p,q);
    }
    /* If the cost of road is not less than the cost of temple,
    then construct the temple */
    if(cost_road>cost_temple) 
    {
        sum=cost_temple*vertices;
    }
    else
        sum=g.dfs();
    cout<<"Minimum cost: "<<sum<<endl;
    return 0;
}
/*Example:-

Input:-
Enter vertices,total edges,cost of temple and cost of road:
3 3 2 1 
Enter edges: 
1 2
3 1
2 3

Output:-
Minimum cost: 4

Time Complexity: O(n)
Space Complexity: O(n)
*/

