// Is Sudoku Valid 

// Given an incomplete Sudoku configuration in terms of a 9x9  2-D square matrix(mat[][]) the task to check if the current 
// configuration is valid or not where a 0 represents an empty block.

// Note: Current valid configuration does not ensure validity of the final solved sudoku. 



#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int isValid(vector<vector<int>> mat){
        int a[9][9], b[9][9], s[3][3][9];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(s, 0, sizeof(s));
        int number;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (mat[i][j] > 0 && mat[i][j] <= 9) {
                    number = mat[i][j] - 1;
                    if (a[i][number]) 
                        return 0;
                    a[i][number] = 1;
                    if (b[j][number]) 
                        return 0;
                    b[j][number] = 1;
                    if (s[i / 3][j / 3][number]) 
                        return 0;
                    s[i / 3][j / 3][number] = 1;
                }
            }
        }
        return 1;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  

// Example:

// Input: mat[][] = [
// [3, 0, 6, 5, 0, 8, 4, 0, 0]
// [5, 2, 0, 0, 0, 0, 0, 0, 0]
// [0, 8, 7, 0, 0, 0, 0, 3, 1]
// [0, 0, 3, 0, 1, 0, 0, 8, 0]
// [9, 0, 0, 8, 6, 3, 0, 0, 5]
// [0, 5, 0, 0, 9, 0, 6, 0, 0]
// [1, 3, 0, 0, 0, 0, 2, 5, 0]
// [0, 0, 0, 0, 0, 0, 0, 7, 4]
// [0, 0, 5, 2, 0, 6, 3, 0, 0]
// ]
// Output: 1
// Explaination: It is possible to have a proper sudoku with the given input.