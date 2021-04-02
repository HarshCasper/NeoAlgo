/*
 Author: Sarthak Saxena (@Sarthak-9)

 A Linked List is a linear data structure which includes a series of connected nodes. Each node stores the data and the address of the next node.
 Middle Element can be extracted using following two methods :
 Method 1 - MiddleNode1 finds the length of the linked list and the prints the data at position length/2.
 Time complexity of MiddleNode1 : O(n)
 Space Complexity of MiddleNode1 : O(1)
 Method 2 - MiddleNode2 is an optimized approach which uses two pointers namely slow and fast pointers. The fast pointer moves two steps in each iteration while the slow pointer jumps only one step.
 When the fast pointer reaches the end, the slow pointer reaches the middle element and its data is printed.
 Time complexity of MiddleNode2 : O(n/2)
 Space Complexity of MiddleNode2 : O(1)
*/

#include <iostream>
#include <cmath>

using namespace std;

class Node{
public:
        int data;
        Node* next;
};

Node* head = new Node;

void create(int arr[], int n){
        Node* temp;
        Node* tail;

        head->data = arr[0];
        head->next = nullptr;
        tail = head;

        // creates the linked list from array
        for (int i = 1; i < n; i++){
                temp = new Node;
                temp->data = arr[i];
                temp->next = nullptr;
                tail->next = temp;
                tail = temp;
        }
}

// counts the length of list and prints the value at length/2
void MiddleNode1(Node* p){

        int length = 0;

        // counts the length
        while (p){
                length++;
                p = p->next;
        }

        int index = (int) ceil(length / 2.0);

        Node* q = head;

        // traverses to the middle element
        for (int i = 0; i < index - 1; i++){
                q = q->next;
        }
        cout << "Middle Element (Method-I): " << q->data << endl;
}

// uses two pointers where 1st jumps two steps to reach end while the 2nd reaches middle element
void MiddleNode2(Node* p){

        Node* q = p;

        while (q){

                // q jumps two steps
                q = q->next;
                if (q){
                        q = q->next;
                }

                // p jumps one step
                if (q){
                        p = p->next;
                }
        }
        cout << "Middle Element (Method-II): " << p->data << endl;
}

int main() {

        int n;
        cout<<"Enter the size of list"<<endl;
        cin>>n;
        int arr[n];
        cout<<"Enter the elements of linked list"<<endl;

        // inputs the list in an array
        for(int i = 0; i < n; i++){
                cin>>arr[i];
        }

        create(arr,n);

        MiddleNode1(head);
        MiddleNode2(head);

        return 0;
}

/*

 Input :
 Enter the size of list
 8
 Enter the elements of linked list
 45 24 32 72 54 18 90 65

 Output :
 Middle Element (Method-I): 72
 Middle Element (Method-II): 72

*/
