import java.util.Scanner;
// JAVA Implementation of recursive Interpolation Search

public class InterpolationSearch {
  int findEleByInterSearching(int arr[], int low, int high, int key) {
    if (high >= low && key >= arr[low] && key <= arr[high]) {
      //if value of high and low ae same
      if (low == high) {
        // value of key compared with element at index low
        if (arr[low] == key) return low;
        else return - 1;
      }
      //determining the position of the key element in an array
      int pos = low + (((high - low) / (arr[high] - arr[low])) * (key - arr[low]));
      // value of key compared with element at index low
      if (arr[pos] == key) return pos;
      /* If element key  is smaller than pos value
                    then it can only be present in left subarray */
      if (arr[pos] > key) return findEleByInterSearching(arr, low, pos - 1, key);
      /* Else the element key  can only be present 
                   in right subarray */
      if (arr[pos] < key) return findEleByInterSearching(arr, pos + 1, high, key);
    }
    return - 1;
  }
  // Driver method to test above 
  public static void main(String args[]) {
    InterpolationSearch s = new InterpolationSearch();
    Scanner sc = new Scanner(System. in );
    System.out.println("Input :");
    System.out.println("Enter the size of array: ");
    int size = sc.nextInt();
    sc.nextLine();
    int sortedarr[] = new int[size];
    System.out.println("Enter the elements of array:");
    for (int index = 0; index < size; index++) {
      sortedarr[index] = sc.nextInt();
    }
    System.out.println("Enter the element to be searched:");
    int searchKey = sc.nextInt();
    int position = s.findEleByInterSearching(sortedarr, 0, size - 1, searchKey);
    System.out.println("Output :");
    if (position == -1) System.out.println("Element not found");
    else System.out.println("Element found at index " + position);
  }
}
/*
   Input :
   Enter the size of array:
   4
   Enter the elements of an array:
   1 3 5 7
   Enter the element to be search:
   5
   Output :
   Element found at index 2
 */
/* 
  Time Complexity: If elements are uniformly distributed, then O (log log n)). In worst case it can take upto O(n).
  Auxiliary Space: O(1)
*/