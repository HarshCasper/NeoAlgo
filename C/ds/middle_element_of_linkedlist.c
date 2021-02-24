/*
A program written in C language to detect the middle element of a linkedlist. 
The approach used is the Two-pointer Approach. 
In this approach, we use 2 pointers, assign both to the head. We move the first pointer by one mode and the other pointer by two nodes, such that when the second pointer reaches the end, the first pointer reaches the middle. Hence, we are able to detect the middle element of the linkedlist.
*/
#include<stdio.h>  
#include<stdlib.h>  
  
/*Defining a Node*/
struct Node  
{  
    int val;  
    struct Node* next;  
};  
/*Fuction to dtetct the middle element*/
void detectMiddle(struct Node *head)  
{  
    struct Node *first_ptr = head;  
    struct Node *second_ptr = head;  
  
    if (head!=NULL)  
    {  
        while (second_ptr != NULL && second_ptr->next != NULL)  
        {  
            second_ptr = second_ptr->next->next;  
            first_ptr = first_ptr->next;  
        }  
        printf("The middle element is %d\n", first_ptr->val);  
    }  
}  
/*A Function to push the element at the end of the linkedlist*/  
void push(struct Node** head_ref, int new_data)  
{  
    
    struct Node* new_node =  
        (struct Node*) malloc(sizeof(struct Node));  
  
    
    new_node->val = new_data;  
  
   
    new_node->next = (*head_ref);  
  
    
    (*head_ref) = new_node;  
}  
/* Driver function*/
int main()  
{  
    struct Node* head = NULL;  
    int i;
    printf("Enter the number of elements in the linkedlist "); 
    scanf("%d",&i); 
    for (int p=i; p>0; p--)  
    {  
        int c;
        printf("\nEnter the element ");
        scanf("%d",&c);
        push(&head, c);  
    }  
     detectMiddle(head); 
    return 0;  
}  

/*
Output: 
Enter the number of elements 5
Enter the element 2
Enter the element 3
Enter the element 1
Enter the element 6
Enter the element 7
The middle element is 1
*/