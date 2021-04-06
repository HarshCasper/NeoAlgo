/*
ROW WISE SUM OF A 2D ARRAY

Question: For a given two-dimensional integer array/list of size (N x M), 
find and print the sum of each of the row elements in a single line, 
separated by a single space.
Ex :    Let arr be an 2d array such as:
          arr=[ [1 ,2],[3,4],[5,6],[7,8] ]
          then rowise sum of each row in a single line seperated by space is:
          3 7 11 15 
i.e 1+2=3, 3+4=7, 5+6=11 and 7+8=15

Input-->
1) First line contains the integer 't' which denotes number of test cases.
2) First line of each test case or query contains two integer values, 'N' and 'M',
     separated by a single space. They represent the 'rows' and 'columns' respectively,
     for the two-dimensional array/list.
3) Second line onwards, the next 'N' lines or rows represent the ith row values.

Output-->
1) For each test case, print the sum of every ith row elements in a single line separated by a single space.
2) Output for every test case will be printed in a seperate line.

Sample Input 1:
1
4 2 
1 2 
3 4 
5 6 
7 8

output-->
3 7 11 15 

Input 2-->
2
2 5 
4 5 3 2 6 
7 5 3 8 9
4 4
1 2 3 4
9 8 7 6
3 4 5 6
-1 1 -10 5

Output-->
20 32 
10 30 18 -5 

 */
package rowwise_sum;
import java.util.*;
class solution{
 public static int[][] take2DInput(int n)
    {
          Scanner s=new Scanner(System.in);
          int n_rows=s.nextInt();
           int n_cols=s.nextInt();
           
           if(n_rows==0)
           {
               return new int[0][0] ;
           }
           int mat[][]=new int[n_rows][n_cols];
           
           for(int row=0 ; row<n_rows ;row++)
           {
               for(int col=0 ; col<n_cols; col++)
               { 
                    int item=s.nextInt();
                    mat[row][col]=item;
               
               }
           }
           return mat;
           
    }
 public static void rowWiseSum(int[][] mat) {
		//Your code goes here
        if(mat.length!=0){
         int rows=mat.length;
         int cols=mat[0].length;     
         int sumit=0;
        
        for( int k=0;k<rows;k++){
            for(int j=0;j<cols;j++) {
             sumit+=mat[k][j];
                          
              }
              System.out.print(sumit+" ");
              sumit=0;
	}
   }
  }  


}

public class RowWise_Sum {        
    public static void main(String[] args) {
          Scanner s=new Scanner(System.in);
          int t=s.nextInt();
          while (t>0)
          {
              int[][] mat = solution.take2DInput(t);

              solution.rowWiseSum(mat);
             System.out.println();

            t -= 1;
          }
          
    }

}
