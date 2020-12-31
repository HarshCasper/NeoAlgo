
# Python program implementation for Counting sort

#This soring algorithm will only works with array length n consist of
#elements from 0 to k for integer k < n.



def counting_sort(A, max_val):
    k = max_val + 1
    count = [0]*k
    result = [None]*len(A)
    
    print("Array A = ", A)
    
    # counting the number of i (1 < i < k) in A and store in count
    for i in A:
        count[i] += 1

    print("Counting array (storing number of elements appear in A) = ", count)

# calculate the position of each element in the sorted array
for i in range(1, len(count)):
    count[i] = count[i] + count[i-1]
    
    print("Counting array (storing order of elements appear in A) = ", count)
    
    # store the elements back in result using the position of elements stored in count
    for i in range(len(A)-1, -1, -1):
        result[count[A[i]]-1] = A[i]
        count[A[i]] -= 1
    
    return result

import random

# test function
def test():
    while True:
        try:
            n = int(input("Enter length of array A (n): "))
            max_val = int(input("Enter the max val in A (smaller than n): "))
            
            if max_val >= n:
                print("Invalid input.\n")
        
            else:
                A = []
                
                for _ in range(n):
                    A.append(random.randint(0, max_val))
                
                print("\nResult: ", counting_sort(A, max_val), "\n")
    
    except Exception as e:
        print(e)
        print("Exiting...\n")
        break

if __name__ == "__main__":
    test()
