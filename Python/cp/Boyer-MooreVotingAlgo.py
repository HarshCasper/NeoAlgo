'''
Boyer-Moore Voting Algorithm (The Majority Element)

Objective: Given an array A of N elements, Find the majority element in the array.
A majority element in an array of N elements is an element that occurs 
N/2 times in an array.

'''

# Python Code:

def majorityElement(A, n):    
 
    # here 'm' stores the majority element (if present)
    mx = -1
 
    # initialize `c` with 0
    c = 0
 
    # do for each element `A[j]` in the list of elements
    for i in range(n): 
        # if counter `c` becomes 0
        if c == 0: 
            # set the current candidate to `A[i]`
            mx = A[i]
 
            # reset the counter to 1
            c = 1 
        # or increment the counter if `A[j]` is a current candidate
        elif mx == A[i]:
            c = c + 1 
        # or decrement the counter if `A[j]` is a current candidate
        else:
            c = c - 1 
    if c> n//2:
        print(mx)
 
    else:
        print("No Majority Element")


# Driver code

if __name__ == "__main__":
    B = [2, 6, 4, 6, 2, 5, 6]
    p = len(A)
 
    # Function calling
    majorityElement(B p)
    

'''

Time Complexity: O(n*n)
Space Complexity: O(1)

Output: 6 ('6' occurs 3 times in list A so it is the majority element)

'''