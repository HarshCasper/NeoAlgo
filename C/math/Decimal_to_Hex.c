/*
Hexadecimal number is a number which has base value as 16.
To convert a decimal number to hexadecimal number, we have to keep on dividing the decimal number by 16 & store the remainder in
each division. According to remainder the hexadecimal digits are stored. The mapping of remainder to hex digit is same for
remainder 0-9(i.e 0 in decimal is 0 in hexadecimal as well). For remainder 10-15, the corresponding hexadecimal digits are A-F.
(i.e 10(in decimal) = A(in hex) & so on). Once all the remainders are calculated write those remainders in reverse order, this
gives the equivalent hexadecimal number.

In this problem, decimal number is given as input & we have to output its equivalent hexadecimal number.
I/O : 201
O/P : C9
Explanation : 201 in decimal format is equivalent to the C9 in hexadecimal.
*/

#include<stdio.h>

//Function that converts decimal number to hexadecimal number.
int decToHex(int fdec , char fhex[])
{
	int j = 0, remainder = 0;
	
	//This loop calculates the remainder & map it to hex number until the number is greater than 0.
	while(fdec > 0)
	{
		remainder = fdec % 16 ;
		/*
		If remainder is less than 10(i.e 0-9) then add remainder to 48. 48 is the ASCII value of 0. ASCII value of 1 is 49. So
		we add the remainder to ASCII value of 0 to get ASCII value of remainder & store it in character array. Here, j is used
		to keep track of array index.

		If remainder is greater than 9(i.e 10-15) which means remainder is A-F in hexadecimal. So add remainder to 55. 55 is
		ASCII value of A. ASCII value of B is 56. So we add remainder & ASCII value of A to get ASCII value of remainder in
		terms of hex form & store it in array.
		*/
		if(remainder < 10)
		{
			fhex[j] = 48 + remainder ;
		}
		else
		{
			fhex[j] = 55 + remainder ;
		}
		j = j + 1 ;
		fdec = fdec / 16 ;
	}

	//j contains the number of digits in hexadecimal number.
	return j ;
}

int main(void)
{
	int dec = 0, i = 0, len = 0 ;
	//Character array to store hexadecimal number.
	char hex[100] = {'\0'} ;

	//Take decimal number as input.
	printf("Enter the number in Decimal form : ");
	scanf("%d" , &dec) ;

	//Call to the function decToHex().
	len = decToHex(dec , hex);

	printf("The equivalent Hexadecimal number is : ") ;

	/*
	Here array is printed reversely as according to method to convert decimal number to hex number, the 1st obtained & stored
	remainder in array is actually last digit in hexadeciaml number. So to get correct hexadecimal number, print it reversely.
	*/
	for(i=len-1 ; i>=0 ; --i)
	{
		printf("%c" , hex[i]);
	}
	return 0 ;
}
/*
Sample Input/Output :

Input :
Enter the number in Decimal form : 45

Output :
The equivalent Hexadecimal number is : 2D

Time Complexity : O(n)
Space complexity : O(1)
*/

