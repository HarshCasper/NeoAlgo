class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def create_linked_list(self, arr):
        last = dummy = self.head = Node(arr.pop(0))

        while arr:
            dummy.next = Node(arr.pop(0))
            last = dummy
            dummy = dummy.next
        return last

    def intersection_point(self, head2):
        """ Return the point of intersection of Y-shaped linked lists"""
        iterator1 = self.head
        iterator2 = head2
        while iterator1 or iterator2:
            if iterator1 == iterator2:
                return iterator1.val
            iterator1 = iterator1.next if iterator1 else head2
            iterator2 = iterator2.next if iterator2 else self.head
        return 'No intersecting point found!'

inp1 = list(map(int, input('Elements of list1: ').split(',')))
inp2 = list(map(int, input('Elements of list2: ').split(',')))
try:
    intersection = list(map(int, input('Intersection list').split(',')))
    intersectionList = LinkedList()
except:
    intersection = []

linked_list1 = LinkedList()
linked_list2 = LinkedList()

last_list1 = linked_list1.create_linked_list(inp1)
last_list2 = linked_list2.create_linked_list(inp2)
if intersection != []:
    intersectionList.create_linked_list(intersection)
    last_list1.next = intersectionList.head
    last_list2.next = intersectionList.head


print(linked_list1.intersection_point(linked_list2.head))


'''
Input format: 4 lines-> For Intersection
3,5,6,2         :: linkedlist1 elements which won't intersect with list 1
3,12,4,10,3,32  :: linkedlist2 elements  which won't intersect with list 2
9,1,5,3         :: elements to be common in both list

                   3 - 5 - 6 - 2
                                \
                                 9 - 1 - 5 - 3
                                /
        3 - 12 - 4 - 10 - 3 - 32

Output: 9
Input format: 4 lines-> For NO Intersection
3              :: linkedlist1 elements which won't intersect with list 1
3,12,4,10,3,32 :: linkedlist2 elements  which won't intersect with list 2

                3
                3 - 12 - 4 - 10 - 3 - 32            (No intersection)
Output: False


Approach: Two likedlist can be of different lengths. If any one reaches None,
equate its iterator with head of other linkedlist. Doing this, either both will
meet at intersection point or both will reach None together
means no intersection.

Complexity: Time-> O(n)
                        Space->O(1)
contributed by @pradeep98
'''
