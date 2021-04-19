/*CYCLE SORT
  
  >> A worst case time complexity O(n^2) sorting algorithm.
  >> Does minimum number of memory writes and can be useful in cases where memory write is costly

*/

import java.util.*;

class cycle_sort
{
    public static void main (String[] args) 
    {
        Scanner in=new Scanner(System.in);
        System.out.print("Enter the number of elements you want to input : ");
        int num=in.nextInt();
        int arr[] = new int[num];
        for(int i=0;i<num;i++)
          {System.out.print("Enter the element : ");
              arr[i]=in.nextInt();} 
        int n = arr.length; 
        cycleSortDistinct(arr, n); 
        System.out.print("The sorted numbers are : ");
        for (int i = 0; i < n; i++) 
            System.out.print( arr[i] + " ");
        
    }
    
    static void cycleSortDistinct(int arr[], int n) 
    { 
        for(int cs=0;cs<n-1;cs++){
            int item=arr[cs];
            int pos=cs;
            for(int i=cs+1;i<n;i++)
                if(arr[i]<item)
                    pos++;
            //swap(item,arr[pos])
            
            int temp=item;
            item=arr[pos];
            arr[pos]=temp;
            while(pos!=cs){
                pos=cs;
                for(int i=cs+1;i<n;i++)
                    if(arr[i]<item)
                        pos++;
                        
                //swap(item,arr[pos])
                temp=item;
                item=arr[pos];
                arr[pos]=temp;
            }
        }
    }
}

 
/* INPUT :

Enter the number of elements you want to input : 4
Enter the element : 6
Enter the element : 1
Enter the element : 5
Enter the element : 3

   OUTPUT:
The sorted numbers are : 1 3 5 6 

*/
