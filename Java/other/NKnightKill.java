/**
It is a backtracking problem in which there are N knights 
that need to be placed on an N*N board in such a manner so 
that no two knights can kill each other.
The code will display all the possible positions of Knights
where - will represent a blank box and 
X will represent a Knight in a box.
*/

import java.util.Scanner;

public class NKnightKill {

    private static void display(char[][] board) {
		
		for (int i=0; i<board.length; i++) {
			for (int j=0; j<board.length; j++) {
				System.out.print (board[i][j]+"\t");
			}
			System.out.println();
		}
	}
	
	private static boolean isSafe(char[][] board, int i, int j) {
		// function will check if is it safe to
		// place the Knight at i,j

		if (i-2>=0 && j-1>=0 && board[i-2][j-1]=='X') {
			return false;
		}
		if (i-2>=0 && j+1<board.length && board[i-2][j+1]=='X') {
			return false;
		}
		if (i-1>=0 && j-2>=0 && board[i-1][j-2]=='X') {
			return false;
		}
		if (i-1>=0 && j+2<board.length && board[i-1][j+2]=='X') {
			return false;
		}
		return true;
	}
	
	private static void nKnight(char[][] board, int i, int j, int n) {

		if (n==0) {
			System.out.println("Possibility "+count+" - ");
			display (board);
			count++;
			System.out.println();
			return;
			
		} else if (i==board.length) {
			return;
			
		} else if (j==board.length) {
			nKnight(board, i+1, 0, n);
			
		} else {
			if (isSafe(board,i,j)) {
				board[i][j]='X';
				nKnight(board, i, j+1, n-1);
				board[i][j]='-';
			}
			
			nKnight(board, i, j+1, n);
		}
	}
	
	static int count = 1;
	
	public static void main(String[] args) {

		Scanner sc=new Scanner(System.in);
		
		System.out.print ("Enter no. of Knights / board size - ");
		int n=sc.nextInt();
		
		char[][] board=new char[n][n];
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				board[i][j]='-';
			}
		}
		
		nKnight(board,0,0,n);
	}
}

/**
Time Complexity  : O(2^(N*N))
Space Complexity : O(N*N)

Input:

Enter no. of Knights / board size - 3

Output (Many boards are possible therefore showing only one):

Possibility 1 - 
X   X   X
-   -   -
-   -   -

*/
