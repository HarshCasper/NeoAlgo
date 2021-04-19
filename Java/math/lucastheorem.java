/*
   This is a simple program in java language in lucas theorem. Lucas' 
   theorem is a result about binomial coefficients modulo a prime p.
   We will be given three numbers n, r and p and we need to compute 
   value of nCr mod p.

*/

import java.util.*;

class lucastheorem{

   // minimum return function
   static int min(int x,int y){

     if(x<y)
       return x;
     else
       return y;

   } 

   //computes the nCr % p value
   static int mod(int n,int r,int p){

     int[] array = new int[r+1];
     array[0] = 1;
     for(int i=1;i<r+1;i++){
         array[i] = 0;
     }

     for(int i=1;i<n+1;i++){
        int j = min(i,r);
        while(j>0){
           array[j] = (array[j]+array[j-1] )%p;
           j--;
        }
     }

     return array[r];

   }

   // lucas theoreme function
   static int lucastheorem(int n,int r,int p){

      if(r == 0){
         return 1;
      }  
      int n1 = n % p; 
      int r1 = r % p;            
      return(lucastheorem(n/p,r/p,p) * mod(n1,r1,p)) % p;  

   }

   // driver method
   public static void main(String[] args){
   
      // taking the input from user from here
      Scanner scan = new Scanner(System.in);
      System.out.print("Enter The Value of n : "); 
      int n = scan.nextInt();
   
      System.out.print("Enter The Value of r : ");
      int r = scan.nextInt();
   
      System.out.print("Enter The Value of p : ");
      int p  = scan.nextInt();
   
      System.out.print("Value of nCr % p is ");
      // calling lucastheorem
      System.out.print(lucastheorem(n,r,p));
   }

}
/*
   Sample I/O :

    Enter The Value of n : 10
    Enter The Value of r : 2
    Enter The Value of p : 13
    Value of nCr % p is 6

*/

