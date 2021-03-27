/*
AIM :: To take any decimal number from the user 
       and convert that given decimal number into binary number
       using stack (by Array represention).
*/

#include <stdio.h>
//MACRO definition
#define SIZE 50

//Array representation of stack
int stack[SIZE];
int top = -1;

//for insertion
void push(int);

//for deletion
int pop();

//to check stack is empty or full
int isEmpty();
int isFull();

int main()
{
    //number for storing decimal number given by user
    int number, num, reminder;

    printf("\nEnter decimal number: ");
    scanf("%d", &number);

    //preserving original number for further use
    num = number;
    while (num >= 1)
    {
        reminder = num % 2;
        push(reminder);
        num = num / 2;
    }

    printf("\nDECIMAL :: %d\n", number);
    printf("BINARY  :: ");

    while (!isEmpty())
        printf("%d", pop());

    return 0;
}

int isEmpty()
{
    if (top == -1)
        return 1;

    return 0;
}

int isFull()
{
    if (top == SIZE - 1)
        return 1;

    return 0;
}

void push(int r)
{
    if (isFull())
        printf("\nSTACK OVERFLOW\n");
    else
        stack[++top] = r;
}

int pop()
{
    if (isEmpty())
        printf("\nSTACK UNDERFLOW\n");
    else
        return stack[top--];
}

/*
TEST CASE

Enter decimal number: 10

DECIMAL :: 10
BINARY  :: 1010

*/
