
/* Java program to solve N Queen Problem
using backtracking in an Optimization Method*/
import java.util.*;

class nQueens
{
    static int N;
    //ldia : Left Diagonal to store negative indices
    static int []ldia = new int[30];
    //rdia : Right Diagonal queen placed in right diagonal or not(row+column)
    static int []rdia = new int[30];
    //col :  column array
    static int []col = new int[30];

    //An Effective Funtion to print Solution
    static void printSolution(int onBoard[][])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                System.out.printf(" %d ", onBoard[i][j]);
            System.out.printf("\n");
        }
    }

    /* By this Utility Function, Consider using column 
    and try placing this queen in all rows one by one and
    check if queen can be placed or not. If Queen can be
    placed on Board then we can check left diagonal and 
    Right diagonal. If Queen placed dosen't match the 
    rules, then remove Queen on that position.*/
    static boolean solveUtil(int onBoard[][], int colo)
    {
        //BaseCase : If all Queens Placed
        if (colo >= N)
            return true;

        for (int i = 0; i < N; i++) {
            if ((ldia[i - colo + N - 1] != 1 &&
                    rdia[i + colo] != 1) && col[i] != 1) {

                onBoard[i][colo] = 1;
                ldia[i - colo + N - 1] =
                        rdia[i + colo] = col[i] = 1;

                if (solveUtil(onBoard, colo + 1))
                    return true;

                onBoard[i][colo] = 0; // BACKTRACK
                ldia[i - colo + N - 1] =
                        rdia[i + colo] = col[i] = 0;
            }
        }
        return false;
    }
    /* This function returns false if queens
    cannot be placed, otherwise, return true and
    prints placement of queens in the form of 1s.
    */
    static boolean solBoard()
    {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        int onBoard[][] = new int[N][N];

        if (solveUtil(onBoard, 0) == false)
        {
            System.out.printf("Solution does not exist");
            return false;
        }
        printSolution(onBoard);
        return true;
    }
    public static void main(String[] args)
    {
        solBoard();
    }
}

/*
Input : N = 4;
Output : 0  0  1  0
         1  0  0  0
         0  0  0  1
         0  1  0  0
 Input : N = 5
         1  0  0  0  0
         0  0  0  1  0
         0  1  0  0  0
         0  0  0  0  1
         0  0  1  0  0
 */
