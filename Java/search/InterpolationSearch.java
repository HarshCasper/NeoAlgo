import java.util.Scanner;                                                            //importing the packages required for this code
// JAVA Implementation of recursive Interpolation Search

      public class InterpolationSearch {                                                     
             
	    int findEleByInterSearching(int arr[], int low, int high, int key) {         // Returns index of key if it is present in arr[low..high], else return -1 
     
             if(high >= low && key>=arr[low] && key<=arr[high]) {
            
            	if(low==high)                                                             //if value of high and low ae same
            	{
            		if(arr[low]==key)                                                // value of key compared with element at index low
            	           return low;
                        else
            		   return -1;
                 }

                int pos = low + (((high-low)/(arr[high]-arr[low]))*(key-arr[low]));        //determining the position of the key element in an array
                
                if(arr[pos] == key)                                                      // If the element key is present at the pos value itself 
                  return pos;
               
                if(arr[pos] > key)                                                       // If element key  is smaller than pos value
                  return findEleByInterSearching(arr, low, pos - 1, key);                // then it can only be present in left subarray 
               
                if(arr[pos] < key)                                                       //Else the element key  can only be present 
                  return findEleByInterSearching(arr, pos + 1, high, key);              //in right subarray 
               
            }  
       
      return -1;                                                                         // return statement
      } 
  
     // Driver method to test above 
     public static void main(String args[]) {
        InterpolationSearch s = new InterpolationSearch();
        Scanner sc=new Scanner(System.in);   
        System.out.println("<-----Input------->");                                  
        System.out.println("Enter the size of array: ");
        int size = sc.nextInt();                                                    
        sc.nextLine();
        int sortedarr[]=new int[size];
        System.out.println("Enter the elements of array:");                          // dynamic input of elements in an array
        for(int index=0;index<size;index++) {
           
            sortedarr[index]=sc.nextInt(); 
        }
        System.out.println("Enter the element to be searched:");
        int searchKey=sc.nextInt();
        int position = s.findEleByInterSearching(sortedarr, 0, size - 1, searchKey);    
        System.out.println("<------Output------>");  
        if (position == -1) 
            System.out.println("Element not found"); 
        else
            System.out.println("Element found at index " + position); 
    } 

} 
/* <-----Input------->
   Enter the size of array:
   4
   Enter the elements of an array:
   1 3 5 7
   Enter the element to be search:
   5
   <------Output------>
   Element found at index 2
 */

