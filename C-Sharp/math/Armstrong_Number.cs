// Armstrong Number
using System;
public class Armstrong // Class Declaration
{
  public static void Main(string[] args) {
    int number, r, sum = 0, temp;
    Console.Write("Enter the Number to check whether it is an Armstrong Number or Not = ");
    number = int.Parse(Console.ReadLine()); // Getting Number From User    
    temp = number;
    while (number > 0) {
      r = number % 10;
      sum = sum + (r * r * r);
      number = number / 10;
    }
    // Checking if the number is Armstrong number or not
    if (temp == sum) Console.Write("{0} Is an Armstrong Number.", temp);
    else Console.Write("{0} Is Not an Armstrong Number.", temp);

  }
}

/*
Input:
Enter the Number to check whether it is an Armstrong Number or Not = 153
Output:
153 Is an Armstrong Number.

Input:
Enter the Number to check whether it is an Armstrong Number or Not = 788
Output:
788 Is Not an Armstrong Number.

Time Complexity: O(log(n))
Space Complexity: O(1)
*/
