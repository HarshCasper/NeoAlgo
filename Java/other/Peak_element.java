  /*
  An array element is a peak
  if it is NOT smaller than its neighbours.
  For corner elements, we need to consider only one neighbour.
  */
  import java.util.Scanner;
  public class peak_element 
  {
      // Function to find the peak element
      peak_element(int arr[], int length) 
      {
          for(int i=0;i<=length;i++) 
          {
              if(arr[i]==arr[0]) 
              {
                  if(arr[i]>arr[i+1]) 
                  {
                      System.out.println("Peak value : "+arr[i]);
                  }
              }    
              if(arr[i]==arr[length-1]) 
              {
                  if(arr[i]>arr[length-2]) 
                  {
                      System.out.println("Peak value : "+arr[i]);
                  }
              }
              if(arr[i]>arr[i+1] && arr[i]>arr[i-1]) 
              {
                  System.out.println("Peak value : "+arr[i]);
              }
          }
      }
  public static void main(String[] args) 
  {
      Scanner sc = new Scanner(System.in);
      System.out.println("Enter length of an array..");
      int length=sc.nextInt();
      System.out.println("your array please..");
      int arr[]=new int[length];
      for(int i=0;i<length;i++) 
      {
          arr[i]=sc.nextInt();
      }
      peak_element obj=new peak_element(arr, length);
  }
  }

  /*
  Input--
  Enter length of an array..
  5 
  your array please..
  2 5 8 9 5

  Output--
  Peak value : 9

  Time Complexity : O(n)
  Space Complexity : O(n)
  */
