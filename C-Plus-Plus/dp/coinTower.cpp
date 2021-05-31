/*
Jack and Harry are playing a new game today. They form a tower of N coins 
and make a move in alternate turns. harry plays first. In one step, the player 
can remove either 1, X, or Y coins from the tower. The person to make the last 
move wins the game. Find who wins the game for different number of coins.
*/


#include <bits/stdc++.h>
using namespace std;

string findWinner(int totalcoins, int coinsThatCanBeRemoved1, int coinsThatCanBeRemoved2) {
    //We are assuming that coinsThatCanBeRemoved2 is greater than or equal to coinsThatCanBeRemoved1
    if(coinsThatCanBeRemoved1>coinsThatCanBeRemoved2){
        swap(coinsThatCanBeRemoved1,coinsThatCanBeRemoved2);
    }
    /*
        dp[i] represents whether Harry will win provided that "i" coins
        are remaining and it is Harry's turn.
        If Harry will win in that scenario, dp[i] will be true otherwise
        it'll be false.
    */
    
    bool*dp = new bool[totalcoins+1];
    
    //i represents number of remaining coins
    for(int i=1; i<=totalcoins; ++i){
        /*
            Trivial case : if 1, coinsThatCanBeRemoved1 or coinsThatCanBeRemoved2 coins are remaining and it's Harry's turn,
            he will simply pick up all coins and win the game.
        */
        
        if(i==1 || i==coinsThatCanBeRemoved1 || i==coinsThatCanBeRemoved2){
            dp[i]=true;
        }
        
        /*
            If less than coinsThatCanBeRemoved1 coins remain, each player can only pick up one coin per turn.
            so the result of the game when i coins are remaining will be the reverse
            of the result when there were i - 1 coins.
        */
        
        else if(i<coinsThatCanBeRemoved1){
            dp[i] = !dp[i-1];
        }
        
        /*
            If the number of coins is between coinsThatCanBeRemoved1 and coinsThatCanBeRemoved2, each player can pick up either 1 or coinsThatCanBeRemoved1 coins
            per turn. Now, each player wants to win, so they will look at the state of the game when
            i - 1 coins remain and also when i - coinsThatCanBeRemoved1 coins remain. If the player is winning in any of
            those states, he will try to get to that state, i.e, if the player is winning in i - 1
            state, he will remove 1 coin. If he's winning in the i - coinsThatCanBeRemoved1 state, he will remove i - coinsThatCanBeRemoved1
            coins. If he is losing in both states, then it doesn't matter what he does, he will still
            lose.
            So to get the value of dp[i], we will first AND(&) the values of dp[i]
            and then NOT(!) it.
        */
        
        else if(i<coinsThatCanBeRemoved2){
            dp[i] = !(dp[i-coinsThatCanBeRemoved1] && dp[i-1]);
        }
        //The reasoning for this case is similar to the one above
        
        else{
            dp[i] = !(dp[i-coinsThatCanBeRemoved1] && dp[i-coinsThatCanBeRemoved2] && dp[i-1]);
        }
    }
    
    bool result = dp[totalcoins];
    delete[] dp;
    if(result){
        return "Harry";
    }
    else{
        return "Jack";
    }
}

int main()
{
	int totalcoins, coinsThatCanBeRemoved1, coinsThatCanBeRemoved2;
	cout<<"Enter total coins: "<<endl;
	cin >> totalcoins;
	cout<<"1. Enter number of coins that can be removed: "<<endl;
	cin>> coinsThatCanBeRemoved1;
	cout<<"2. Enter number of coins that can be removed: "<<endl;
	cin >> coinsThatCanBeRemoved2;
	cout<<"The winner is: ";
	cout << findWinner(totalcoins, coinsThatCanBeRemoved1, coinsThatCanBeRemoved2);
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
where n is the initial number of coins

Sample Input:
Enter total coins: 
10
1. Enter number of coins that can be removed: 
2
2. Enter number of coins that can be removed: 
4

Sample Output:
The winner is: Harry
*/
