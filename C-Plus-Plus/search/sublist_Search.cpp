/*
SUBLIST SEARCH
    to search if a given sublist is present in a mainList using LinkedList.
*/

#include <bits/stdc++.h> 
using namespace std;

//A linkedlist Node
typedef struct Node{
	int data;
	struct Node* next;
}Node;


Node* getNode(int data){
	Node* n = new Node;
	n->data = data;
	n->next = NULL;
	return n;
}

//returns true if the given sublist is found in MainList.
bool searchSublist(Node* mainList,Node* subList){
	Node *main = mainList, *sub = subList;
	//if both the lists are empty, return true.
	if(main == NULL && sub == NULL)
		return true;
	//if one list is empty and other is not return false
	else if(main == NULL ||(main != NULL && sub == NULL))
		return false;
	
	while(mainList != NULL){
		main = mainList;
		//searching for the sublist in mainlist.
		while(sub != NULL){
			if(main == NULL)
				return false;
			else if(main->data == sub->data){
				main = main->next;
				sub = sub->next;
			}else
				break;
		}

		//if the sub list is completely found in Main list, succesful search.
		if(sub == NULL)
			return true;
		sub = subList;
		mainList = mainList->next;
	}
	return false;
}

Node* insertToList(Node* head,int data){
	if(head == NULL){
		head = getNode(data);
	}else{
		Node *ptr = head;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = getNode(data);
	}
	return head;
}

int main(){
	Node *mainHead = NULL,*subHead = NULL;
	int data,sizeMainlist,sizeSublist;
	//Input MainList in which search is to be done
	cout<<"Enter number of elements in Main List: ";
	cin>>sizeMainlist;
	cout<<"Enter Main List: ";
	for(int i=0;i<sizeMainlist;i++){
		cin>>data;
		mainHead = insertToList(mainHead,data);
	}
	//Input sublist which is to searched for
	cout<<"Enter number of elements in Sub List: ";
	cin>>sizeSublist;
	cout<<"Enter Sub List: ";
	for(int i=0;i<sizeSublist;i++){
		cin>>data;
		subHead = insertToList(subHead,data);
	}

	//Printing the search result
	if(searchSublist(mainHead,subHead))
		cout<<"SEARCH SUCCESSFUL";
	else
		cout<<"SEARCH UNSUCCESSFUL";
	return 0;
}


/*
Time Complexity: O(sizeMainlist * sizeSublist)

CASE 1:
MAIN: 1 2 3 4 5 6 7 8
SUB: 2 3 4
Expected Output: SEARCH SUCCESSFUL

CASE 1:
MAIN: 1 44 3 13 12 6 19 8
SUB: 13 12 12
Expected Output: SEARCH UNSUCCESSFUL

*/

