/*
Matrix is a 2-D array.
The transpose of a matrix is simply a flipped version of the original matrix.
Transpose of a matrix can be computed by switching its rows with its columns.
This code gives output as transpose of input matrix.
*/

#include<iostream>
using namespace std ;

//Function that computes transpose.
void transpose(int frows, int fcolumns, int **finput_matrix, int **ftranspose_matrix)
{
    int i = 0, j = 0 ;
    for(i=0 ; i<fcolumns ; ++i)
    {
        for(j=0 ; j<frows ; ++j)
        {
            //According to definition of transpose, each element of transpose matrix is assigned.
            ftranspose_matrix[i][j] = finput_matrix[j][i] ;
        }
    }
}

int main(void)
{
    int **input_matrix = NULL, **transpose_matrix = NULL ;
    int rows = 0, columns = 0, i = 0, j = 0 ;

    //Taking input as number of rows and columns.
    cout << "Enter the number of rows in matrix : " << endl ;
    cin >> rows ;
    cout << "Enter the number of columns in matrix : " << endl ;
    cin >> columns ;

    //Assigning the memory to the 2_D array according to input matrix size.
    input_matrix = new int*[rows] ;
    for(i=0 ; i<rows ; ++i)
    {
        input_matrix[i] = new int[columns] ;
    }

    cout << "Enter the elements of matrix in row wise manner separated by space : " << endl ;
    //Taking user input as each element of matrix.
    for(i=0 ; i<rows ; ++i)
    {
        for(j=0 ; j<columns ; ++j)
        {
            cin >> input_matrix[i][j] ;
        }
    }

    //Assigning the memory to the transpose matrix. It will have reversed rows and columns as that of input matrix.
    transpose_matrix = new int*[columns] ;
    for(i=0 ; i<columns ; ++i)
    {
        transpose_matrix[i] = new int[rows] ;
    }

    //Call to the function that computes the transpose.
    transpose(rows , columns , input_matrix , transpose_matrix) ;

    //Display input matrix on the screen.
    cout << "The input matrix is : " << endl ;
    for(i=0 ; i<rows ; ++i)
    {
        for(j=0 ; j<columns ; ++j)
        {
            cout << input_matrix[i][j] << " " ;
        }
        cout << endl ;
    }
    cout << endl ;

    //Display the transpose of input matrix on the screen.
    cout << "The transpose matrix of above matrix is : " << endl ; 
    for(i=0 ; i<columns ; ++i)
    {
        for(j=0 ; j<rows ; ++j)
        {
            cout << transpose_matrix[i][j] << " " ;
        }
        cout << endl ;
    }

    //Deallocate the memory assigned to input matrix as well as transpose of it.
    for(i=0 ; i<rows ; ++i)
    {
        delete[] input_matrix[i] ;
    }
    delete[] input_matrix ;

    for(i=0 ; i<columns ; ++i)
    {
        delete[] transpose_matrix[i] ;
    }
    delete[] transpose_matrix ;
    return 0 ;
}

/*
Sample I/O :
I/P :
2
3
1 2 3 4 5 6 

O/P :
1 4 
2 5
3 6

Explanation: Here, rows=2 & columns=3. On next line, each element of matrix is entered in rowwise manner separated by space.
So input matrix is:   1 2 3
                      4 5 6
The code gives output as its transpose.


Time Complexity : O(mn)  , where m = number of rows & n = number of columns
Space Complexity : Transpose matrix requires extra storage same as input matrix. So space complexity becomes O(mn).
*/

