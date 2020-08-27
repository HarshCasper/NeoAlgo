#include <stdio.h>
#include <malloc.h>

typedef struct node
{
    int value;
    struct node *next;
}node;

node* create_node(int);
void insert_node_first();
void insert_node_last();
void insert_node_pos();
void count();
void delete_pos();
void search();
void empty();
void display();

node *newnode, *ptr, *prev, *temp;
node *first = NULL, *last = NULL;

 int main()
 {
    int ch;
    char ans = 'Y';

    while (ans == 'Y'||ans == 'y')
    {
        printf("\n---------------------------------\n");
        printf("\nOperations on singly linked list\n");
        printf("\n---------------------------------\n");
        printf("\n1-Insert node at first");
        printf("\n2-Insert node at last");
        printf("\n3-Insert node at position");
        printf("\n4-Display the total number of nodes");
        printf("\n5-Delete Node from any Position");
        printf("\n6-Check if list is empty or not");
        printf("\n7-Search Element in the linked list");
        printf("\n8-Display List from Beginning to end");
        printf("\n9-Exit\n");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nInserting node at first :\n");
            insert_node_first();
            break;
        case 2:
            printf("\nInserting node at last :\n");
            insert_node_last();
            break;
        case 3:
            printf("\nInserting node at position :\n");
            insert_node_pos();
            break;
        case 4:
            count();
            break;
        case 5:
            delete_pos();
            break;
        case 6:
            printf("\nchecking the list :\n");
            empty();
            break;
        case 7:
            printf("\nSearching Element in the List :\n");
            search();
            break;
        case 8:
            printf("\nDisplaying List From Beginning to End :\n");
            display();
            break;
        case 9:
            printf("\nExiting :\n");
            return 0;
            break;
        default:
            printf("\nInvalid Choice :\n");
            break;
        }
        printf("\nYOU WANT TO CONTINUE (Y/N)");
        scanf(" %c", &ans);
    }
    return 0;
 }

node* create_node(int val)
{
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
    {
        printf("\nMemory was not allocated");
        return 0;
    }
    else
    {
        newnode->value = val;
        newnode->next = NULL;
        return newnode;
    }
}

void insert_node_first()
{
    int val;

    printf("\nEnter the value for the node:");
    scanf("%d", &val);
    newnode = create_node(val);
    if (first == last && first == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        temp = first;
        first = newnode;
        first->next = temp;
    }
    printf("\n----INSERTED----");
}

void insert_node_last()
{
    int val;

    printf("\nEnter the value for the Node:");
    scanf("%d", &val);
    newnode = create_node(val);
    if (first == last && last == NULL)
    {
        first = last = newnode;
        first->next = NULL;
        last->next = NULL;
    }
    else
    {
        last->next = newnode;
        last = newnode;
        last->next = NULL;
    }
 printf("\n----INSERTED----");
}

void insert_node_pos()
{
    int pos, val, cnt = 0, i;

    printf("\nEnter the value for the Node:");
    scanf("%d", &val);
    newnode = create_node(val);
     printf("\nEnter the position ");
    scanf("%d", &pos);
    ptr = first;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        cnt++;
    }
    if (pos == 1)
    {
        if (first == last && first == NULL)
        {
            first = last = newnode;
            first->next = NULL;
            last->next = NULL;
        }
        else
        {
            temp = first;
            first = newnode;
            first->next = temp;
        }
        printf("\nInserted");
    }
    else if (pos>1 && pos<=cnt)
    {
        ptr = first;
        for (i = 1;i < pos;i++)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = newnode;
        newnode->next = ptr;
        printf("\n----INSERTED----");
    }
    else
    {
        printf("Position is out of range");
    }
}


void count()
{
    node *nxt;
    int t = 0;

    if (first == NULL)
    {
        printf("\nEMPTY LIST:");;
    }
    else
    {
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
          t++;
        }
        printf("\nTotal Number of nodes : %d",t);

    }
}


void delete_pos()
{
    int pos, cnt = 0, i;

    if (first == NULL)
    {
        printf("\nEMPTY LIST:");;
        printf(":No node to delete\n");
    }
    else
    {
        printf("\nEnter the position of value to be deleted:");
        scanf(" %d", &pos);
        ptr = first;
        if (pos == 1)
        {
            first = ptr->next;
            printf("\nElement deleted");
        }
        else
        {
            while (ptr != NULL)
            {
                ptr = ptr->next;
                cnt = cnt + 1;
            }
            if (pos > 0 && pos <= cnt)
            {
                ptr = first;
                for (i = 1;i < pos;i++)
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                prev->next = ptr->next;
            }
            else
            {
                printf("Position is out of range");
            }
        free(ptr);
        printf("\nElement deleted");
        }
    }
}

void empty()
{
    int oldval, newval, flag = 0;

    if (first == NULL)
    {
        printf("The list is empty\n");
    }
}


void search()
{
    int flag = 0, key, pos = 0;

    if (first == NULL)
    {
        printf("\nEMPTY LIST:");;
        printf(":No nodes in the list\n");
    }
    else
    {
        printf("\nEnter the value to search");
        scanf("%d", &key);
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
            pos = pos + 1;
            if (ptr->value == key)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            printf("\nElement %d found at %d position\n", key, pos);
        }
        else
        {
            printf("\nElement %d not found in list\n", key);
        }
    }
}

void display()
{
    if (first == NULL)
    {
        printf("\nEMPTY LIST:");;
        printf(":No nodes in the list to display\n");
    }
    else
    {
        for (ptr = first;ptr != NULL;ptr = ptr->next)
        {
            printf("%d\t", ptr->value);
        }
    }
}

/*
Following are the sample of Input/Output processed by this program :

---------------------------------

Operations on singly linked list

---------------------------------

1-Insert node at first
2-Insert node at last
3-Insert node at position
4-Display the total number of nodes
5-Delete Node from any Position
6-Check if list is empty or not
7-Search Element in the linked list
8-Display List from Beginning to end
9-Exit

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter your choice : 1

Inserting node at first :

Enter the value for the node:12

----INSERTED----
YOU WANT TO CONTINUE (Y/N)y

---------------------------------

Operations on singly linked list

---------------------------------

1-Insert node at first
2-Insert node at last
3-Insert node at position
4-Display the total number of nodes
5-Delete Node from any Position
6-Check if list is empty or not
7-Search Element in the linked list
8-Display List from Beginning to end
9-Exit

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter your choice : 2

Inserting node at last :

Enter the value for the Node:13

----INSERTED----
YOU WANT TO CONTINUE (Y/N)y

---------------------------------

Operations on singly linked list

---------------------------------

1-Insert node at first
2-Insert node at last
3-Insert node at position
4-Display the total number of nodes
5-Delete Node from any Position
6-Check if list is empty or not
7-Search Element in the linked list
8-Display List from Beginning to end
9-Exit

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter your choice : 8

Displaying List From Beginning to End :
12      13
YOU WANT TO CONTINUE (Y/N)n

Process returned 0 (0x0)   execution time : 31.014 s
Press any key to continue.
*/
