package com.company;
/* Java program to solve N Queen Problem
using backtracking in an Optimization Method*/
import java.util.*;

class anaGram
{
    static int N;
    static int []neg = new int[30];// to store negative indices
    static int []dia = new int[30];// queen placed in right diagonal or not(row+column)
    static int []col = new int[30];// column array
    static void printSolution(int onBoard[][])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                System.out.printf(" %d ", onBoard[i][j]);
            System.out.printf("\n");
        }
    }
    static boolean solveUtil(int onBoard[][], int colo)
    {
        if (colo >= N)
            return true;

    /* Consider this column and try placing
    this queen in all rows one by one and
    check if queen can be placed or not*/
        for (int i = 0; i < N; i++) {
            if ((neg[i - colo + N - 1] != 1 &&
                    dia[i + colo] != 1) && col[i] != 1) {

                onBoard[i][colo] = 1;
                neg[i - colo + N - 1] =
                        dia[i + colo] = col[i] = 1;

                if (solveUtil(onBoard, colo + 1))
                    return true;

                onBoard[i][colo] = 0; // BACKTRACK
                neg[i - colo + N - 1] =
                        dia[i + colo] = col[i] = 0;
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

    // Driver Code
    public static void main(String[] args)
    {
        solBoard();
    }
}