/*Problem Statement: 
Given a 1 to N snakes and ladders board, starting and the ending points of all snakes and ladders.
You have to find out the minimum number of dice throws to win the game.
Each dice throw can have any number from 1 to 6. */

#include<bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    list<int> *a;

public:
    graph(int v)
    {
        V=v;
        a=new list<int> [v];
    }

    void AddEdge(int u,int v,bool bidir=true)
    {
        a[u].push_back(v);
        if(bidir)
        {
            a[v].push_back(u);
        }
    }

    void bfs(int src,int dest)
    {
        queue<int> q;
        bool *visited=new bool[V]{0};
        int *dist=new int[V+1]{0};
        int *parent=new int[V+1];
        for(int i=0;i<V;i++)
        {
            parent[i]=-1;
        }

        q.push(src);
        visited[src]=true;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(int neighbour: a[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                    dist[neighbour]=dist[node]+1;
                    parent[neighbour]=node;
                }
            }
        }
        cout<<"Minimum number of moves: "<<dist[dest]<<endl; 
    }
};

int main()
{
    int board[200]={0};
    int total_jumps;
    cout<<"Enter total number of ladders and snakes present in board: "<<endl;
    cin>>total_jumps;
    cout<<"Enter the points where the ladders and snakes are present(add negative jump for snakes): "<<endl;
    for(int i=0;i<total_jumps;i++)
    {
        int temp,jump;
        cin>>temp>>jump;
        board[temp]=jump;
    }
    int board_size;
    cout<<"Enter board size: "<<endl;
    cin>>board_size;
    graph game_board(board_size);
    for(int i=0;i<36;i++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int v=i+dice+board[i+dice];
            game_board.AddEdge(i,v,false);
        }
    }
    game_board.bfs(0,36);
    return 0;
}
/*
Example: 

Input:-
Enter total number of ladders and snakes present in board: 
10
Enter the points where the ladders and snakes are present(add negative jump for snakes): 
2 13
5 2
9 18
18 11
17 -13
20 -14
24 -8
25 -10
32 -2
34 -22
Enter board size: 
50

Output:-
Minimum number of moves: 4

Time Complexity: O(n)
Space Complexity: O(n)
*/

