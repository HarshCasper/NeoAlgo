import java.util.*;
class Main {
    public static void main(String[] args)
    {
        /*View a matrix as a collection of arrays.sort it by using any custom sorting algorithm,
        Use Arrays.sort(ARRAY_NAME) which uses QuickSort.
        Copy the matrix elements to a temporary array of size number of rows*number of columns of the matrix at hand and sort it.
        Copy it back, we can get the sorted matrix.*/
        Scanner abc=new Scanner(System.in);
        System.out.print("ENTER NUMBER OF ROWS:");
        int rows=abc.nextInt();
        System.out.print("ENTER NUMBER OF COLUMNS:");
        int cols=abc.nextInt();
        int matrix[][]=new int[rows][cols];
        //taking the matrix as input taking O(n*m) time complexity where n=rows and m=cols
        System.out.println("ENTER MATRIX ELEMENTS");
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
                matrix[i][j]=abc.nextInt();
        }
        //creating a temporary 1D array
        int temporary[]=new int[rows*cols];
        //iterating and storing elements in the temp array
        int k=0;
        //display the matrix and copy it to the temp array
        System.out.println("ORIGINAL MATRIX");
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
        System.out.println("SORTED MATRIX");
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
    /*INPUT :
    ENTER NUMBER OF ROWS:3
    ENTER NUMBER OF COLUMNS:3
    ENTER MATRIX ELEMENTS
    12
    -6
    15
    12
    0
    11
    -9
    22
    34
    OUTPUT:
    ORIGINAL MATRIX
    12  -6  15
    12  0  11
    -9  22  34

    SORTED MATRIX
    -9  -6  0
    11  12  12
    15  22  34
    */
    }
}