import java.util.*;
public class Main
{  
   // Recursive Approach
  static int ternarySearchRecursive (int arr[], int f, int l, int h)
  {
    if (l <= h)
      {
	int mid1 = l + (h - l) / 3;
	int mid2 = h - (h - l) / 3;
	if (arr[mid1] == f)
	  return mid1 + 1;
	else if (arr[mid2] == f)
	  return mid2 + 1;
	else if (f < arr[mid1])
	    return ternarySearchRecursive (arr, f, l, mid1 - 1);
	else if (f > arr[mid2])
	    return ternarySearchRecursive (arr, f, mid2 + 1, h);
	else

	    return ternarySearchRecursive (arr, f, mid1 + 1, mid2 - 1);
      }
    return -1;
  }
    // Iterative Approach
 static int ternarySearch(int arr[],int f,int l,int h)
    {  int found = -1;
        while(l<=h)
        {
          int  mid1 = l + (h-l)/3;
          int  mid2 = h - (h-l)/3; 
            if(arr[mid1]==f)
                return mid1+1;
            else if(arr[mid2]==f)
                return mid2+1;
            else if(f<arr[mid1])
             h = mid1-1;
            else if(f>arr[mid2])
               l =mid2+1;
            else 
              {
                  l=mid2+1;
                  h=mid2-1;
              }
            
        } 
        return found;
       
    }
    

  public static void main (String[]args)
  {
    Scanner sc = new Scanner (System.in);
    int i, j, k, l, m, n, h, mid1, mid2, f = -1, element;
    System.out.println ("Enter length of array");
    n = sc.nextInt ();
    System.out.println ("Enter  array elements");
    int arr[] = new int[n];
    for (i = 0; i < n; i++)
      arr[i] = sc.nextInt ();
    System.out.println ("Enter element to be searched");
    element = sc.nextInt ();

    Arrays.sort (arr);
    l = 0;
    h = n - 1;

    f = ternarySearch(arr, element, l, h);
    if (f != -1)
      System.out.println ("Element found at " + (f));
    else
      System.out.println ("Element not found");
  }
}

// Complexity -  O(log3N)

/* 
Input/Output -  
Enter length of array
4
Enter  array elements
1 2 3 4
Enter element to be searched
4
Element found at 4 */


