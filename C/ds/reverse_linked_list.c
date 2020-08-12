/**
 * Reversing a linked list in C programming.
 */

#include <stdio.h>
#include <stdlib.h>


/* Structure of a node */
typedef struct node {
    int data; //data storage
    struct node *next; //address storage
}node;

node *head;

/* Functions used in the program */
void create(int n);
void reverse();
void display();


int main()
{
    int n, choice;

    /*
     * Taking number of nodes as input from user
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    create(n);

    printf("\nData in the list \n");
    display();

    /*
     * Reverse the list
     */
    printf("\nPress 1 to reverse the order of linked list\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        reverse();
    }

    printf("\nData in the list\n");
    display();

    return 0;
}


/*
 * Create a list of n nodes
 */
void create(int n)
{
     node *newNode, *temp;
    int data, i;

    if(n <= 0)
    {
        printf("List size can not be zero.\n");
        return;
    }

    head = ( node *)malloc(sizeof( node));

    /*
     * If unable to allocate memory for head node
     */
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        /*
         * Read data of node from the user
         */
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; // Link the data field with data
        head->next = NULL; // Link the address field to NULL

        temp = head;

        /*
         * Create n nodes and adds to linked list
         */
        for(i=2; i<=n; i++)
        {
            newNode = ( node *)malloc(sizeof( node));

            /* If memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; // Link the data  of newNode with data
                newNode->next = NULL; // Link the address  of newNode with NULL

                temp->next = newNode; // Link previous node
                temp = temp->next;
            }
        }

        printf("LINKED LIST CREATED SUCCESSFULLY\n");
    }
}


/*
 * Reverse the order of nodes of a singly linked list
 */
void reverse()
{
    struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; // Make first node as last node

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; // Make last node as head

        printf("SUCCESSFULLY REVERSED THE LINKED LIST\n");
    }
}


void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d\t", temp->data); // Print the data of current node
            temp = temp->next;                 // Move to next node
        }
    }
}
