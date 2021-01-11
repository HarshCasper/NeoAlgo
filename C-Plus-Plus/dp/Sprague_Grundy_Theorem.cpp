/*The game used to implement Sprague-Grundy is defined below

 -> There are 2 people playing this composite impartial game
 -> The second player writes an arbitrary string . 
 -> Then each player starting with the first player starts 
 	removing a continous substring which exists in a list of 
 	substrings that are possible to remove.
 -> The first player who can't remove a substring loses. */

#include <bits/stdc++.h>
using namespace std;
// Macros used 
typedef pair<int, int> pii;

#define maxs 33
#define INF 1e9

// Global Variables
int t, y, st[maxs][maxs], pc[maxs][maxs], kk[maxs][maxs];
string a, wq[maxs];

void process(int x)
{
	// Process the Grundy numbers for each input
	int g, h;
	pc[x][0] = -1;
	for (g = 0, h = -1; g < wq[x].size();)
	{
		while (h >= 0 && wq[x][g] != wq[x][h])
		{
			h = pc[x][h];
		}
		g++, h++;
		pc[x][g] = h;
	}
}
vector<pii> kmp(int x, string s)
{
	int g, h;
	vector<pii> all;
	for (g = 0, h = 0; g < s.size();)
	{
		while (h >= 0 && s[g] != wq[x][h])
		{
			h = pc[x][h];
		}
		g++, h++;
		if (h == wq[x].size())
		{
			all.push_back(pii(g - h, g));
			h = pc[x][h];
		}
	}
	return all;
}

// Sprague Grundy Theorem implemented
/*Note that after a player erases a substring S(a, b), 
in S(i, j), the game is split into two subgames, S(i, a-1) 
and S(b+1, j). Because a player can choose any game in his/her 
turn, the Grundy number of the game is simply the XOR of the 
Grundy numbers of the two subgames. */

int sprague_grundy(int nx, int ny)
{
	if (nx > ny)
		return 0;
	if (kk[nx][ny] == t)
		return st[nx][ny];
	int g, h, px, py, xr1, xr2, now;
	string s;
	vector<int> ss;
	vector<pii> all;
	for (g = nx; g <= ny; g++)
	{
		s += a[g];
	}
	for (g = 0; g < y; g++)
	{
		all = kmp(g, s);
		for (h = 0; h < all.size(); h++)
		{
			px = all[h].first, py = all[h].second;
			xr1 = (sprague_grundy(nx, nx + px - 1));
			xr2 = (sprague_grundy(nx + py, ny));
			ss.push_back(xr1 ^ xr2);
		}
	}
	sort(ss.begin(), ss.end());
	ss.erase(unique(ss.begin(), ss.end()), ss.end());
	/*A game is losing iff its Grundy number is zero. 
	So the first player, will win if G(1, |S|) is not zero.
	On the other hand, player 2 will win if G(1, |S|) is zero. */
	for (g = now = 0; g < ss.size(); g++, now++)
	{
		if (ss[g] != now)
			break;
	}
	st[nx][ny] = now;
	kk[nx][ny] = t;
	return now;
}

/*Let G(i, j) be the Grundy number of the substring 
S(i, j). Then G(i, j) = mex({G(i, a-1) XOR G(b+1, j) : S(a, b) 
exists in the dictionary and is a substring of S(i, j)} */
int main()
{
	int g, h, re;
	// Intitialising the array with value of INF
	for (g = 0; g <= 30; g++)
	{
		for (h = 0; h <= 30; h++)
		{
			kk[g][h] = INF;
		}
	}
	cout << "Enter Main String : ";
	cin >> a;
	cout << "Enter total number of substrings : ";
	cin >> y;
	cout << "Enter all " << y << " substrings : " << endl;
	for (g = 0; g < y; g++)
	{
		cin >> wq[g];
		process(g);
	}
	// Run the Sprague Grundy algo on each recursive combination
	re = sprague_grundy(0, a.size() - 1);
	// Outputting which player wins
	if (re == 1)
		cout << "Player 1 wins.";
	else
		cout << "Player 2 wins.";

	return 0;
}

/*
Time Complexity: O(n^2)

Sample Input:
Enter main string : spraguegrundy
Enter total number of substrings : 2
Enter all 2 substrings : 
spra
grundy

Sample Output: 
Player 2 wins.
*/
