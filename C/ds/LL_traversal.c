//Traversal in linked list is used to visit each node of the list until NULL is found.

#include <stdio.h>

#include <stdlib.h>

//First create a self referential structure.

struct node
{
    
    int data;
    
   struct node *next;

};



//Function to traverse the list.

void traversal(struct node *ptr){
 
   printf("Elements are: ");
    
          while(ptr!=NULL){
        
          printf("%d ",ptr->data);
     
          ptr=ptr->next;
    
      }

}

int main()
{
    
//Create the list and allocate the memory dyanamically to the nodes.
    
struct node *head=(struct node*)malloc(sizeof(struct node));
   
struct node *second=(struct node*)malloc(sizeof(struct node));
 
struct node *third=(struct node*)malloc(sizeof(struct node));
 

 //Link the nodes
   
 head->data=7;
    
head->next=second;
    

   
 second->data=9;
   
 second->next=third;
   
 
    
third->data=11;
    
third->next=NULL;
    
   

 traversal(head);
    
return 0;

}
