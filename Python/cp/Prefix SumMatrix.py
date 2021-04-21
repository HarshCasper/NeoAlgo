'''In Algorithms, the prefix sum (cumulative sum) of a sequence of numbers x0, x1, x2, ... is a second sequence 
    of numbers y0, y1, y2, ..., the sums of prefixes (i.e, running totals) of the provided input sequence
    as follows-
    y0 = x0
    y1 = x0 + x1
    y2 = x0 + x1+ x2
    and so on...
    Time Complexity= O(R*C)
    Space Complexity= O(R*C)'''

# Code for Prefix Sum Matrix[2D Array] in Python -
r = int(input())    #no. of rows
c = int(input())    #no. of columns
 
# New Array claculation:
def prefixSum(A) :          # A= Original Array, Ap= PrefixSum Array
    global C, R
    Ap = [[0 for x in range(c)]
              for y in range(r)]
    Ap[0][0] = A[0][0]
 
    #Enter Values in First row & column:
    for i in range(1, c) :
        Ap[0][i] = (Ap[0][i - 1] +
                       A[0][i])
    for i in range(0, r) :
        Ap[i][0] = (Ap[i - 1][0] +
                       A[i][0])
 
    # updation of the values of cells as per above working:
    for i in range(1, r) :
        for j in range(1, c) :
 
            # values in the cells of prefixsum array are updated
            Ap[i][j] = (Ap[i - 1][j] +
                         Ap[i][j - 1] -
                         Ap[i - 1][j - 1] +
                           A[i][j])
 
    # Displaying the new array
    for i in range(0, r) :
        for j in range(0, c) :
            print (Ap[i][j],
                   end = " ")
        print ()
 
# Matrix whose prefix we need to find
# enter the matrix
A = [[ 10, 20, 30],
     [ 5, 10, 20],
     [ 2, 4, 6 ]]
 
prefixSum(A)

'''output

    r=3
    c=3
    Ap= [[ 10, 30, 60],
         [ 15, 45, 95],
        [ 17, 51, 107 ]]
'''