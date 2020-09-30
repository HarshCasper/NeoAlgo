#include <bits/stdc++.h>
using namespace std;

int maxSizeSquareWithOnes(int** input, int row, int col, int i, int j, int* ans, int** output){
    if(i == 0 || j == 0){
        output[i][j] = input[i][j];
        return input[i][j];
    }
    if(i < 0 || j < 0)
        return INT_MAX;
    if(output[i][j] > -1)
        return output[i][j];
    int option1 = maxSizeSquareWithOnes(input, row, col, i-1, j, ans, output);
    int option2 = maxSizeSquareWithOnes(input, row, col, i-1, j-1, ans, output);
    int option3 = maxSizeSquareWithOnes(input, row, col, i, j-1, ans, output);
    int res = min(option1, min(option2, option3));
    if(input[i][j] == 1)
        res++;
    if(input[i][j] == 0)
        res = 0;
    *ans = max(*ans, res);
    output[i][j] = res;
    return res;
}

int main()
{
    int row,col;
    cout << "Enter number of rows and colums: " << endl;
    cin >> row >> col;
    int** input = new int*[row];
    int** output = new int*[row];
    cout << "Enter elements for input matrix: " << endl;
    for(int i = 0; i < row; i++){
        input[i] = new int[col];
        output[i] = new int[col];
        for(int j = 0; j < col; j++){
            cin >> input[i][j];
            output[i][j] = -1;
        }
    }

    int ans = INT_MIN;
    maxSizeSquareWithOnes(input, row, col, row-1, col-1, &ans, output);
    cout << "Size of Maximum Square Matrix with all 1s is: " << ans << endl;

    for(int i = 0; i < row; i++){
        delete[] input[i];
        delete[] output[i];
    }
    delete[] input;
    delete[] output;
    return 0;
}

/*
Sample input/output:
Enter number of rows and colums:                                                                                                
6 5                                                                                                                             
Enter elements for input matrix:                                                                                                
0 1 1 0 1                                                                                                                       
1 1 0 1 0                                                                                                                       
0 1 1 1 0                                                                                                                       
1 1 1 1 0                                                                                                                       
1 1 1 1 1                                                                                                                       
0 0 0 0 0                                                                                                                       
Size of Maximum Square Matrix with all 1s is: 3 

Time complexity = O(rows * cols)
Space complexity = O(rows * cols)
*/