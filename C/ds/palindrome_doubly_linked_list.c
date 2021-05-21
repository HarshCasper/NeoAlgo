/*
DOUBLY LINKED LIST TO CHECK IF A STRING IS PALINDROME
A string is accepted as input from the user.
The characters in the string are inserted as nodes
into the doubly linked list.
Two pointers lptr and rptr are used to point to the
beginning and end of the string respectively.
The list is traversed from left to right using lptr
and right to left using rptr.
If the characters match until they reach the same node
the string is palindrome
*/

#include <stdio.h>
#include <stdlib.h>

//structure for doubly linked list
typedef struct node
{
    char data;
    struct node *rlink;
    struct node *llink;
} node;

//to insert into doubly linked list
void insert(node *head, char a)
{
    node *n = malloc(sizeof(node));
    n->data = a;
    n->rlink = NULL;
    node *ptr = head;
    while (ptr->rlink)
        ptr = ptr->rlink;
    ptr->rlink = n;
    n->llink = ptr;
}

//to check if the string is palindrome
int palindrome(node *head)
{
    if (head->rlink == NULL)
        return 1;
    node *rptr = head;
    while (rptr->rlink)
        rptr = rptr->rlink;
    node *lptr = head->rlink;
    while (lptr != rptr)
    {
        if (lptr->data != rptr->data)
            return 0;
        lptr = lptr->rlink;
        rptr = rptr->llink;
    }
    return 1;
}

//driver code
void main()
{
    node *head = malloc(sizeof(node));
    char str[30];
    printf("Enter a string : ");
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++)
        insert(head, str[i]);
    if (palindrome(head) == 1)
        printf("%s is a palindrome\n", str);
    else
        printf("%s is not a palindrome\n", str);
}

/*
SAMPLE I/O:
Enter a string : refer
refer is a palindrome

Time Complexity: O(n)
Space Complexity: O(n)
*/
