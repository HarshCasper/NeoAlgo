'''
Given an array of integers and a number x, find the smallest subarray with sum greater than the given value. 
'''
def smallSubarrayLength(arr, n, k):
    
    if n == 0:
        return 0  
    # use 2 pointers min_len & greater_k, increment greater_k until sum becomes greater than or equal k, and after that find out min length   
    min_len = 0
    greater_k = -1
    Sum = 0
    length = n+1

    # start incrementing min_len until Sum becomes less k again
    while min_len<n and greater_k<n:
        if Sum<k:
            greater_k += 1
            if greater_k<n: Sum += arr[greater_k]
        else:
            length = min(length, (greater_k-min_len+1))
            Sum -= arr[min_len]
            if min_len == greater_k:
                greater_k += 1
            min_len += 1  
    return length

    

if __name__ == '__main__':
        arr = list(map(int, input("Enter the element: ").split()))
        k = int(input("Enter the value X: "))
        n = len(arr)
        print("Minimum length subarray is: ",smallSubarrayLength(arr, n, k))

'''
Time complexcity : O(n)
Space Complexcity : O(n)

Input:
Enter the element: 1 11 100 1 0 200 3 2 1 250 
Enter the value X: 280 

Output:
Minimum length subarray is:  4
'''