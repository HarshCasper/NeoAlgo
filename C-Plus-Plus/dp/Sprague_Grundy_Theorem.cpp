/* Game Description-
"A game is played between two players and there are N piles
of stones such that each pile has certain number of stones.
On his/her turn, a player selects a pile and can take any
non-zero number of stones upto 3 (i.e- 1,2,3)
The player who cannot move is considered to lose the game
(i.e., one who take the last stone is the winner).
Can you find which player wins the game if both players play
optimally (they don't make any mistake)? "

A DP approach to calculate Grundy Number
and Mex and find the Winner using Sprague - Grundy Theorem. */

#include<bits/stdc++.h>
using namespace std;

/* piles[] -> Array having the initial count of stones/coins
			in each piles before the game has started.
n	 -> Number of piles
Grundy[] -> Array having the Grundy Number corresponding to
			the initial position of each piles in the game
The piles[] and Grundy[] are having 0-based indexing*/

#define PLAYER1 1
#define PLAYER2 2

// Find MEX
int calculateMex(unordered_set<int> Set)
{
	int Mex = 0;
	while (Set.find(Mex) != Set.end())
		Mex++;
	return (Mex);
}

// A function to Compute Grundy Number of 'n'
int calculateGrundy(int n, int Grundy[])
{
	Grundy[0] = 0;
	Grundy[1] = 1;
	Grundy[2] = 2;
	Grundy[3] = 3;
	if (Grundy[n] != -1)
		return (Grundy[n]);
	unordered_set<int> Set;
	for (int i=1; i<=3; i++)
			Set.insert (calculateGrundy (n-i, Grundy));
	Grundy[n] = calculateMex (Set);
	return (Grundy[n]);
}

void declareWinner(int whoseTurn, int piles[],
					int Grundy[], int n)
{
	int xorValue = Grundy[piles[0]];
	for (int i=1; i<=n-1; i++)
		xorValue = xorValue ^ Grundy[piles[i]];
	if (xorValue != 0)
	{
		if (whoseTurn == PLAYER1)
			printf("Player 1 wins\n");
		else
			printf("Player 2 wins\n");
	}
	else
	{
		if (whoseTurn == PLAYER1)
			printf("Player 2 wins\n");
		else
			printf("Player 1 wins\n");
	}
	return;
}

int main()
{
	// Sample Test
	int piles[] = {1, 4, 5};
	int n = sizeof(piles)/sizeof(piles[0]);

	// Find max element
	int maximum = *max_element(piles, piles + n);
	
	int Grundy[maximum + 1];
	memset(Grundy, -1, sizeof (Grundy));

	// Calculate Grundy Value of piles[i] and store it
	for (int i=0; i<=n-1; i++)
		calculateGrundy(piles[i], Grundy);

	declareWinner(PLAYER1, piles, Grundy, n);

	return (0);
}

