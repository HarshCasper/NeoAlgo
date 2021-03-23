'''
Stack implementation using List in Python
'''

stack = []

# For the stack to be dynamic it has been put in a loop
# While the loop is true the user gets 5 options:
# 1 to push  element in stack
# 2 to pop element from stack
# 3 to display elements in stack
# 4 To peek
# 5 To exit


try:  # try except so that the program does not crash[optional]

    while True:
        op = int(input('''
Press-->
1 to push into stack
2 to pop from stack
3 to diplay elements of stack
4 to peek top most element
5 to exit

'''))

        if op == 1:  # To push into stack

            ele = int(input("\nenter element  to push "))
            stack.append(ele)

        elif op == 2:  # To pop from stack.

            if len(stack) == 0:
                print("\nStack is empty ")
            else:
                ele = stack.pop()
                print("\npopped element ", ele)

        elif op == 3:  # To display stack elements

            if len(stack) == 0:
                print("\nStack is empty ")
            else:
                print(stack)

        elif op == 4:  # To peek stack top.

            if len(stack) == 0:
                print("\nStack is empty ")
            else:
                print("\nTop most element in stack is ", stack[-1])

        elif op == 5:  # To exit from loop

            break

        else:

            print("\ninvalid option")


except ValueError:

    print("Please enter integer only")

except:

    print("There's been some issue please check the data you've entered")


"""
Sample Input- Output
Press-->
1 to push into stack
2 to pop from stack
3 to diplay elements of stack
4 to peek top most element
5 to exit
1
enter element  to push 2
Press-->
1 to push into stack
2 to pop from stack
3 to diplay elements of stack
4 to peek top most element
5 to exit
1
enter element  to push 3
Press-->
1 to push into stack
2 to pop from stack
3 to diplay elements of stack
4 to peek top most element
5 to exit
1
enter element  to push 4
Press-->
1 to push into stack
2 to pop from stack
3 to diplay elements of stack
4 to peek top most element
5 to exit
3
[2, 3, 4]
Press-->
1 to push into stack
2 to pop from stack
3 to diplay elements of stack
4 to peek top most element
5 to exit
2
popped element  4
Press-->
1 to push into stack
2 to pop from stack
3 to diplay elements of stack
4 to peek top most element
5 to exit
5
"""

"""
Time complexity - O(n)
"""

