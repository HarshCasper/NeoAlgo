/*  

QUEUE USING STACKS
A queue can be implemented using 2 stacks.

Enqueue operation proceeds by:
Popping second stack and pushing into first stack
till second stack becomes empty. New value is then
pushed into the first stack.

Dequeue operation proceeds by:
Popping first stack and pushing into second stack
till first stack becomes empty. Thus first element
appears at the top of second stack. Second stack is
then popped.

*/

#include <bits/stdc++.h>
using namespace std;

//structure for stack
typedef struct Stack
{
    int data;
    struct Stack *next;
} Stack;

//to push into stack
void push(Stack *s, int data)
{

    Stack *ptr, *top=s->next;
    ptr = new Stack;
    ptr->data = data;
    ptr->next = top;
    top = ptr;
    s->next = top;
}

//to delete from stack
int pop(Stack *s)
{
    //if stack is not empty
    if (s->next != NULL)
    {
        Stack *top = s->next;
        Stack *ptr = top;
        int i = top->data;
        top = top->next;
        free(ptr);
        s->next = top;
        return i;
    }
    return -1;
}

//to display elements of stack
void display(Stack *s)
{
    Stack *top = s->next;
    Stack *ptr = top;
    //if stack is empty
    if (top == NULL)
        return;
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

//to insert into queue
void enqueue(int n,Stack *s1,Stack *s2)
{
    while (s2->next != NULL)
        push(s1, pop(s2));
    push(s1, n);
}

//to delete from queue
void dequeue(Stack *s1,Stack *s2)
{
    while (s1->next != NULL)
        push(s2, pop(s1));
    //if queue is empty
    if (s2->next == NULL)
        printf("Deletion not possible\n");
    else
        pop(s2);
}

//to display queue contents
void display_queue(Stack *s1,Stack *s2)
{
    while (s1->next)
        push(s2, pop(s1));
    if (s2->next == NULL)
        printf("Queue is empty!\n");
    else
        display(s2);
}

//driver code
int main()
{
    Stack *s1 = new Stack;
    Stack *s2 = new Stack;
    printf("Choose an option\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    int opt, val;
    //menu driven program
    printf("Option : ");
    scanf("%d", &opt);
    while(opt!=4)
    {
        switch (opt)
        {
        case 1: printf("Enter the value : ");
            scanf("%d", &val);
            enqueue(val,s1,s2);
            break;

        case 2:
            dequeue(s1,s2);
            break;

        case 3:
            display_queue(s1,s2);
            break;
        }
        printf("Option : ");
        scanf("%d", &opt);
    }
    return 0;
}
/*
SAMPLE I/O:

Choose an option
1. Enqueue
2. Dequeue
3. Display
4. Exit
Option : 1
Enter the value : 1
Option : 1
Enter the value : 2
Option : 1
Enter the value : 3
Option : 2
Option : 1
Enter the value : 4
Option : 3
2 3 4
Option : 4

Time Complexity: O(n) 
Space complexity : O(n)

*/
