/*
Infix, postfix and prefix are three different but equivalent notations of writing
algebraic expressions.
In postfix notation, operators follow their operands. 
In prefix notation, operators precede their operands.
    In this program, the user inputs a postfix expression and the prefix notation for that
given postfix notation is the output. Postfix notation is converted to prefix notation with
the help of stack data structure.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 30

struct stack
{
	char sta[MAX];
	struct stack * next;
};
struct stack *st = NULL;
char a[MAX], b[MAX], c[MAX];

//push function of stack
void push(char s[MAX])
{
	struct stack *temp = (struct stack *) malloc(sizeof(struct stack));
	strcpy(temp->sta, s);
	temp->next = NULL;
	if (temp == NULL)
		printf("Memory Overflow\n");
	else
	{
		if (st == NULL)
			st = temp;
		else
		{
			temp->next = st;
			st = temp;
		}
	}
}

//pop function of stack
void pop(char d[])
{
	struct stack *t = st;
	st = t->next;
	strcpy(d, t->sta);
	free(t);
}

//Function to count number of elements in stack
int count()
{
	int c = 0;
	struct stack *t = st;
	while (t != NULL)
	{
		c++;
		t = t->next;
	}

	return c;
}

//Function to convert postfix expression to prefix expression
void PostfixToPrefix(char post[], char pre[])
{
	int i = 0;
	char op[3];
	while (post[i] != '\0')
	{
		if (isalpha(post[i]) != 0 || isdigit(post[i] != 0))
		{
			op[0] = post[i];
			op[1] = '\0';
			push(op);
		}
		else
		{
			if (count() < 2)
			{
				printf("Not sufficient values in the expression\n");
				exit(1);
			}
			else
			{
				op[0] = post[i];
				op[1] = '\0';
				pop(a);
				pop(b);
				c[0] = '\0';
				strcat(c, op);
				strcat(c, b);
				strcat(c, a);
				push(c);
			}
		}

		i++;
	}

	if (count() == 1)
	{
		pop(pre);
		printf("Prefix Expression: %s", pre);
	}
	else
	{
		printf("Invalid user input");
	}
}

void main()
{
	char pre[MAX], post[MAX];
	printf("Enter a postfix expression: ");
	gets(post);
	PostfixToPrefix(post, pre);
}

/*
Time Compexity:
Push function - O(1)
Pop function - O(1)
Count funtion - O(n)
PostfixToPrefix function - O(n)

Space Complexity: O(n)

Sample Output: 
Enter a postfix expression: ABCDE-+^*EF*-
Prefix Expression: -*A^B+C-DE*EF
*/
