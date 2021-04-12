// Program to convert decimal to octal
#include<stdio.h>
//Function which convert decimal to octal and print it
void dec_to_oct(int n)
{
  //base case when the recursion will stop
     if(n==0)
        //returns nothing
        return;
        //the function will call itself by passing n/8
           dec_to_oct(n/8);
        //print the n%8 value ex. n=2 so the n%8=2
        printf("%d",n%8);
     //returns nothing
        return;
}
//driver code
int main()
{
    //Initialize num variable
    int Num;
    printf("Enter a Number: ");
    //taking input
    scanf("%d",&Num);

    if(Num<0){
    //providing better UI to user
    printf("The octal conversion of %d is: -",Num);
    //converting no into a positive one
    Num=Num*-1;
    }
else
        //providing better UI to user
        printf("The octal conversion of %d is: ",Num);
    //function to convert decimal to octal
    dec_to_oct(Num);
    return 0;
}
/*
Example:
case 1:
Input: Enter a Number: 16
Output: The octal conversion of 16 is: 20
case 2:
Input: Enter a Number: -10
Output: The octal conversion of -10 is -12

Time complexity:O(n)
Space Complexity:O(1)

*/
