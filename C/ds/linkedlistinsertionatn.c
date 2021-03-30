//Linked List: Inserting a node at nth position
#include <stdio.h>
#include <stdlib.h>
struct Node{ //creating a node
	int data;
	struct Node* next;
};
struct Node* head;
void Insert(int data,int n){ //inserting the entered data at nth position
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = data;
	temp1->next = NULL;
	if(n==1){
		temp1->next=head;
		head = temp1;
		return;
	}
	struct Node* temp2 = head;
	int i;
	for(i=0;i<n-2;i++){
		temp2=temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}
void Print(){
	//function to print the linkedlist
	struct Node* temp = head;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
		
	}
	printf("\n");
}
int main(){
	head = NULL;  //empty list
	Insert(2,1); //List: 2
	Insert(3,2); //List: 2 3
	Insert(4,1); //List: 4 2 3 
	Insert(5,2); //List: 4 5 2 3
	Print();
	
}
