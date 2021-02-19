'''
To cyclically (clockwise) rotate a list of integers by N
(N is user defined)
'''


def Rotate(list, N):
    for i in range(N):
        a = list.pop()
        list.insert(0, a)
    return list

try:
    list = []

    # For the list rotation to be dynamic it has been put in a loop
    # While the loop is true the user gets 4 options

    while True:
        op = int(input('''
Press-->
1 to insert element in the list
2 to rotate list cyclically
3 to display list
4 to exit
'''))

        if op == 1:
            ele = int(input("enter element to put in list "))
            list.append(ele)

        elif op == 2:
            if len(list) == 0:
                print("The list is empty, insert values if required")
            else:
                N = int(input("By how much would you like to rotate "))
                print("list before rotating by ", N, " ", list)
                list = Rotate(list, N)
                print("list after rotating by ", N, " ", list)

        elif op == 3:

            if len(list) == 0:
                print("The list is empty, insert values if required")
            else:
                print(list)

        elif op == 4:
            break

        else:
            print("invalid option")

except ValueError:

    print("Please enter integer only")

except:

    print("There's been some issue please check the data you've entered")

'''
Sample Input-output:

>Cyclically_rotate.py

Press-->
1 to insert element in the list
2 to rotate list cyclically
3 to display list
4 to exit
1
enter element to put in list 3

Press-->
1 to insert element in the list
2 to rotate list cyclically
3 to display list
4 to exit
1
enter element to put in list 2

Press-->
1 to insert element in the list
2 to rotate list cyclically
3 to display list
4 to exit
1
enter element to put in list 4

Press-->
1 to insert element in the list
2 to rotate list cyclically
3 to display list
4 to exit
2
By how much would you like to rotate 2
list before rotating by  2   [3, 2, 4]
list after rotating by  2   [2, 4, 3]

'''

'''
Time complexity - O(n)
'''
