import java.util.*;

class Distinct_Element {
    static void FindDistinct(int arr[], int size, int k) {
        // using set for storing the distinct elements.
        Set<Integer> elements = new HashSet<Integer>();
        for (int i = 0; i <= size - k; i++) {
            for (int j = 0; j < k; j++) {
                elements.add(arr[i + j]);
            }
            System.out.println(elements.size());
            elements.clear();
        }

    }

    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        int len, k;
        System.out.println("Enter the length of array and window size");
        len = sc.nextInt();
        k = sc.nextInt();
        int arr[] = new int[len];
        System.out.println("Enter the array elements");

        for (int i = 0; i < len; i++)
            arr[i] = sc.nextInt();
        System.out.println("Distinct elements are:");
        FindDistinct(arr, len, k);
    }
}

/*
output:
Enter the length of array and window size: 4 2
Enter the array elements: 10 10 20 30
Distinct elements are: 1 2 2
Time complexity : O(K^2)
space complexity : O(size)
*/
