/************************************************************************

In this Program we will implement Double Ended Queue (de_que)

It contain the following operation
1. enqueue_back(int)
2. enqueue_front(int)
3. dequeue_back()
4. dequeue_front()
5. is_empty()
6. display()
7. display_reverse()
8. size_deque()




**********************************************************************/

#include <bits/stdc++.h>
using namespace std;


struct node {

    node(int x): data(x), next(NULL), privious(NULL) {}
    int data;
    node *next;
    node *privious;
};

class de_que{

    node *head;
    node *tail;
    int n;
public:
   // constructor of tree
    de_que()
    {
        head = NULL;
        tail = NULL;
        n=0;
    }


    void enqueue_back(int x){

        node *tnode = new node(x);
        //if dqueue is empty
        if(is_empty())
        {
            head = tnode;
            tail = tnode;
        }
        //if deque is not empty
        else
        {

            tnode->privious = tail;
            tail->next = tnode;
            tail = tnode;

        }
        n++;

    }
    void enqueue_front(int x){

        node *tnode = new node(x);
        //if deque is empty
        if(is_empty())
        {
            head = tnode;
            tail = tnode;
        }
        //if deque is not empty
        else
        {

            tnode->next = head;
            head->privious = tnode;
            head = tnode;

        }
        n++;

    }
    int dequeue_back(){

        //if deque is empty
        if(is_empty())
        {
            cout<<"Deque is Empty"<<endl;
            return -9999999;

        }
        //if deque is not empty
        else
        {
            n--;
            int temp = tail->data;
            tail = tail->privious;
            tail->next = NULL;
            return temp;
        }


    }
    int dequeue_front(){
        //if deque is empty
        if(is_empty())
        {
            cout<<"Deque is Empty"<<endl;
            return -9999999;

        }
        //if deque is not empty
        else
        {
            n--;
            int temp = head->data;
            head = head->next;
            head->privious = NULL;
            return temp;
        }


    }
    bool is_empty()
        {
            if(n==0)
                return true;
            else
                return false;

        }
    void display()
    {
        node* temp = head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void display_reverse()
    {
        //starting from tail
        node* temp = tail;

        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->privious;
        }
        cout<<endl;
    }

    int size_deque()
    {
        //return the size of de_que
        return n;
    }


};



int main() {

    de_que q;
    q.enqueue_front(5);
    // q will be : 5
    q.enqueue_front(15);
    // q will be : 15 5
    q.display();

    q.enqueue_back(6);
    // q will be : 15 5 6
    q.enqueue_back(20);
    // q will be : 15 5 6 20
    q.display();


    q.display_reverse();

    cout<<q.dequeue_back()<<endl;
    // q will be : 15 5 6
    q.display();

    cout<<"size of deque :"<<q.size_deque()<<endl;

    cout<<q.dequeue_front()<<endl;
    // q will be : 5 6
    q.display();

    cout<<"size of deque :"<<q.size_deque()<<endl;

    q.enqueue_front(25);
    // q will be : 25 15 5 6
    q.enqueue_back(30);
    // q will be : 25 15 5 6 30
    q.enqueue_back(11);
    // q will be : 25 15 5 6 30 11
    q.enqueue_front(35);
    // q will be : 35 25 15 5 6 30 11
    q.display();




}
