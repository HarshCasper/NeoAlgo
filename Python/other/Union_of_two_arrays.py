# Find array union of two arrays
def union_of_arrays(arr1, arr2):
    # let's sort both arrays
    arr1.sort()
    arr2.sort()
    
    # iterators for arr1, arr2
    firstelement = 0
    secondelement  = 0
    # result
    union = []

    # then go along both arrays
    while firstelement < len(arr1) and secondelement < len(arr2):
        # if an element is lower than another, increment iterator in that array
        if arr1[firstelement] < arr2[secondelement]:
            firstelement += 1
        elif arr1[firstelement] > arr2[secondelement]:
            secondelement += 1
        else:
            # if we find equal elements
            union.append(arr1[firstelement]) # add element to the result
            # increment iterators of both arrays 
            firstelement += 1
            secondelement += 1

    return union


if __name__ == "__main__":
    arr1 = list(map(int,input("Enter the Number in list 1:\n").split()))
    arr2 = list(map(int,input("Enter the Number in list 2:\n").split()))
    print(union_of_arrays(arr1, arr2))

'''
Time Complexity : O((n+m)log(n+m))
Space Complexity : O(n+m)

INPUT:
    Enter the list 1: 
    1 2 3 2 0
	Enter the list 2: 
    5 1 2 7 3 2

OUTPUT  
    [1, 2, 2, 3]
'''