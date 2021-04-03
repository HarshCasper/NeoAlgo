def union_of_arrays(arr1, arr2):
    arr1.sort()
    arr2.sort()

    
    firstelement = 0
    secondelement  = 0
    union = []

    while firstelement < len(arr1) and secondelement < len(arr2):
        if arr1[firstelement] < arr2[secondelement]:
            firstelement += 1
        elif arr1[firstelement] > arr2[secondelement]:
            secondelement += 1
        else:
            union.append(arr1[firstelement])  
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