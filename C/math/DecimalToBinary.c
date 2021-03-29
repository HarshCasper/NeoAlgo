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

//function to check whether stack is empty or not by returning 1 for empty and 0 for non-empty
int isEmpty()
{
    if (top == -1)
        return 1;

    return 0;
}

//function to check whether stack is full or not by returning 1 for full and 0 for not-full
int isFull()
{
    if (top == SIZE - 1)
        return 1;

    return 0;
}

//function to insert value into the stack
void push(int r)
{
    if (isFull())
        printf("\nSTACK OVERFLOW\n");
    else
        stack[++top] = r;
}

//function for delete value from the stack
int pop()
{
    if (isEmpty())
        printf("\nSTACK UNDERFLOW\n");
    else
        return stack[top--];
}

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

/*
TEST CASE

Enter decimal number: 10

DECIMAL :: 10
BINARY  :: 1010

TIME COMPLEXITY  :: O(n)
SPACE COMPLEXITY :: O(1)

*/
