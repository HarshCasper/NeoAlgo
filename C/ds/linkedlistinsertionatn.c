//Linked List: Inserting a node at nth position
#include <stdio.h>
#include <stdlib.h>
struct Node{ //creating a node
	int data;
	struct Node* next;
};
struct Node* head = NULL;
void Insert(int data){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));//creating new node
	temp->data = data;
	temp->next = NULL;
	if(head!=NULL) temp->next = head;
	head = temp;
}
void Insert_at_pos_n(int data,int pos){ //inserting the entered data at nth position
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = data;
	struct Node* temp2 = head;
	
	if(pos == 1){
		temp1->next=temp2;
		head = temp1;
		return;
	}
	
	int i;
	for(i=1;i<pos-1;i++){//moving to pos-1th place in linkedlist
		temp2=temp2->next;
	}
	temp1->next = temp2->next;//linking newly created node point to next node of temp1
	temp2->next = temp1;      //linking temp1 point to newly created node 
}
void Print(){
	//function to print the linkedlist
	struct Node *temp = head;
	printf("\nList: ");
	while(temp != NULL){
		printf("%d ",temp->data);
	
	temp = temp->next;
}
	printf("\n");
}
int main(){
	int i, n, pos, data;
	printf("Enter the number of elements in the linkedlist: \n");
	scanf("%d",&n);
	printf("Enter the elements of the linkedlist: \n");
	for(i=0;i<n;i++){
		scanf("%d",&data);
		Insert(data);
	}
	Print();
	printf("Enter the element to insert in the linkedlist: \n");
	scanf("%d",&data);
	printf("Enter the position at which the element should be inserted in the linkedlist: \n");
	scanf("%d",&pos);
	if(pos > n){
		printf("You entered an invalid position");
	}
	else{
		Insert_at_pos_n(data,pos);
	}
	Print();
	return 0;
	printf("\n");
	
	
	
}

//Sample Output;
//Enter the number of elements in the linkedlist:
//5
//Enter the elements of the linkedlist:
//8
//64
//34
//74
//8

//List: 8 74 34 64 8
//Enter the element to insert in the linkedlist:
//77
//Enter the position at which the element should be inserted in the linkedlist:
//3

//List: 8 74 77 34 64 8

//Time Complexity: O(n)
//Space Complexity: O(n)
