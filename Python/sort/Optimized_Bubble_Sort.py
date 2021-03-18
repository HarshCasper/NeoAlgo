#Optimized Bubble Sort
#Written by XZANATOL

"""
Add a small optimization for Bubble Sort algorithm, so that is stops looping on the given \
list if it is sorted.
"""

def optimized_BS(L):
    length = len(L)
    for i in range(length):
        sorted = 0 #sorted flag
        for j in range(length-i-1):
            if L[j] > L[j+1]: #Reverse the operator for descending order
                L[j], L[j+1] = L[j+1], L[j]
                sorted = 1
                
        #If no swaps happened for a complete pass
        #Then the array is sorted
        if sorted == 0:
            break        
    return L


#Start checkpoint
if __name__ == "__main__":
    #Convert to a list so len() function can work on it
    L = list(map(int, input("Enter list > ").split()))
    
    print("List after sorting: {} ".format(optimized_BS(L)))

"""
The idea of the sorted flag is that it detects where a swap happenned or not in each pass \
of the for second for loop. If no swaps took place then the list is sorted already, and \
no need for more passes to take place, so it breaks out of the loop.

I/O example:
=============
Input:
Enter list > 65 89 1 4 5 6 87

Output:
List after sorting: [1, 4, 5, 6, 65, 87, 89]

Time Complexity:
=================
Time Complexity here is affected by how the list if first provided. The algorithm takes \
lesser time to order elements when elements are already sorted.

Best case Time Complexity: O(n)
Explain: When the array is already sorted

Worst case Time Complexity: O(n^2)
Explain: Will occur when the array is sorted in the opposite order of the alrogrithm
  If the algorithm is configured to sort in ascending order and the provided list is in descending order \
  and vice versa.
"""
