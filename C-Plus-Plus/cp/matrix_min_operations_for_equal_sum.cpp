/*
Problem: The input is n x n square matrix. The output is minimum number of operations required to convert input
matrix into the matrix in which sum of elements of each row & column is equal. One operation means incrementing any value of 
cell of matrix by 1. Also, the converted matrix is displayed on screen.
For Ex: I/P = 2
1 2
3 4

O/P : 4
4 3
3 4
In above example, input matrix is converted so that sum of each row and column of output matrix is 7. The minimum number of
operations required to do so are 4.

Solution: In find_min_steps function, first the sum of individual row and column is stored in 2 arrays, one for
storing sum of rows & other for sum of columns. The maximum of both the arrays is calculated(i.e maximum of sum of cells 
in individual rows & columns.) By iterating over the matrix and performing addition wherever required the sum of all 
individual rows & columns is made equal to maximum sum.
*/

#include<iostream>
using namespace std ;

//Function that converts matrix into matrix which contains equal row and column sum & returns number of operations required to do so.
int find_min_steps(int fn , int **finput_matrix)
{
    int *rowSum = NULL, *columnSum = NULL ;
    int i = 0, j = 0, maxSum = 0, operations = 0, diff = 0 ;

    /*
    Assigning memory to 2 sum arrays. rowSum stores the sum of cells of individual rows & columnSum stores the sum
    of cells of individual columns.
    */
    rowSum = new int[fn] ;
    columnSum = new int[fn] ;

    //Calculating sum of cells of each row and column and storing it in array rowSum & columnSum respectively.
    for(i=0 ; i<fn ; ++i)
    {
        for(j=0 ; j<fn ; ++j)
        {
            rowSum[i] = rowSum[i] + finput_matrix[i][j] ;
            columnSum[j] = columnSum[j] + finput_matrix[i][j] ;
        }
    }

    //Finding the maximum sum(i.e array element) among 2 arrays rowSum & columnSum.
    for(i=0 ; i<fn ; ++i)
    {
        maxSum = max(maxSum , columnSum[i]) ;
        maxSum = max(maxSum , rowSum[i]) ;
    }

    //i is counter for rows and j is counter for columns
    for(i=0, j=0 ; i<fn && j<fn ;)
    {
        /*
        We calculate the difference between maximum sum and sum of elements of ith row and jth column respectively.This
        minimum difference is added to the element [i][j]. Minimum among the both differences is considered so as to avoid
        increasing any row or column sum beyond the maximum sum.
        As the value of [i][j] th element is increased by diff, this diff has to be added in sum arrays rowSum[i] & columnSum[j].
        According to the problem statement, one operation means addition by one, hence the difference has to be added in number of
        operations as well.
        */
        diff = min(maxSum - rowSum[i] , maxSum - columnSum[j]) ;
        finput_matrix[i][j] = finput_matrix[i][j] + diff ;
        rowSum[i] = rowSum[i] + diff ;
        columnSum[j] = columnSum[j] + diff ;
        operations = operations + diff ;

        //If sum of elements in i th row becomes equal to maximum sum, we move on to the next row.Hence i is incremented.
        if(rowSum[i] == maxSum)
        {
            i = i + 1 ;
        }
        //If sum of elements in j th column becomes equal to maximum sum, we move on to the next column. Hence j is incremented
        if(columnSum[j] == maxSum)
        {
            j = j + 1 ;
        }
    }

    //Deallocate memory assigned to rowSum & columnSum array.
    delete[] rowSum ;
    delete[] columnSum ;

    return operations ;
}

int main(void)
{
    int **input_matrix = NULL ;
    int n = 0, i = 0, j = 0, min_operations  = 0 ;

    //Taking the input as number of rows and columns
    cout << "Enter the size of square matrix : " << endl ;
    cin >> n ;

    //Assigning the memory to the 2-D array according to given matrix size.
    input_matrix = new int*[n] ;
    for(i=0 ; i<n ; ++i)
    {
        input_matrix[i] = new int[n] ;
    }

    cout << "Enter the elements of matrix in row wise manner separated by space : " << endl ;
    //Taking user input as each element of matrix.
    for(i=0 ; i<n ; ++i)
    {
        for(j=0 ; j<n ; ++j)
        {
            cin >> input_matrix[i][j] ;
        }
    }

    //Calling the function find_min_steps
    min_operations = find_min_steps(n , input_matrix);

    //Display the number of operation and converted matrix on the screen.
    cout <<"The number of operations required = "<<min_operations<< endl;
    cout << endl << "The converted matrix with equal row & column sum:  " << endl ;
    for(i=0 ; i<n ; ++i)
    {
        for(j=0 ; j<n ; ++j)
        {
            cout << input_matrix[i][j] << "  " ;
        }
        cout << endl ;
    }

    //Deallocate the memory assigned to the input matrix.
    for(i=0 ; i<n ; ++i)
    {
        delete[] input_matrix[i] ;
    }
    delete[] input_matrix ;

    return 0 ;
}

/*
Sample I/O :
I/O:
3
1 2 3 4 5 6 7 8 9

O/P:
27
13 8  3
4  8  12
7  8  9

Explanation: Here, matrix size is 3 i.e 3x3 matrix.n next line each element of matrix is entered in row wise manner
separated by space. So input matrix is :   1 2 3
                                           4 5 6
                                           7 8 9
Maximum sum in this matrix is of last row i.e 7+8+9 = 24. So sum of each row and column is made equal to 24 by
performing addition. The minimum number of operations needed to convert input matrix is 27.


Time Complexity: O(n^2)
 Space Complexity: O(n)
*/

