"""
Sorting the array into a wave-like array.
For eg: arr[] = {1,2,3,4,5}
Output: 2 1 4 3 5
"""


def convertToWave(length,array):
    for i in range(0, length - length%2, 2):               #swapping alternatively
        temp=array[i]
        array[i]=array[i+1]
        array[i+1]=temp
    return array

arr = list(map(int,input("Enter the elements of the array : ").split()))
N = len(arr)    # length of the array

arr = convertToWave(N,arr)

print("Wave Array: ")
for el in arr:
  print(el, end=" ")
   
    
"""
Time complexity : O(1) 
Space complexity : O(1) 

INPUT:-
Enter the elements of the array : 1 2 3 4 5 6 7
OUTPUT:-
Wave Array: 2 1 4 3 6 5 7 

"""
