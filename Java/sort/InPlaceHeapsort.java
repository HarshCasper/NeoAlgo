/*
Given an integer array of size n, sorting it using Heap Sort in descending order.
In-place: Those sorting algorithm which do not require extra space.
*/
public class InPlaceHeapsort {
          static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));;
	  static StringTokenizer st;
    public static void inplaceHeapSort(int arr[]) {
	 int n = arr.length; 
         for (int i = n / 2 - 1; i >= 0; i--) { 
            heapify(arr, n, i); 
         }
            for (int i=n-1; i>0; i--){ 
               int temp = arr[0]; 
               arr[0] = arr[i]; 
               arr[i] = temp; 
               heapify(arr, i, 0); 
              }
        }
        static void heapify(int arr[], int n, int i) { 
        // Initialize largest as root 
        int largest = i; 
        // left = 2*i + 1 
        int left = 2*i + 1; 
        // right = 2*i + 2
        int right = 2*i + 2;  
         if (left < n && arr[left] < arr[largest]){ 
           largest = left; 
	     }
         if (right < n && arr[right] < arr[largest]){ 
            largest = right; 
	     }
         if (largest != i){ 
            int swap = arr[i]; 
            arr[i] = arr[largest]; 
            arr[largest] = swap; 
            heapify(arr, n, largest); 
         } 
      }
   static void print_array(int A[])
      {
           int n = A.length;
           for (int i=0; i<n; ++i)
            System.out.print(A[i]+" ");
         System.out.println();
      }

   public static void main(String args[])
     {
              st = new StringTokenizer(br.readLine());
	      int n = Integer.parseInt(st.nextToken());
       	      st = new StringTokenizer(br.readLine());
	      int input[] = new int[n];
	        for (int i = 0; i < n; i++) {
			input[i] = Integer.parseInt(st.nextToken());
		}
		Solution.inplaceHeapSort(input);
		for (int i : input) {
			System.out.print(i + " ");
		}
     }
  }
/*
 Sample Input
 6 
 2 6 8 5 4 3
 Sample Output
 8 6 5 4 3 2
*/
