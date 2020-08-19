class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
        
class LinkedList:
    def __init__(self):
        self.head = None
        
    def createLinkedList(self, arr, serial = 0, skip1 = 0, skip2 = 0, head1 = None):
        if serial == 0:
            dummy = self.head = Node(arr.pop(0))
            while arr:
                dummy.next = Node(arr.pop(0))
                dummy = dummy.next
        else:
            while skip1:
                head1 = head1.next
                skip1 -= 1
            if skip2 == 0:
                self.head = head1
                return
            dummy = self.head = Node(arr.pop(0))
            while skip2-1:
                dummy.next = Node(arr.pop(0))
                dummy = dummy.next
                skip2 -= 1
            dummy.next = head1
    
    def intersectionPoint(self, head2):
        iterator1 = self.head
        iterator2 = head2
        while iterator1 or iterator2:
            if iterator1 == iterator2:
                return iterator1.val
            iterator1 = iterator1.next if iterator1 else head2
            iterator2 = iterator2.next if iterator2 else self.head
        return False
                
inp1 = list(map(int, input('Elements of list1: ').split(',')))
inp2 = list(map(int, input('Elements of list2: ').split(',')))
skip1 = int(input('No. of elements to be skipped for l1: '))
skip2 = int(input('No. of elements to be skipped for l2: '))

linkedList1 = LinkedList()
linkedList2 = LinkedList()

linkedList1.createLinkedList(inp1)
linkedList2.createLinkedList(inp2, 1, skip1, skip2, linkedList1.head)

print(linkedList1.intersectionPoint(linkedList2.head))

'''
Input format: 4 lines->
3,5,6,2,9,1,5,3                     :: linkedlist1 elements
3,12,4,10,3,32,9,1,5,3              :: linkedlist2 elements
4                                   :: elements to be skipped in linkedlist1 before intersection
6                                   :: elements to be skipped in linkedlist2 before intersection

                   3 - 5 - 6 - 2
                                \
                                 9 - 1 - 5 - 3
                                /
        3 - 12 - 4 - 10 - 3 - 32  

Output: 9

Approach: Two likedlist can be of different lengths. If any one reaches None,
            equate its iterator with head of other linkedlist. Doing this, either both will meet
            at the intersection point or both will reach None together means no intersection.
            
            For no intersection-> input skip1 = length of linkedList1
                                  input skip2 = length of linkedList2
Complexity: Time-> O(n)
						Space->O(1)
contributed by @pradeep98
'''
