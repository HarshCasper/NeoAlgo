#python program to rotate array by k elements
'''
it will rotate the array by k elements 
input format
1
5 2
1 2 3 4 5
ans : 3 4 5 1 2
'''

#function to totate the array A
def rotateArr(A, k, N):
    # let if array is [1,2,3,4,5,6,7] and k = 2
    #first k elements [1,2]
    lst = A[0:k]

    #shifting all elements to left by k steps
    for i in range(0, N - k):
        A[i] = A[i + k]

    #adding first k elemets to end in rerverse order
    A[N - k:] = lst[:]
    return A

def main():
    #test cases
    T = int(input())
    while (T > 0):
        nd = [int(x) for x in input().strip().split()]
        N = nd[0]
        k = nd[1]
        A = [int(x) for x in input().strip().split()]
        rotateArr(A, k, N)
        # printing the result
        for i in A:
            print(i, end=" ")
        print()
        T -= 1


if __name__ == "__main__":
    main()
# } Driver Code Ends


#sample i/o
'''
input format

2           no of test cases 
5 2         no_of_elements and K
1 2 3 4 5   array

output : 3 4 5 1 2
'''
#Time complexity : O(n)
