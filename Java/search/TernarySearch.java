import java.util.*;
public class Main
{  
   // Recursive Approach
  static int ternarySearchRecursive (int arr[], int f, int left, int right)
  {
    if (left <= right)
      {
	int mid1 = left + (right - left) / 3;
	int mid2 = right - (right - left) / 3;
	if (arr[mid1] == f)
	  return mid1 + 1;
	else if (arr[mid2] == f)
	  return mid2 + 1;
	else if (f < arr[mid1])
	    return ternarySearchRecursive (arr, f, left, mid1 - 1);
	else if (f > arr[mid2])
	    return ternarySearchRecursive (arr, f, mid2 + 1, right);
	else

	    return ternarySearchRecursive (arr, f, mid1 + 1, mid2 - 1);
      }
    return -1;
  }
    // Iterative Approach
 static int ternarySearch(int arr[], int f, int left, int right)
    {  int found = -1;
        while(left <= right)
        {
          int mid1 = left + (right - left) / 3;
	int mid2 = right - (right - left) / 3;
            if(arr[mid1] == f)
                return mid1 + 1;
            else if(arr[mid2] == f)
                return mid2 + 1;
            else if(f < arr[mid1])
             right = mid1 - 1;
            else if(f > arr[mid2])
               left = mid2 + 1;
            else 
              {
                  left = mid2 + 1;
                  right = mid2 - 1;
              }
            
        } 
        return found;
       
    }
    

  public static void main (String[]args)
  {
    Scanner sc = new Scanner (System.in);
    int i, n, left, right, f = -1, element;
    System.out.println ("Enter length of array");
    n = sc.nextInt ();
    System.out.println ("Enter  array elements");
    int arr[] = new int[n];
    for (i = 0; i < n; i++)
      arr[i] = sc.nextInt ();
    System.out.println ("Enter element to be searched");
    element = sc.nextInt ();

    Arrays.sort (arr);
    left = 0;
    right = n - 1;

    f = ternarySearch(arr, element, left, right);
    if (f != -1)
      System.out.println ("Element found at " + (f));
    else
      System.out.println ("Element not found");
  }
}

/*
Time Complexity -  O(log3(N))

Sample I/O :

Input :  
Enter length of array
4
Enter  array elements
1 2 3 4
Enter element to be searched
4

Output :
Element found at 4 
*/
