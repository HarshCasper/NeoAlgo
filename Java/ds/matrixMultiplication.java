/*
  MatrixMultiplication code helps in taking input as 2 matrices of any order and prints their product.
*/

import java.io.*;
import java.util.*;

public class matrixMultiplication{

    public static void main(String[] args) throws Exception {
      Scanner s = new Scanner(System.in);
    //    Taking input as matrix1:
        System.out.println("Enter the no. of rows of the first matrix:");
        int row1 = s.nextInt();
        System.out.println("Enter the no. of cols of the first matrix:");
        int col1 = s.nextInt();
        int[][] mat1 = new int[row1][col1];
        System.out.println("Enter the elements of the first matrix:");
        for (int i = 0; i < row1; i++) {
            for (int j = 0; j < col1; j++) {
                mat1[i][j] = s.nextInt();
            }
        }
    //    Taking input as matrix2:
        System.out.println("Enter the no. of rows of the second matrix:");
        int row2 = s.nextInt();
        System.out.println("Enter the no. of cols of the second matrix:");
        int col2 = s.nextInt();
        int[][] mat2 = new int[row2][col2];
        System.out.println("Enter the elements of the second matrix:");
        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < col2; j++) {
                mat2[i][j] = s.nextInt();
            }
        }

        if (col1 == row2) {
            int ans[][] = matrixMul(mat1, mat2);
            display(ans);
        } else System.out.print("Invalid input");
        s.close();
    }

    public static int[][] matrixMul(int[][] arr1, int[][] arr2) {
        int[][] res = new int[arr1.length][arr2[0].length];
        for (int i = 0; i < arr1.length; i++) {
            for (int j = 0; j < arr2[0].length; j++) {
                res[i][j] = 0;
                for (int k = 0; k < arr1[0].length; k++) {
                    res[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        return res;
    }
    public static void display(int [][] mat){
        for (int i=0;i<mat.length;i++){
            for (int j=0;j<mat[0].length;j++){
                System.out.print(mat[i][j] +" ");
            }
            System.out.println();
        }
    }

    }

    /*
    Sample Input/Output:

    Input:
    2
    2
    1 2
    3 4
    2
    2
    5 6
    7 8

    Output:
    19 22
    43 50

    Time Complexity:O(n^2)
    Space Complexity:O(n)
    */
