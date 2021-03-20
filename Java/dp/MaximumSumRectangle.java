import java.util.Scanner;

public class MaximumSumRectangle {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter number of rows and columns:");
        int r = scanner.nextInt();
        int c = scanner.nextInt();
        int[][] matrix = new int[r][c];
        System.out.println("Enter elements of the matrix:");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        System.out.println("Maximum sum is:" + maxSum(matrix));
    }

    private static int maxSum(int[][] matrix) {

        int r = matrix.length;
        int c = matrix[0].length;
        int[][] prevSum = new int[r + 1][c];

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                prevSum[i + 1][j] = prevSum[i][j] + matrix[i][j];
            }
        }

        // solving with the method of Kadane's Algorithm
        int maxSum = -1;
        int minSum = Integer.MIN_VALUE;
        int negRow = 0, negCol = 0;
        int rStart = 0, rEnd = 0, cStart = 0, cEnd = 0;
        for(int rowBegin = 0; rowBegin < r; rowBegin++) {
            for(int row = rowBegin; row < r; row++){
                int sum = 0;
                int curColStart = 0;
                for(int col = 0; col < c; col++) {
                    sum += prevSum[row + 1][col] - prevSum[rowBegin][col];
                    if(sum < 0) {
                        if(minSum < sum) {
                            minSum = sum;
                            negRow = row;
                            negCol = col;
                        }
                        sum = 0;
                        curColStart = col + 1;
                    }
                    else if(maxSum < sum) {
                        maxSum = sum;
                        rStart = rowBegin;
                        rEnd = row;
                        cStart = curColStart;
                        cEnd = col;
                    }
                }
            }
        }

        return maxSum == -1 ? minSum : maxSum;
    }
}
/*
* Sample input/output:
* Enter number of rows and columns:
* 4 5
* Enter elements of the matrix:
* 1 2 -1 -4 -20
* -8 -3 4 2 1
* 3 8 10 1 3
* -4 -1 1 7 -6
* Maximum sum is:29
*
* Time complexity: O(n^3)
*/
