'''
Its a simple python program to rotate array by k elements.
Approch : First Select first k elements and puth them in seperate array , then move all the elements after position k to their left by k steps.
After this we just put the elements which are in seperate array at the end in reverse order.  
it will rotate the array by k elements.
'''

# function to totate the array A
def rotateArr(A, k, N):
    # first k elements
    lst = A[0:k]
    # shifting all elements to left by k steps
    for i in range(0, N - k):
        A[i] = A[i + k]
    # adding first k elemets to end in rerverse order
    A[N - k:] = lst[:]
    return A

def main():
    print("Enter the value of no of elements in array and K in one line")
    nd = [int(x) for x in input().strip().split()]
    N = nd[0]
    k = nd[1]
    print("Enter the array in one line")
    A = [int(x) for x in input().strip().split()]
    rotateArr(A, k, N)
    print("After rotating array by ",k," elements the array is ")
    # printing the result
    for i in A:
        print(i, end=" ")
    print()


# Driver Code
if __name__ == "__main__":
    main()

'''
Sample Input/Output:

Enter the value of no of elements in array and K in one line
5 2
Enter the array in one line
1 2 3 4 5

Output:
After rotating array by 2 elements the array is 
3 4 5 1 2

Time Complexity : O(n)
Space Complexity : O(k)

'''
