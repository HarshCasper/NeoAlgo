#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;

} *first = NULL;

void create(int value)
{

    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    t->next = NULL;

    if (first == NULL)
        first = t;

    else
    {

        struct Node *p = first;
        while (p->next != NULL)
            p = p->next;
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

void insertSorted(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    struct Node *p = first;
    struct Node *prev = NULL;
    while (t->data > p->data && p->next != NULL)
    {
        prev = p;
        p = p->next;
    }
    if (t->data > p->data)
    {
        prev = p;
        p = p->next;
    }
    if (prev == NULL)
    {
        t->next = first;
        first = t;
    }
    else
    {
        t->next = prev->next;
        prev->next = t;
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
    insertSorted(4);
    display(first);

    return 0;
}