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
        printf("Memory couldn't be allocated");
    }
    t->data = value;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }

    else
    {

        struct Node *p;
        p = first;

        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf(" %d", p->data);
        p = p->next;
    }
}

void insertEnd(int num)
{
    struct Node *t, *p;
    t = (struct Node *)malloc(sizeof(sizeof(struct Node)));
    if (t == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        t->data = num;
        t->next = NULL;
        p = first;
        while (p->next != NULL)
            p = p->next;
        p->next = t;
    }
}

int main()
{

    int n;
    printf("Enter size of the list: \n");
    scanf("%d", &n);

    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
    {
        int element;
        scanf("%d", &element);
        create(element);
    }
    insertEnd(10);
    display(first);

    return 0;
}