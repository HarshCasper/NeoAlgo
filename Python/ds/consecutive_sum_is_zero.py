'''
Remove Zero Sum Consecutive Nodes from Linked List:

Explanation:
An algorithm called as prefix sum or accumalated sum is used.
Here we start off with sum 0 and  iterate through the linked
list  accumalate the sum.

Consider an example:

    3 -> 4 -> 2 -> -6 -> 1 -> 1 -> 5 -> -6
its corresponding prefix sum is:
0 -> 3 -> 7 -> 9 -> 3 -> 4 -> 5 -> 10 -> 4

A dictionary in python is used to store the prefix sum as the
key and its value will be stored in the corresponding node object.

During the iteration we push the node value(address) in dictionary
and simultaneously update the prefix sum.

If the prefix sum equates to any key in the dictionary then it
indicates we have previously accumaleted the sum,indicating
that all elements between them have net sum as 0.


Thus,all the elements in the window can be removed.
'''
'''create a node class'''


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


'''class for accessing linked lists and its methods'''


class LinkedList:
    def __init__(self):
        self.head = None

    def insert_node_at_end(self, data):
        new_node = Node(data)
        if self.head:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
        else:
            self.head = new_node
        #print all the nodes of a LinkedList'''

    def print_node(self):
        current = self.head
        while current:
            print(current.data, end=" ")
            current = current.next
        #function to remove elements that sum to 0'''

    def remove_zero_sum_lists(self):
        current = Node(0)
        #assign a dummy node with value 0'''
        current.next = self.head

        prefix_sum = 0
        #finding prefix sum to verify if it already exists'''

        dict = {}
        #similar to hashmap,dict can be used to map prefix_sum,node address.
        #Adding an element to it'''
        dict[prefix_sum] = current
        #dict stores prefix_sum as key and its corresponing address as value.

        while self.head:
            prefix_sum += self.head.data
            #calculate prefix sum'''

            dict[prefix_sum] = self.head
            self.head = self.head.next

        self.head = current
        prefix_sum = 0
        while self.head:
            prefix_sum += self.head.data
            temp = dict[prefix_sum]
            if temp != self.head:
                self.head.next = temp.next
            self.head = self.head.next
            #if same element exists then remove the nodes'''

        return current.next

    #print nodes of modified linked list'''

    def print_node_for_sublist(self, return_address):
        current = return_address
        while current:
            print(current.data, end=" ")
            current = current.next


#driver code'''
if __name__ == '__main__':

    OBJ = LinkedList()

    list_nodes = int(input("Enter no of nodes for input :"))
    for iterator in range(list_nodes):
        node_data = int(input("Enter data : "))
        OBJ.insert_node_at_end(node_data)

    OBJ.print_node()
    print("\n")
    return_address = OBJ.remove_zero_sum_lists()
    print("Output: ")
    OBJ.print_node_for_sublist(return_address)

#Examples:
#input = [1,2,-3,3,1]
#output = [3,1]

#input = [1,2,3,-3,1]
#output = [1,2,1] 

#input = [1,2,3,-3,-2]
#output = [1]
