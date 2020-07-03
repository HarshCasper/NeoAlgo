'''
    Author: Dasu Srinivas
    Description : Implement a queue using double linked list
'''


class Node:
    def __init__(self, value):
        self.value = value
        self.next = None
        self.prev = None


class Queue:
    def __init__(self):
        self.head = None
        self.last = None

    # Inserts the element to the queue
    def enQueue(self, data):
        if self.last is None:
            self.head = Node(data)
            self.last = self.head
        else:
            self.last.next = Node(data)
            self.last.next.prev = self.last
            self.last = self.last.next

    # Removes element from the queue
    def deQueue(self):
        if self.head is None:
            return
        else:
            temp = self.head.value
            self.head = self.head.next
            self.head.prev = None
            return temp

    # Returns firstelement of the queue
    def firstEle(self):
        return self.head.value

    # Returns length of the queue
    def sizeOf(self):
        temp = self.head
        count = 0
        while temp is not None:
            count += 1
            temp = temp.next
        return count

    # Checks whether queue is empty or not
    def isEmpty(self):
        if self.head is None:
            return True
        else:
            return False

    # Displays the elements in the queue
    def printqueue(self):
        print("queue elements are:")
        temp = self.head
        while temp is not None:
            print(temp.value, end="->")
            temp = temp.next


queue = Queue()
queue.enQueue(4)
queue.enQueue(5)
queue.enQueue(6)
queue.enQueue(7)
print("First element is :", queue.firstEle())
queue.printqueue()
queue.deQueue()
queue.printqueue()