/*
This is singly linked list implementation in which 
a unique key has to be given while entering the new node to the linked list,
and you cannot give same key to the different node.
*/

#include <iostream>
using namespace std;

class Node
{
public:
	int key; //key = index of particular node in linked list
	int data;
	Node *next;

	Node()
	{
		key = 0;
		data = 0;
		next = NULL;
	}
	Node(int k, int d)
	{
		int key = k;
		int data = d;
	}
};

class sll
{
public:
	Node *head;

	sll()
	{
		head = NULL;
	}
	sll(Node *n)
	{
		head = n;
	}

	// nexist : checks wether node exist in the linked list or not
	Node *nexist(int k) //k= key value
	{
		Node *temp = NULL;
		Node *ptr = head;

		while (ptr != NULL)
		{
			if (ptr->key == k)
			{
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
	}

	// appendnode : adds the new node at the end of the linked list
	void appendnode(Node *n) //n= new node
	{
		if (nexist(n->key) != NULL)
		{
			cout << "Entered node exist " << n->key << endl;
		}
		else
		{
			if (head == NULL) //assuming that node is empty
			{
				head = n;
				cout << "Node appended" << endl;
			}
			else //assuming that node stores some data
			{
				Node *ptr = head;
				while (ptr->next != NULL)
				{
					ptr = ptr->next;
				}
				ptr->next = n;
				cout << "Node appended " << endl;
			}
		}
	}

	// prependnode : adds the node at the head of the linked list
	void prependnode(Node *n)
	{
		if (nexist(n->key) != NULL)
		{
			cout << "Node already exist = " << n->key << endl;
		}
		else
		{
			n->next = head;
			head = n;
			cout << "Node prepended " << endl;
		}
	}

	// insertnode : insert new node in the middle of the linked list.
	void insertnode(int k, Node *n)
	{
		Node *ptr = nexist(k);
		if (ptr == NULL) //checking wether the entered key node exist or not
		{
			cout << "No node exist with this key value = " << k << endl;
		}
		else
		{
			if (nexist(n->key) != NULL)
			{
				cout << "Node already exist with same key value = " << n->key << endl;
			}
			else
			{
				n->next = ptr->next;
				ptr->next = n;
				cout << "Node inserted " << endl;
			}
		}
	}

	// dnode : to delete the node from the linked list
	void dnode(int k)
	{
		if (head == NULL)
		{
			cout << "Node is empty " << endl;
		}
		else if (head != NULL)
		{
			if (head->key == k) // assuming that the head is being deleted
			{
				head = head->next;
				cout << "Node deleted " << endl;
			}
			else //assuming that any middle or last node is being is deleted
			{
				Node *temp = NULL;
				Node *prevptr = head;
				Node *currentptr = head->next;
				while (currentptr != NULL)
				{
					if (currentptr->key == k)
					{
						temp = currentptr;
						currentptr = NULL;
					}
					else
					{
						prevptr = prevptr->next;
						currentptr = currentptr->next;
					}
				}
				if (temp != NULL)
				{
					prevptr->next = temp->next;
					cout << "Node deleted " << k << endl;
				}
				else
				{
					cout << "No node exist with " << k << " value " << endl;
				}
			}
		}
	}

	// updatenode : by this you have to update the data entered in linked list
	void updatenode(int k, int d)
	{
		Node *ptr = nexist(k);
		if (ptr != NULL)
		{
			ptr->data = d;
			cout << "Node data updated successfully " << endl;
		}
		else
		{
			cout << "Node doesn't exist " << k << " value " << endl;
		}
	}

	// printlist : it prints the linked list
	void printlist()
	{
		if (head == NULL)
		{
			cout << "Node is empty " << endl;
		}
		else
		{
			cout << "\nSingly linked list values are " << endl;
			Node *temp = head;

			while (temp != NULL)
			{
				cout << "(" << temp->key << "," << temp->data << ")-->"
					 << " ";
				temp = temp->next;
			}
			cout << "NULL";
		}
	}
};

int main()
{
	sll s;
	int option;
	int key1, k1, data1;

	do
	{
		cout << "\nWhat operation you want to perform " << endl;
		cout << "1 Append the node or insert the node " << endl;
		cout << "2 Add the node in the begining " << endl;
		cout << "3 Insert the node in between " << endl;
		cout << "4 Delete the node " << endl;
		cout << "5 Update or make correction in the node " << endl;
		cout << "6 Print the node " << endl;
		cout << "7 Clear the screen\n"<< endl;

		cin >> option;
		Node *n1 = new Node();

		switch (option)
		{
		case 0:
			break;
		case 1:
			cout << "Append node operation choosed " << endl;
			cout << "Enter the key " << endl;
			cin >> key1;
			cout << "Enter the data " << endl;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;

			s.appendnode(n1);
			break;
		case 2:
			cout << "Prepend operation choosed " << endl;
			cout << "Enter the key " << endl;
			cin >> key1;
			cout << "Enter the data " << endl;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;

			s.prependnode(n1);
			break;
		case 3:
			cout << "Insert node operation selected " << endl;
			cout << "Enter the key after which you want to insert " << endl;
			cin >> k1;
			cout << "Enter the key " << endl;
			cin >> key1;
			cout << "Enter the data " << endl;
			cin >> data1;
			n1->key = key1;
			n1->data = data1;

			s.insertnode(k1, n1);
			break;
		case 4:
			cout << "Delete node operation selected " << endl;
			s.printlist();
			cout << "Enter the key to be deleted " << endl;
			cin >> k1;
			s.dnode(k1);
			break;
		case 5:
			cout << "Update operation selected " << endl;
			cout << "Enter the key " << endl;
			cin >> key1;
			cout << "Enter the NEW data " << endl;
			cin >> data1;

			s.updatenode(key1, data1);
			break;
		case 6:
			s.printlist();
			break;
		case 7:
			system("cls");
			break;
		default:
			cout << "Enter the proper option : " << endl;
		}
	} while (option != 0);
	{
		cout << "Thank you !!" << endl;
	}
	return 0;
}

/*

Test Case 1 :
input : 1 1 12 2 2 34 3 1 3 24 6
outout: (2,34)--> (1,12)--> (3,24)--> NULL

Test case 2:
input: 1 1 100 1 2 101 4 2 6
outout: (1,100)--> NULL

*/

/*
Time complexity - O(n)

Space complexity - O(n)
*/

