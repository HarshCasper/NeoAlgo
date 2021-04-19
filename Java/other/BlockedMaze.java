/**
Given a Maze of dimensions M*N in which X represents blocked 
path and - represents open path. It is required to generate
all the possible pathways to reach from top-left corner to
bottom-right corner. Movement is allowed in all the four 
directions. The code will generate all the possible pathways 
where * will represent the path of the movement.
*/

import java.util.Scanner;

public class BlockedMaze {

	private static void display(char[][] maze, int m, int n) {

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(maze[i][j] + " ");
			}
			System.out.println();
		}
	}

	private static boolean isSafe(char[][] maze, int i, int j, int m, int n, boolean[][] visited) {

		if (i < 0 || j < 0 || i >= m || j >= n) {
			return false;
		}
		if (visited[i][j] == true || maze[i][j] == 'X') {
			return false;
		}
		return true;
	}

	private static void blockedMaze(char[][] maze, int i, int j, int m, int n, boolean[][] visited) {

		if (i == m - 1 && j == n - 1) {
			display(maze, m, n);
			System.out.println();
			return;

		} else {
			
			// Move in up direction
			if (isSafe(maze, i - 1, j, m, n, visited)) {
				visited[i - 1][j] = true;
				maze[i - 1][j] = '*';
				blockedMaze(maze, i - 1, j, m, n, visited);
				visited[i - 1][j] = false;
				maze[i - 1][j] = '-';
			}
			
			// Move in left direction
			if (isSafe(maze, i, j - 1, m, n, visited)) {
				visited[i][j - 1] = true;
				maze[i][j - 1] = '*';
				blockedMaze(maze, i, j - 1, m, n, visited);
				visited[i][j - 1] = false;
				maze[i][j - 1] = '-';
			}
			
			// Move in down direction
			if (isSafe(maze, i + 1, j, m, n, visited)) {
				visited[i + 1][j] = true;
				maze[i + 1][j] = '*';
				blockedMaze(maze, i + 1, j, m, n, visited);
				visited[i + 1][j] = false;
				maze[i + 1][j] = '-';
			}
			
			// Move in right direction
			if (isSafe(maze, i, j + 1, m, n, visited)) {
				visited[i][j + 1] = true;
				maze[i][j + 1] = '*';
				blockedMaze(maze, i, j + 1, m, n, visited);
				visited[i][j + 1] = false;
				maze[i][j + 1] = '-';
			}
		}
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		System.out.print("Enter size of Maze - ");
		int m = sc.nextInt();
		int n = sc.nextInt();

		char[][] maze = new char[m][n];
		System.out.println ("Draw the Maze - ");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				maze[i][j] = sc.next().charAt(0);
			}
		}

		// the matrix visited will keep the track
		// of the path we are visiting to prevent
		// from looping over the same path again.
		boolean[][] visited = new boolean[m][n];
		maze[0][0] = '*';
		visited[0][0] = true;

		System.out.println ("Possible pathways - ");
		blockedMaze(maze, 0, 0, m, n, visited);
	}
}

/**
Time Complexity : O(4^(m*n))
Space Complexity : O(m*n)

Input :

Enter size of Maze - 5 5
Draw the Maze - 
- X - - -
- - - X -
X - X - -
- - - - -
X - - X -

Output :

Possible pathways - 
* X - - - 
* * - X - 
X * X * * 
- * * * * 
X * * X * 

* X - - - 
* * - X - 
X * X - - 
- * * * * 
X * * X * 

* X - - - 
* * - X - 
X * X * * 
- * * * * 
X - - X * 

* X - - - 
* * - X - 
X * X - - 
- * * * * 
X - - X * 

* X * * * 
* * * X * 
X - X * * 
- - - * * 
X - - X * 

* X * * * 
* * * X * 
X - X - * 
- - - - * 
X - - X *

*/

