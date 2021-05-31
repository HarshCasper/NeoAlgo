"""
When given a list of integers,
we have to find the pair of adjacent
elements that have the largest product
and return that product.
"""


def MaxAdjacentProduct(intList):
    max = intList[0]*intList[1]
    a = 0
    b = 1
    for i in range(1, len(intList) - 1):
        if(intList[i]*intList[i+1] > max):
            a = i
            b = i+1
            max = intList[i]*intList[i+1]
    return(a, b, max)
    
if __name__ == '__main__':
    intList = list(map(int, input("\nEnter the numbers : ").strip().split()))
    pos1, pos2, max = MaxAdjacentProduct(intList)
    print("Max= ", max, " product of elements at position ", pos1, ",", pos2)

"""
Sample Input - Output:

Enter the numbers : -5 -3 -2
Max=  15  product of elements at position  0 , 1

Time Complexity : O(n)
Space Complexity : O(1)

"""
