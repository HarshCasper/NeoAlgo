''' 
Next-Greater-Element
Problem Statement : Given an array A[] of size N having
                    distinct elements, the task is to find
                    the next greater element for each element
                    of the array in order of their appearance
                    in the array.
                    Next greater element of an element in the
                    array is the nearest element on the
                    right which is greater
                    than the current element.
Input : Enter the length of the list and enter the list.
Output : If there does not exist next greater of
         current element, then next greater
         element for current element is -1.
         For example, next greater of the last
         element is always -1.

Time Complexity : O(n)
Space Complexity : O(n)
'''

def NGE(l, inputs):
    stack = []
    arr = [-1] * inputs
    print(arr)
    for i in range(len(l)):
        if len(stack) == 0:
            stack.append(i)
        else:
            while(len(stack) > 0 and l[stack[-1]] < l[i]):
                j = stack.pop()
                arr[j] = l[i]
            stack.append(i)
    print(*arr)


# -----------------------Driver Code-----------------------
# INPUT
# Enter the length of the list
inputs = int(input("Enter the length of the list: "))
# Enter the list 
numbers = list(map(int, input("Enter the elements: ").rstrip().rsplit())) 
# OUTPUT
NGE(numbers, inputs)

'''
SAMPLE INPUT/OUTPUT:
INPUT
    Enter the brackets: {{[[[()]]]}}{(())}
OUTPUT
    The parentheses are balnced
'''
