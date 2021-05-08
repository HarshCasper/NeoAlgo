/*
A stack is a linear data structure in which elements are added and removed only from
one end which is called the top. Hence, a stack is called a LIFO (Last-in-First-out) data structure.    
    In this program, the stack is sorted in ascending order without using another user defined stack.
Using the sort function, the elements of the stack are first popped out of the stack in a recursive manner.
Then, the insert function is called which pushes the elements back in the stack in ascending order. 
*/
#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int *arr;
	int top;
	int size;
};

//push function of stack
void push(struct stack **s, int x)
{
	if ((((*s)->top)) == ((*s)->size) - 1)
		printf("STACK OVERFLOW\n");
	else
	{
		((*s)->top) += 1;
		(*s)->arr[(*s)->top] = x;
	}
}

//pop function of stack
int pop(struct stack **s)
{
	if ((*s)->top != -1)
	{
		int n = (*s)->arr[(*s)->top];
		((*s)->top) --;
		return n;
	}
}

//display function of stack
void display(struct stack **sta)
{
	struct stack *s = *sta;
	if (s->top == -1)
		return;
	else
	{
		int n = pop(&s);
		printf("%d ", n);
		display(&s);
		push(&s, n);
	}
}

//function used by sort function to push elements back in stack in ascending order
int insert(struct stack **sta, int x)
{
	struct stack *s = *sta;
	if (s->top == -1 || s->arr[s->top] > x)
	{
		push(&s, x);
		return 0;
	}

	int n = pop(&s);
	insert(&s, x);
	push(&s, n);
}

//function to sort the stack
void sort(struct stack **s)
{
	int n = pop(&(*s));
	if ((*s)->top != -1)
		sort(&(*s));
	insert(&(*s), n);
}

void main()
{
	struct stack *s = (struct stack *) malloc(sizeof(struct stack));
	printf("Enter the size of stack : ");
	scanf("%d", &s->size);
	s->arr = (int*) malloc((s->size) *(sizeof(int)));
	s->top = -1;
	int op;
	char c = 'Y';
	while (c == 'y' || c == 'Y') {
		printf("\nEnter an option:\n1.push()\t2.pop()\n3.display()\t4.sort()\n");
		printf("Enter your choice: ");
		scanf("%d", &op);
		switch (op)
		{
			case 1:
				{
					int x;
					printf("Enter the data: ");
					scanf("%d", &x);
					push(&s, x);
					break;
				}

			case 2:
				{
					int n = pop(&s);
					break;
				}

			case 3:
				{
					if (s->top == -1)
						printf("STACK UNDERFLOW\n");
					else
					{
						printf("The stack is: ");
						display(&s);
						printf("\n");
					}

					break;
				}

			case 4:
				{
					if (s->top == -1)
						printf("STACK UNDERFLOW\n");
					else
					{
						printf("The sorted stack is : ");
						sort(&s);
						display(&s);
						printf("\n");
					}

					break;
				}

			default:
				printf("Not an option\n");
		}

		printf("Do you want to continue : ");
		scanf(" %c", &c);
	} 
}

/*
Time Compexity:
Push function - O(1)
Pop function - O(1)
Display function - O(n)
Sort function - O(n)
Insert function - O(n)

Space Compexity: O(n)

Sample Output:

Enter the size of stack : 4

Enter an option:        
1.push()        2.pop() 
3.display()     4.sort()
Enter your choice: 1    
Enter the data: 5
Do you want to continue : y

Enter an option:        
1.push()        2.pop() 
3.display()     4.sort()
Enter your choice: 1    
Enter the data: 3
Do you want to continue : y

Enter an option:        
1.push()        2.pop()
3.display()     4.sort()
Enter your choice: 1
Enter the data: 8
Do you want to continue : y

Enter an option:
1.push()        2.pop()
3.display()     4.sort()
Enter your choice: 1
Enter the data: 2
Do you want to continue : y

Enter an option:
1.push()        2.pop()
3.display()     4.sort()
Enter your choice: 3
The stack is: 2 8 3 5
Do you want to continue : y

Enter an option:
1.push()        2.pop()
3.display()     4.sort()
Enter your choice: 4
The sorted stack is : 2 3 5 8
Do you want to continue : n
*/
