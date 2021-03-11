 #Staicase Problem

#Staicase Problem implemented on 2D matrix to find a key(element) in the matrix in which rows and columns are in increasing sorted order. 

# Algorithm : 
# 	In this function, the property of both the row and column sorted can be exploited.
#  We can start from top-right postion of the matrix, because it is the largest element of the row and smallest element of the column.
#  Now, if the key is smaller than that element, it surely means that we should move towards left,thereby excluding the current column.
#  Else, if the key is greater than that element, it surely means that we should move towards bottom,thereby excluding the current row.
#  Time Complexity - O(n) -> since, a row or column is skipped with comparison of just a single element

def staircase(mat, n, key):
    i, j = 0, n-1
    while i <=n-1 and j >=0:
        #When element matches print the element with its position
        if key == mat[i][j]:    
            print ('Key %s found at (%s,%s)' % (key, i+1, j+1)) 
            return
        #When key is smaller than current matrix element,decrease the column number by 1
        if key < mat[i][j]:
            j -= 1
        #When key is greater than current matrix element,go to next row
        else:
            i += 1
    print ('Key %s not found' % (key))


def main():
    mat = [ [10, 20, 30, 40],
        [15, 25, 35, 45],
        [27, 29, 37, 48],
        [32, 33, 39, 50] ]
    key = 48
    for x in mat:
        print (x)
    staircase(mat, len(mat), key)


if __name__ == '__main__':
    main()
