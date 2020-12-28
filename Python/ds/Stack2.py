#lifo


stack=[]
try:           #try except so that the program does not crash[optional]
	while True:
		op = int(input("Select---> 1 to push, 2 to pop top most element, 3 to display elements in stack,4 to peek,5 to exit "))
		if op==1:                                      #to push into stack
			ele = int(input("enter elem to push "))
			stack.append(ele)
		elif op==2:                                    #to pop from stack. If stack is empty it will display "Stack is empty"
			if len(stack) ==0:
				print("Stack is empty ")
			else:
				ele=stack.pop()                        
				print("popped element ",ele)
		elif op==3:                                   #TO display stack elements and print "Stack is empty " if there are no elements
			if len(stack) ==0:
				print("Stack is empty ")
			else:                      
				print(stack)                                                         
		elif op==4:                                   #To peek at stack top. i.e see the topmost element                                      
			if len(stack) ==0:						  
				print("Stack is empty ")
			else:
				print(stack[-1])
		elif op==5:                                   #To exit from loop
			break
		else:
			print("invalid option")
except ValueError:
	print("Please enter integer only")                 #If user inputs an alphabet or string the program should not crash
except:
	print("There's been some issue please check the data you've entered")