#include <stdio.h> //headers
#include <stdbool.h>
#define size 5  //the size of the queue we are taking here

typedef struct //defining a structure
{
    int data[5]; // creating the queu structure with data, front and rear nodes pointing to front and the last(behind) node
    int front;//a node containg the value of a pointer/address pointing to the front node
    int rear;//a node containing the value of a pointer/address pointing to the back/behind/rear node
} mainf;

mainf st;//the name of the structure
//we will be referencing our structure with st in the code below

//In the circular queue, in the last node, the front pointer points to the first node.

int enque(int number)
{ // adding a value to the queue
    if (st.front == st.rear + 1) //if the queue is full user cant add anything more
    {
        printf("Queue is full!\n");
    }
    else if (st.rear == size - 1)
    {
        st.rear = 0;
        printf("Rear resetted to one.\n");
    }
    else
    {
        st.rear++;
        st.data[st.rear] = number; //adding the value to the queue
        printf("%d -> Added! \n", st.data[st.rear]);
    }
}

void dequeue()
// removing a specific node fromt he queue
{
    int out;
    st.front++;
    out = st.data[st.front];

    printf("%d -> Removed! \n", out);
}

int main(void)
{
    int user, value;
    st.front = -1; //setting the front pointer to null
    st.rear = -1; //setting the rear pointer to null
    // this means that our queue is empty rn
    bool out = true;
    //to ensure user selects some good/valid option from below

    printf("Enter 1 to enqueue queue.\n");
    printf("Enter 2 to dequeue queue.\n");
    printf("Enter 3 to exit.\n");
    while (out = true)
    {
        scanf("%d", &user);

        if (user == 1)
        {
            printf("Enter a value to enqueue : ");
            scanf("%d", &value);
            enque(value);//entering an element at the back
            out = true;
        }
        else if (user == 2)
        {
            dequeue();//to remove the first element
            out = true;

        }
        else if (user == 3)
        {
            out == false;
            return 0;
        }
        else
        {
            out = false;
            return 0;
        }
    }
}