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
    t->data = value;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }
    else
    {
        struct Node *p = first;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = t;
    }
}

void search(struct Node *p, int x)
{
    p = first;

    while (p->next != NULL)
    {
        if (p->data == x)
        {
            printf("Found");
            break;
        }
        p = p->next;
    }
    if (p->data != x)
        printf("Not found");
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
    struct Node *k;

    search(k, 10);

    return 0;
}