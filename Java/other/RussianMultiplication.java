/*************************************************************
 Program to multiply two numbers using Russian peasant method
 Given two integers, write a function to multiply them without using multiplication operator.
 We double the first number and halve the second number repeatedly till the second number doesn’t become 1. 
In the process, whenever the second number becomes odd, we add the first number to result.

 *************************************************************/
import java.io.*;
import java.util.Scanner;
 
class RussianMultiplication
{
 public static void main(String[] args)
 {
  //get the input numbers
  Scanner sc=new Scanner(System.in);
  System.out.print("Enter the first number: ");
  int num1=sc.nextInt();
  
  System.out.print("Enter the second number: ");
  int num2=sc.nextInt();
  int product=0;
  
  if(num1%2!=0)
   product=product+num2;
  while(num1!=1)
  {
	  //implementation of logic
   num1=num1>>1;
   num2=num2<<1;
   if(num1%2!=0)
    product=product+num2;
    }
  
  System.out.println("The product of two numbers  is: "+product);
 }
}

/*
Enter the first number: 7
Enter the second number: 14
The product is: 98
*/