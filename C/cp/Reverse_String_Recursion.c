/*
Program to input an string to obtain the reversal string and it's length using recursion.
*/

#include<stdio.h>
#include<string.h>

void org_str(char *str);
void rev_str(char *str);
int length(char *str);

void org_str(char *str )
{
	if(*str == '\0')
	    return;
	putchar(*str );
	org_str(str+1);
}

void rev_str(char *str )	
{
	if(*str == '\0')
	    return;
	rev_str(str+1);
	putchar(*str );
}

main( )
{
	char str[100];
	printf("Enter the string : \n");
	gets(str);
	printf("Your entered string is : \n");
	org_str( str );
	printf("\n");
	printf("The reversed string is : \n");
	rev_str(str);
	printf("\n");
	printf("The length of the string is : \n");
	printf("%d",strlen(str));
	printf("\n");
}	

/*
Enter the string :                                                                                                                                               
string                                                                                                                                                           
Your entered string is :                                                                                                                                         
string                                                                                                                                                           
The reversed string is :                                                                                                                                         
gnirts                                                                                                                                                           
The length of the string is :                                                                                                                                    
6

Time Complexity : O(n)
Space Complexity : o(1)
*/
