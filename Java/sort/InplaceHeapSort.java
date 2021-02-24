//Given an integer array of size n, sorting it using Heap Sort in descending order.
//In-place: Those sorting algorithm which do not require extra space.
public class InplaceHeapSort {
	public static void inplaceHeapSort(int arr[]) {
	 int n = arr.length; 
         for (int i = n / 2 - 1; i >= 0; i--) 
            heapify(arr, n, i); 
         for (int i=n-1; i>0; i--) 
        { 
            int temp = arr[0]; 
            arr[0] = arr[i]; 
            arr[i] = temp; 
            heapify(arr, i, 0); 
        }
    }
        static void heapify(int arr[], int n, int i) 
    { 
        int largest = i; // Initialize largest as root 
        int l = 2*i + 1; // left = 2*i + 1 
        int r = 2*i + 2; // right = 2*i + 2 
         if (l < n && arr[l] < arr[largest]){ 
            largest = l; 
	 }
        if (r < n && arr[r] < arr[largest]){ 
            largest = r; 
	}
        if (largest != i) 
        { 
            int swap = arr[i]; 
            arr[i] = arr[largest]; 
            arr[largest] = swap; 
            heapify(arr, n, largest); 
              } 
	}
  }
// Sample Input
// 6 
// 2 6 8 5 4 3
// Sample Output
// 8 6 5 4 3 2