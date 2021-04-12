

/* 
Largest Row or Column

-For a given two-dimensional integer array/list of size (N x M), 
you need to find out which row or column has the largest  sum(sum of all
the elements in a row/column) amongst all the rows and columns.

Note: If there are more than one rows/columns with maximum sum, 
consider the row/column that comes first. And if ith row and jth column
has the same largest sum, consider the ith row as answer.
*/
import java.util.Scanner;
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
 public static void findLargest(int mat[][]){
		
         int sum=Integer.MIN_VALUE;
         int col=Integer.MIN_VALUE;
         int row=0;
         int col1=0;
         
        
         if(mat.length==0 || mat[0].length==0){
            System.out.print("row" + " "+ 0 +" "+ -2147483648);
         }
        else{
           for(int i=0;i<mat.length;i++){
             int sumit=0;
             for(int j=0;j<mat[i].length;j++) {
                    sumit+=mat[i][j];
                          
              }
              if(sumit>sum){
                    sum=sumit;
                    row=i;
              }
            
          }
          for(int k=0;k<mat[0].length;k++){
              int sum_col=0; 
              for(int m=0; m<mat.length ;m++){
                  sum_col+=mat[m][k];
              }
              if (sum_col>col){
                  col=sum_col;
                  col1=k;
                  
              }
              
           }
            
           if(sum<col){
              System.out.print("column"+" "+col1+" "+col);
              
              }
          
           else{
             System.out.print("row"+" "+row+" "+sum);
        } 
       }
 
  }  
}



public class LargestRowOrColumn {
    public static void main(String[] args) {
          Scanner s1=new Scanner(System.in);
          int t=s1.nextInt();
          while (t>0)
          {
              int[][] mat = solution.take2DInput(t);

              solution.findLargest(mat);
             System.out.println();

            t -= 1;
          }
    }
    
}

/*
Sample Input 1
 1
2 2 
1 1 
1 1

Output--> 
row 0 2

Output format-->
For each test case,
If row sum is maximum, 
then print: "row" <row_index> <row_sum>
 OR
OR
If column sum is maximum,
then print: "column" <col_index> <col_sum>
*/
