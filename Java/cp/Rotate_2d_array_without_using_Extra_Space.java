//You are given an n x n 2D matrix representing an image.
//
//        Rotate the image by 90 degrees (clockwise).
//
//        You need to do this in place.
//
//        Note that if you end up using an additional array, you will only receive partial score.
//
//        Example:
//
//        If the array is
//
//        1 2 3 4 5 6 7 8 9
//
//        Then the rotated array becomes:
//
//        7 4 1 8 5 2 9 6 3
//
//        Input:
//
//        The first line contains an integer 'T' denoting the total number of test cases.
//        In each test cases, the first line contains an integer 'N' denoting the size of the 2D square matrix.
//
//        And in the second line, the elements of the matrix A[][], each separated by a space in row major form.



//Input:
//
//        2
//        3
//        1 2 3 4 5 6 7 8 9
//        2
//        56 96 91 54
//
//        Output:
//
//        7 4 1 8 5 2 9 6 3
//        91 56 54 96


/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main (String[] args) {
        //code
        Scanner s=new Scanner(System.in);
        int t=s.nextInt();
        while (t>0){
            int n=s.nextInt();
            int[][] arr=new int[n][n];
            for (int i = 0; i <n ; i++) {
                for (int j = 0; j <n ; j++) {
                    arr[i][j]=s.nextInt();

                }

            }
            for (int j = 0; j <n ; j++) {
                for (int i = n-1; i >=0 ; i--) {
                    System.out.print(arr[i][j]+" ");

                }

            }
            System.out.println();
            t--;

        }
    }
}