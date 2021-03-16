#include <stdio.h>
#include <malloc.h>

/*
Code Description :
Doubly linked list is a type of linked list in which each node
has a data part and two pointer part. The first pointer points 
to the previous node in the list and the second pointer points 
to the next node in the list.

In the code below we have created the structure of doubly linked list.
We have also provided options to the user to choose among the opearations.

As per the option selected, respective switch-case will execute and function 
will be called. Brief description of each function is also provided below.
*/

struct node
{
    int info;
    struct node *prev,*next;
};

struct node *start = NULL;

//Function Declarations
void insertstart();
void insertlast();
void insertafter(struct node *);
struct node* find ();
void insertat();
void deletefirst();
void deletelast();
void deleteafter();
void viewlist();


int main()
{
    int choice;
    char ans = 'Y';
    
    while(ans == 'Y' || ans == 'y')
    {
        printf("\n\n Operations on doubly linked list");
        printf("\n----------------------------------");
        printf("\n 1- To view the list.");
        printf("\n 2- Insertion of element at starting.");
        printf("\n 3- Insertion of element at end.");
        printf("\n 4- Insertion of element at any position by providing previous element.");
        printf("\n 5- Insertion of element at any position by providing index.");
        printf("\n 6- Deletion of the first element.");
        printf("\n 7- Deletion of the last element.");
        printf("\n 8- Delete an element from any position.");
        printf("\n 9- To exit.");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nEnter your choice : ");
        scanf("%d" , &choice);

        switch(choice)
        {
        case 1:
                viewlist();
                break;
        case 2:
                insertstart();
                break;
        case 3:
                insertlast();
                break;
        case 4:
                insertafter(find());
                break;
        case 5:
                insertat();
                break;
        case 6:
                deletefirst();
                break;
        case 7:
                deletelast();
                break;
        case 8:
                deleteafter();
                break;
        case 9:
        		printf("\nExiting :\n");
                return 0;
                break;
        default:
            printf("\nIncorrect Choice!\n");
            break;
        }
        printf("\nYOU WANT TO CONTINUE (Y/N) : ");
        scanf(" %c", &ans);
    }
    return 0;
}

/*
To insert a node at the starting of the Doubly linked list,
create a new node and make it point by the start pointer.
*/

void insertstart()
{
    int data;
    struct node *temp;
    temp = (struct node*) malloc (sizeof(struct node));
    printf("\nEnter the element : ");
    scanf("%d" , &data);
    temp->info = data;
    temp->prev = NULL;
    temp->next = start;
    start = temp;
}

/*
To insert a node at the end of the Doubly linked list,
create a new node and make it pointed by the previously last node.
*/

void insertlast()
{
    int data;
    struct node *temp , *trav;
    temp = (struct node*) malloc (sizeof(struct node));
    printf("\nEnter the element : ");
    scanf("%d" , &data);
    temp->info = data;
    temp->next = NULL;
    trav = start;
    if(start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        while(trav->next != NULL)
            trav = trav->next;
        temp->prev = trav;
        trav->next = temp;
    }
}

/*
To insert a node at a specific position of the Doubly linked list,
create a new node, traverse the list till the desired position,
make the new node pointed by the previous node. 
Also make the new node point to the previou's next node.
*/

void insertafter(struct node *ptr)
{
    int data;
    struct node *temp;
    temp = (struct node*) malloc (sizeof(struct node));
    if(ptr == NULL)
        printf("\nThe list is empty.\n");
    else
    {
         printf("\nEnter the element : ");
         scanf("%d" , &data);
         temp->info = data;
         temp->prev = ptr;
         temp->next = ptr->next;
         ptr->next->prev = temp;
         ptr->next = temp;
    }
}


struct node* find ()
{
    int data;
    struct node *temp;
    if(start == NULL)
        return NULL;
    else
    {
        printf("\nEnter the element after which you want the insertion : ");
        scanf("%d" , &data);
        temp = start;
        while(temp != NULL)
        {
            if(temp->info == data)
                return temp;
            else
                temp = temp->next;
        }
        return NULL;
    }
}

