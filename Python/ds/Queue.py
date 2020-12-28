# Queue implementation using List in Python

try:  #try catch so that the program does not crash
	queue=[]

	while True:
		op = int(input("Press--> 1 to insert into queue | 2 to  remove from queue | 3 to display values of queue | 4 to reverse the exisiting queue| 5 to exit "))
		if op==1:                                       #to insert an elelment in the queue
			ele = int(input("enter elem to insert "))
			queue.append(ele)
		elif op==2:                                    #to remove an element from the queue
			if len(queue)==0:
				print("The queue is empty, insert values if required")
			else:
				ele=queue.pop(0)
				print("Element removed is - ",ele)
		elif op==3:                                    #to display the elements in the queue
			if len(queue)==0:
				print("The queue is empty, insert values if required")
			else:
				print(queue)
		elif op==4:                                    #to reverse queue
			queue.reverse()
		elif op==5:                                     #to exit
			break
		else:
			print("invalid option")

except ValueError:
	print("Please enter integer only")                 #If user inputs an alphabet or string the program should not crash
except:
	print("There's been some issue please check the data you've entered")
