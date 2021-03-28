/*
* Matrix is the Two-Dimensional Model
* Matrix is the combination of rows and columns,here the rows are n & columns are m
* size = n x m
* Transpose of the matrix is swapping of the rows and columns in the given matrix
* Following code gives the output of the transpose of the matrix
*/

import java.util.Scanner;

public class Matrix_Transpose 
{
	//Function for the transpose
	public static void transpose(int[][] a,int[][] b, int n , int m) 
	{
		int i=0, j=0;
		
	    	for(i=0;i<m;i++)
    		{
	    		for(j=0;j<n;j++)
	    		{
				//Each element of the transpose is assigned
				b[i][j]=a[j][i]; 
	    		}
    		}
	}
	
	public static void main(String[] args) 
	{
		//To read inputs from the users Scanner is used
		Scanner sc = new Scanner(System.in);
		//To read number of rows required in the matrix as per user 
		System.out.println("Enter number of rows:");
		int n = sc.nextInt(); 
		//To read number of columns required in the matrix as per user 
		System.out.println("Enter number of columns:");
		int m = sc.nextInt(); 
		int i=0,j=0;
		//Assigning the memory to the 2-D array according to given matrix size
		int[][] a = new int[n][m];
		int[][] b = new int[m][n]; 
		System.out.println("Enter matrix elements:");
	    	for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
			        //Taking user inputs(elements) of the matrix
				a[i][j]=sc.nextInt();
			}

			System.out.println();
		}
	    
	     	System.out.println("Given Matrix elements are:");
	    	for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				System.out.print(a[i][j]+" ");
			}

			System.out.println();
		}
	   	transpose(a, b , n , m);
	        System.out.println("Transpose of Matrix:");
	        for(i=0;i<m;i++)
	   	{
		   	for(j=0;j<n;j++)
		   	{
		   		//Printing the elements of the matrix after transpose calculation
		   		System.out.print(b[i][j]+" ");
		   	}
		   	System.out.println();
	   	}
	}
}
	
/*
Sample Input:

Enter number of rows:
2
Enter number of columns:
3
Enter matrix elements:
10 20 30 40 50 60

Sample Output:

Given Matrix elements are:
10 20 30 
40 50 60 

Transpose of Matrix:
10 40 
20 50 
30 60 

Explanation:
*Inputs, rows are 2 and columns are 3 
* On the next line all the elements of the matrix have been entered
10 20 30 40 50 60
* Then, the code gives output for the transpose.
 
 
 Time Complexity : theta(nm) where, n = number of rows & m = number of columns
 Space Complexity : Transpose matrix requires extra memory space, theta(nm)
 
*/
