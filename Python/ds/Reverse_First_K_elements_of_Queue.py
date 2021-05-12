'''
This is a simple program for reversing first k elements in a queue.
Approch: First make a queue and insert all elements into it.
         Then we pass the queue , k and n to function reverseK for reversing it, after reversing it will return a lists
         In reverseK function we use a stack , we will dequeue first k elements and push them in stack
         Then we just pop all elements from stack and enque to queue and then we deque the remaining item and add them at last.
'''


def enqueue(lst, item):
    # insert at last
    lst.append(item)


def dequeue(lst):
    # remove 1st item
    item = lst.pop(0)
    return item


def reverseK(queue, k, n):
    # first deque k elements from queue and push them into stack
    stack = []
    for i in range(0, k):
        d_item = dequeue(queue)
        stack.append(d_item)

    # then pop all elements from stack and enque to queue
    while(len(stack) != 0):
        pi = stack.pop()
        enqueue(queue, pi)

    # now deque the remaining item and add them at last
    for i in range(0, len(queue)-k):
        d_item = dequeue(queue)
        enqueue(queue, d_item)
    return queue


if __name__ == '__main__':
    print("Enter the number of elements in array")
    n = int(input())
    print("Enter the array")
    a = list(map(int, input().strip().split()))
    print("Enter value of k")
    k = int(input())
    queue = []  # our queue to be used
    for i in range(n):
        queue.append(a[i])  # enqueue elements of array in our queue

    print(*reverseK(queue, k, n))

'''
Sample Input/Output :

Enter the number of elements in array
5
Enter value of k
2
Enter the array
1 2 3 4 5

Output: 2 1 3 4 5

Time complexity : 0(n)
Space complexity : 0(n)
'''
