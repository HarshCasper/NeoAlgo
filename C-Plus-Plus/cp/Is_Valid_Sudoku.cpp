/*
Introduction 
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
- Each row must contain the digits 1-9 without repetition.
- Each column must contain the digits 1-9 without repetition.
- Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
- A Sudoku board (partially filled) could be valid but is not necessarily solvable.
- Only the filled cells need to be validated according to the mentioned rules.

Argument/Return Type
Input of 9x9 matrix is taken
A function which returns bool is implemented
*/

#include <bits/stdc++.h> 
using namespace std;

// Function to determine if the sudoku is valid
bool isValidSudoku(vector<vector<char>>& sudoku) 
{
    /*Define 2D maps to store presence of already visited values 
      row wise , column wise and box wise */
    map<int,map<int,int>>row;
    map<int,map<int,int>>col;
    map<int,map<int,int>>box;

    // Now Traverse to every cell
    for(int rowInd=0;rowInd<=8;rowInd++)
    {
       //In each row visit all cells column wise
       for(int colInd=0;colInd<=8;colInd++)
       {
           // If the cell is not empty
           if( sudoku[rowInd][colInd] != '.')
            {
                // Get the relative ASCII value of character 
                int value = sudoku[rowInd][colInd]-'0';

                /* Check if the this value is already present in 
                   the column or row or box to which this value belongs to */
                bool isPresentInRow = row[value][rowInd];
                bool isPresentInCol = col[value][colInd];
                bool isPresentInBox = box[value][3*(rowInd/3)+(colInd/3)];
                if(isPresentInRow || isPresentInCol || isPresentInBox)   
                {
                   /*If it is present in any of them already
                    It means that the sudoku is not valid */
                   return false; 
                }    
                else
                {
                   /* else if value is not present in any of them 
                      increment corresponding map values 
                      to indicate the prescence of this value */
                    row[value][rowInd]++;
                    col[value][colInd]++;
                    box[value][3*(rowInd/3)+(colInd/3)]++;
                }    
            }
       }
    }
    //If vailidity is not failed for any cell return true
    return true;   
}


// Driver code
int main()
{
    //create a vector to take input and store them
    vector<vector<char>>sudoku;

    for(int row=0;row<9;row++)
    {
        cout<<"Enter cell values of row "<<row+1<<" with spaces between them , If any cell is empty enter '.' : ";
        vector<char>rowValues;
        for(int col=0;col<9;col++)
        {
           char value;
           cin>>value;
           rowValues.push_back(value);
        }
        sudoku.push_back(rowValues);
    }   

    //Call the function and print the result
    if(isValidSudoku(sudoku))
        cout<<"Hence the given sudoku is valid";
    else
        cout<<"Hence the given sudoku is not valid";

    return 0; 
}
    
/*
Input:
1 <= cell value <= 9
If cell is empty '.' is entered

Sample Test Case 1  

Input Format : 
Example :
Enter cell values of row 1 with spaces between them , If any cell is empty enter '.' : 5 3 . . 7 . . . .
Enter cell values of row 2 with spaces between them , If any cell is empty enter '.' : 6 . . 1 9 5 . . .
Enter cell values of row 3 with spaces between them , If any cell is empty enter '.' : . 9 8 . . . . 6 .
Enter cell values of row 4 with spaces between them , If any cell is empty enter '.' : 8 . . . 6 . . . 3
Enter cell values of row 5 with spaces between them , If any cell is empty enter '.' : 4 . . 8 . 3 . . 1
Enter cell values of row 6 with spaces between them , If any cell is empty enter '.' : 7 . . . 2 . . . 6
Enter cell values of row 7 with spaces between them , If any cell is empty enter '.' : . 6 . . . . 2 8 .
Enter cell values of row 8 with spaces between them , If any cell is empty enter '.' : . . . 4 1 9 . . 5
Enter cell values of row 9 with spaces between them , If any cell is empty enter '.' : . . . . 8 . . 7 9

Output Format :
Example : ( Output to the above input example ) 
Hence the given sudoku is valid

Time/Space Complexity
Time Complexity : O(1) 
Space Complexity : O(1) 

*/
