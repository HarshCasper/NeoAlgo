# The Minion Game solution


def minion_game(string):
    # Players, Scores
    Stuart, kevin = 0, 0
    # Check loop
    for i in range(len(string)):
        if string[i] in ['A', 'E', 'I', 'O', 'U']:
            kevin += len(string) - i
        else:
            Stuart += len(string) - i
    # Print score
    if kevin > Stuart:
        print("Kevin", kevin)
    elif Stuart > kevin:
        print("Stuart", Stuart)
    else:
        print("Draw")


"""
Description:
=============
2 players Stuart & Kevin are given the same string S.
Both players have to make substrings using the letters of that string.
A player gets +1 point for each occurrence of the substring in the string.
The game ends when both players have made all possible substrings.
The winner is the one with most points.
(difficulity: Medium)
Link: https://www.hackerrank.com/challenges/the-minion-game/

I/O Example:
=============
Input:
BANANA

Output:
Stuart 12

Complexity:
============
Time Complexity: O(n)
Explain: Loop time is dependent on inputed string length
"""
