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
}

int len()
{
    int l = 0;

    struct Node *p = first;
    while (p->next != first)
    {
        l++;
        p = p->next;
    }
    return l;
}

void insAny(int value, int pos)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = value;
    struct Node *p;
    p = first;

    if (pos == 1)
    {
        t->next = first;

        while (p->next != first)
        {
            p = p->next;
        }

        first = t;
        p->next = first;
        return;
    }
    --pos;
    while (--pos != 0)
    {

        p = p->next;
    }
    struct Node *q = p->next;
    p->next = t;
    t->next = q;
}

void delAny(int pos)
{
    struct Node *p = first;
    struct Node *q;
    if (pos == 1)
    {
        while (p->next != first)
        {
            p = p->next;
        }

        q = first->next;
        p->next = q;
        free(first);
        first = q;
    }

    else if (pos == len())
    {
        while (p->next->next != first)
        {
            p = p->next;
        }

        q = p->next;
        p->next = first;

        free(q);
    }

    else

    {
        --pos;
        while (--pos)
        {
            p = p->next;
        }
        q = p->next;

        p->next = p->next->next;
        free(q);
    }
}

void search(int key)
{

    struct Node *p = first;

    while (p->next != first && p->data != key)
    {
        if (p->data == key)
        {
            printf("Found\n");
            return;
        }

        p = p->next;
    }
    printf("Not found\n");
    return;
}

void sortedInsert(int x)
{

    struct Node *p = first;
    struct Node *prev = NULL;

    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    while (t->data > p->data && p->next != first)
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
        while (p->next != first)
            p = p->next;
        first = t;
        p->next = first;
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
    printf("Enter size of list: ");
    scanf("%d", &n);

    printf("Enter elements: \n ");
    for (int i = 0; i < n; i++)
    {
        int element;
        scanf("%d", &element);
        create(element);
    }
    len();
    // insAny(10, 4);
    // search(4);
    // delAny(5);
    sortedInsert(1);
    display(first);
}