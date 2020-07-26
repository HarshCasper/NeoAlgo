/*Implementation of Queue using linked list U can peerfom enqueue , dequeue and display elements of queue */

#include<iostream>
using namespace std;

class Node{
    int data;
    Node *next;
    public:
    friend class queue;
};


class queue{
    Node *front , *rear;
    public:
    queue(){
        front=rear=NULL;

    }
    void enQueue(int x){
        
        if(rear==NULL){
            Node *temp = new Node();
            temp->data = x;
            temp->next=NULL;
            rear=temp;
            front=rear;
        }
        else{
        Node *temp = new Node();
        temp->data = x;
        temp->next = NULL;
        rear->next = temp;
        rear = temp;
        }
        
    }
    void deQueue(){
        // Node *temp = front;
        if(front==NULL)
        {
            return;
        }
        Node * temp = front;
        front = front->next;
        
        if(front==NULL){
            rear = NULL;
        }
        cout<<"Deleted Elemeted is :"<<temp->data<<endl;
        free(temp);
   
    }
    void displayQueue(){
        Node *temp = front;
        if((front==NULL) || (rear==NULL)){
            cout<<"Queue is empty!!"<<endl;
            return;
        }
        cout<<"Queue Elements are :"<<endl;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp= temp->next;
        }
        cout<<endl;
    }

};

int main(){
    queue q;
    int ch;
    do{
        cout<<"Enter the option below :\n1.Enqueue an Element \n2.Dequeue an Element \n3.Display all elements of a queue\n4.Exit \n";
        cin>>ch;
        switch(ch){
            case 1:
            int k;
            cin>>k;
            q.enQueue(k);
            break;
            case 2:
            q.deQueue();
            break;
            case 3:
            q.displayQueue();
            break;
        }
    }while(ch!=4);
}


