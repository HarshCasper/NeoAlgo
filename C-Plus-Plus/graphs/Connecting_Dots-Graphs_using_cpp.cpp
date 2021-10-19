/*
we have a board of size NxM. Each cell in the board is a coloured dot. 
There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). 
we want to play a game. The key of this game is to find a cycle that contain dots of same colour. 
Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

These k dots are different: if i ≠ j then di is different from dj.
k is at least 4.
All dots belong to the same colour.
For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Our task is to determine if there exists a cycle on the board.
*/
#include<bits/stdc++.h>
using namespace std;

// directions in which we can move

int move1[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
bool isvalid(int x,int y,int n,int m)
{
    if(x>=0&&x<n&&y>=0&&y<m)
        return 1;
    return 0;
}

// Connecting the dots

bool connect(vector<vector<char>> &board,int n,int m,bool **visited,int x,int y,int s,int e,char ch,int k)
{
    if(k>=4&&x==s&&y==e)
    {
        return 1;
    }
    if(!isvalid(x,y,n,m)||board[x][y]!=ch||visited[x][y]==1){
        return false;
    }
    
    bool ans=false;
    for(int i=0;i<4;i++)
    {
        int nr=x+move1[i][0];
        int nc=y+move1[i][1];
        visited[x][y]=1;
        ans=ans|| connect(board,n,m,visited,nr,nc,s,e,ch,k+1);
        visited[x][y]=0;
    }
    return ans;
    
}

// finding out if a cycle exists

bool hasCycle(vector<vector<char>> &board, int n, int m)
{

    bool **visited=new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[m];
        for(int j=0;j<m;j++)
            visited[i][j]=false;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            bool ans=connect(board,n,m,visited,i,j,i,j,board[i][j],1);
            if(ans){
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int rows, columns;
    cout<<"enter the number of rows and columns"<<endl;
    cin >> rows >> columns;

    vector<vector<char>> board(rows, vector<char>(columns));
  
//     Each of the following rows  contain columns characters. 
//     Please note that characters are not space separated.
//     Each character is an uppercase Latin letter.
    cout<<"enter the characters on the board in rows lines having columns capital characters"<<endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, rows, columns) ? "true" : "false");
}


/*
Time Complexity - O(N*M)
Space Complexity - O(N*M)

where N and M  are rows and columns respectively of the board.

Sample Input 1:
enter the number of rows and columns
3 4
enter the characters on the board in N lines having M capital characters
AAAA
ABCA
AAAA

Sample Output 1:
true

*/
