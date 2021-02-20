'''
Rotation of the list means that each elementis shifted right by one index, and the last element of the list is moved to the first place. This is done N number of times,
where N is user-defined
'''

def Rotate(list, N):
    for i in range(N):
        a = list.pop()
        list.insert(0, a)
    return list

try:

    # For the list rotation to be dynamic it has been put in a loop
    # While the loop is true the user gets 4 options

    while True:
        op = int(input('''
Press-->
1 to insert elements in the list
2 to rotate list cyclically
3 to display list
4 to add an element in the list
5 to exit
'''))

        if op == 1:
            list = list(map(int, input("Enter the numbers: ").split()))

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
            ele = int(input("Enter element to put in list "))
            list.append(ele)

        elif op == 5:
            break

        else:
            print("Invalid option")

except ValueError:
    print("Please enter integer only")

except:
    print("There's been some issue please check the data you've entered")

'''
Sample Input-output:

>Cyclically_rotate.py
Press-->
1 to insert elements in the list
2 to rotate list cyclically
3 to display list
4 to add an element in the list
5 to exit
1
Enter the numbers: 2 3 4 5

Press-->
1 to insert elements in the list
2 to rotate list cyclically
3 to display list
4 to add an element in the list
5 to exit
3
[2, 3, 4, 5]

Press-->
1 to insert elements in the list
2 to rotate list cyclically
3 to display list
4 to add an element in the list
5 to exit
4
Enter element to put in list 4

Press-->
1 to insert elements in the list
2 to rotate list cyclically
3 to display list
4 to add an element in the list
5 to exit
2
By how much would you like to rotate 2
list before rotating by  2   [2, 3, 4, 5, 4]
list after rotating by  2   [5, 4, 2, 3, 4]

Press-->
1 to insert elements in the list
2 to rotate list cyclically
3 to display list
4 to add an element in the list
5 to exit
5

Time complexity - O(n)
'''
