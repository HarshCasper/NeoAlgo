//Implementation of all the basic functionality of queue using array.

#include<iostream>
using namespace std;
class QueueUsingArray
{
    int *data;
    int nextindex;    //Index where the element should be inserted
    int firstindex;    //Index where top value is stored
    int size;    //The no. of elements present in queue
    int capacity;   //The total size of queue
public:
    QueueUsingArray(int num)
    {
        data = new int[num];
        nextindex = 0;      //indexing start from 0
        firstindex = -1;    //firstindex is initialised by -1 because till now we don't have any element as top .
        size = 0;
        capacity = num;
    }
    int getSize()     //Return the number of elements present in queue
    {
        return size;
    }
    bool isEmpty()     //Indicate whether the queue is empty or not
    {
        return size == 0;
    }
    void enqueue()     //function to insert an element at the rear of the queue
    {
        int element;
        cout<<"Enter the Element to be inserted in queue  ";
        cin>>element;
        if(size == capacity)
        {
            cout<<"Queue is Full !"<<endl;
            return;
        }
        cout<<"Insertion is successfull !"<<endl;
        data[nextindex]=element;
        nextindex = (nextindex+1)% capacity;
        if(firstindex == -1)
        {
            firstindex = 0;
        }
        size++;    //increament the size when a new  element is inserted
    }
    int front()     //Return the top value of queue
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }
        return data[firstindex];

    }
    int dequeue()     //function to delete an element from the front of the queue
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty!"<<endl;
            return 0;
        }
        int ans = data[firstindex];
        firstindex = (firstindex+1)% capacity;    //modify the firstindex value to top value index
        size--;
        cout<<"Deletion is successfull !"<<endl;
        return ans;
    }
};
int main()
{
    int num;
    cout<<"Enter the no. of element to be inserted in queue :";
    cin>>num;
    QueueUsingArray q(num);    // Create a queue of capacity num

    int choice;
    do
    {
        cout<<"\n1.Insertion of Element\n2.Deletion of Element\n3.Displat top value of queue\n4.Size of queue\n5.Is Empty\n6.Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            q.enqueue();
            break;
        case 2:
            cout << "Pop  value from the queue : "<<q.dequeue() << endl;
            break;
        case 3:
            cout << "Top value of queue : "<<q.front() << endl;
            cout<<"Displaying top value function of queue is Successfull !"<<endl;
            break;
        case 4:
            cout << "Total element in the queue : "<<q.getSize() << endl;
            cout<<"Size function is Successfull !"<<endl;
            break;
        case 5:
            cout << "Isempty "<<q.isEmpty() << endl;
            cout<<"IsEmpty function is Successfull !"<<endl;
            break;
        case -1:
            choice = -1;
            cout<<"Exit Function is Successfull !"<<endl;
            break;
        default:
            cout<<"\nEnter a valid choice!!";
        }
    }
    while(choice != -1);
}
