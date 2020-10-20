//C Program to check a number is Happy Number or not.

#include<stdio.h>

void main(){
    int n, sum, digit;
    printf("Enter a number: ");
    scanf("%d", &n);
    int temp = n;
    while(sum != 1 && sum != 4){
            sum = 0;
        while(temp != 0){
            digit = temp % 10;
            sum += digit * digit;
            temp = temp / 10;
        }
        temp = sum;
    
    }
    if(sum == 1)
        printf("%d is a happy number.",n);
    else
        printf("%d is not a happy number.",n);
}

/*
    Sample input/output:
    Example 1:
    Input : Enter a number: 32
    Output : 32 is a happy number.
    Example 2:
    Input : Enter a number: 14
    Output : 14 is not a happy number.
*/
