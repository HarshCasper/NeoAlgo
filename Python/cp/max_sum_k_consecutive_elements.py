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
k = int(input("Enter k: "))                      #inputting k

print("Maximum sum of k consecutive elements in array is: " + str(maxSumofKelements(arr, n, k)))

#Sample test case: 
# arr = {50, 70, 30, 10}, k = 2, n = 4
# 1. ans = 0, now once the for loop is executed, ans becomes 120 (50 + 70)
# 2. Now we have to check whether any other sum of k consecutive elements is greater than our initial sum.
# 3. Now we run a loop from k to n, and everytime we calculate curr_sum and check whether it is greater than our ans or not, if it is greater, we update our ans.
# 4. Iterations: curr_sum = 120 + 30 - 50 = 100(i.e 70 + 30) (So here we calculated arr[1] + arr[2]) (i = 2)(ans > curr_sum, therefore, ans = 120)
#                curr_sum = 100 + 10 - 70 = 40(i.e. 30 + 40) (arr[2] + arr[3]) (i = 3)(ans > curr_sum, therefore, ans = 120)
# 5. So the final ans is 120
