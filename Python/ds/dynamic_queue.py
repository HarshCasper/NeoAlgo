'''
Queue implementation using List in Python
'''

try:
    queue = []

    # For the queue to be dynamic it has been put in a loop
    # While the loop is true the user gets 5 options:
    # To insert element in queue,remove,
    # display all elelements,reverse queue or exit

    while True:
        op = int(input('''
        Press-->
         1 to insert into queue
         2 to  remove from queue
         3 to display values of queue
         4 to reverse the exisiting queue
         5 to exit '''))
        
        if op == 1:
            ele = int(input("enter elem to insert "))
            queue.append(ele)

        elif op == 2:

            if len(queue) == 0:
                print("The queue is empty, insert values if required")
            else:
                ele = queue.pop(0)
                print("Element removed is - ", ele)

        elif op == 3:

            if len(queue) == 0:
                print("The queue is empty, insert values if required")
            else:
                print(queue)

        elif op == 4:
            queue.reverse()
            print(queue)

        elif op == 5:
            break

        else:
            print("invalid option")

except ValueError:

    print("Please enter integer only")

except:

    print("There's been some issue please check the data you've entered")


"""
Sample Input- Output
dynamic_queue.py
        Press-->
         1 to insert into queue
         2 to  remove from queue
         3 to display values of queue
         4 to reverse the exisiting queue
         5 to exit 1
enter elem to insert 3
        Press-->
         1 to insert into queue
         2 to  remove from queue
         3 to display values of queue
         4 to reverse the exisiting queue
         5 to exit 1
enter elem to insert 4
        1 to insert into queue
         2 to  remove from queue
         3 to display values of queue
         4 to reverse the exisiting queue
         5 to exit 1
enter elem to insert 5
        Press-->
        1 to insert into queue
         2 to  remove from queue
         3 to display values of queue
         4 to reverse the exisiting queue
         5 to exit 4
[5, 4, 3]
        Press-->
        1 to insert into queue
         2 to  remove from queue
         3 to display values of queue
         4 to reverse the exisiting queue
         5 to exit 2
Element removed is -  5
        Press-->
        1 to insert into queue
         2 to  remove from queue
         3 to display values of queue
         4 to reverse the exisiting queue
         5 to exit 5
"""

"""
Time Complexity - O(n)
"""
