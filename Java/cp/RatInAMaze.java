/*
__Rat In A Maze Problem__
Given a maze in the form of a matrix of size m * n. Each cell is either clear or blocked denoted by 1 and 0 respectively.
A rat sits at the top-left cell (matrix[0][0]) and there exists a block of cheese at the bottom-right cell (matrix[m-1][n-1]). Both these cells are guaranteed to be clear.
Find if the rat can get the cheese if it can move only in one of the two directions - down and right. It can’t move to blocked cells.

Input:
2 integers m and n denoting rows and columns
Next m lines contain n space-separated integers which are either 0 or 1

Output:
single line containing 1 or 0 based on whether the rat can get the cheese or not respectively.
*/

import java.util.*;

public class RatInAMaze{

    //global variable to store whether possible to reach cheese
    static boolean solution = false;
	
    //check if position maze[i][j] is free and lies on the grid
	private static boolean safestate(int[][] maze, int m, int n, int i, int j){
		if(i >= m || j>= n || maze[i][j]!=1) return false;
		return true;
	}

	private static void CheeseFinder(int[][] maze, int m, int n, boolean[][] visited, int i, int j){
		//base case
        if(i == m-1 && j == n-1){
            solution=true; 
            return;
        }
        //mark current position as visited
		visited[i][j] = true;
        //move down (backtracking)
		if(safestate(maze,m,n,i+1,j) && !visited[i+1][j]) CheeseFinder(maze, m,n,visited,i+1,j);
        //move right (backtracking)
		if(safestate(maze,m,n,i,j+1) && !visited[i][j+1]) CheeseFinder(maze,m,n,visited,i,j+1);
		visited[i][j] = false;
		return;
	}

	public static boolean canGetCheese(int[][] maze){
		solution = false;
		int m = maze.length;
		int n = maze[0].length;
		boolean[][] visited = new boolean[m][n];
		CheeseFinder(maze, m, n, visited, 0, 0);
		if(!solution) return false;
		return true;
	}

    public static void main(String[] args){
        Scanner inp = new Scanner(System.in);
        int m = inp.nextInt();
        int n = inp.nextInt();
        int[][] maze = new int[m][n];
        for(int x = 0; x < m; x++){
            for(int y = 0; y < n; y++){
                maze[x][y] = inp.nextInt();
            }
        }
        boolean PossibleToGetCheeese = canGetCheese(maze);
        if(PossibleToGetCheeese) System.out.println("1");
        else System.out.println("0");
        inp.close();
    }
}

/*Sample I/O
Sample 1
4 4
1 1 0 0
1 1 1 1
0 1 0 1
0 1 0 1

1   (Output)

Sample 2
4 4
1 1 0 0
1 1 1 1
0 1 1 0
0 1 0 1

0    (Output)

Time Complexity = O(2^(n^2))
Space Complexity = O(n^2)
*/
