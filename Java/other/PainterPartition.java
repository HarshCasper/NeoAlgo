import java.util.Scanner;

public class PainterPartition {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the array size, number of painters and amount of time:");
        int size = scanner.nextInt();
        int numOfPainters = scanner.nextInt();
        int time = scanner.nextInt();
        int[] boards = new int[size];
        System.out.println("Enter board sizes:");
        for (int i = 0; i < size; i++) {
            boards[i] = scanner.nextInt();
        }
        scanner.close();

        System.out.println("Total time taken:" + partition(boards, size, numOfPainters) * time);
    }

    private static int partition(int[] boards, int size, int numOfPainters) {

        // base cases
        if (numOfPainters == 1) {
            return totalLength(boards, 0, size - 1);
        }
        if (size == 1) {
            return boards[0];
        }

        int best = Integer.MAX_VALUE;

        // find minimum of all possible maximum sums of partitions of the array
        for (int i = 1; i <= size; i++) {
            best = Math.min(best, Math.max(partition(boards, i, numOfPainters - 1),
                    totalLength(boards, i, size - 1)));
        }

        return best;
    }

    private static int totalLength(int[] boards, int from, int to) {
        int total = 0;
        for (int i = from; i <= to; i++) {
            total += boards[i];
        }
        return total;
    }
}
/*
* Sample input/output:
* Enter the array size, number of painters and amount of time:
* 2 2 5
* Enter board sizes:
* 1 10
* Total time taken:50
* Enter the array size, number of painters and amount of time:
* 6 3 1
* Enter board sizes:
* 10 20 30 40 50 60
* Total time taken:90
*
* Time complexity: O(2^n)
*/
