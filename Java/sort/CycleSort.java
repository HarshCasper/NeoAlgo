/*
Cycle sort is an in-place sorting Algorithm, unstable sorting algorithm, a comparison sort that is theoretically optimal in terms of the total number of writes 
to the original array.It is optimal in terms of number of memory writes. It minimizes the number of memory writes to sort (Each value is either written zero 
times, if it’s already in its correct position, or written one time to its correct position.)It is based on the idea that array to be sorted can be divided into 
cycles. Cycles can be visualized as a graph. We have n nodes and an edge directed from node i to node j if the element at i-th index must be present at j-th 
index in the sorted array.We one by one consider all cycles. We first consider the cycle that includes first element. We find correct position of first element,
place it at its correct position, say j. We consider old value of arr[j] and find its correct position, we keep doing this till all elements of current cycle are 
placed at correct position, i.e., we don’t come back to cycle's starting point.

This sorting algorithm is best suited for situations where memory write or swap operations are costly.
*/
import java.util.*; 
import java.lang.*; 
  
public class CycleSort { 
    // Function sort the array using Cycle sort 
    public static void cycleSorting(int arr[], int n) 
    { 
        // count number of memory writes 
        int writes = 0; 
  
        // traverse array elements and put it to on 
        // the right place 
        for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) { 
            // initialize item as starting point 
            int item = arr[cycle_start]; 
  
            // Find position where we put the item. We basically 
            // count all smaller elements on right side of item. 
            int pos = cycle_start; 
            for (int i = cycle_start + 1; i < n; i++) 
                if (arr[i] < item) 
                    pos++; 
  
            // If item is already in correct position 
            if (pos == cycle_start) 
                continue; 
  
            // ignore all duplicate elements 
            while (item == arr[pos]) 
                pos += 1; 
  
            // put the item to it's right position 
            if (pos != cycle_start) { 
                int temp = item; 
                item = arr[pos]; 
                arr[pos] = temp; 
                writes++; 
            } 
  
            // Rotate rest of the cycle 
            while (pos != cycle_start) { 
                pos = cycle_start; 
  
                // Find position where we put the element 
                for (int i = cycle_start + 1; i < n; i++) 
                    if (arr[i] < item) 
                        pos += 1; 
  
                // ignore all duplicate elements 
                while (item == arr[pos]) 
                    pos += 1; 
  
                // put the item to it's right position 
                if (item != arr[pos]) { 
                    int temp = item; 
                    item = arr[pos]; 
                    arr[pos] = temp; 
                    writes++; 
                } 
            } 
        } 
    } 
  
    // Driver program to test above function
    public static void main(String[] args) 
    { 
        Scanner sc=new Scanner(System.in);
        // taking input array
        System.out.println("Enter size of array:");
        int size = sc.nextInt();
        int arr[] = new int[size];
        System.out.println("Enter array elements:");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }
        int n = arr.length; 
        cycleSorting(arr, n); 
  
        System.out.println("After sort : "); 
        for (int i = 0; i < n; i++) 
            System.out.print(arr[i] + " "); 
    } 
} 

/*
Sample Input/ Output:-

Enter size of array:7
Enter array elements:
9 8 7 6 5 4 3
After sort : 
3 4 5 6 7 8 9 

Complexity:-

Space Complexity : O(1)
Time Complexity : O(n^2) , n is size of array
Worst Case Complexity : O(n^2)
Average Case Complexity: O(n^2)
Best Case Complexity: O(n^2)

*/
