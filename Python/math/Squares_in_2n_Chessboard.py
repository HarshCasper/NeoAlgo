#Find total number of Squares in a N*N cheesboard.

class Solution:
    # using mathematical logic
    def squares(self, N):
        
        sum=0
        for i in range(1,N+1):
            s=i*i
            sum+=s
        return sum

#taking input
num = int(input("Enter the number :"))
obj = Solution()
print("The square : ")
print(obj.squares(num))

'''
Time complexity : O(N)
Space complexity : O(1)

Input :
Enter the number :  1
Output :
The square is : 1
'''