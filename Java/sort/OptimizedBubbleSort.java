/**
 * Optimized Bubble Sort Algorithm
 *
 * In optimized version of bubble sort algorithm we keep track of an extra variable inside the
 * inner loop to check if there was even a single swap if in an iteration of outer loop no elements
 * were swapped in inner loop this means that array is sorted and any extra running of outer loop is
 * redundant.
 *
 * @author [Lakhan Nad](https://github.com/Lakhan-Nad)
 */

import java.util.Scanner;

public class OptimizedBubbleSort {
  /**
   * A main function to test the algorithm
   * 
   * Example Input: 2, 11, 5, -1, 0, 10, 20, 2, 8, 56, -34
   * Ouput: -34, -1, 0, 2, 2, 5, 8, 10, 11, 20, 56
   *
   * @param args the input arguments
   */
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    System.out.print("Enter size of array: ");
    int n = scan.nextInt();
    int[] array = new int[n];
    System.out.println("Enter elements of array");
    for(int i = 0; i < n; i++){
      array[i] = scan.nextInt();
    }
    bubbleSort(array);
    for (int i = 0; i < n; i++) {
      System.out.print(array[i] + " ");
    }
  }

  /**
   * Implementation of optimized bubble sort
   *
   * @param arr the array to sort
   */
  public static void bubbleSort(int[] arr) {
    /* extra variable to see maintain if swap was done */
    boolean swapped;
    int n = arr.length;
    for (int i = 0; i < n - 1; i++) {
      /* At start of outer loop make it false */
      swapped = false;
      for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          swap(arr, j, j + 1);
          /* Even if a single swap occurs during inside loop make it true */
          swapped = true;
        }
      }
      /* If no swap occurred this variable is false and we can end our iterations */
      if (!swapped) {
        break;
      }
    }
  }

  /**
   * A utility to swap elements
   *
   * @param array the array whose elements need to be swapped
   * @param i first index to swap
   * @param j second index to swap
   */
  public static void swap(int[] array, int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
  }
}
