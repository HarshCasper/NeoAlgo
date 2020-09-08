class Node:
    def __init__(self,data=None):
        self.next=None
        self.prev=None
        self.data=data

class doublylist:
    def __init__(self):
        self.head=None


    def insertlast(self,data):
        temp=self.head
        while(temp is not None and temp.next is not None):
            temp=temp.next
        newnode=Node(data)
        if(temp is None):
            self.head=newnode
        else:
            temp.next=newnode
            newnode.prev=temp



    def count_nodes(self):
        temp=self.head
        count=0
        while(temp is not None):
            count+=1
            temp=temp.next
        return count


    def insert_at_pos(self,pos,ele):
        # iteration=self.head
        # count=0
        # while(iteration is not None):
        #     count+=1
        #     iteration=iteration.next
        count=self.count_nodes()
        if pos==0:
            temp=Node(ele)
            temp.next=self.head
            if self.head is not None:
                self.head.prev=temp
            self.head=temp
        elif pos<count:
            count=0
            temp=Node(ele)
            iter=self.head
            while count!=pos-1:
                count+=1
                iter=iter.next
            temp.next=iter.next
            iter.next.prev=temp
            temp.prev=iter
            iter.next=temp


    def delete_last(self):
        temp=self.head
        trail=None
        while((temp is not None )and(temp.next is not None)):
            trail=temp
            temp=temp.next
        trail.next=temp.next
        temp=None




    def delete_at_pos(self,pos):
        if pos>self.length():
            print("Enter position in the valid range")
            return None
        if pos==0:
            temp=self.head
            if temp is None:
                return self.head
            self.head=self.head.next
            if self.head is not None:
                self.head.prev=None
            temp.next=None
        else:
            temp=self.head
            count=0
            while(count!=pos-1):
                count+=1
                temp=temp.next
            if temp.next is not None:
                temp.next=temp.next.next
                if temp.next is not None:
                    temp.next.prev=temp




    def reverse(self,temp):
        if temp is None or temp.next is None:
            return temp
        ret=self.reverse(temp.next)
        temp.next.next=temp
        temp.next=None
        return ret

    def display(self):
        temp=self.head
        while(temp is not None):
            print(temp.data)
            temp=temp.next

if __name__=="__main__":
    obj=doublylist()
    while(True):
        choice =int(input("Enter your choice,To  know more about the choices press 8"))
        if choice ==1:
            pos,value=map(int,input("Enter position and value u want to insert").split())
            obj.insert_at_pos(pos,value)
        elif choice==2:
            value=int(input("Enter  value u want to insert"))
            obj.insertlast(value)
        elif choice ==3:
            pos=int(input("Enter position at which u want to delete"))
            obj.delete_at_pos(pos)
        elif choice ==4:
            obj.delete_last()
        elif choice ==5:
            obj.head=obj.reverse(obj.head)
        elif choice ==6:
            obj.count_nodes()
        elif choice ==7:
            obj.display()
        elif choice ==8:
            print('''So what do u want to perform
            case 1: Insertion in the linked list
                    For insertion at a particular position press 1
                    For always inserting at end press 2
            case 2: \nDeletion in the linked list
                    For deletion at a particular position press 1
                    For always deleting at end press 2
            case 3: \nFor reversing the linked list press 5
            case 4:\n  For getting the length of linked list press 6
            case 5:\n For printing the linked list press 7
            case 6:press 9 for exit()
            ''')
        elif choice ==9:
            quit()
