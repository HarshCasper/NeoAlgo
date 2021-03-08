package com.company;


import java.util.*;

class Main {
    public static void main(String[] args)
    {
        /*Sorting a matrix may look tough but you have to view a matrix as a collection of arrays. If you see it as an array, you can sort it by using any custom sorting algorithm, I will be using Arrays.sort(ARRAY_NAME) here which uses QuickSort. If we copy the matrix elements to a temporary array of size number of rows*number of columns of the matrix at hand and sort it and copy it back, we can get the sorted matrix. The approach may seem to be simple but it is a good practice for beginners to know they can solve problems by brute force at first before optimizing the code*/
        Scanner abc=new Scanner(System.in);
        int rows=abc.nextInt();
        int cols=abc.nextInt();
        int matrix[][]=new int[rows][cols];
        //taking the matrix as input taking O(n*m) time complexity where n=rows and m=cols
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                matrix[i][j]=abc.nextInt();
        }
        //creating a temporary 1D array
        int temporary[]=new int[rows*cols];
        //display the matrix and copy it to the temp array
        int k=0;//iterating and storing elements in the temp array
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++) {
                System.out.print(matrix[i][j]+"  ");
                temporary[k++] = matrix[i][j];
            }
            System.out.println();
        }
        System.out.println();
        //sort the temporary array. This takes 0(nlogn) time where n is the size of the array-->here is rows*cols
        Arrays.sort(temporary);
        k=0;
        //copy it back to the main matrix
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                matrix[i][j]=temporary[k++];

        }
        //display final state of original matrix
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++) {
                System.out.print(matrix[i][j]+"  ");
            }
            System.out.println();
        }
        /*
        overall time complexity is (n^2)+2(n^2)logn making it O(n^2logn)
        overall space complexity is O(n^2)
        */
        /*INPUT:4
3
34
-45
0
23
99
1234
89
1
0
23
-99
-345 */
        /*OUTPUT
34  -45  0
23  99  1234
89  1  0
23  -99  -345

-345  -99  -45
0  0  1
23  23  34
89  99  1234   */
    }
}