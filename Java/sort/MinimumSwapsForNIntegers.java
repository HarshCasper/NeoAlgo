import java.util.*;

class MinimumSwapsForNIntegers {

    private static int minSwaps(int[] arr) {
        int countSwaps = 0;

        for(int i=0; i<arr.length; i++) {

            //swapping elements if not in their right positions
            if (arr[i] != i+1) {
                while (arr[i] != i+1) {
                    int temp = arr[arr[i]-1];
                    arr[arr[i]-1] = arr[i];
                    arr[i] = temp;
                    countSwaps++;
                }
            }
        }

        return countSwaps;
    }

    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);

        // taking input array
        System.out.println("Enter size of array:");
        int size = sc.nextInt();
        int arr[] = new int[size];
        System.out.println("Enter array elements:");
        for (int i=0; i<size; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        // initial array
        System.out.println("Array before sorting:");
        for (int i=0; i<size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        int minSteps = minSwaps(arr);

        // final array
        System.out.println("Array after sorting:");
        for (int i=0; i<size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        System.out.println("Minimum number of swaps required to sort:" + minSteps);
    }
}

/*
Sample input/output:

Enter size of array:
7
Enter array elements:
2
3
7
4
6
1
5
Array before sorting:
2 3 7 4 6 1 5 
Array after sorting:
1 2 3 4 5 6 7 
Minimum number of swaps required to sort:5

Time Complexity: O(N) where N is the size of array.
Auxiliary Space: O(1)
*/
