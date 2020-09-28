import java.util.Scanner;

public class SudokuSolver {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter elements of unsolved sudoku. Type 0 for empty cells:");
        int[][] sudokuArr = new int[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                sudokuArr[i][j] = scanner.nextInt();
            }
        }
        scanner.close();

        if (solveSudoku(sudokuArr)) {
            System.out.println("Solved sudoku:");
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    System.out.print(sudokuArr[i][j]+ ", ");
                }
                System.out.println();
            }
        } else {
            System.out.println("Unsolvable");
        }
    }

    private static boolean solveSudoku(int[][] sudokuArr) {
        int row = -1, col = -1;
        boolean isEmpty = true;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (sudokuArr[i][j] == 0) {
                    row = i;
                    col = j;

                    // we still have some remaining
                    // missing values in Sudoku
                    isEmpty = false;
                    break;
                }
            }
            if (!isEmpty) {
                break;
            }
        }

        if (isEmpty) {
            return true;
        }

        for (int i = 1; i <= 9; i++) {
            if (isSafe(sudokuArr, row, col, i)) {
                sudokuArr[row][col] = i;
                if (solveSudoku(sudokuArr)) {
                    return true;
                }
                else {
                    sudokuArr[row][col] = 0;
                }
            }
        }

        return false;
    }

    private static boolean isSafe(int[][] sudokuArr, int row, int col, int i) {
        for (int d = 0; d < 9; d++) {
            if (sudokuArr[row][d] == i) {
                return false;
            }
        }

        for (int r = 0; r < 9; r++) {
            if (sudokuArr[r][col] == i) {
                return false;
            }
        }

        int rowStart = row - (row % 3);
        int colStart = col - (col % 3);
        for (int r = rowStart; r < rowStart + 3; r++) {
            for (int d = colStart; d < colStart + 3; d++) {
                if (sudokuArr[r][d] == i) {
                    return false;
                }
            }
        }

        return true;
    }
}

/*
* Sample input/output:
* Enter elements of unsolved sudoku. Type 0 for empty cells:
* 3 0 6 5 0 8 4 0 0
* 5 2 0 0 0 0 0 0 0
* 0 8 7 0 0 0 0 3 1
* 0 0 3 0 1 0 0 8 0
* 9 0 0 8 6 3 0 0 5
* 0 5 0 0 9 0 6 0 0
* 1 3 0 0 0 0 2 5 0
* 0 0 0 0 0 0 0 7 4
* 0 0 5 2 0 6 3 0 0
* Solved sudoku:
* 3, 1, 6, 5, 7, 8, 4, 9, 2,
* 5, 2, 9, 1, 3, 4, 7, 6, 8,
* 4, 8, 7, 6, 2, 9, 5, 3, 1,
* 2, 6, 3, 4, 1, 5, 9, 8, 7,
* 9, 7, 4, 8, 6, 3, 1, 2, 5,
* 8, 5, 1, 7, 9, 2, 6, 4, 3,
* 1, 3, 8, 9, 4, 7, 2, 5, 6,
* 6, 9, 2, 3, 5, 1, 8, 7, 4,
* 7, 4, 5, 2, 8, 6, 3, 1, 9,
*
* Time complexity: O(9^(n*n))
* Space Complexity: O(n*n)
*/
