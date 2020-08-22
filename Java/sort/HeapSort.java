import java.util.*;

class BucketSort {

    private static void heapSort(int arr[]) {
        int size = arr.length;

        System.out.println("Time to make first max heap:");
        long startTime = System.nanoTime();
        // calling buildHeap() to rearrange along with creating max heap
        for(int i = size/2 - 1; i>=0; i--) {
            buildHeap(arr, size, i);
        }
        long stopTime = System.nanoTime();
        System.out.println((stopTime - startTime)*0.000000001);

        System.out.println("Time to make sort using max heaps and putting largest element in the end:");
        startTime = System.nanoTime();
        // exchanging and extracting elements one by one from the final heap to sort the array
        for(int i = size-1; i>0; i--) {

            // swap the current root and last term
            swap(arr, i, 0);

            // doing max heap again
            buildHeap(arr, i, 0);
        }
        stopTime = System.nanoTime();
        System.out.println((stopTime - startTime)*0.000000001);
    }

    private static void buildHeap(int arr[], int size, int i) {

        int max = i;
        int leftNode = 2 * i + 1;
        int rightNode = 2 * i + 2;

        // for max heap root must be greater than both nodes, so we compare to check this
        if(leftNode<size && arr[leftNode]>arr[max]) {
            // left node larger than current root
            max = leftNode;
        }

        if(rightNode<size && arr[rightNode]>arr[max]) {
            // right node larger than left node and current root
            max = rightNode;
        }

        if (max != i) {
            // root is not greatest
            swap(arr, max, i);

            // since this sub-heap got rearranged we need to rearrange all sub-heaps before this recursively
            buildHeap(arr, size, max);
        }
    }

    private static void swap(int arr[], int pos1, int pos2) {
        int temp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = temp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // taking input array
        System.out.println("Enter size of array:");
        int size = sc.nextInt();
        int arr[] = new int[size];
        System.out.println("Enter array elements:");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }

        // before sorting
        System.out.println("Array before heap sort:");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

        long startTime = System.nanoTime();
        heapSort(arr);
        long stopTime = System.nanoTime();
        System.out.println("Time to sort the array:");
        System.out.println((stopTime - startTime)*0.000000001);

        // after sorting
        System.out.println("Array after heap sort:");
        for (int i=0; i<arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        sc.close();
    }
}
/*
Sample input/output:-
Enter size of array:
9
Enter array elements:
12
11
9
10
3
7
6
20
1
Array before heap sort:
12 11 9 10 3 7 6 20 1 
Time to make first max heap:
1.0418000000000001E-5
Time to make sort using max heaps and putting largest element in the end:
7.484000000000001E-6
Time to sort the array:
0.002423689
Array after heap sort:
1 3 6 7 9 10 11 12 20

Building the max heap requires O(n) calls to the buildHeap function which
takes O(Logn) time to build the max heap
Therefore, total time complexity = O(nLogn)

In heap sort since we are only keeping data in the array and only
rearranging it so no data needs to be stored anywhere else (other than the swap step)
So, space complexity = O(1)
*/
