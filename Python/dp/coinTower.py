'''
Jack and Harry are playing a new game today. They form a tower of N coins 
and make a move in alternate turns. harry plays first. In one step, the player 
can remove either 1, X, or Y coins from the tower. The person to make the last 
move wins the game. Find who wins the game for different number of coins.
'''

def findWinner(totalcoins ,coinsThatCanBeRemoved1, coinsThatCanBeRemoved2) :
    #We are assuming that y is greater than or equal to x
    if coinsThatCanBeRemoved1>coinsThatCanBeRemoved2 :
        coinsThatCanBeRemoved1, coinsThatCanBeRemoved2 = coinsThatCanBeRemoved2, coinsThatCanBeRemoved1
        
    '''
        dp[i] represents whether Harry will win provided that "i" coins
        are remaining and it is Harry's turn.
        If Harry will win in that scenario, dp[i] will be true otherwise
        it'll be false.

    '''
   
    dp = [False] * (totalcoins+1)
    #i represents number of remaining coins
   
    for i in range(1, (totalcoins+1)) :
        if (i == 1) or (i == coinsThatCanBeRemoved1) or (i == coinsThatCanBeRemoved2) :
            '''
            Trivial case : if 1, coinsThatCanBeRemoved1 or coinsThatCanBeRemoved2 coins are remaining and it's Harry's turn,
            he will simply pick up all coins and win the game.
            '''
           
            dp[i] = True
           
        elif i < coinsThatCanBeRemoved1 :
            '''
            If less than coinsThatCanBeRemoved1 coins remain, each player can only pick up one coin per turn.
            so the result of the game when i coins are remaining will be the reverse
            of the result when there were i - 1 coins.
            '''
            dp[i] = not(dp[i-1])
       
        elif i < coinsThatCanBeRemoved2 :
            '''
            If the number of coins is between coinsThatCanBeRemoved1 and coinsThatCanBeRemoved2, each player can pick up either 1 or coinsThatCanBeRemoved1 coins
            per turn. Now, each player wants to win, so they will look at the state of the game when
            i - 1 coins remain and also when i - coinsThatCanBeRemoved1 coins remain. If the player is winning in any of
            those states, he will try to get to that state, i.e, if the player is winning in i - 1
            state, he will remove 1 coin. If he's winning in the i - coinsThatCanBeRemoved1 state, he will remove i - coinsThatCanBeRemoved1
            coins. If he is losing in both states, then it doesn't matter what he does, he will still
            lose.
            So to get the value of dp[i], we will first AND(&) the values of dp[i]
            and then NOT(!) it.
            '''
            dp[i] = not(dp[i - coinsThatCanBeRemoved1] and dp[i - 1])
           
        else:
            #The reasoning for this case is similar to the one above
            dp[i] = not(dp[i-coinsThatCanBeRemoved1] and dp[i-coinsThatCanBeRemoved2] and dp[i-1])
           
    result = dp[totalcoins]
   
    if result :
        return "Harry"
    else :
        return "Jack"
       
       
def main():
    print('Enter total number of coins and coins that can be removed: ')
    li = input().rstrip().split(" ")
    totalcoins = int(li[0])
    coinsThatCanBeRemoved1 = int(li[0])
    coinsThatCanBeRemoved2 = int(li[2])
    print('The winner is: ')
    print(findWinner(totalcoins, coinsThatCanBeRemoved1, coinsThatCanBeRemoved2))

if __name__ == '__main__':
    main()
    
'''
Time Complexity: O(n)
Space Complexity: O(n)
where n is the initial number of coins

Sample Input:
Enter total number of coins and coins that can be removed: 
10 2 4
Sample Output:
The winner is: 
Harry
'''
