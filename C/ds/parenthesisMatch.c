#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;

    struct Node *next;

} *top = NULL;

void push(char x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
    {
        printf("Stack is Full");
    }

    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char pop()
{
    struct Node *t;
    char x = -1;

    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {

        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }

    return x;
}

void display()
{
    struct Node *p;

    p = top;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int isBalanced(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else
        {

            if (top == NULL)
                return 0;

            pop();
        }
    }

    if (top == NULL)
        return 1;
    else
        return 0;
}
int main()
{

    char *exp = "((a+b)*(c-d)))";

    printf("%d ", isBalanced(exp));

    return 0;
}