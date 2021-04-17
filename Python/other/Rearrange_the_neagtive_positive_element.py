"""
Given an array of positive and negative numbers, arrange them in an alternate 
fashion such that every positive number is followed by negative and vice-versa 
maintaining the order of appearance. 
Number of positive and negative numbers need not be equal. 
If there are more positive numbers they appear at the end of the array.
If there are more negative numbers, they too appear in the end of the array.

Examples : 

Input:  {1, 2, 3, -4, -1, 4}
Output: {-4, 1, -1, 2, 3, 4}

Input:  {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
output: {-5, 5, -2, 2, -8, 4, 7, 1, 8, 0} 
"""

def rearrange_list_with_order(arr):
    posi=[]
    negi=[]
    
    for i in range(len(arr)):
        if arr[i]>=0:
            posi.append(arr[i])
        else:
            negi.append(arr[i])
    
    l=len(arr)

    arr2=[]      
    
    for i in range(l):
    #print(negi[i],posi[i],len(negi),len(posi))
        if i<len(negi):
            arr2.append(negi[i])
        if i<len(posi):
            arr2.append(posi[i])
    return arr2 

if __name__ == "__main__":
    arr = list(map(int,input("Enter the list : ").split()))
    print('After rearrange with order',rearrange_list_with_order(arr))

"""
Time Complexity: O(n^2)
Space Complexity : O(1)

INPUT: 
Enter the list 1: 1 2 3 -4 -1 4


OUTPUT:
After rearrange with order [-4, 1, -1, 2, 3, 4]
"""
