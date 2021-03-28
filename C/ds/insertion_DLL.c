#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head,  *tail;

void create();
void insert_at_beg();
void insert_at_end();
void insert_at_pos();
void insert_after_pos();
void display();

void create(int n){
	struct node *newnode;
	int i,data;
	head = NULL;
	if(n>=1){
		head = (struct node*)malloc(sizeof(struct node));
		if(head !=NULL){
			printf("Enter data in node 1 - ");
			scanf("%d",&head->data);
			head->prev  =NULL;
			head->next = NULL;
			tail = head;
			for(i=2;i<=n;i++){
			newnode = (struct node*)malloc(sizeof(struct node));
           	printf("Enter data in %d - ",i);
         	scanf("%d", &newnode->data);
            newnode->prev = tail;
         	newnode->next = NULL;
	         
	         
		tail->next = newnode;
		tail = newnode;
			}
		}

	else{
		printf("Unable to allocate");
	
	}	}
}

void insert_at_beg(){
	struct node *newnode;
	newnode  =(struct node*)malloc(sizeof(struct node));
	printf("Enter Data - ");
	scanf("%d",&newnode->data);
	newnode->prev= NULL;
	newnode->next = NULL;
	
	head->prev = newnode;
	newnode->next = head;
	head = newnode;
}

void display(){
	struct node *temp;
	int n=1;
	if(head == NULL)
	printf("Empty List");
	else{
		temp = head;
		while(temp!=NULL){
			printf("%d\t",temp->data);
			n++;
			temp = temp->next;
		}
	}
}

void insert_at_end(){
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter Data - ");
	scanf("%d", &newnode->data);
	newnode->prev = NULL;
	newnode->next = NULL;
	
	tail->next = newnode;
	newnode->prev = tail;
	tail = newnode;
}

void insert_at_position(){
	int pos;
	printf("Enter position - ");
	scanf("%d",&pos);
	if(pos == 0)
	printf("Invalid");
	
	else {
	if(pos == 1)
	insert_at_beg();
    
    
    else{
    	struct node *newnode, *temp;
    	temp = head;
    	int i;
    	newnode = (struct node*)malloc(sizeof(struct node));
    	printf("Enter data - ");
    	scanf("%d",&newnode->data);
    	while(i<pos-1){
    		temp = temp->next;
    		i++;
		}
		newnode->prev = temp;
		newnode->next = temp->next;
		temp->next = newnode;
		
		newnode->next->prev  =newnode;
	}
}}
int main(){
	int n;
	printf("Enter the length - ");
	scanf("%d",&n);
	create(n);
	printf("\nCalling insert at beg\n");
	insert_at_beg();
	display();
	printf("\nCalling insert at end\n");
	insert_at_end();
	display();
	printf("\nCalling insert at pos\n");
	insert_at_position();
	display();
}
