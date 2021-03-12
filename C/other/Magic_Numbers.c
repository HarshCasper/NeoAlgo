/*
Sidharth Sethi
GitHub - TechSpiritSS
*/
#include<stdio.h>
int main()
{
    int num;
    printf("Enter the number to check for magic number\n");
    scanf("%d", &num);
    //Loop till number isn't a single digit
    while(num>=10)
    {
        int sum=0, temp;
        //Loop to get sum of digits
        while(num>0)
        {
            temp = num % 10;
            sum += temp;
            num /= 10;
        }
        num = sum;
    }
    if(num==1)
        printf("Magic Number");
    else
        printf("Not a magic number");
    return 0;
}