// Program to Print the total number of digits in a given number
#include<stdio.h>
//Function to find the number of digits
int number_of_digits(int num)
{
  //initializing required variable
 int result=0;
 // the loop will run until the num variable is not equal to 0
 while(num)
 {
     // reducing number last digit and then storing in num variable
     num=num/10;
     // increasing the result variable which is counting the number of digits
     result++;
 }
 return result;
}
int main()
{
  //initializing required variable
int num;
// Giving Better UI to user to understand what to do
printf("Enter a number: ");
// putting value in num variable
scanf("%d",&num);
//printing the result given by the function number_of_digits
printf("The total number of digits in %d is: %d",num,number_of_digits(num));
return 0;
}
/*
Case 1:
Input:6545
Output: The total number of digits in 6545 is: 4
Case 2:
Input: -313
Output: The total number of digits in -313 is: 3
Time complexity: O(N) where N is total number of digit in Num variable
Space Complexity:O(1)
*/
