'''Crossword Puzzle Problem
Problem Link:https://www.hackerrank.com/challenges/crossword-puzzle/problem
Steps:
1. Check the cell to be '-' of first character of the word
2. Check if that particular word can be filled in That place horizontally or vertically
3. If the word can be filled , fill it!
4. If it cann't be filled,Backtrack the previous word and fill it in other position
5. Repeat the process until all the words are filled that is index == words.length.'''


def solveCrossword(crossword0, words0, index0, wordfill0):
    if index0 == len(words0):
        printCrossword(crossword0)
        return
    for i0 in range(10):
        for j0 in range(10):
            if crossword0[i0][j0] in ('-', words0[index0][0]):
                # try to insert it vertically
                inserted = insertVerPoss(i0, j0, crossword0, words0, index0, wordfill0)
                if inserted:
                    solveCrossword(crossword0, words0, index0+1, wordfill0)
                if inserted:
                    removeVertically(i0, j0, crossword0, words0, index0, wordfill0)
                # try to insert it horizontally
                inserted = insertHorPoss(i0, j0, crossword0, words0, index0, wordfill0)
                if inserted:
                    solveCrossword(crossword0, words0, index0 + 1, wordfill0)
                if inserted:
                    removeHorizontally(i0, j0, crossword0, words0, index0, wordfill0)


def removeHorizontally(i1, j1, crossword1, words1, index1, wordfill1):
    for x1 in enumerate(words1[index1]):
        if wordfill1[index1][x1]:
            crossword1[i1][j1] = '-'
        wordfill1[index1][x1] = False
        j1 = j1+1


def insertHorPoss(i2, j2, crossword2, words2, index2, wordfill2):
    word = words2[index2]
    wordIndex = 0
    initial_j = j2
    while j2 < 10:
        # if(crossword[i][j]=='+'):
        #     return False
        if crossword[i2][j2] == '-':
            wordIndex = wordIndex+1
        elif crossword2[i2][j2] == word[wordIndex]:
            wordIndex = wordIndex+1
        else:
            return False
        if wordIndex == len(word):
            for x2 in enumerate(word):
                if crossword2[i2][initial_j] == word[x2]:
                    wordIndex = wordIndex+1
                else:
                    crossword2[i2][initial_j] = word[x2]
                    wordfill2[index2][x2] = True
                initial_j = initial_j+1
            return True
        j2 = j2+1
    return False


def insertVerPoss(i3, j3, crossword3, words3, index3, wordfill3):
    word = words3[index3]
    wordIndex = 0
    initial_i = i3
    while i3 < 10:
        # if(crossword[i][j]=='+'):
        #     return False
        if crossword3[i3][j3] == '-':
            wordIndex = wordIndex+1
        elif crossword3[i3][j3] == word[wordIndex]:
            wordIndex = wordIndex+1
        else:
            return False
        if wordIndex == len(word):
            for x3 in enumerate(word):
                if crossword3[initial_i][j3] == word[x3]:
                    wordIndex = wordIndex+1
                else:
                    crossword3[initial_i][j3] = word[x3]
                    wordfill3[index3][x3] = True
                initial_i = initial_i+1
            return True
        i3 = i3+1
    return False


def removeVertically(i4, j4, crossword4, words4, index4, wordfill4):
    for x4 in enumerate(words4[index4]):
        if wordfill4[index4][x4]:
            crossword4[i4][j4] = '-'
        wordfill4[index4][x4] = False
        i4 = i4+1


def printCrossword(crossword5):
    for i5 in range(10):
        for j5 in range(10):
            print(crossword5[i5][j5], end='')
        print()
# -------------------------------Driver Code-------------------------------


if __name__ == "__main__":
    # For taking user input
    crossword_temp = []
    for _ in range(10):
        # Inputting the 10 lines of crossword
        crossword_temp.append(input())
    # converting strings to character Array beacuse strings in python are immutable
    crossword = [[0 for i in range(10)] for j in range(10)]
    for i6 in range(10):
        for j6 in range(10):
            crossword[i6][j6] = crossword_temp[i6][j6]
    # Take input words separated by ';'
    words = list(map(str , input().split(';')))
    wordfill = [False for _ in range(len(words))]
    for i7 in enumerate(words):
        wordfill[i7] = [False]*len(words[i7])
    solveCrossword(crossword, words, 0, wordfill)
# Sample Input:
# +-++++++++
# +-++++++++
# +-++++++++
# +-----++++
# +-+++-++++
# +-+++-++++
# +++++-++++
# ++------++
# +++++-++++
# +++++-++++
# LONDON;DELHI;ICELAND;ANKARA
# Sample Output:
# +L++++++++
# +O++++++++
# +N++++++++
# +DELHI++++
# +O+++C++++
# +N+++E++++
# +++++L++++
# ++ANKARA++
# +++++N++++
# +++++D++++
