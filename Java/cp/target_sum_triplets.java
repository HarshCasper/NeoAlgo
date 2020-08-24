import java.util.*;

class target_sum_triplets
  
  {
      
    public static void main(String args [])
    
    {
        Scanner sc=new Scanner (System.in);
        int n=sc.nextInt(); //  array size
        
        int arr[]=new int[n];
        
        for(int i=0;i<n;i++) 
          arr[i]=sc.nextInt(); // array input
          
          int target =sc.nextInt(); // target sum
          
          Arrays.sort(arr);
          
          for(int j=0; j<n-1; j++)
          {
              int start=j+1;
              int end=n-1;
              
              while(start<end){
                  
                  if(arr[j] + arr[start] + arr[end] == target)
                  {
                   System.out.println(arr[j] + ", " + arr[start] + " and " + arr[end]);
                   start++;
                   end--;
                  } 
                   else if(arr[j]+arr[start]+arr[end] < target)
                   start++;
                   
                   else 
                   end--;
              }
              
          }
          
    }
  }
  
  // Sample Input Output ->


  // Input
  // 9
  // 5 7 9 1 2 4 6 8 3
  // 10

  // Output
  // 1, 2 and 7
  // 1, 3 and 6
  // 1, 4 and 5
  // 2, 3 and 5



  // Complexity Analysis

  // Time Complexity - O(n^2)
  // Space Complexity - O(1)
