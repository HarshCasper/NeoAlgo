/*
 * It's the use of two different pointers (usually to keep track of array or string indices)
 * to solve a problem involving said indices with the benefit of saving time and space. 
 * 
*/
import java.util.Scanner;
public class two_pointer 
{
  public static void main(String[] args) 
  {
    int array[] = { -4, -1, 0, 2, 3, 5, 6, 7, 8, 9 };
    int k = 10, j = array.length - 1;
    while (j > 0) 
    {
      for (int i = 0; i < j; i++) 
      {
        if (array[i] + array[j] > k) 
        {
          --j;   
          if (i == j) 
          {
            break;
          }           
        }
       /* 
        * Check if sum of two digit is equal to k or not.
	* if it is equal to the value of k then print those digits. 
        */
        if (array[i] + array[j] == k) 
        {
          System.out.println(array[i] + "," + array[j]);
          break;
        }
      }      
      --j;
    }
  }
}

/*
 * Time complexity is O(n)
 * Space complexity is O(n)
 *
 * OUTPUT : 2,8
 *          3,7
 * */
