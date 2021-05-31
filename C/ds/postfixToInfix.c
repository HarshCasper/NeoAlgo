/* This is the code for converting postfix expression to corresponding infix expression. The input is postfix expression(Eg: ab+).
 * This code gives output as the corresponding infix expression with parenthesis(a+b). This approach uses stack data structure.
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>

//SIZE is the size of character array 'data' that holds intermediate expressions.
#define SIZE 50

/* Here, stack is implemented using linked list. Each node in linked list represents one element in stack. This is the definition of
 * each node of that linked list.
*/
struct stackNode
{
	/* In process of converting postfix expression to infix expression, we need to push intermediate expressions in stack. To store
	 * those expressions, character array 'data' is used. 'next' is the pointer pointing towards the next element in the stack.
	 */
	char data[SIZE];
	struct stackNode *next;
};

//The function to check whether stack is empty or not.
int isEmpty(struct stackNode *ftop)
{
	int rval = 0;
	if (ftop == NULL)
	{
		rval = 0;
	}
	else
	{
		rval = 1;
	}
	return rval;
}

//The function to check whether stack is full or not.
int isFull(struct stackNode *fnewnode)
{
	int rval = 0;
	if (fnewnode == NULL)
	{
		rval = 0;
	}
	else
	{
		rval = 1;
	}
	return rval;
}

//Function to push element in the stack.
int push(struct stackNode **ftop, char fidata[])
{
	struct stackNode *top = NULL, *newnode = NULL;
	int rval = 0;
	top = *ftop;

	//Memory is assigned to element to be pushed.
	newnode = (struct stackNode*) calloc(1, sizeof(struct stackNode));

	//Check if stack is full or not. If not then push the character/expression.
	rval = isFull(newnode);
	if (rval == 1)
	{
		strcpy(newnode->data , fidata);
		if (top == NULL)
		{
			top = newnode;
		}
		else
		{
			newnode->next = top;
			top = newnode;
		}
	}
	*ftop = top;

	//rval=1 indicates successful push, else stack is full.
	return rval;
}

//Function to pop an element from stack.
int pop(struct stackNode **fhead, char fddata[])
{
	struct stackNode *head = NULL, *dnode = NULL;
	int rval = 0;
	head = *fhead;

	//Check if stack is empty or not. If not, then pop the character/expression.
	rval = isEmpty(head);
	if (rval == 1)
	{
		dnode = head;
		strcpy(fddata , dnode ->data);
		head = head->next;
		dnode->next = NULL;
		free(dnode);
		dnode = NULL;
	}
	*fhead = head;

	//rval=1 indicates successful pop, else stack is empty.
	return rval;
}

//Function to determine the priority of the character.
int checkSymbol(char fsymbol)
{
	int pr = 0;

	/* If fsymbol is operator(i.e +,-,*,/ or %) 1 is returned. Else if fsymbol is a operand(i.e either character or intermediate sub
	 * expression) then 0 is returned.
	 */
	switch (fsymbol)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			pr = 1;
			break;

		default:
			pr = 0;
			break;
		}
		return pr;
}

//Function that evaluates the infix expression from postfix expression.
void postfixToInfix(char fpostfix[SIZE], char finfix[SIZE])
{
	int i = 0, symbolCheck = 0 ;
	char symbol = '\0';
	char operator[2] = {'\0'}, operandExpression[10] = {'\0'}, operand1[SIZE] = {'\0'}, operand2[SIZE] = {'\0'} ;

	//This approach requires a stack to store operands. opndtop is the top of the operand stack.
	struct stackNode *opndtop = NULL ;

	//iterate through input postfix string. i is the iterating variable.
	while(fpostfix[i] != '\0')
	{
		//symbol contains character of postfix string.
		symbol = fpostfix[i];

		//Check whether current symbol is operand or operator by calling the function checkSymbol().
		symbolCheck = checkSymbol(symbol);

		/* If checkSymbol() returns 0, that means the symbol is operand. If it is operand, push it in the stack. Go to next character
		 * in expression.
		 *
		 * If checkSymbol() does not returns 0, that means the symbol is operator(either +,-,* or /). If we encounter the operator, pop
		 * 2 operands from the stack & concatinate the strings as (+operand1+operator+operand2+). This will give sub expression in
		 * infix expression. Push this intermediate sub expression in the stack. Move on to next character in postfix string. Keep
		 * doing this till last symbol is encountered.
		 */
		if(symbolCheck == 0)
		{
			operandExpression[0] = symbol ;
			operandExpression[1] = '\0';
			push(&opndtop , operandExpression);
			i = i + 1 ;
		}
		else
		{
			operator[0] = symbol ;
			operator[1] = '\0' ;
		    pop(&opndtop , operand2);
			pop(&opndtop , operand1);
			strcpy(finfix, "(") ;
			strcat(finfix, operand1) ;
			strcat(finfix, operator) ;
			strcat(finfix, operand2) ;
			strcat(finfix, ")") ;
		    push(&opndtop , finfix);
			i = i + 1 ;
		}
	}

	/* After the above while loop is completed, the stack contains only 1 element, i.e the final infix expression. Pop it. It is stored
	 * in finfix.
	 */
	pop(&opndtop , finfix);
}

int main(void)
{
	char postfix[SIZE] = {'\0'}, infix[SIZE] = {'\0'};

	//Taking input as the postfix expression.
	printf("Enter the postfix expression = ");
	__fpurge(stdin);
	scanf("%9s", postfix);

	//Call to the function postfix_to_infix
	postfixToInfix(postfix, infix);

	//Output the converted infix string.
	printf("\nInfix expression = %s", infix);

	return 0;
}

/*
 * Sample Input/Output:
 *
 * Input:
 * Enter a postfix expression = ABC*EF-/+
 *
 * Output:
 * Infix string = (A+((B*C)/(E-F)))
 *
 * Time Complexity: O(n) , where n is length of postfix expression.
 * Space Complexity: O(n) , where n is length of postfix expression.
 */

