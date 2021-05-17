class Queue:
    """
    Queue implementation using a list. Front of the queue is the first
    elememt and back of the queue is the last element.
    """

    def __init__(self):
        self._items = []

    def __str__(self):
        return f"front --> {self._items} <-- rear"

    def __len__(self):
        return len(self._items)

    def get_front(self):
        return self._items[0]

    def get_rear(self):
        return self._items[-1]

    def is_empty(self):
        return len(self._items) == 0

    def enqueue(self, item):
        """
        Add an element to the rear of the queue.
        """
        self._items.append(item)

    def dequeue(self):
        """
        Remove the element at the end of the front of the queue and return it.

        Raises:
            IndexError: If queue is empty.
        """
        return self._items.pop(0)


if __name__ == "__main__":
    q = Queue()

    print(f"Initialized : {q}")

    for elm in range(5):
        q.enqueue(elm)
        print(f"Enqueued '{elm}': {q}")

    for _ in range(3):
        q.dequeue()
        print(f"Dequeued    : {q}")
