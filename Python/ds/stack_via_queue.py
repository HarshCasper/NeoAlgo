 Implement Stack using single queue and recursion
class Stack:

	# Constructor
	def __init__(self):
		self.q = []

	# Insert an item into the stack
	def push(self, data):
		self.q.append(data)

	# Utility function to reverse contents of a queue
	def reversedeque(self):
		# base case
		if not self.q:
			return

		# hold front element in recursion call stack and insert
		# it back into the queue after recursive call is over

		front = self.q.pop()
		self.reversedeque()
		self.q.append(front)

	# Remove the top item from the stack
	def pop(self):
		# if the queue is isEmpty
		if not self.q:
			print("Underflow!!")
			exit(0)

		# reverse the queue
		self.reversedeque()

		# pop front element of reversed queue
		front = self.q.pop()

		# revert the queue to original state
		self.reversedeque()

		return front
