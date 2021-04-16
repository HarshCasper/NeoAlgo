//Program in C++ to multiply two matrices

# include <iostream>

using namespace std;

int main()
{
    //Declaring the variables to store number of rows and columns in both matrices
    //r1 stores number of rows in 1st matrix
    //c1 stores number of columns in 1st matrix
    //r2 stores number of rows in 2nd matrix
    //c2 stores number of columns in 2nd matrix

    int r1,c1,r2,c2;

    //Taking the number of rows and columns in both matrices as input from user

    cout<<"Enter the number of rows and columns in Ist Matrix "<<endl;
    cin>>r1>>c1;

    cout<<"Enter the number of rows and columns in 2nd Matrix "<<endl;
    cin>>r2>>c2;

    //Declaring the 2-D arrays to store input matrices and resultant product matrix
    //Taking maximum number of elements in a matrix to be 10^4
    //A stores 1st input matrix
    //B stores 2nd input matrix
    //P stores product of the matrices

    long A[100][100],B[100][100],P[100][100];
    
    //Declaring the iteration variables
    int i,j,k;

    //Taking the first matrix as input
    cout<<"Enter the elements of 1st matrix"<<endl;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            cin>>A[i][j];
        }
    }

     //Taking the second matrix as input
     cout<<"Enter the elements of 2nd matrix"<<endl;
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            cin>>B[i][j];
        }
    }

    //check if the two matrices are multiplicable or nor
    //To do this check if the number of columns in first matrix is equal to the number of rows in the second matrix

    if(c1==r2)
    {
        //The size of product matrix thus created will be r1 X c2
        //Hence first loop runs r1 times
        for(i=0;i<r1;i++)
        {
            //The second loop runs c2 times
            for(j=0;j<c2;j++)
            {

                //Initializing every element of the product matrix as 0
                P[i][j]=0;

                //This loop will run c1 or r2 times(both are same)
                //To multiply every element in i'th row of 1st matrix to every element in j'th column of 2nd matrix
                //Then add these products to the corresponding element of product matrix to get P[i][j]

                for(k=0;k<r2;k++)
                {
                    P[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
    }

    //if the above condition is not satisfied then the matrices are not multiplicable
    else
    {
        cout<<"Matrices are not multiplicable"<<endl;
    }

    //displaying the resultant product matrix
    cout<<"The product matrix is"<<endl;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



/*Test Case 1
Enter the number of rows and columns in Ist Matrix 
2 3
Enter the number of rows and columns in 2nd Matrix 
3 4
Enter the elements of 1st matrix
1 2 3
4 5 6
Enter the elements of 2nd matrix
1 2 1 2
1 2 1 2
1 2 1 2
The product matrix is
6 12 6 12
15 30 15 30

Test case 2
Enter the number of rows and columns in Ist Matrix 
1 3
Enter the number of rows and columns in 2nd Matrix
3 3
Enter the elements of 1st matrix
233 455 644
Enter the elements of 2nd matrix
1 0 0
0 1 0
0 0 1
The product matrix is
233 455 644
*/



/* Time complexity
Time taken for program to run to completion=(r1*c2*r2)T+2T
where T is the time taken for execution of single operation
all are input from user, for worst case all three (r1,c2,r2) are assumed to be very large numbers say n
Worst case time complexity=O(n^3)

Space Complexity
Memory occupied by program=(r1*c2)m+3m
Assuming r1 and c2 to be very large in worst case
Space Complexity=n^2
*/