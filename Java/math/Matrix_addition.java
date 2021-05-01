/*
In mathematics, matrix addition is the operation of adding two matrices by adding 
the corresponding entries together.This program takes two matrices of order n*m and 
stores it in two-dimensional array. Then, the program adds these two matrices and 
displays it on the screen.
*/

import java.util.Scanner;

class Code {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows of the first matrix");
        int n1 = sc.nextInt();
        System.out.println("Enter the number of columns of the first matrix");
        int m1 = sc.nextInt();
        System.out.println("Enter the elements of the first matrix");
        int arr_1[][] = new int[n1][m1];
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m1; j++) {
                arr_1[i][j] = sc.nextInt();
            }
        }
        System.out.println("Enter the number of rows of the second matrix");
        int n2 = sc.nextInt();
        System.out.println("Enter the number of columns of the second matrix");
        int m2 = sc.nextInt();
        System.out.println("Enter the elements of the second matrix");
        int arr_2[][] = new int[n2][m2];
        for (int i = 0; i < n2; i++) {
            for (int j = 0; j < m2; j++) {
                arr_2[i][j] = sc.nextInt();
            }
        }
        int res[][] = new int[n1][m1];
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m1; j++) {
                res[i][j] = arr_1[i][j] + arr_2[i][j];
            }
        }
        System.out.println("The result of matrix addition is :");
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < m1; j++) {
                System.out.print(res[i][j] + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}

/*
Sample I/O: 
Enter the number of rows of the first matrix 3 
Enter the number of columns of the first matrix 3 
Enter the elements of the first matrix 
1 2 3
4 5 6 
7 8 9 
Enter the number of rows of the second matrix 3 
Enter the number of columns of the second matrix 3 
Enter the elements of the second matrix 
9 8 7 
6 5 4 
3 2 1 
The result of matrix addition is : 
10 10 10 
10 10 10 
10 10 10
 
Time complexity = O(n*m) 
Space complexity = O(n*m) 
n : number of rows 
M : number of columns
 */


