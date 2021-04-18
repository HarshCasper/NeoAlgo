import math
'''
This is a simple code in python to find the Nth term of a GP , let say 1 3 9 27 is GP its first term (a) is 1 and the Common Ratio (r) is 3 and if n=3 it means 3rd term which is 9.
Approach : Enter the values of A (first term of GP) and R (Common Ratio of GP) it will calculate the nth term.
'''
def termOfGP(A, B, N):
    r = B / A
    ans = A * ((math.pow(r, N - 1)))
    return ans



def main():
    print("Enter the value of first term a and the Common Common Ratio r of a GP")
    AR = [int(x) for x in input().strip().split()]
    A = AR[0]
    R = AR[1]
    print("Enter the value of N to find the value of its Nth term")
    N = int(input())
    print("The Nth term of this GP is ",math.floor(termOfGP(A, R, N)))


#  Driver Code Starts
if __name__ == "__main__":
    main()

'''
Sample Input/Output:

Enter the value of first term a and the Common Ratio r of a GP
1 3
Enter the value of N to find the value of its Nth term
3

Output:
The Nth term of this GP is 9
Time Complexity : O(1)
Space Complexity : O(1)
'''