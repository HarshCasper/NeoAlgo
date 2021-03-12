using System;
  
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
    for (int i=0; i<size; i++){
      Console.Write(arr[i] + " "); 
      }
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
    int[] a = {65, 3,91, 80, 45, 106,41, 1};
    Console.Write("Unsorted array: ");
    print_arr(a);
    radixSort(a);
    Console.Write("Sorted array: ");
    print_arr(a);  
  }
}
