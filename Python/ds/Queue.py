# Stack implementation using List in Python

class Queue :
  def __init__(self):
    self.items =[]
    
  def print_queue(self):
    print ("\nQueue: ", self.items)
    print ("Length of Queue: ", len(self.items))
    self.print_top()
    
  def print_top(self):
    try:
      print ("Topmost element in the Queue: ", self.items[0], "\n")
    except IndexError:
      print ("Topmost element in the Queue: NULL\n")
      
  def enqueue(self, item):
    self.items.insert(0,item)
    print ("Enqueued value: ", item)
  
  def dequeue(self):
    print ('Dequeued value: ',self.items.pop())
  
if __name__ == '__main__' :
  q = Queue()
  q.print_queue()
  q.enqueue(10)
  q.enqueue(20)
  q.enqueue(30)
  q.enqueue(40)
  q.enqueue(50)
  q.print_queue()
  q.dequeue()
  q.dequeue()
  q.dequeue()
  q.print_queue()