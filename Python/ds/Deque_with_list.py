'''
Doubly ended queue
implementation using List in Python
'''

try:
    queue = []

    # For the queue to be dynamic it has been put in a loop
    # While the loop is true the user gets options:
    # To insert at rear/front
    # remove from front/rear
    # display all elelements,reverse queue or exit

    while True:
        op = int(input('''
Press-->
1 to insert in rear
2 to remove from front
3 to insert in front
4 to remove from rear
5 to display values of queue
6 to reverse the exisiting queue
7 to exit '''))

        if op == 1:
            ele = int(input("enter elem to insert "))
            queue.append(ele)
            print(queue)

        elif op == 2:

            if len(queue) == 0:
                print("The queue is empty, insert values if required")
            else:
                ele = queue.pop(0)
                print("Element removed is - ", ele)
                print(queue)

        elif op == 3:
            ele = int(input("enter elem to insert "))
            queue.insert(0, ele)
            print(queue)

        elif op == 4:

            if len(queue) == 0:
                print("The queue is empty, insert values if required")
            else:
                ele = queue.pop(-1)
                print("Element removed is - ", ele)
                print(queue)

        elif op == 5:

            if len(queue) == 0:
                print("The queue is empty, insert values if required")
            else:
                print(queue)

        elif op == 6:
            queue.reverse()
            print(queue)

        elif op == 7:
            break

        else:
            print("invalid option")

except ValueError:

    print("Please enter integer only")

except:

    print("There's been some issue please check the data you've entered")

"""
Sample Input-output:

Press-->
1 to insert in rear
2 to remove from front
3 to insert in front
4 to remove from rear
5 to display values of queue
6 to reverse the exisiting queue
7 to exit 1
enter elem to insert 3
[3]

Press-->
1 to insert in rear
2 to remove from front
3 to insert in front
4 to remove from rear
5 to display values of queue
6 to reverse the exisiting queue
7 to exit 1
enter elem to insert 5
[3, 5]

Press-->
1 to insert in rear
2 to remove from front
3 to insert in front
4 to remove from rear
5 to display values of queue
6 to reverse the exisiting queue
7 to exit 3
enter elem to insert 5
[5, 3, 5]

Press-->
1 to insert in rear
2 to remove from front
3 to insert in front
4 to remove from rear
5 to display values of queue
6 to reverse the exisiting queue
7 to exit 2
Element removed is -  5
[3, 5]

Press-->
1 to insert in rear
2 to remove from front
3 to insert in front
4 to remove from rear
5 to display values of queue
6 to reverse the exisiting queue
7 to exit 4
Element removed is -  5
[3]

Press-->
1 to insert in rear
2 to remove from front
3 to insert in front
4 to remove from rear
5 to display values of queue
6 to reverse the exisiting queue
7 to exit 1
enter elem to insert 7
[3, 7]

Press-->
1 to insert in rear
2 to remove from front
3 to insert in front
4 to remove from rear
5 to display values of queue
6 to reverse the exisiting queue
7 to exit 1
enter elem to insert 2
[3, 7, 2]

Press-->
1 to insert in rear
2 to remove from front
3 to insert in front
4 to remove from rear
5 to display values of queue
6 to reverse the exisiting queue
7 to exit 6
[2, 7, 3]

Press-->
1 to insert in rear
2 to remove from front
3 to insert in front
4 to remove from rear
5 to display values of queue
6 to reverse the exisiting queue
7 to exit 7

Space Complexity - O(1)
Time Complexity - O(n^2)
"""
