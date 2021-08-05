class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def add_node(self, val):
        node = Node(val)

        if not self.head:
            self.head = self.tail = node
        else:
            node.prev = self.tail
            self.tail.next = node
            self.tail = node

    def __str__(self):
        temp = self.head
        res = []
        while temp:
            res.append(temp.data)
            temp = temp.next

        return " -> ".join(map(str, res))


class Node:
    def __init__(self, val):
        self.data = val
        self.prev = None
        self.next = None


def reverse_dll(head):
    temp = tail = head
    while temp:
        temp.next, temp.prev = temp.prev, temp.next
        head = temp
        temp = temp.prev

    return head, tail


if __name__ == "__main__":
    dll = DoublyLinkedList()
    dll.add_node(4)
    dll.add_node(5)
    dll.add_node(6)
    dll.add_node(7)

    print(dll)
    # 4 -> 5 -> 6 -> 7

    rdll = DoublyLinkedList()
    rdll.head, rdll.tail = reverse_dll(dll.head)

    print(rdll)
    # 7 -> 6 -> 5 -> 4
