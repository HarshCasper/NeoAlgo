/* This program will swap even and odd bits of
 the given integer.
 For Ex: 
         If the given number is 21(00010101) the ouput 
         should be 42(00101010).
 */
 import java.util.*;
 import java.lang.*;
 import java.io.*;

 class swap_even_odd_bits
 {
 	public static void main (String[] args) throws java.lang.Exception
 	{

        Scanner scn = new Scanner(System.in);
         System.out.println("Enter the number:");
         int n=scn.nextInt();

        //e represents hexadecimal number 1010(10)
         int e=0xAAAAAAAA ;

        //o represents hexadecimal number 0101(5)
         int o=0x55555555;

        //this will preserve all even bits of n and
        //make all odd bits of n 0.
         int even= e&n;

         //this will preserve all odd bits of n and
        //make all even bits of n 0.
         int odd= o&n;

         even >>= 1;
         odd <<= 1;

         System.out.println(even | odd); 
 	}
 }

 /*           TEST CASES

    1)Input:
            Enter the number:
            25
     Output:
            38
    
    2)Input:
            Enter the number:
            32
     Output:
            16
            

     Time Complexity:  O(1)
     Space Complexity: O(1)
 */
