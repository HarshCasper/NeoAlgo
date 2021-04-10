/* In a good number, every digit is greater than the sum of all digits on its right.
   Approach: The last digit of the number is extracted and stored in sum.
   That digit is removed and the last digit of the number so obtained is compared with sum.
   If it is less than sum iteration goes on till we are left with only one digit in the modified number else the iteration is stopped
*/

import java.util.Scanner;
 public class good_number 
 {
    static void return_good(int first,int last)
    {
       for(int count=first;count<last;count++)
	 {
	     int current=count,sum=0;

             while(current!=0)
             {
                 sum=sum+current%10;
                 current/=10;
                 if((current!=0) && (current%10<=sum))
                  break;
             }

            if(current==0)
                System.out.print(count+"  ");
         }
    }
    
     public static void main(String [] args)
     {
         Scanner scan=new Scanner(System.in);
         int start,end;

         System.out.println("Enter the Range");
         start=scan.nextInt();
         end=scan.nextInt();
         
         return_good(start,end);
     }
 }

/*
                     OUTPUT:
Test Case 1:
Input: 345 678
Output: 410  420  421  430  510  520  521  530  531  540  610  620  621  630  631  632  640  641  650

Space Complexity: O(1)
Time Complexity: O(n2)
*/

