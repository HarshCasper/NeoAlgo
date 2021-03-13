#include<stdio.h>
#include<math.h>


int main() {

    float principal, rate, time, si, ci, amount;
    printf("Enter principal amount : ");
    scanf("%f", &principal);
    printf("Enter annual rate of interest : ");
    scanf("%f", &rate);
    printf("Enter time in number of years : ");
    scanf("%f", &time);

    si = principal * rate * time / 100;
    amount = principal * pow(1+rate/100, time); // amount
    ci = amount - principal;
    printf("Simple interest = %.2f\n",si);
    printf("Compound interest = %.2f\n",ci);

    return 0;
    
}
