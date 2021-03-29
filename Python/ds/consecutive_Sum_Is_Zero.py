
'''
Explanation:
An algorithm called as prefix sum or accumalated sum is used.
Here we start off with sum 0 and  iterate through the linked list we accumate the sum.

Consider an example:

		3 -> 4 -> 2 -> -6 -> 1 -> 1 -> 5 -> -6  

its corresponding prefix sum is: 

	0 -> 3 -> 7 -> 9 -> 3 -> 4 -> 5 -> 10 -> 4

we can use a dictionary in python which stores the prefix sum as the key and its value will be stored in the corresponding node object.

during the iteration we push the node value in dictionary and simultaneously update the prefix sum.

if the prefix sum equates to any key in the dictionary then it indicates we have previously accumaleted the sum of 3 indicating that the window of change or all elements between them have net sum as 0.

Thus,all the elements in the window can be removed.
'''

#create a node class
class node:
		def __init__(self,data):
			self.data = data
			self.next = None

#class for accessing linked lists and its methods 
class linkedList:
		def __init__(self):
			self.head = None

#method to insert  node to end of linkedList.
		def insertNodeAtEnd(self,data):
			newNode = node(data)
			if(self.head):
				current = self.head
				while(current.next):
					current = current.next
				current.next = newNode
			else:
				self.head = newNode

#print all the nodes of a linkedList
		def printNode(self):
			current = self.head
			while(current):
				print(current.data , end = " ")
				current = current.next


#function to remove elements that sum to 0
		def removeZeroSumLists(self):
			current = node(0) 
			#assign a dummy node with value 0
			current.next = self.head 

			prefixSum = 0 
			# finding prefix sum to verify if it already exists
			
			Dict = {} 
			#similar to hashmap,dict can be used to map prefixSum and node address 
			

			#Adding an element to it
			Dict[prefixSum] = current 
			#dict stores prefixSum as key and its corresponing address as value
			

			while(self.head):
				prefixSum += self.head.data 
				#calculate prefix sum
				
				Dict[prefixSum] = self.head
				self.head = self.head.next

			self.head = current
			prefixSum = 0
			while(self.head):
				prefixSum += self.head.data
				temp = Dict[prefixSum]
				if(temp!=self.head):
					self.head.next = temp.next
				self.head = self.head.next 
				#if same element exists then remove the nodes
			
			return current.next 

#print nodes of modified linked list 
		def printNodeForSublist(self,returnAddress):
			current = returnAddress
			while(current):
				print(current.data , end = " ")
				current = current.next

l = linkedList()
print("Input :")
l.insertNodeAtEnd(1)
l.insertNodeAtEnd(2)
l.insertNodeAtEnd(3)
l.insertNodeAtEnd(-3)
l.insertNodeAtEnd(1)
l.printNode()
print("\n")
returnAddress = l.removeZeroSumLists()
print("Output: ")
l.printNodeForSublist(returnAddress)

#Examples:
#input = [1,2,-3,3,1]
#output = [1,2,1]

#input = [1,2,3,-3,4]
#output = [1,2,4]

#input = [1,2,3,-3,-2]
#output = [1]






