'''
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
The replacement must be in place and use only constant extra memory.
Ex1: 
Input :[1, 2, 3]
output:[1, 3, 2]

Ex2:
Input :[3, 2, 1]
output:[1, 2, 3]

Ex3:
Input :[1, 1, 5]
output:[1, 5, 1]


'''
def permute(arr):
    #if the arr is smaller than 2 return the arr same 
    if len(arr)<2:
        return arr
    
    inverse=len(arr)-2
    #if the array element start larger value then inverse the array 
    while inverse>=0 and arr[inverse]>=arr[inverse+1]:
        inverse-=1
    
    if inverse<0:
        return 
    
    #checking the value  larger value swap the poistion with smaller element  
    for i in reversed(range(inverse, len(arr))):
        if arr[i]>arr[inverse]:
            arr[i], arr[inverse]=arr[inverse],arr[i]
            break
    arr[inverse+1:]= reversed(arr[inverse+1:])
    #result 
    return arr

if __name__ == "__main__":
    arr= list(map(int, input("Enter the list: ").split()))
    print(permute(arr))

'''
Time Complexcity: O(n)
Space Complexcity: O(1)

INPUT:
Enter the list: 
1 2 3 

OUTPUT:
[1,3,2]

'''
