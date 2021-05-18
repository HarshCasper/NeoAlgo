/* 
Problem: Solving Quadratic equations in C.
Aim: A program that prints roots and also tells us the types of the roots of a quadratic equation ax²+bx+c=0
*/
#include<stdio.h>
#include<math.h>

void quadratic_equation_roots(){
	// value a, b, and c;
	double a, b, c;
	double discriminant;
	printf("Enter the co-efficients (x^2), x, and 1 of the quadratic equation (a*x*x+b*x+c)=0: ");
	scanf("%lf%lf%lf",&a,&b,&c);
	// calculate the discriminant (b^2 - 4ac)
	discriminant=(b*b-4*a*c);
	// If a is 0, then equation is not quadratic, but linear
	if(a==0){
		printf("\nThe equation is a linear equation, not a qudratic equation");
	}
	// discriminant is greater than 0 --> real and distinct roots
	else if(discriminant>0){
		printf("\nThe roots are unequal and both have real value. And the roots are,");
		printf("\nroot1 = %.2lf",(-b+sqrt(discriminant))/(2*a));
		printf("\nroot2 = %.2lf",(-b-sqrt(discriminant))/(2*a));
	}
	// discriminant is equal to 0 --> real and equal roots
	else if(discriminant==0){
		printf("\nThe roots are equal and both have real values. And the roots are, ");
		printf("\nroot1 = root2 = %.2lf",-b/(2*a));
	}
	// discriminant is less than zero, imaginary roots
	else{
		printf("\nThe roots are complex numbers and have imaginary roots. And the roots are, ");
		printf("\nroot1 = %.2lf + %.2lfi",-b/(2*a),sqrt(-discriminant)/(2*a));
		printf("\nroot2 = %.2lf - %.2lfi",-b/(2*a),sqrt(-discriminant)/(2*a));
	}	
}
void main(){
	quadratic_equation_roots();
}
/* 
Sample Test Cases:
....Test case 1:
Enter the co-efficients (x^2), x, and 1 of the quadratic equation (a*x*x+b*x+c)=0: 3 -6 2

The roots are unequal and both have real value. And the roots are,
root1 = 1.58
root2 = 0.42

....Test case 2:
Enter the co-efficients (x^2), x, and 1 of the quadratic equation (a*x*x+b*x+c)=0: 6 -12 6

The roots are equal and both have real values. And the roots are,
root1 = root2 = 1.00

....Test case 3:
Enter the co-efficients (x^2), x, and 1 of the quadratic equation (a*x*x+b*x+c)=0: 4.5 6 9

The roots are complex numbers and have imaginary roots. And the roots are,
root1 = -0.67 + 1.25i
root2 = -0.67 - 1.25i

#Time Complexity: O(1)
#Space Complexity: O(1)
*/
