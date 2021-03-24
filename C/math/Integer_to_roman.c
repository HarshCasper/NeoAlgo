// Program to convert the given integer into a roman numeral
#include <stdio.h>

void integer_to_roman(int);
int printing_roman(int, char[], int);
int main()
{
	int num;
	printf("Enter the number:");
	scanf("%d", &num);
	printf("Roman Numeral:");
	integer_to_roman(num);
}

//  Function which gives all the possible combinations to form a roman numeral
void integer_to_roman(int number)
{
	number = printing_roman(1000, "M", number);
	number = printing_roman(900, "CM", number);
	number = printing_roman(500, "D", number);
	number = printing_roman(400, "CD", number);
	number = printing_roman(100, "C", number);
	number = printing_roman(90, "XC", number);
	number = printing_roman(50, "L", number);
	number = printing_roman(40, "XL", number);
	number = printing_roman(10, "X", number);
	number = printing_roman(9, "IX", number);
	number = printing_roman(5, "V", number);
	number = printing_roman(4, "IV", number);
	number = printing_roman(1, "I", number);
}

// Printing Roman characters one by one
int printing_roman(int roman_num, char roman_char[50], int number)
{
	if (number >= roman_num)
	{
		printf("%s", ch);
		return (printing_roman(roman_num, roman_char, number - num1));
	}
}

/*
Sample Output
Enter the number:1984
Roman Number:MCMLXXXIV

Complexities
Time Complexity:O(n)
Space Complexity:O(1)
*/

