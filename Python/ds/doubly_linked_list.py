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



    def length(self):
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
        count=self.length()
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
    obj.insertlast(1)
    obj.insertlast(2)
    obj.insertlast(3)
    obj.insertlast(4)
    obj.head=obj.reverse(obj.head)
    obj.delete_at_pos(3)
    obj.display()
