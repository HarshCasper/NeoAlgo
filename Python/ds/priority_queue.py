""" Demonstartion of Priority Queue in Python.

Priority Queue is an extension of queue with some additional properties-
-> Every item has a priority associated with it.
-> An element with high priority is dequeued before an element with low priority.
-> If two elements have the same priority, they are served according to their order in the queue.

A priority queue supports following main operations:
-> insert_into(item, priority): Inserts an item with given priority.
-> get_min(): Returns the lowest priority item.
-> remove_min(): Removes the lowest priority item.
"""


class PriorityQueueNode:
    """
    Node class for PriorityQueue.
    """

    def __init__(self, value, priority):
        self.value = value
        self.priority = priority


class PriorityQueue:
    """
    PriorityQueue implementation using a list.
    A priority is attached with every value of the queue.
    """

    def __init__(self):
        self.pq = []

    def get_size(self):
        """
        Return the size of the priority queue.
        """
        return len(self.pq)

    def isEmpty(self):
        """
        Return boolean value.
        `True` if the priority queue is empty,
        esle, returns `False`.
        """
        return self.get_size() == 0

    def get_min(self):
        """
        Return the least priority element in the priority queue.
        """
        if self.isEmpty():
            return None
        return self.pq[0].value

    def insert_into_pq(self, value, priority):
        """
        Insert elements into the priority queue.
        """
        pq_node = PriorityQueueNode(value, priority)
        self.pq.append(pq_node)

        self.percolate_up()

    def percolate_up(self):
        """Find correct place for the element to be added
        into the priority queue, following Heap Order Property.
        """
        child_index = self.get_size() - 1

        while child_index > 0:
            parent_index = (child_index - 1) // 2

            if self.pq[child_index].priority < self.pq[parent_index].priority:
                # swap
                self.pq[child_index], self.pq[parent_index] = self.pq[parent_index], self.pq[child_index]
                child_index = parent_index
            else:
                break

    def remove_min(self):
        """
        Remove element with the least priority.
        """
        if self.isEmpty():
            return None

        ele = self.get_min()

        self.pq[0] = self.pq[self.get_size() - 1]
        self.pq.pop()

        self.percolate_down()
        return ele

    def percolate_down(self):
        """Find the position of the element to be removed
        and ensures that Heap Order Property is maintained
        after removal of the element.
        """
        parent_index = 0
        left_child_index = (2 * parent_index) + 1
        right_child_index = (2 * parent_index) + 2

        while left_child_index < self.get_size():
            min_index = parent_index

            if self.pq[min_index].priority > self.pq[left_child_index].priority:
                min_index = left_child_index

            if right_child_index < self.get_size(
            ) and self.pq[min_index].priority > self.pq[right_child_index].priority:
                min_index = right_child_index

            if min_index == parent_index:
                break
            self.pq[parent_index], self.pq[min_index] = self.pq[min_index], self.pq[parent_index]
            parent_index = min_index
            left_child_index = 2 * parent_index + 1
            right_child_index = 2 * parent_index + 2


if __name__ == "__main__":
    pq1 = PriorityQueue()
    """initialise the priority queue object.
    """
    size = int(input("Enter the size of the priority queue: "))
    print("Enter space-separated value and priority to push into the queue: ")
    """Enter two space separated values.
    The first value is the value to be pushed in the priority queue
    and the second value is it's priority
    """
    value = []
    for i in range(size):
        value.append([ele for ele in input().split()])
        """all the values along with their priority are inserted into a list"""
    for i in range(len(value)):
        pq1.insert_into_pq(value[i][0], value[i][1])
        """all the values are being inserted into the queue according to their priority"""
    for i in range(pq1.get_size()):
        print(pq1.remove_min(), end=" ")

"""Space-Time Complexity Analysis:

->insert_into()
Time-Complexity: O(logN)
Space-Complexity: O(1)

->get_min():
Time-Complexity: O(logN)
Space-Complexity: O(1)

->remove_min():
Time-Complexity: O(logN)
Space-Complexity: O(1)
"""

"""Test-Cases:
>>>
Input:
Enter the size of the priority queue: 3
Enter space-separated value and priority to push into the queue:
A 1
B 2
C 3

Output:
A B C

>>>
Input:
Enter the size of the priority queue: 5
Enter space-separated value and priority to push into the queue:
Anamika a
B.Tech b
CSE c
College c
Python p

Output:
Anamika B.Tech College CSE Python
"""
