import java.util.*;

public class CocktailSort {

    private static void swap(int arr[], int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    private static void cocktailSort(int arr[]) {
        boolean isSwapped = true;
        int begin = 0;
        int last = arr.length-1;

        while (isSwapped == true) {
            // set isSwapped to false so that if nothing gets
            // sorted in this iteration we can break right away
            isSwapped = false;

            for(int i = begin; i < last; i++) {
                // going forward
                if (arr[i] > arr[i+1]) {
                    swap(arr, i, i+1);
                    isSwapped = true;
                }
            }

            // if nothing swapped then the array is already sorted
            if (isSwapped == false)
                break;

            // else, reset isSwapped to check for next iteration
            isSwapped = false;

            // since largest item is now in last. we only need
            // to check for one place before it
            last -= 1;

            for (int i = last; i >= begin; i--) {
                // going backward
                if (arr[i] > arr[i+1]) {
                    swap(arr, i, i+1);
                    isSwapped = true;
                }
            }

            // now the smallest number is on first place
            // so move starting point one position ahead
            begin++;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        //taking input array
        System.out.println("Enter size of array:");
        int size = sc.nextInt();
        int arr[] = new int[size];
        System.out.println("Enter array elements:");
        for (int i=0; i<size; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        // before sorting
        System.out.println("Array before Cocktail sort:");
        for (int i=0; i<arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        cocktailSort(arr);

        // after sorting
        System.out.println("Array after Cocktail sort:");
        for (int i=0; i<arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
/**
 * Sample input/output
 * Enter size of array:
 * 10
 * Enter array elements:
 * 88 26 77 49 91 62 33 85 99 11
 * Array before Cocktail sort:
 * 88 26 77 49 91 62 33 85 99 11 
 * Array after Cocktail sort:
 * 11 26 33 49 62 77 85 88 91 99
 * 
 * Enter size of array:
 * 7
 * Enter array elements:
 * 5 1 4 2 8 0 2
 * Array before Cocktail sort:
 * 5 1 4 2 8 0 2 
 * Array after Cocktail sort:
 * 0 1 2 2 4 5 8
 * 
 * Worst case Time complexity = O(n*n)
 * Best case Time complexity = O(n) when array is already sorted
 * Auxillary space = O(1)
 */
