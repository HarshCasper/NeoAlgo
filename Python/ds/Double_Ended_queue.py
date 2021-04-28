'''  
DOUBLE ENDED QUEUE
Double ended queue or dequeue is a special type of queue 
wherein elements can be inserted or deleted from both ends
i.e front and rear
'''

# to insert an element to the front of double ended queue
def enqueue_front(n):
    global rear
    global front
    global dequeue
    # If dequeue is not full
    if ((rear + 1) % 10 != front):
        # If dequeue is empty insert as first element
        if front == -1:
            front = 0
            rear = 0
        # decrement front in circular manner and insert
        else:
            front = (front + 9) % 10
        dequeue[front] = n


# to insert an element to the rear of double ended queue
def enqueue_rear(n):
    global rear
    global front
    global dequeue
    if ((rear + 1) % 10 != front):
        if (rear == -1):

            front = 0
            rear = 0
        # increment rear in circular manner and insert
        else:
            rear = (rear + 1) % 10
        dequeue[rear] = n


# to delete an element and return it from the front of dequeue
def delete_front():
    global rear
    global front
    global dequeue
    item = -1
    # If dequeue is empty
    if (front == -1):
        return -1
    else:
        item = dequeue[front]
        # if there is only one element
        if (front == rear):
            front = -1
            rear = -1
        else:
            front = (front + 1) % 10
    return item


# to delete an element and return it from the rear of dequeue
def delete_rear():
    global rear
    global front
    global dequeue
    item = -1
    if (rear == -1):
        return -1
    else:
        item = dequeue[rear]
        if (front == rear):
            front = -1
            rear = -1
        else:
            rear = (rear + 9) % 10
    return item


# to display the double ended queue from front to rear
def display():
    global rear
    global front
    global dequeue
    if (front <= rear):
        for i in range(front, rear+1):
            print(dequeue[i], end=" ")
    else:
        for i in range(front, 10):
            print(dequeue[i], end=" ")
        for i in range(0, rear+1):
            print(dequeue[i], end=" ")
    print("\n")


# driver code
def main():
    global dequeue
    global rear
    global front
    rear = -1
    front = -1
    dequeue = [None]*10
    # menu driven program to insert,delete or display dequeue
    print("1.Enqueue front\n2.Enqueue rear\n3.Delete front\n4.Delete rear")
    print("5.Display\n6.Exit\nChoose an option")
    opt = int(input())
    while opt != 6:
        if opt == 1:
            n = int(input("Enter the value to be inserted: "))
            enqueue_front(n)

        if opt == 2:
            n = int(input("Enter the value to be inserted: "))
            enqueue_rear(n)

        if opt == 3:
            print(str(delete_front())+" is deleted")

        if opt == 4:
            print(str(delete_rear())+" is deleted")

        if opt == 5:
            display()

        print("Choose an option")
        opt = int(input())

main()

'''
SAMPLE I/O: 
1.Enqueue front
2.Enqueue rear 
3.Delete front 
4.Delete rear  
5.Display       
6.Exit
Choose an option
1
Enter the value to be inserted: 1
Choose an option
2
Enter the value to be inserted: 2
Choose an option
1
Enter the value to be inserted: 3
Choose an option
2
Enter the value to be inserted: 4
Choose an option
3
3 is deleted
Choose an option
5
1 2 4

Choose an option
6

Time Complexity: O(1)
Space complexity: O(1)

'''
