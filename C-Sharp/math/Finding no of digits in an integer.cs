/*  Find number of digits in an integer : 
	This program will gives you the result in O(1) Time Complexity  
*/

using System; 
  
class CountDigits { 
  
    static int countDigit(long num) {
        return (int)Math.Floor(Math.Log10(num) + 1); 
    }
    
    public static void Main() 
    { 
        Console.WriteLine("Enter the number: ");
        long num = Convert.ToInt32(Console.ReadLine());
        Console.WriteLine("Number of digits= " + countDigit(num)); 
    } 
}
