import java.util.*;

public class CatalanNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number: ");
        int num = sc.nextInt();
        System.out.println();
        int[] arr = new int[num + 2];
        arr[0] = 1;
        arr[1] = 1;
        for (int i = 1; i <= num; i++) {
            for (int j = i; j > 1; j--)
                arr[j] = arr[j] + arr[j - 1];
            arr[i + 1] = arr[i];
            for (int j = i + 1; j > 1; j--)
                arr[j] = arr[j] + arr[j - 1];
            System.out.printf("%d ", arr[i + 1] - arr[i]);
        }
    }
}

/*
Sample input and output
Enter number: 7

1 2 5 14 42 132 429 

time complexity: O(n^2)
space complexity: O(n)
*/
