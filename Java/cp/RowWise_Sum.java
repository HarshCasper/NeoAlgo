/*
ROW WISE SUM OF A 2D ARRAY

Question: For a given two-dimensional integer array/list of size (N x M), 
find and print the sum of each of the row elements in a single line, 
separated by a single space.

*/



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

/*
Sample Input-->
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
