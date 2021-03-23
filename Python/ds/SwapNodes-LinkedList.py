'''
Problem Statement-
Given a linked list, i & j, swap the nodes that are
present at i & j position in the Linked List.
You need to swap the entire nodes, not just the data.

Logical Intuition-
We change the links of the prev
and the next pointers of the nodes
we are swapping.
'''


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def inputLL():
    '''
    Summary Line-:
    This method helps to take input for the Linked List.
    We use '-1' at the end of our input to indicate the
    end of our list.

    Returns:
    Returns the head of our newly
    formed Linked List
    '''
    print("Enter elements of the Linked List and use -1 to end the list-")
    llist = list(int(i) for i in input().split())
    head = None
    tail = None
    for data in llist:
        if data != -1:
            newNode = Node(data)
            if head is None:
                head = newNode
                tail = newNode
            else:
                tail.next = newNode
                tail = newNode
        else:
            return head


def lengthLL(head):
    '''
    Summary Line:
    Helps us to get the length
    of the Linked List.

    Args:
    head- Head of our Linked List.

    Returns:
    Length of our Linked list.
    '''
    count = 0
    while head is not None:
        count += 1
        head = head.next
    return count


def swapNodes(head, m, n):
    '''
    Summary Line:
    This function helps us to swap the
    particular nodes of the Linked List.

    Args:
    head- Head of our Linked List
    m- index of the first node being swapped.
    n- index of the second node being swapped.

    Returns:
    Head of the new Linked list with
    swapped nodes.
    '''
    if head is None:
        return head
    x = m
    y = n
    m = min(x, y)
    n = max(x, y)
    i = 0
    temp = head
    prev1 = None
    while(i < m):
        if temp is None:
            break
        prev1 = temp
        temp = temp.next
        i = i+1
    current1 = temp  # current1 set at the first node
    i = 0
    temp = head
    prev2 = None
    while i < n:
        if temp is None:
            break
        prev2 = temp
        temp = temp.next
        i = i+1
    current2 = temp  # current2 set to the other node
    temp = current2.next
    '''
    We iterate over the prev and the next nodes
    of our current1 and current2 and manually change
    their links to swap the nodes.
    '''
    if prev1 is not None and prev2 is not None:
        prev1.next = current2
        prev2.next = current1
        current2.next = current1.next
        current1.next = temp
    if prev1 is None:
        prev2.next = current1
        head = current2
        current2.next = current1.next
        current1.next = temp
    return head


def printLL(head):
    '''
    Summary Line:
    Prints the data in the nodes
    of our Linked list.

    Args:
    head- Head of our Linked list
    '''
    while head is not None:
        print(head.data, end=" ")
        head = head.next
    print()


if __name__ == "__main__":
    head = inputLL()
    print("Enter index of nodes to be swapped-")
    i, j = map(int, input().split())
    head = swapNodes(head, i, j)
    printLL(head)

'''
Sample Input-

Enter elements of the Linked List and use -1 to end the list-
3 4 5 2 6 1 9 -1
Enter index of nodes to be swapped-
3 4

Sample Output-

3 4 5 6 2 1 9

Time complexity- O(n) where n is the
number of nodes in the Linked List.

Space complexity- O(1) because we are only
storing definite number of nodes/ values.
'''
