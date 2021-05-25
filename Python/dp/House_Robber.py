
#A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.


def maxMoneyLooted(houses, n) :
    #If there are 0 houses , return 0 
    if n == 0 :
        return 0
    
    #If there is only one house , return its money    
    if n == 1 :
        return houses[0]
    
    #If there are atleast 2 houses ,create arr and calculate the maximum amount of money that can be looted
    maxMoneyCanBeLooted = [0]*n
    
    maxMoneyCanBeLooted[0] = houses[0]
    maxMoneyCanBeLooted[1] = max(houses[0], houses[1])
    
    for currHouse in range(2,n) :
        #At each i th house either (houses upto i-2) + (i th house) or (houses upto i-1) can be robbed
        maxMoneyCanBeLooted[currHouse] = max(maxMoneyCanBeLooted[currHouse - 1], (houses[currHouse] + maxMoneyCanBeLooted[currHouse - 2]))
    
    #Return the required answer which is the maximum amount of money that can be robbed till last house    
    return maxMoneyCanBeLooted[n-1]
    
    
def takeInput() :
    n = int(input().rstrip())
    if n == 0 :
        return list(), 0
        
    arr = list(map(int, input().rstrip().split(" ")))
    return arr, n

def main():
    arr,n = takeInput()
    print(maxMoneyLooted(arr,n))
    
if __name__ == '__main__':
    main()
    
    
'''

Time Complexity: O(n)
Space Complexity: O(n)
where n is the total number of houses

Sample Input:
6
10 2 30 20 3 50

Sample Output:
90

Explanation :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot,
and all the other possible combinations would result in less than 90.

'''