void insertat()
{
    int data , pos , i=1;
    struct node *temp , *newnode;
    newnode = malloc(sizeof(struct node));
    printf("\nEnter the index/position : ");
    scanf("%d" , &pos);
    printf("\nEnter the element : ");
    scanf("%d" , &data);
    newnode->info = data;
    temp = start;
    if(start == NULL)
    {
        start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    else
    {
        while(i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }

}

/*
To delete the first node, make start ointer point to the next node.
*/

void deletefirst()
{
    struct node *temp;
    if(start == NULL)
        printf("\nThe list is empty.\n");
    else
    {
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
    }
}

/*
To delete the last node, traverse till second last node;
and make it point to NULL.
*/

void deletelast()
{
    struct node *temp;
    if(start == NULL)
        printf("\nThe list is empty.\n");
    else
    {
        temp = start;
        while(temp->next != NULL)
            temp = temp->next;
        if(start->next == NULL)
            start = NULL;
        else
        {
            temp->prev->next = NULL;
            free(temp);
        }
    }
}

/*
To delete a specific node, traverse till that node (lets say current),
use an extra pointer to point its previous node,
now make the previous node point to current node's next node.
*/


void deleteafter()
{
    int pos , i=1;
    struct node *temp , *position;
    temp = start;
    if(start == NULL)
        printf("\nThe list is empty.\n");
    else
    {
        printf("\nEnter the index : ");
        scanf("%d",&pos);
        while(i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        position = temp->next;
        position->next->prev = temp;
        temp->next = position->next;

        free(position);
    }
}

/*
To view the list, use a pointer and make it point to start,
now print the node's data part and make it point to next node. 
Repeat both the steps until the pointer points to NULL.
*/

void viewlist()
{
    if(start == NULL)
        printf("\nThe list is empty.\n");
    else
    {
        struct node *temp;
        temp = start;
        printf("\nThe list is : ");
        while(temp != NULL)
        {
            printf("%d  " , temp->info);
            temp = temp->next;
        }
    }
}

/*Sample Input/Output of this program-

 Operations on doubly linked list
----------------------------------
 1- To view the list.
 2- Insertion of element at starting.
 3- Insertion of element at end.
 4- Insertion of element at any position by providing previous element.
 5- Insertion of element at any position by providing index.
 6- Deletion of the first element.
 7- Deletion of the last element.
 8- Delete an element from any position.
 9- To exit.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter your choice : 2

Enter the element : 10

YOU WANT TO CONTINUE (Y/N) : y


 Operations on doubly linked list
----------------------------------
 1- To view the list.
 2- Insertion of element at starting.
 3- Insertion of element at end.
 4- Insertion of element at any position by providing previous element.
 5- Insertion of element at any position by providing index.
 6- Deletion of the first element.
 7- Deletion of the last element.
 8- Delete an element from any position.
 9- To exit.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter your choice : 3

Enter the element : 20

YOU WANT TO CONTINUE (Y/N) : y


 Operations on doubly linked list
----------------------------------
 1- To view the list.
 2- Insertion of element at starting.
 3- Insertion of element at end.
 4- Insertion of element at any position by providing previous element.
 5- Insertion of element at any position by providing index.
 6- Deletion of the first element.
 7- Deletion of the last element.
 8- Delete an element from any position.
 9- To exit.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter your choice : 4

Enter the element after which you want the insertion : 10

Enter the element : 15

YOU WANT TO CONTINUE (Y/N) : y


 Operations on doubly linked list
----------------------------------
 1- To view the list.
 2- Insertion of element at starting.
 3- Insertion of element at end.
 4- Insertion of element at any position by providing previous element.
 5- Insertion of element at any position by providing index.
 6- Deletion of the first element.
 7- Deletion of the last element.
 8- Delete an element from any position.
 9- To exit.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter your choice : 1

The list is : 10  15  20
YOU WANT TO CONTINUE (Y/N) : y


 Operations on doubly linked list
----------------------------------
 1- To view the list.
 2- Insertion of element at starting.
 3- Insertion of element at end.
 4- Insertion of element at any position by providing previous element.
 5- Insertion of element at any position by providing index.
 6- Deletion of the first element.
 7- Deletion of the last element.
 8- Delete an element from any position.
 9- To exit.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter your choice : 6

YOU WANT TO CONTINUE (Y/N) : y


 Operations on doubly linked list
----------------------------------
 1- To view the list.
 2- Insertion of element at starting.
 3- Insertion of element at end.
 4- Insertion of element at any position by providing previous element.
 5- Insertion of element at any position by providing index.
 6- Deletion of the first element.
 7- Deletion of the last element.
 8- Delete an element from any position.
 9- To exit.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter your choice : 7

YOU WANT TO CONTINUE (Y/N) : y


 Operations on doubly linked list
----------------------------------
 1- To view the list.
 2- Insertion of element at starting.
 3- Insertion of element at end.
 4- Insertion of element at any position by providing previous element.
 5- Insertion of element at any position by providing index.
 6- Deletion of the first element.
 7- Deletion of the last element.
 8- Delete an element from any position.
 9- To exit.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Enter your choice : 1

The list is : 15
YOU WANT TO CONTINUE (Y/N) : n

Process returned 0 (0x0)   execution time : 50.165 s
Press any key to continue.

*/

