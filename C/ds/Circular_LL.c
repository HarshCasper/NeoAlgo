#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node * next;
}node;

node * insert_at_beg(node *,int);
node * insert_at_pos(node *,int,int);
node * insert_at_end(node *,int);
node * delete_at_beg(node *);
node * delete_at_pos(node *,int);
node * delete_at_end(node *);
node * count_length(node *);
node * display(node *);
node * check_empty(node *);
int search_element(node *,int);
void sortList(node *);
void reverseList(node **); 

node * insert_at_beg(node *head,int value)
{
    node *temp1=(node *)malloc(sizeof(node));
    temp1->data=value;
    if(head==NULL)
    {
        head=temp1;
        temp1->next=head;
    }
    else
    {
        temp1->next = head;
        node *ptr1 = head;
        while(ptr1->next != head)
        {
            ptr1= ptr1->next;
        }
        ptr1->next = temp1;
        head = temp1;
    }
    return head;
}

node * insert_at_pos(node *head,int value,int pos)
{
    node *temp2=(node *)malloc(sizeof(node));
    temp2->data=value;
    if(head==NULL)
    {
        printf("List is Empty.Inserting at beginning");
        head=insert_at_beg(head,value);
    }
    else if(pos==1)
        head=insert_at_beg(head,value);
    else
    {
        node *ptr2 = head;
        for(int i=2; i<=pos-1; i++)
        {
            ptr2 = ptr2->next;
        }
        temp2->next = ptr2->next;
        ptr2->next = temp2;
    }
    return head;
}

node * insert_at_end(node *head, int value)
{
    node *temp3=(node *)malloc(sizeof(node));
    temp3->data=value;
    node *ptr3=head;
    while(ptr3->next !=head)
        ptr3=ptr3->next;
    ptr3->next=temp3;
    temp3->next=head;
    return head;
}

node * delete_at_beg(node *head)
{
    if(head==NULL)
        printf("\n UNDERFLOW \n");
    else
    {
        node * temp4=head;
        while(temp4->next != head)
            temp4=temp4->next;
        head=head->next;
        printf("\n Deleted First Node\n");
        temp4->next=head;
    }
    return head;
}

node * delete_at_pos(node *head,int pos)
{
    node *temp5=(node *)malloc(sizeof(node));
    if(head==NULL)
    {
        printf("List is Empty.Nothing to delete.");
    }
    else if(pos==1)
        head=delete_at_beg(head);
    else
    {
        node *ptr5 = head;
        int i=1;
        while(i<pos)
        {
            temp5=ptr5;
            ptr5=ptr5->next;
            i++;
        }
        temp5->next = ptr5->next;
        free(ptr5);
    }
    return head;
}

node * delete_at_end(node * head)
{
    if(head==NULL)
        printf("\n UNDERFLOW\n");
    else if(head->next==head)
    {
        head=NULL;
        printf("\nDELETED\n");
    }
    else
    {
        node * temp6=head;
        node *ptr6=(node *)malloc(sizeof(node));
        while(temp6->next !=head)
        {
            ptr6=temp6;
            temp6=temp6->next;
        }
        ptr6->next=temp6->next;
        printf("\nDELETED LAST NODE\n");
    }
    return head;
}

node *count_length(node *head)
{
    int count=0;
    if(head==NULL)
    {
        printf("No of elements = 0");
    }
    else
    {
        node *temp7=(node *)malloc(sizeof(node));
        temp7=head;
        do{
            count++;
            temp7=temp7->next;
        }while(temp7 !=head);
        printf("Length of list : %d",count);
    }
    return head;
}

node * display(node *head)
{
    node *temp8;
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp8=head;
        do {
            printf("%d---->", temp8->data);
            temp8 = temp8->next;
        }while(temp8 != head);
    }
    return head;
}

node * check_empty(node *head)
{
    if(head==NULL)
        printf("List is empty");
    else
        printf("List is not empty");
    return head;
}

int search_element(node *head,int key)
{
    int j = 0;
    node *temp9 = head;
    do 
    {
		if (temp9 == NULL)
			return 0;
		
		if (temp9->data == key)
			return j;
        temp9 = temp9->next;
		j++;
    } while (temp9 != head);
    return -1;
}

void sortList(node *head)
{  
    node *temp10 = head;
    node *ptr10 = NULL;  
    int x;  
    if(head == NULL)  
        printf("List is empty");  
    else {  
        do{  
            ptr10 = temp10->next;  
            while(ptr10 != head) {  
                if(temp10->data > ptr10->data) {  
                    x =temp10->data;  
                    temp10->data= ptr10->data;  
                    ptr10->data = x;  
                }  
                ptr10= ptr10->next;  
            }  
            temp10 =temp10->next;  
        }while(temp10->next != head);   
    }  
}  

void reverseList(struct node **head) 
{
    struct node *prev, *cur, *next, *last;
    if (*head == NULL)
        printf("Cannot reverse empty list.\n");
    else
    {   last = *head;
        prev  = *head;
        cur   = (*head)->next;
        *head = (*head)->next;
        while (*head != last)
        {
            *head = (*head)->next;
            cur->next = prev;
            prev = cur;
            cur  = *head;
        }
        cur->next = prev;
        *head = prev;
    }
}


void main()
{
    node *head=NULL;
    int element,position,index;
    int choice=0;

    while (choice !=6)
    {
        printf("1-> Insert at beginning\n");
        printf("2-> Insert at position\n");
        printf("3-> Insert at end\n");
        printf("4-> Delete at beginning\n");
        printf("5-> Delete at position\n");
        printf("6-> Delete at end\n");
        printf("7-> Count No of nodes\n");
        printf("8-> Display \n");
        printf("9-> Check Empty \n");
        printf("10-> Search Element\n");
        printf("11-> Sort List\n");
        printf("12-> Reverse List\n");
        printf("13-> Exit\n");
        printf(" Enter Choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element\n");
                    scanf("%d",&element);
                    head=insert_at_beg(head,element);
                    printf("INSERTED\n");
                    break;
                    
            case 2: printf("Enter the element\n");
                    scanf("%d",&element);
                    printf("Enter the position\n");
                    scanf("%d",&position);
                    head=insert_at_pos(head,element,position);
                    printf("INSERTED\n");
                    break;

            case 3: printf("Enter the element\n");
                    scanf("%d",&element);
                    head=insert_at_end(head,element);
                    printf("INSERTED\n");
                    break;
                    
            case 4: head=delete_at_beg(head);
                    head=display(head);
                    printf("\n");
                    break;
            
            case 5:printf("Enter the position\n");
                    scanf("%d",&position);
                    head=delete_at_pos(head,position);
                    printf("DELETED\n");
                    break;
                    
            case 6: head=delete_at_end(head);
                    head=display(head);
                    printf("\n");
                    break;
                    
            case 7: head=count_length(head);
                    printf("\n");
                    break;
                    
            case 8: head=display(head);
                    printf("\n");
                    break;
                    
            case 9: head=check_empty(head);
                    printf("\n");
                    break;
                    
            case 10:printf("Enter element to search: ");
				    scanf("%d", &element);
				    index = search_element(head, element);
				    if (index == -1)
					    printf("%d not found in list.\n", element);
				    else 
                	    printf("%d found at %d position.\n", element, (index + 1));
                    break;
                    
            case 11:sortList(head);
                    break;
                    
            case 12: reverseList(&head);
                    printf("List reversed.\n");
                    break; 

            case 13: exit(0);
                    break;
                    
            default:printf("\nInvalid Choice !!\n");
                    break;
        }
    }
}


