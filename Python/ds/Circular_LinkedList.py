class circular_llist:

    def __init__(self,node):
        self.head = node
        self.tail = self.head


    def append(self,node):
        '''Insert node given as argument to the end of the list'''
        self.tail.next = node
        self.tail = node
        node.next = self.head

    def prepend(self,node):
        '''insert node given as argument to the start of the list'''
        node.next = self.head
        self.head = node
        self.tail.next = self.head
    def printAll(self):
        '''Print all the nodes of list'''
        node = self.head

        # print("Your List: ")

        while node.next!=self.head:

            print(node.value,end='')
            print("--->",end='')
            node = node.next

        else:
            print(node.value)



    def insert(self,n,index):
        '''Insert node at position passed in argument

        usage : insert(Node,position)

        '''
        i = 0
        node = self.head
        while node:
            if i==index-1:
                nextNode = node.next
                node.next = n
                n.next = nextNode
                break
            else:
                i+=1
                node=node.next
        else:
            print("Given index is not in proper range")
    def remove(self,data):
        '''Remove node at position passed in argument

        usage : remove(value)

        '''
        node = self.head
        while node:
            if node.next.value == data:
                nextNode = node.next.next
                node.next = nextNode
                break
            else:
                node = node.next

        else:
            print("Value not Found")


class Node:
    def __init__(self,data):
        self.value = data
        self.next = None

if __name__ == '__main__':

    # Testing
    l  = circular_llist(Node(0))
    l.append(Node(1))
    l.append(Node(2))
    l.append(Node(3))
    l.append(Node(4))
    l.prepend(Node(10))
    l.insert(Node(23),7)
    l.remove(0)
    l.remove(23)
    l.printAll()

