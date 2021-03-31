/* How to determine if a number is a Magic number.
   We calculate the sum of digits of the number till
   we get a single digit, recursively. If the single
   digit comes out to be 1, then we say that the number
   is a magic number.*/

import java.util.*;

//This function checks if a number is a magic number
class Magicnumber{
    
    static boolean magicNumber(int n){
         
         int sum = 0;
         /*We loop till the number is greater than 0 or we
           get a single digit sum of the digits of the number*/  
         while(n>0 || sum>9){
               
               //This is the iterating step.
               if(n == 0){
                  n =sum;
                  sum = 0; 
               }
               else{
                  //We find the sum of the digits of number
                  sum += n%10;
                  n = Math.floorDiv(n,10); 
               } 
         }

         /*After we get a single digit sum, we check if
           it 1, then it is a magic number and we return True.*/
         if(sum == 1){
            return true;
         }
         else{
            return false;
         }

    }    

    public static void main(String[] args){

         Scanner scan = new Scanner(System.in);
         System.out.print("Enter the number :");
         //Taking input from user
         int n = scan.nextInt();
         
         //checker  
         boolean check = magicNumber(n);
         
         //If the above function returns true, it means n is Magic number 
         if(check == true)
             System.out.println("The given number "+n+" is Magic number!");
         else
             System.out.println("The given number "+n+" is not Magic number!");       

    }     

}
/*
    Simple I/O :
 
    a) Is a magic number!
       
       Enter the number :112222
       The given number 112222 is Magic number!

    b) Is not a Magic number! 
      
       Enter the number :123
       The given number 123 is not Magic number!           
*/ 

