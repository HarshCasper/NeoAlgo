//headers
#include <stdio.h> 
#include <stdbool.h>
//defining the size of the queue we are taking here
#define size 5  

//defining a structure
typedef struct 
{
    // creating the queue structure with data, front and rear nodes pointing to front and the last(behind) node
    int data[5]; 
    
    //a node containg the value of a pointer/address pointing to the front node
    int front;
    
    //a node containing the value of a pointer/address pointing to the back/behind/rear node
    int rear;
} mainf;

//the name of the structure
mainf queuestructure;

//In the circular queue, in the last node, the front pointer points to the first node.
int enque(int number)
{ 
    //adding a value to the queue
    //if the queue is full user cant add anything more
    if (queuestructure.front == queuestructure.rear + 1) 
    {
        printf("Queue is full!\n");
    }
    else if (queuestructure.rear == size - 1)
    {
        queuestructure.rear = 0;
        printf("Rear resetted to one.\n");
    }
    else
    {
        queuestructure.rear++;
        //adding the value to the queue
        queuestructure.data[queuestructure.rear] = number; 
        printf("%d -> Added! \n", queuestructure.data[queuestructure.rear]);
    }
}


void dequeue()
//removing a specific node from the queue
{
    //the element which is being removed
    int out;
    queuestructure.front++;
    out = queuestructure.data[queuestructure.front];

    printf("%d -> Removed! \n", out);
}

int main(void)
{
    int user, value;
    //setting the front pointer to null
    queuestructure.front = -1; 
    //setting the rear pointer to null
    queuestructure.rear = -1; 
    //this means that our queue is empty at the beginning
    bool out = true;

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
            //entering an element at the back
            enque(value);
            out = true;
        }
        else if (user == 2)
        {
            //to remove the first element
            dequeue();
            out = true;
        }
        else
        {
            out = false;
            return 0;
        }
    }
}


/*
Output:

Enter 1 to enqueue queue.                                                                                                                       
Enter 2 to dequeue queue.                                                                                                                       
Enter 3 to exit.                                                                                                                                
1                                                                                                                                               
Enter a value to enqueue : 11                                                                                                                   
11 -> Added!                                                                                                                                    
1                                                                                                                                               
Enter a value to enqueue : 12                                                                                                                   
12 -> Added!                                                                                                                                    
1                                                                                                                                               
Enter a value to enqueue : 14                                                                                                                   
14 -> Added!                                                                                                                                    
1                                                                                                                                               
Enter a value to enqueue : 13                                                                                                                   
13 -> Added!                                                                                                                                    
2                                                                                                                                               
11 -> Removed!                                                                                                                                  
3    
*/
