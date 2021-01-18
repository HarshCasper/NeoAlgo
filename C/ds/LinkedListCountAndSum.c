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
        return;
    }

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
            p = p->next;
        p->next = t;
    }
}

void displayCountAndSum(struct Node *p)
{
    int c = 0, s = 0;
    while (p != NULL)
    {
        printf("%d ", p->data);
        s = s + p->data;

        p = p->next;
        c++;
    }
    printf("\n Number of nodes: %d\n", c);
    printf("Sum: %d\n", s);
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

    displayCountAndSum(first);

    return 0;
}