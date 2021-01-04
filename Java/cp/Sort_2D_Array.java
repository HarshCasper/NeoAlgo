import java.util.*;
class Sort_2D_Array {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of rows and columns");
        int m = sc.nextInt();
        int n = sc.nextInt();
        int arr[][] = new int[m][n];
        System.out.println("Enter the elements of the array");
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                arr[i][j] = sc.nextInt();

        System.out.println("Enter the column to be sorted");
        int k = sc.nextInt();
        sort(arr, k, m);

    }

    public static void sort(int[][] arr, int col, int row) {
        int max = 0, ind = -1;
        for (int j = 0; j < row - 1; j++) {
            max = arr[j][col];
            ind = -1;
            for (int i = (j + 1); i < row; i++) {
                if (arr[i][col] > max) {
                    max = arr[i][col];
                    ind = i;
                }
            }

            if (ind != -1) {
                for (int k = 0; k <= col; k++) {
                    int temp = arr[j][k];
                    arr[j][k] = arr[ind][k];
                    arr[ind][k] = temp;
                }
            }
        }
        for (int[] x : arr) {
            for (int y : x) {
                System.out.print(y + "        ");
            }
            System.out.println();
        }

    }
}
/*
Enter number of rows and columns
4
4
Enter the elements of the array
39 27 11 42
10 93 91 90
54 78 56 89
24 64 20 65
Enter the column to be sorted
3
10        93        91        90
54        78        56        89
24        64        20        65
39        27        11        42

Space Complexity : O(1)
Time Complexity : O(m^2)
 */
