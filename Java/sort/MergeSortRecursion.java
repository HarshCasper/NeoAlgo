//merge sort using divide and conquer and recursion
import java.util.Scanner;
class MergeSortRecursion 
{
    
    public static void sort(int arr[], int start, int end)
    {
        if(start==end) //base case
        return;
        else
             {
            // Find the mid of the array
           int mid = start + ((end - start) / 2);
 
            // Sort first and second halves
            sort(arr, start, mid);
            sort(arr, mid + 1, end);
            merge(arr,start, mid, end); // Merge the sorted halves
        }
    }
    public static void merge(int arr[], int start, int mid, int end)
    {
        // Find sizes of two subarrays to be merged
        int nL = mid - start + 1; //left size
        int nR = end - mid;     //right size
 
        /* Create temporary arrays */
        int L[] = new int[nL];  //left array
        int R[] = new int[nR]; //right array
 
        /*Copy data to temporary arrays*/
        for (int i = 0; i < nL; ++i)
            L[i] = arr[start + i];
        for (int j = 0; j < nR; ++j)
            R[j] = arr[mid + 1 + j];
        int i = 0, j = 0;
 
        // Initial index of merged subarry array
        int k = start;
        while (i < nL && j < nR) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
 
        /* Copy remaining elements of L[] */
        while (i < nL) {
            arr[k] = L[i];
            i++;
            k++;
        }
 
        /* Copy remaining elements of R[] */
        while (j < nR) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    public static void printArray(int arr[])
    {
        int n = arr.length;
        for (int i = 0; i < n; ++i)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
    public static void main(String args[])
    {
       Scanner sc=new Scanner(System.in);
       System.out.print("Enter size of array"+"\n"+" n = ");
       int n=sc.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++)
        arr[i]=sc.nextInt();
 
        System.out.println("Inputted array : ");
        printArray(arr);
        sort(arr, 0, n-1);
 
        System.out.println("\nMergeSorted array : ");
        printArray(arr);
    }
}

/* Sample Input And Output : 
 * Enter size of array
 n = 5
33 47 19 2 101
Inputted array : 
33 47 19 2 101 

MergeSorted array : 
2 19 33 47 101 

Time Complexity : 
Worst case: O(n*log n)
Best Case: O(n*log n)

Space Complexity : O(n)
*/
 
