/* The n-queens puzzle is the problem of placing n queens 
on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle. */


/* Function to get the number of way N queens can be placed on a NxN chess board */
const totalNQueens = (n) => {
    
    /* Helper Function */
    const getTotalWays = (board, row, col, n) => {

        /* Base case when we filled each and every row */
        if(row == n){
            return true;
        }
        
        /* Checking every column in a particular row */
        for(let i=col; i<n; i++){

            /* Checking if a queen is already placed in that particular spot */
            if(!board[row][i]){
                /* Placing a queen in that spot */
                board[row][i] = true;

                /* Checking the validity of our move and continuing to place queens in the next row */
                if(validMove(board, row, i, n) && getTotalWays(board, row+1, 0, n)){
                    /* Incrementing our answer if n queens are placed on the chessboard */
                    ans++;
                }

                /* Removing the queen in that spot to get a different combination */
                board[row][i] = false;
            }
        }

        /* Returning false if we cannot place any queens in that row */
        return false;
    }
            

    /* Function to check the validity of our move */
    const validMove = (board, row, col, n) => {
        return validCol(board, row, col, n) &&
            validRow(board, row, col, n) && 
            validRightUpperDiagonal(board, row, col, n) && 
            validRightLowerDiagonal(board, row, col, n) && 
            validLeftUpperDiagonal(board, row, col) && 
            validLeftLowerDiagonal(board, row, col, n)
    }
            

    /* Function to check if no two queens can kill each other in their respective columns */
    const validCol = (board, row, col, n) => {
        let count = 0;
        for(let i=0; i<n; i++){
            if(board[i][col]){
                count++;
            }
            if(count > 1){
                return false;
            }
        }
        return true;
    }
            
    /* Function to check if no two queens can kill each other in their respective row */
    const validRow = (board, row, col, n) => {
        let count = 0;
        for(let i=0; i<n; i++){
            if(board[row][i]){
                count++;
            }
            if(count > 1){
                return false;
            }
        }
        return true;
    }
            
    /* Function to check if no two queens can kill each other in their respective right upper diagonal */
    const validRightUpperDiagonal = (board, row, col, n) => {
        let r = row-1;
        let c = col+1;
        let count = 0;
        while(r>=0 && c<n){
            if(board[r][c]){
                count++;
            }
            if(count > 0){
                return false;
            }
            r--;
            c++;
        }
        
        return true;
    }
    
    /* Function to check if no two queens can kill each other in their respective right lower diagonal */
    const validRightLowerDiagonal = (board, row, col, n) => {
        let r = row+1;
        let c = col+1;
        let count = 0;
        while(r<n && c<n){
            if(board[r][c]){
                count++;
            }
            if(count > 0){
                return false;
            }
            r++;
            c++;
        }
            
        return true;
    }
            
    /* Function to check if no two queens can kill each other in their respective left upper diagonal */
    const validLeftUpperDiagonal = (board, row, col) => {
        let r = row-1;
        let c = col-1;
        let count = 0;
        while(r>=0 && c>=0){
            if(board[r][c]){
                count++;
            }
            if(count > 0){
                return false;
            }
            r--;
            c--;
        }
            
        return true;   
    }
            
    /* Function to check if no two queens can kill each other in their respective left lower diagonal */
    const validLeftLowerDiagonal = (board, row, col, n) => {
        let r = row+1;
        let c = col-1;
        let count = 0;
        while(r<n && c>=0){
            if(board[r][c]){
                count++;
            }
            if(count > 0){
                return false;
            }
            r++;
            c--;
        }
            
        return true;   
    }

    const createRow = ()=>{
        return new Array(n).fill(false);
    }
    

    /* Creating an empty board */
    let board = new Array(n).fill(null).map(createRow);

    let ans = 0;

    /* Gets the total number of way N Queens can be placed */
    getTotalWays(board, 0, 0, n);
    
    /* Returning the answer */
    return ans;
};

/* Printing the answer for 10x10 chessboard -> Ans = 724 ways */
console.log(`${totalNQueens(10)} ways`);


/*Example 1

Input :
4

Output :
2

Explanation :
There are only two possible ways to place 4 Queens on a 4x4 chessboard

Example 2

Input :
10

Output :
724

Explanation :
There are 724 possible ways to place 10 Queens on a 10x10 chessboard


Time Complexity : O(N^N)
Space Complexity : O(NxN)
*/

