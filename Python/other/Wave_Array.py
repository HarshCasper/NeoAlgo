"""
Sorting the array into a wave-like array. In other words, arranging the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5..... (considering the increasing lexicographical order) in python.
For eg: arr[] = {1,2,3,4,5}
Output: 2 1 4 3 5
"""


def convertToWave(N,A):
    for i in range(0, N-N%2, 2):               #swapping alternatively
        temp=A[i]
        A[i]=A[i+1]
        A[i+1]=temp
    return A

A = list(map(int,input("Enter the elements of the array : ").split()))
N = len(A)

A = convertToWave(N,A)

print("Wave Array: ")
for el in A:
  print(el, end=" ")
   
    
"""
Time complexity : O(1) 
Space complexity : O(1) 

INPUT:-
Enter the elements of the array : 1 2 3 4 5 6 7
OUTPUT:-
Wave Array: 2 1 4 3 6 5 7 

"""
