#include <bits/stdc++.h>
using namespace std;

int kadane(int* arr, int n){
    int curr_sum = 0, best_sum = 0;
    int flag = -1;
    for(int i = 0; i < n; i++){
        curr_sum += arr[i];
        if(best_sum < curr_sum){
            best_sum = curr_sum;
            flag = 0;
        }
        if(curr_sum < 0)
            curr_sum = 0;
    }
    if(flag != -1)
    	return best_sum;
    best_sum = INT_MIN;
    for(int i = 0; i < n; i++){
        best_sum = max(arr[i], best_sum);
    }
    return best_sum;
}

int maxSumRect(int** input, int row, int col){
    int maxSum = INT_MIN,sum;
    for(int l = 0; l < col; l++){
        int* arr = new int[row];
        fill(arr, arr+row, 0);
        for(int r = l; r < col; r++){
            for(int i = 0; i < row; i++){
                arr[i] += input[i][r];
            }
            sum = kadane(arr, row);
            maxSum = max(maxSum, sum);
        }
        delete[] arr;
    }
    return maxSum;
}

int main()
{
    int row,col;
    cout << "Enter no. of rows and columns: " << endl;
    cin >> row >> col;
    cout << "Enter matrix elements: " << endl;
    int** input = new int*[row];
    for(int i = 0; i < row; i++){
        input[i] = new int[col];
        for(int j = 0; j < col; j++){
            cin >> input[i][j];
        }
    }
    
    cout << "Maximum Sum is: " << maxSumRect(input, row, col) << endl;
    
    for(int i = 0; i < row; i++){
        delete[] input[i];
    }
    delete[] input;
    return 0;
}

/*
Sample input/output:
Enter no. of rows and columns:                                                                                                
4 5                                                                                                                           
Enter matrix elements:                                                                                                        
1 2 -1 -4 -20                                                                                                                 
-8 -3 4 2 1                                                                                                                   
3 8 10 1 3                                                                                                                    
-4 -1 1 7 -6                                                                                                                  
Maximum Sum is: 29  

Time Complexity: O(cols^2 * rows) 
Space Compleity: O(rows)
*/

