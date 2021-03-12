using System;

/*  Radix sort is a sorting technique that sorts the elements by 
    first grouping the individual digits of the same place value. 
    Then, sort the elements according to their increasing/decreasing order.
*/

 class RadixSort{
  static void radixSort(int[] arr){
    int size = arr.Length;
    int max_element = arr[0];
    
    for (int i=1; i<size; i++){  
      if(max_element < arr[i])
        max_element = arr[i];
    }

    for (int x = 1; max_element/x > 0; x *= 10){ 
      countingSort(arr, x); 
      }
  }

 
  static void print_arr(int[] arr){ 
    int size = arr.Length; 
   
    Console.Write("\n"); 
  } 
  
    static void countingSort(int[] arr, int x){   
    int size = arr.Length;    
    int[] new_arr = new int[size];
    
    int[] fr = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int i = 0; i < size; i++){
      fr[(arr[i]/x)%10]++;
      }

    for (int i = 1; i < 10; i++){ 
      fr[i] += fr[i - 1];     
      }

    for (int i = size - 1; i >= 0; i--){ 
      new_arr[fr[(arr[i]/x)%10] - 1] = arr[i]; 
      fr[(arr[i]/x)%10]--; 
    } 
  
    for (int i = 0; i < size; i++){ 
      arr[i] = new_arr[i]; 
     } 
  }


  public static void Main(string[] args){
    int n = Convert.ToInt32(Console.ReadLine());
    int[] a = new int[n];
   
   int i,j;
    for(i=0; i<n;i++){
        Console.Write("Element {0} : ", i);
        a[i] = Convert.ToInt32(Console.ReadLine());
    }
    Console.Write("Unsorted array: ");
    for (j=0; j<n; j++){
      Console.Write(a[j] + " "); 
    } 
      
    Console.Write("\n");
    
    radixSort(a);
    
    Console.Write("Sorted array: ");
     for (j=0; j<n; j++){
      Console.Write(a[j] + " "); 
      } 
  }
}

/* Input
    6                                                                                         
    Element 0 : 87                                                                            
    Element 1 : 12                                                                            
    Element 2 : 4                                                                             
    Element 3 : 76                                                                            
    Element 4 : 1                                                                             
    Element 5 : 23 
*/

/* Output
    Unsorted array: 87 12 4 76 1 23 
    Sorted array: 1 4 12 23 76 87 
*/

/* Time Complexity = O(d(n+k)) 
        where k= largest element in the array
              n= number of elements in the array
              d = base of numbers(decimal base system =10)
*/


