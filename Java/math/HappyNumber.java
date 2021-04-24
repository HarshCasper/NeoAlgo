/* This code checks if a number is a happy number. A number is
   called happy if it becomes 1 after iterating thorugh a several
   number of steps wherein each step the number is replaced by the
   sum of its digits.*/

import java.util.*;
//import java.lang.*;

class HappyNumber{
   
   /*This function takes a number as input and returns
     sum of its digits.*/
   static int sumOfSquares(int n){
      
       int sum = 0;
       while(n != 0){
           /*Taking mod of number with 10 each time
            gives its units place digit. We add its
            square to the sum.*/
           int d = n%10;
           sum += d*d;
           //Replace the number with number / 10.
           n = Math.floorDiv(n,10);
       }

       return sum;
   }   
       
   /*This function takes a number as input and checksif the number is a 
     happy number.*/
   static boolean happyNumber(int n){
       
       int first = n;
       int second = n;

       while(true){

          //The first variable calling sum of digits function once 
          first = sumOfSquares(first);

          //The second variable calling sum of digits function twice
          second = sumOfSquares(second);
          second = sumOfSquares(second);

          /*If the first one equals the second, we break out of the loop. Otherwise,
            it will run into an infinite loop.*/
          if(first == second)
             break;
          else
             continue;    
       }   

       /*The number is happy if at the end of iterations the number
          becomes 1. If it is one, then we return True*/ 
       if(first == 1)
          return true;
       else
          return false; 

   }

   public static void main(String[] args){
     
       Scanner scan = new Scanner(System.in);
       System.out.print("Enter the number :");
       //Taking input from the user 
       int n = scan.nextInt();
       scan.close();       
       
       //checker
       boolean check = happyNumber(n);      
        
       //If the above function returns True, it means number is a happy number
       if(check == true){
          System.out.println("The given number "+n+" is a happy number!");
       }
       else
          System.out.println("The given number "+n+" is not happy number!");   
   }

}
/*
   Simple I/O :
   
   a) Is a happy number!   

   Enter the number :13
   The given number 13 is a happy number! 

   b) Is not a happy number!

   Enter the number :67
   The given number 67 is not happy number!     
*/

