#include <iostream>
using namespace std;

void mazeHelper(int **  maze, int **solution, int m, int n, int curri, int currj)
{
    if(curri == m - 1 && currj == n - 1)
    {
        //If reached the end printing out the solution
        solution[m - 1][n - 1] = 1;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
                cout << solution[i][j] << " ";
            cout << endl;
        }
        solution[m - 1][n - 1] = 0;
        return ;
    }

    // Validating whether the current position of the maze is not exceeding the maze area
    if(curri < m && currj < n && curri >= 0 && currj >= 0)
    {   
        //Checking whether we have encountered an obstacle
        if(maze[curri][currj] == 1)
            return;
        //Checking whether the current position has been already traversed
        if(solution[curri][currj] == 1)
            return;

        //Marking the path in solution
        solution[curri][currj] = 1;
        //Move Down
        mazeHelper(maze, solution, m, n, curri + 1, currj);
        //Move Up
        mazeHelper(maze, solution, m, n, curri - 1, currj);
        //Move Right
        mazeHelper(maze, solution, m, n, curri, currj + 1);
        //Move Left
        mazeHelper(maze, solution, m, n, curri, currj - 1);
        //Unmarking the path in solution
        solution[curri][currj] = 0;
    } 

}

void mazeSolver(int **maze, int m, int n)
{
    int ** solution = new int * [m];
    for(int i = 0 ; i < m ; i++)
        solution[i] = new int[n];

    for(int i = 0 ; i < m ; i++)
        for(int j = 0 ; j < n ; j++)
            solution[i][j] = 0;

    //Starting from the top left corner
    mazeHelper(maze, solution, m, n, 0, 0);
}

int main()
{
    int m, n;
    //Size of maze
    cin >> m >> n;
    int ** maze = new int * [m];
    for(int i = 0 ; i < m ; i++)
        maze[i] = new int[n];

    for(int i = 0 ; i < m ; i++)
        for(int j = 0 ; j < n ; j++)
            cin >> maze[i][j];
    
    mazeSolver(maze, m, n);

    return 0;
}