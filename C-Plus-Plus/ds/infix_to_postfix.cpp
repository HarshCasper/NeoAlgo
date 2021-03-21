/*
   * This program converts the infix expression into postfix expression.
   
   * This program assumes that there are five operators: ('+' , '-' , '^' , '*' , '/')
   
   * this program will not work for fractional numbers.
   
   * This program doesn't check whether infix expression is valid or not in terms of number of operators & operands.
*/


#include <iostream>


char stack [100] ;
int top = -1 ;

void push  ( char x )
{
	stack [ ++top ] = x ;
}

char pop () 
{
	if ( top == -1 )
		return -1 ;
	
	else
		return stack[ top-- ] ;
}

int priority ( char x )
{
	
	 if ( x == '(' )
		 return 0 ;
	 
	 if ( x == '+' || x == '-' )
		 return 1 ;
	 
	 if ( x == '*' || x == '/') 
		 return 2 ;
	 
	 return 0 ;
}


int main () 
{
	char exp [100] ;
	char *e, x ;
	
	printf( "\t\t\t------INFIX TO POSTFIX------\n\n" ) ;
	printf ( "Enter Infix Expression: " ) ;
	scanf( "%s", exp );
	printf ( "\n" ) ;
	e=exp;
	
	while( *e != '\0' )
	{
		if ( isalnum ( *e ) )
			printf ( " %c " , *e ) ;
		else if ( *e == '(' )
			push ( *e ) ;
		else if ( *e == ')' )
		{
			while ( (x = pop()) != '(' )
				printf ( "%c" , x) ;
		}
		
		else 
		{
			while ( priority(stack[top]) >= priority(*e) )
				printf ( "%c" , pop() );
			push (*e) ;
		}
		
		e++ ;
	}
	
	while  ( top != -1 ){
		printf ( "%c" , pop() ) ;
	}
	
    return 0 ;
}



/*

COMPLEXITY:
~ Time Complexity: O(n^2)
~ Space Complexity: O(n)


EXAMPLE:

Infix Expression:  3+4*5/6
Postfix Expression: 3 4 5 * 6 / +

*/

