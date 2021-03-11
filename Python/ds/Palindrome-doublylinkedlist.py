'''

Palindrome : A sequence which appears the same when read forwards and backwards
Purpose : To find if the given string is a palindrome or not, using doubly linked list

Method : Data Structures :- Doubly Linked List
        - Create a doubly linked list
        - Assign each character to one node of the doubly linked list
        - Check if the data in the before node and after node are equal
        - If they are equal, perform increment and decrement operations
        - If they are not equal, return false

Time complexity : 0(n)
Space complexity : 0(1)
Arguments : Arbitrary arguments
Return : Message if the input is a palindrome or not
Sample Input/Output :

- Test case 1:
Enter the string : clouds
Not a Palindrome

- Test case 2:
Enter the string : madam
Is a Palindrome

- Test case 3:
Enter the string : books
Not a Palindrome

'''


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class DoublyLinkedList:

    @staticmethod
    def printList(node):

        '''Reversing the string'''
        rev_key = ""
        while node:
            rev_key += node.data
            node = node.next
        return rev_key

    def __init__(self):
        self.head = None

    def push(self, new_data):

        ''' Adding new node in the front of the list '''
        new_node = Node(new_data)

        if self.head is None:
            self.head = new_node
            return

        last = self.head

        while last.next:
            last = last.next

        last.next = new_node
        new_node.prev = last
        return


if __name__ == "__main__":

    llist = DoublyLinkedList()
    keys = input("Enter the string : ")

    for i in reversed(range(len(keys))):
        llist.push(keys[i])

    rev_keys = llist.printList(llist.head)

    if keys == rev_keys:
        print("Is Palindrome")
    else:
        print("Not a Palindrome")
