#Bead sort (a.k.a Abacus sort, or Gravity sort) is a sorting algorithm 
# that can sort a list of positive integers .
# We can sort negative numbers too by adding a constant to all the integers and subracting it later 
#Bead sort is a natural algorithm 
#It uses (imitates) gravity to sort an input list

def bead_sort(a):
    minimum, maximum = min(a), max(a)
    n = len(a)

    # Initialize a temporary array filled with minimum
    temp = [minimum] * n
    for i in range(maximum-1, minimum-1, -1):
        k = 0
        for j in range(n):
            if a[j] > i:
                temp[k] += 1
                k += 1

    # Copy temp array back into original array
    # replacing the array into sorted order
    # temp array is reverse sorted, so copy backwards for ascending order
    for i in range(n):
        a[i] = temp[n-i-1]

    return a

if __name__ == "__main__":
    a=[]
    print(bead_sort(a))