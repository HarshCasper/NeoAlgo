'''Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes.
For example, in an array A: {1,2,3,-4,5,-2,-3,2,5}
4 is the equilibrium index because (1+2+3-4) = (-2-3+2+5)'''
import math

def equilibriumPoint(arr, N):
    # finding the sum of whole array
    total_sum = sum(arr)
    leftsum = 0
    if N == 1:
        return 1
    for i, num in enumerate(arr):

        # total_sum is now right sum
        # for index i
        total_sum -= num

        if leftsum == total_sum:
            return i + 1
        leftsum += num

        # If no equilibrium index found,
    # then return -1
    return -1




def main():
    print("Enter Number of Elements in the Array")
    N = int(input())
    print("Enter the Array")
    A = [int(x) for x in input().strip().split()]
    print("Equlibrium index is")
    print(equilibriumPoint(A, N))


# Driver Code Starts

if __name__ == "__main__":
    main()

# Driver Code Ends

'''
Input

Enter Number of Elements in the Array
9
Enter the Array
1 2 3 -4 5 -2 -3 2 5
Equlibrium index is
3

Time complexity- O(N)
'''