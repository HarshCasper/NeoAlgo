// C Program to checck whether a number is Armstrong or not

#include<stdio.h>
#include<math.h>

void ArmstrongNumber(int n){
	int num=n, rem, sum=0;
	
	// Counting number of digits
	int digits = (int) log10(num) + 1;

    while(num > 0) 
    {  
        rem = num % 10; 
        sum = sum + pow(rem,digits); 
        num = num / 10; 
    } 
    
    if(n==sum)
    	printf("%d is an Armstrong number.",n);
    else
    	printf("%d is not an Armstrong number.",n);
}

int main(){
	int num;
	
	printf("Enter the number: ");
	scanf("%d",&num);
	
	ArmstrongNumber(num);
	
	return 0;
}

/*
	Sample input/output:
	
	Example 1:
	Enter the number: 153
	153 is an Armstrong number.

	Example 2:
	Enter the number: 1094
	1094 is not an Armstrong number.
	
	Time Complexity= O(log(n)) 
	Space Complexity= O(1)
*/
