def maxSumofKelements(arr, n, k):
    if(k > n):
        return -1;                      #k must be smaller than n
    ans = 0;
    for i in range(0, k):              #first we find sum of first k elements
        ans += int(arr[i])
    curr_sum = ans                     #curr_sum is the current sum
    for i in range(k, n):
        curr_sum += int(arr[i]) - int(arr[i - k])   
        ans = max(ans, curr_sum)
    return ans
    

print("Enter number of elements in array: ")    
n = int(input());                     #inputting num of elements in array

print("Enter array elements in a single line seperated with spaces : ")
input_string = input()                #inputting array elements
arr = input_string.split()

print("Enter k")
k = int(input())                      #inputting k

print("Maximum sum of k consecutive elements in array is: " + str(maxSumofKelements(arr, n, k)))
