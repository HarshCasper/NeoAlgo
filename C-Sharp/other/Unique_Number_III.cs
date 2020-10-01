//Unique_Number_III
//Given an array that contains all elements occurring 3 times, but one occurs only once. Find that unique element.

using System.IO;
using System;

class Neoalgo {
  static void Main() {
    int[] count = new int[64];
    int len, no, i;
    Console.WriteLine("Enter number of element:");
    len = Convert.ToInt32(Console.ReadLine());
    Console.WriteLine("Enter space separated elements:");
    for (i = 0; i < len; i++) {
      //Reading array element
      no = Convert.ToInt32(Console.ReadLine());

      int j = 0;
      //"AND" each element of the array with each set digit
      while (no > 0) {
        int last_bit = no & 1;
        count[j] += last_bit;
        j++;
        no = no >> 1;
      }
    }

    //consider all bits whose count is not multiple of 3
    int num = 1;
    int ans = 0;
    for (i = 0; i < 64; i++) {
      count[i] %= 3;
      ans += (count[i] * num);
      num = num << 1;
    }
    Console.Write("unique num is:");
    Console.Write(ans);
  }
}
/* output

Enter number of element: 7
Enter space separated elements: 10 10 12 21 21 10 21
unique num is: 12

Time Complexity:O(n)
*/

