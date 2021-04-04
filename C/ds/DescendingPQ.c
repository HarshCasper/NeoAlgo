/*
AIM :: TO IMPLEMENT DESCENDING PRIORITY QUEUE 

WHAT IS DESCENDING PRIORITY QUEUE ?

 In descending order priority queue, a higher priority number is given as a higher priority. 
 For example, from 1 to 5 arranged in descending order,
 the largest number, i.e., 5 is given as the highest priority in a Descending priority queue.

*/

#include <stdio.h>
#include <stdlib.h>
#define size 5

//Front for insertion an Rear for deletion
int Front = -1;
int Rear = -1;
int Queue[size];

//for checking whether Priority Queue is full or not
int q_full()
{
    if (Rear == size - 1)
        return 1;

    return 0;
}

//for checking whether Priority Queue is empty or not
int q_empty()
{
    if (Front == -1 || Front > Rear)
        return 1;

    return 0;
}

//to display the data in Priority Queue
void display()
{
    if (q_empty())
        printf("\nqueue is empty\n");
    else
    {
        printf("\n");
        for (int i = Front; i <= Rear; i++)
            printf("%d  ", Queue[i]);
        printf("\n");
    }
}

//for performing insertion
void enq()
{
    if (q_full())
        printf("\nQUEUE OVERFLOW\n");
    else
    {
        int element, i;
        printf("\nenter the element: ");
        scanf("%d", &element);

        //if inserting for firs time then do increment front also
        if (Front == -1)
            Front++;

        //find appropriate place for the element and insert
        for (i = Rear; i >= 0 && element > Queue[i]; i--)
            Queue[i + 1] = Queue[i];
        Queue[i + 1] = element;
        Rear++;

        display();
    }
}

//for performing deletion
void deq()
{
    if (q_empty())
        printf("\nQUEUE UNDERFLOW\n");
    else
    {
        int element = Queue[Front];
        if (Front == Rear)
            Front = Rear = -1;
        else
            Front++;
        display();
    }
}

int main()
{
    int choice;
    printf("\n\n\tPRIORITY QUEUE IMPLEMENTION\n");
    while (1)
    {
        printf("\nMAIN MENU\n");
        printf("1. ENQ\n2. DEQ\n3. DISPLAY\n4. EXIT");
        printf("\nenter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enq();
            break;

        case 2:
            deq();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nexiting...\n\n");
            exit(0);
            break;

        default:
            printf("\ninvalid choice :(\n");
            break;
        }
    }
    return 0;
}

/*
TEST CASE 


        PRIORITY QUEUE IMPLEMENTION

MAIN MENU
1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
enter your choice: 1

enter the element: 5

5

MAIN MENU
1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
enter your choice: 1

enter the element: 10

10  5

MAIN MENU
1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
enter your choice: 1

enter the element: 15

15  10  5

MAIN MENU
1. ENQ
2. DEQ
3. DISPLAY
4. EXIT
enter your choice: 4

exiting...


TIME COMPLEXITY  :: O(n)
SPACE COMPLEXITY :: O(1)

*/
