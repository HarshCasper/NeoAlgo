def numSquareSum(num): 
    squareSum = 0; 
    while(num): 
        squareSum += (num % 10) * (num % 10); 
        num = int(num / 10); 
    return squareSum; 
  
def isHappynumber(num): 

    slow = num 
    fast = num
    while(True): 

        slow = numSquareSum(slow)
        fast = numSquareSum(numSquareSum(fast)); 
        if(slow != fast): 
            continue
        else: 
            break 
    return (slow == 1) 
  
# Driver Code 
num = int(input("Enter a number: "))
if (isHappynumber(num)): 
    print(num , "is a Happy number") 
else: 
    print(num , "is not a Happy number") 
 
"""
Time Complexity: O(logN)
Space Complexity: O(logN)

Sample Input:
Enter a number: 13
Sample Output:
13 is a Happy number
"""
