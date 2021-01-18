#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *next;
    int data;
} *first = NULL;

void create(int value)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Memory could not be allocated");
        return;
    }
    t->data = value;
    t->next = first;
    if (first == NULL)
    {
        first = t;
        first->next = first;
    }
    else
    {
        struct Node *p = first;
        while (p->next != first)
            p = p->next;
        p->next = t;
    }
}

void display(struct Node *p)
{

    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != first);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter size of the list: ");
    scanf("%d", &n);

    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
    {
        int element;
        scanf("%d", &element);
        create(element);
    }
    display(first);

    return 0;
}