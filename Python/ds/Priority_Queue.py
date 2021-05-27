'''
Implementing Priority Queue data structure wherein the elements are 
deleted on the basis of their priority instead of FIFO as in case
of queue
'''
#Creating a class which will denote the priority queue
class Priority(object):
	#Setting up the queue
    def __init__(self):
        self.queue = []
  
    def __str__(self):
        return ' '.join([str(i) for i in self.queue])
    #Insertion of elements
    def insert(self, data):
        self.queue.append(data)
  
    #Deletion of elements based on priority,i.e the largest
	#element will be popped out first
    def delete(self):
		#Checking the length of queue
        if(len(self.queue)!=0):
            max = 0
            for i in range(len(self.queue)):
                if self.queue[i] > self.queue[max]:
                    max = i
            print("The element deleted is:-\n",self.queue[max])
            del self.queue[max]
		#If length of queue is 0 then it is empty
        else:
            print("Queue is empty\n")
        
#Driver's code   
def main():
	#Creating a local variable for queue
    ptr=Priority()
	#Switch based program
    while(True):
        n=(int)(input("Enter 1 for insertion,2 for deletion,3 for display\n"))
        if n==1:
            x=(int)(input("Enter element\n"))
            ptr.insert(x)
        elif n==2:
            ptr.delete()   
        elif n==3:
            print(ptr)
        else:
            break
if __name__=="__main__":
    main()

'''
Time Complexity:O(n);n is the length of queue
Space Complexity:O(n);n is the length of queue

Input/Output-
Enter 1 for insertion,2 for deletion,3 for display 1
Enter element 23
Enter 1 for insertion,2 for deletion,3 for display 1
Enter element 78
Enter 1 for insertion,2 for deletion,3 for display 1
Enter element 12
Enter 1 for insertion,2 for deletion,3 for display 2
The element deleted is:-78
Enter 1 for insertion,2 for deletion,3 for display 3
23 12
Enter 1 for insertion,2 for deletion,3 for display
4
'''
