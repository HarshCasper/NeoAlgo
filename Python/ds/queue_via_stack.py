from collections import deque


# Implement Queue using single stack
class Queue:
	s = deque()

	# Constructor
	def __init__(self):
		self.s = deque()

	# Enqueue an item to the queue
	def enqueue(self, data):
		# Push item into the first stack
		self.s.append(data)

	# Dequeue an item from the queue
	def dequeue(self):

		# if stack is empty
		if not self.s:
			print("Underflow!!")
			exit(0)

		# pop an item from the stack
		top = self.s.pop()

		# if stack becomes empty, return the popped item
		if not self.s:
			return top

		# recur
		item = self.dequeue()

		# push popped item back to the stack
		self.s.append(top)

		# return the result of dequeue() call
		return item 
