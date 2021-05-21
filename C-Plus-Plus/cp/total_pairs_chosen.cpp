/*Problem Statement: 
The member states of the UN are planning to send  people to the moon.
They want them to be from different countries. You will be given a list of pairs of astronaut ID's. 
Each pair is made of astronauts from the same country. 
Determine how many pairs of astronauts from different countries they can choose from. */

#include<bits/stdc++.h>
using namespace std;
    
list<int> *ad;
int *visited;
int vertices;
    
void DFS(int u)
{
    visited[u] = 1;
    vertices++;
    list<int>::iterator it;
    for(it=ad[u].begin();it!=ad[u].end();it++)
    {
        //If the node is not visited
        if(visited[*it] == 0)
        {
            visited[*it] = 1;
            DFS(*it);
        }
    }
}
    
int main()
{
    int no_astronauts,pairs,u,v,numComponents=0,all_vertices=0,temp=2,count=0;
    int eachC[1000];
    cout << "Enter total number of astronauts and the total no of pairs: "<<endl;
    cin >> no_astronauts >> pairs;
    if(no_astronauts == 1)
    {
        cout <<"0"<<endl;
        return 0;
    }
    ad = new list<int>[no_astronauts];
    list<int>::iterator it;
    cout<<"Enter id and nationality: "<<endl;
    for(int i=0;i<pairs;i++)
    {
        cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);    
    }
    visited = new int[no_astronauts];
    for(int i=0;i<no_astronauts;i++)
    {
        visited[i] = 0;
    }
    for(int i=0;i<no_astronauts;i++)
    {
        if(visited[i] == 0)
        {
            vertices = 0;
            DFS(i);
            eachC[numComponents] = vertices;
            numComponents++;
        }
    }
    int totalWays = no_astronauts*(no_astronauts-1) / 2;
    int sameWays = 0;
    for(int i=0;i<numComponents;i++)
    {    
        sameWays = sameWays + (eachC[i]*(eachC[i]-1) / 2);
    }
    cout << "Total chosen pairs: " << (totalWays - sameWays) << endl;
    return 0;
}
/*Example:-

Input:-
Enter total number of astronauts and the total no of pairs: 
5 3
Enter id and nationality: 
0 1
2 3
0 4

Output:-
Total chosen pairs: 6

Time Complexity: O(n)
Space Complexity: O(n)
*/

