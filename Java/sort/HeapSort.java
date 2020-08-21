import java.util.*;

class BucketSort {

    private static void heapSort(int arr[]) {
        int size = arr.length;

        //calling buildHeap() to rearrange along with creating max heap
        for(int i = size/2 - 1; i>=0; i--) {
            buildHeap(arr, size, i);
        }

        int temp = 0;
        // exchanging and extracting elements one by one from the final heap to sort the array
        for(int i = size-1; i>0; i--) {

            //swap the current root and last term
            temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;

            //doing max heap again
            buildHeap(arr, i, 0);
        }
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

        int temp;
        if (max != i) {
            // root is not greatest
            temp = arr[max];
            arr[max] = arr[i];
            arr[i] = temp;

            //since this sub-heap got rearranged we need to rearrange all sub-heaps before this recursively
            buildHeap(arr, size, max);
        }
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

        heapSort(arr);

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
Array after heap sort:
1 3 6 7 9 10 11 12 20 

Time complexity = O(nLogn)
*/
