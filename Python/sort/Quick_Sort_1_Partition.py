# On a single line, print the partitioned numbers (i.e. the elements in left , then the # elements in equal, and then the elements in right). Each integer should be separated 
# by a single space.
def partition(ar):
    p = ar[0]
    left = []
    right = []
    for e in ar[1:]:
        if e <= p:
            left.append(e)
        else:
            right.append(e)
    
    left.append(p)
    for e in right:
        left.append(e)
    ar[:] = left[:]
    for e in ar:
        print(e,end=" ")

# input size of array
m = input()
# input elements of array, where first number is pivot number 
ar = [int(i) for i in input().strip().split()]
# print the partitioned numbers
partition(ar)